//---------------------------------------------------------------------------

#pragma hdrstop

#include "Ethernet.h"
#include "GenModParam.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

#define MAX_LAN_RETRY 3
#define TO_ACK        1000


extern TList *ClientList;

// *****************************************************************************
__fastcall C_ETHERNET::C_ETHERNET()
// *****************************************************************************
{
  OffLineEthernet =false;
	try
  {
    ClientList =new TList;
    // Create Receive Packet Semaphore in MANUAL reset , NOT signalled
    TxList.Semaphore =CreateEvent(NULL, true, false, NULL);
    // Create Tx Packet List Critical Section
    TxList.CrSect =new TMultiReadExclusiveWriteSynchronizer;
    LanLck =new TCriticalSection;
    // Reset Transmitted Packet Count
    TxList.Count =0;
    // Reset Transmit Packet insertion Position
    TxList.InsPos =1;
    // Reset Transmit Packet Extraction Position
		TxList.ExtPos =1;
	}
	catch(...)
	{
	}
}

// *****************************************************************************
__fastcall C_ETHERNET::~C_ETHERNET()
// *****************************************************************************
{
  if(TxList.CrSect)
  {
	  delete TxList.CrSect;
  }
}

// ****************************************************************************
u32 __fastcall CrcRoll(u32 Crc)
// ****************************************************************************
{
  s32 n =1;
  while(n ++ <=8)
  {
    if((Crc & 1) ==1)
    {
      Crc >>= 1;
      Crc ^=0xA0000001;
    }
    else
    {
      Crc >>= 1;
    }
  }
  return(Crc);
}
                  
// *****************************************************************************
s32 __fastcall C_ETHERNET::WritePacket(T_ETHERNET_TRANSMIT_BUFFER *TxBuffer,
                                     u32 TimeOut)
// *****************************************************************************
//
{
	if(OffLineEthernet)
	{
		return(TRANSMIT_OK);
	}
	// Lock Tx Packet List
	TxList.CrSect->BeginRead();
	s32 NPktPresent =TxList.Count;
		// unLock Tx Packet List
	TxList.CrSect->EndRead();
	// If available Packet present
	if(NPktPresent <MAX_TX_PACKET)
	{
		s32 Periferica =IdThread(TxBuffer->PeAddress);
		if(Periferica >=0)
		{
			// Lock Tx Packet List
			TxList.CrSect->BeginWrite();
			// Add new record to the list
			TxList.List[TxList.InsPos] =*TxBuffer;
			// add Checksum
			s32 i =0;
			u32 Crc =0xffffffff;
			while(i <TxList.List[TxList.InsPos].LL)
			{
				Crc =((Crc ^((u32)TxList.List[TxList.InsPos].cmd[i ++] &0xff))& 0xff)|
						 (Crc &0xff000000);
				Crc =CrcRoll(Crc);
			}
			Crc >>=1;
			TxList.List[TxList.InsPos].cmd[i] =Crc;
			TxList.List[TxList.InsPos].IdThread =IdThread(TxList.List[TxList.InsPos].PeAddress);
			++ TxList.List[TxList.InsPos].LL;
			// Update n. of packets to be transmitted
			TxList.Count++;
			if(++ TxList.InsPos >MAX_TX_PACKET)
			{
				TxList.InsPos =1;
			}
			// UnLock Tx Packet List
			TxList.CrSect->EndWrite();
			// *****************************************
			// ************  transmit Packet ***********
			// *****************************************
			SendCommandToPE();
			return(TRANSMIT_OK);
		}
		else
		{
      return(PE_NOT_CONNECTED);
    }
	}
  else
  {
		return(TXLIST_ERR);
  }
}

// *****************************************************************************
T_ETHERNET_TRANSMIT_BUFFER* __fastcall C_ETHERNET::ReadTxMsg()
// *****************************************************************************
{
  T_ETHERNET_TRANSMIT_BUFFER *buffer;
  // Lock Transmit Packet List
  TxList.CrSect->BeginWrite();
  // Copy Packet from Packet List
  buffer =&TxList.List[TxList.ExtPos];
  TxList.Count--;
  if(++ TxList.ExtPos >MAX_TX_PACKET)
  {
    TxList.ExtPos =1;
  }
  // unLock Transmit Packet List
  TxList.CrSect->EndWrite();
  return(buffer);
}

// *****************************************************************************
bool __fastcall C_ETHERNET::ReadOffLine(void)
// *****************************************************************************
{
  return(OffLineEthernet);
}

// *****************************************************************************
void __fastcall C_ETHERNET::WriteOffLine(bool f)
// *****************************************************************************
{
	OffLineEthernet =f;
}

//******************************************************************************
// Funzioni per gestione della rete di connessione con le teste
//******************************************************************************
bool __fastcall C_ETHERNET::ClientSemaphore(u32 IdThread, bool Stato, bool fCmd)
//******************************************************************************
{
	C_SIMPLECLIENT *Client;
	HANDLE ClientSem;

	if((s32)IdThread <ClientList->Count)
	{
		Client =(C_SIMPLECLIENT *)ClientList->Items[IdThread];
		if(fCmd)
		{
			ClientSem =Client->Sem_cmd;
		}
		else
		{
			ClientSem =Client->Sem_ack;
		}
		if(Stato)
		{
			SetEvent(ClientSem);
		}
		else
		{
			ResetEvent(ClientSem);
		}
		return(true);
	}
	return(false);
}

// ****************************************************************************
void __fastcall C_ETHERNET::SendCommandToPE()
// ****************************************************************************
// funzione che invia il comando all'indirizzo indicato
{
	s32 i;
  LanLck->Acquire();
	// Estrae il puntatore del messaggio da spedire
	T_ETHERNET_TRANSMIT_BUFFER *buffer =Ethernet->TxMsg;
	// Carica il puntatore al socket thread della testa a cui spedire il comando
	C_SIMPLECLIENT *Client =(C_SIMPLECLIENT *)ClientList->Items[buffer->IdThread];
	// *******************************************************************
  // ************* Attende il termine del comando Precedente ***********
  // *******************************************************************
	// Attende la fine esecuzione del comando precedente dalla stessa testa
  WaitForSingleObject(Client->Sem_cmd, TOWAITCLIENT);
  //
  // *********************************************************
	// ************* Trasmette il comando alla Testa ***********
  // *********************************************************
  //
  if(Client->Thread->Connection->Connected())
  {
		// Accende il semaforo sull'esecuzione prima del comando successivo
		ResetEvent(Client->Sem_cmd);
		// Accende il semaforo per l'attesa dell'acknoweledge
    ResetEvent(Client->Sem_ack);
    // Accende il led di trasmissione alla testa
//    PostMessage(MainForm->Handle, WM_TX_LED, buffer->Id, 1);
    i =MAX_LAN_RETRY;
    while(i -- >0)
    {
      // Invia il messaggio
      Client->Thread->Connection->WriteBuffer(buffer->cmd, buffer->LL *4, true);
			// Attende Acknoweledge comando dalla testa
      if(WaitForSingleObject(Client->Sem_ack, TO_ACK) ==WAIT_OBJECT_0)
      {
        // comando trasmesso correttamente
        break;
      }
    }
	}
  LanLck->Release();
}

//******************************************************************************
s32 __fastcall C_ETHERNET::ReadNumPerifericheConnesse(void)
//******************************************************************************
{
	return(ClientList->Count);
}
//******************************************************************************
u32 __fastcall C_ETHERNET::IdTesta(AnsiString PeerIP)
//******************************************************************************
{
	u32 id;
	s8 *ip;
	ip =StrPos(PeerIP.c_str(), ".");
	ip =StrPos(ip +1, ".");
	ip =StrPos(ip +1, ".");
	id =StrToIntDef(ip +1, 0);
	return(id);
}

//******************************************************************************
s32 __fastcall C_ETHERNET::IdThread(AnsiString PeerIP)
//******************************************************************************
// ritorna l'indice nella lista dei client socket del thread che gestisce il
// canale che ha per indirizzo 'PeerIP'. Se non lo trova ritorna -1
{
	C_SIMPLECLIENT *Client;
	s32 id =-1;
	for(s32 i =0; i <ClientList->Count; i ++)
	{
		Client =(C_SIMPLECLIENT *)ClientList->Items[i];
		if(Client->IpAddress.AnsiCompare(PeerIP) ==0)
		{
			id =i;
			break;
		}
	}
	return(id);
}
//******************************************************************************
AnsiString __fastcall C_ETHERNET::IpAddress(s32 IdThread)
//******************************************************************************
// ritorna l'indice nella lista dei client socket del thread che gestisce il
// canale che ha per indirizzo 'PeerIP'. Se non lo trova ritorna -1
{
	if (IdThread >=0 &&IdThread <ClientList->Count)
	{
		C_SIMPLECLIENT *Client =(C_SIMPLECLIENT *)ClientList->Items[IdThread];
		return(Client->IpAddress);
	}
	return("");
}

