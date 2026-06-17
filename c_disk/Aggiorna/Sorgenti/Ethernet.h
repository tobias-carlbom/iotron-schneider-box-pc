#ifndef EthernetH
  #define EthernetH
  //---------------------------------------------------------------------------
	#include <Classes.hpp>
	#include <Windows.hpp>
	#include <SysUtils.hpp>
	#include <System.hpp>
	#include <SyncObjs.hpp>
  #include <IdBaseComponent.hpp>
  #include <IdComponent.hpp>
  #include <IdTCPServer.hpp>
	#include "Gk_type.h"

  #define UNITA_UC  				1
  #define UNITA_IMG  				2

  #define CMD_FAIL					100
  #define CMD_NACK 					101
  #define CHAN_DISCONNECTED 102

  #define STOP_WATCHDOG(i) FormMain->TimWD->Enabled =false; \
								LogMessage->WriteLogMessage(SysData.PathLog +"Log.Txt", \
								10, IntToStr(i), " ");



	#define LLTCPCMD		100

	#define UNLOCK_SEM	true
	#define LOCK_SEM	  false
	#define SEM_ACK  	  false
	#define SEM_CMD     true


	// ***************************
	// ***** ERROR CODE **********
	// ***************************
	#define   TXLIST_ERR          6
	#define   TRANSMIT_OK         0
	#define   PE_NOT_CONNECTED    5
	#define   MAX_TX_PACKET       100
	#define   TO_ETHERNET_TX      1500
	#define   TOWAITCLIENT			  3500

	// *****************************
	// ***** COMMAND CODE **********
	// *****************************
	#define 	LAN_ACK				27


	#define PE1				"192.168.0.147"

  //---------------------------------------------------------------------------

	typedef struct S_ETHERNET_TRANSMIT_BUFFER
	{
		s32 IdThread;
		AnsiString PeAddress;
		s32 cmd[LLTCPCMD];
		s32 LL;
	} T_ETHERNET_TRANSMIT_BUFFER;

	struct S_TX_LIST
	{
		TMultiReadExclusiveWriteSynchronizer* CrSect;
		void *Semaphore;
		T_ETHERNET_TRANSMIT_BUFFER List[MAX_TX_PACKET +1];
		s32 Count;
		s32 InsPos;
		int ExtPos;
	} ;

	class C_SIMPLECLIENT : public TObject
	{
		public:		// User declarations
			u32 ListLink;
			TIdPeerThread *Thread;
			HANDLE Sem_cmd;
			HANDLE Sem_ack;
			AnsiString IpAddress;
			s32 PreviousCmd;
			s32 To;											// Time out risposta comando
	};

	class C_ETHERNET : public TObject
	{
		private:
      TCriticalSection *LanLck;
			bool OffLineEthernet;
			struct S_TX_LIST TxList;
			s32 Periferica;

		protected:
			void __fastcall SendCommandToPE();
			T_ETHERNET_TRANSMIT_BUFFER * __fastcall ReadTxMsg(void);
			bool __fastcall ReadOffLine(void);
			void __fastcall WriteOffLine(bool f);
			s32 __fastcall ReadNumPerifericheConnesse(void);

		public:
			__property bool OffLine={read=ReadOffLine, write=WriteOffLine};
			__property T_ETHERNET_TRANSMIT_BUFFER *TxMsg={read=ReadTxMsg};
			__property s32 NumPerifericheConnesse={read=ReadNumPerifericheConnesse};
			__fastcall C_ETHERNET();
			__fastcall virtual ~C_ETHERNET(void);

			s32 __fastcall WritePacket(T_ETHERNET_TRANSMIT_BUFFER *TxBuffer,
																 u32 TimeOut);
			bool __fastcall ClientSemaphore(u32 IdThread, bool Stato, bool fCmd);
      u32  __fastcall IdTesta(AnsiString PeerIP);
			s32  __fastcall IdThread(AnsiString PeerIP);
			AnsiString __fastcall IpAddress(s32 IdThread);
  } ;



#endif

extern C_ETHERNET *Ethernet;
