/*

                GRAFIKONTROL S.P.A.

          ********************************
          *** Modulo:  GENMODPARAM.cpp ***
          ********************************

          
  Revisione modulo: 1.0 Beta

  Data: 22 Marzo 2005




  Il modulo GenModParam.ccp rende disponibile un metodo per la memorizzazione
  di parametri il cui numero, tipo e descrizione sono definibili a piacere.

  Il modulo prevede 2 livelli di definizione dei parametri:
    Livello 1
      In questo livello sono definibili fino a 16 insiemi distinti di dati
      definiti come UNITA'. Graficamente ogni Unità è rappresentata da un
      bottone.
    Livello 2
      In questo livello sono definiti per ogni UNITA' fino a 8 sotto-unità.
      Ad ognuna di queste sotto-unità è associato un FILE di dati
      Graficamente ogni sotto-unità è rappresentata da un bottone.
      Graficamete il file di dati associato è rappresentato da una tabella.

  Per convenzione i nomi dei FILEs dei DATI saranno:
                UNITAxx_y.txt
    dove: xx numero Unità [1..16]
           y numero SottoUnità [1..8]


           
  I parametri e la grafica della form associata a questo modulo sono definiti
  dal contenuto di alcuni file ASCII.

  'GenModParam.txt'
    DEVE RISIEDERE NEL DIRETTORIO CORRENTE OPPURE NELLA root
    Questo file definisce tutti i percorsi di lavoro, i colori e i suffissi
    delle lingue utilizzabili per le descrizioni dei dati e dei parametri
    Inoltre in questo file con la keyword 'fileform=' viene definito
    il nome del file che contiene tutte le definizioni dei bottoni e dei
    pannelli della form. es: fileform=Param.txt
    Una descrizione dettagliata del file è presente nel file stesso.

  'Param.txt' (il nome è indicativo in quanto è definito in GenModParam.txt)
    Deve risiedere nella cartella il cui percorso è definito con la keyword
    'path_dati=' nel file GenModParam.txt.
    Questo file abilita e definisce in tutte le lingue disponibili i bottoni
    delle UNITA', delle SOTTO-UNITA' e i bottoni funzionali per l'accesso e la
    modifica dei valori dei dati memorizzati per ogni sotto-unità abilitata.
    Inoltre ad ogni bottone è associabile una icona tipo bitmap che qualora
    definita dovrà risiedere nella cartella il cui percorso è definito con la
    keyword 'path_bmp=' nel file GenModParam.txt.
    ATTENZIONE! ESISTE QUESTO VINCOLO: PER OGNI SUFFISSO DI LINGUA CHE VIENE
                                       DEFINITO NEL FILE GenModParam.txt DEVE
                                       ESISTERE UNA bitmap xxFlag.bmp NEL
                                       DIRETTORIO il cui percorso è definito con
                                       la keyword 'path_bmp=' nel file G
                                       enModParam.txt.
    Una descrizione dettagliata del file è presente nel file di es. Param.txt.

  'UnitaXX_Y.txt'
    Deve risiedere nella cartella il cui percorso è definito con la keyword
    'path_dati=' nel file GenModParam.txt.
    Questi files contiengono le descrizioni dei parametri in tutte le lingue
    definite, i valori minimi massimi di default ed effettivi dei dati memo-
    rizzati, ed il colore della riga di visualizzazione nella tabella.
    Le stringhe di descrizione dei valori sonodefinibili anche run-time.



  Sono disponibili le seguenti TIPI':    
    typedef struct S_valoridb
    {
      AnsiString Val;
      AnsiString Tipo;
    } S_valoridb;

    typedef S_valoridb* P_valoridb;


  Sono disponibili le seguenti PROPRIETA':
  
    __property bool AdattaSchermo={read=ReadAdattaSchermo,
                                   write=WriteAdattaSchermo};
        [default =false]
        Se questa AdattaSchermo =true all'attivazione della form la risoluzione
        della VGA viene variata al fine di ottenere la miglior qualità di visua-
        lizzazione. Ovviamente la modalità di funzionamento viene ripristinata
        alla chiusura della form.
        Se false viene usata la risoluzione corrente.

    __property u32 CntLingue={read=ReadCntLingue};
        Ritorna il numero di lingue definite.

    __property u32 Lingua={read=ReadLingua, write=WriteLingua};
        Il valore di questa proprietà indica la lingua da usare all'attivazione
        della form. L'ordine della lingue rispetta quanto definito nel file
        GenModParam.txt con la keyword 'language=' dove il primo suffisso è
        richiamato con FGenModParam->Lingua =0;

    __property AnsiString FileLingue={read=ReadFileLingue};
        Ritorna il nome del file definito con la keyword 'fileform=' nel file
        GenModParam.txt



  Sono disponibili le seguenti FUNZIONI:

    bool  __fastcall IsUnitaAggiornata(u32 Uid);
        Ritorna true se uno qualsiasi dei files associati alle sotto-unità della
        unità 'Uid' [1..16] è stato modificato.
        ATTENZIONE: All'attivazione della form tutte le flag di modifica dei
                    file UNITAxx_y.txt vengono resettate.
                    Non è possibile resettare manualmente le flag.


    bool  __fastcall IsSubUnitaAggiornata(u32 Uid,u32 SubUid);
        Ritorna true se il file Associato alla sotto-unità 'SubUid'[1..8] della
        unità 'Uid' [1..16] è stato modificato.
        ATTENZIONE: All'attivazione della form tutte le flag di modifica dei
                    file UNITAxx_y.txt vengono resettate.
                    Non è possibile resettare manualmente le flag.


    bool  __fastcall TFGenModParam::GetData(u32 idUnita,u32 idSubUnita,
                                            s8 *Primo,u32 NDati,TList *Valori,
                                            u32 *NByte)


        Legge il 'Valore' dei campi contenuti nel file relativo alla sotto-unita
        'idSubUnita' dell'Unita 'idUnita'.
        I valori ed il tipo di ogni valore sono scaricati nella lista 'Valori'
        appendendo alla lista per ogni valore contenuto nel file un record del
        tipo 'S_valoridb', inoltre il numero TOTALE di BYTE letti viene salvato
        in all'indirizzo 'NByte'.
        I valori vengono scaricati nella lista a partire dal campo 'Primo' e se
        ne scaricano una quantità pari a NDati se però 'Primo' = NULL o se
        NDati = 0 nella lista di appoggio vengono scaricati TUTTI i dati
        contenuti nel file.
        Input:
          idUnita = Indice Unita [1..16]
          idSubUnita = Indice sub Unita [1..8]
          Primo = nome del primo dato da leggere (keyword '::name=')
          NDati = numero valori da leggere
          Valori = puntatore alla lista di oggetti del tipo 'S_valoridb'
          NByte = puntatore al numero totale di bytes letti dal file
        Output:

          true se lettura valida altrimenti false

    u32 __fastcall SaveDataPacket(u32 idUnita,u32 idSubUnita,s8 *Primo,
                                  u32 NMaxDati,TStringList *Valori)
        Salva i 'Valori' partendo dal campo 'Primo' nel file relativo alla
        sotto-unita'idSubUnita' dell'Unita 'idUnita' per 'NMaxDati'.
        Input:
          idUnita = Indice Unita [1..16]
          idSubUnita = Indice sub Unita [1..8]
          Primo = nome del primo dato da leggere
          NMaxDati = Numero di dati da scrivere
          Valori = Lista di Stringhe dei valori da scrivere
        Output:
          Numero dei dati salvati se scrittura OK; altrimenti 0

    bool __fastcall SaveData(u32 idUnita,u32 idSubUnita,AnsiString Nome,AnsiString *Valore);
        Salva il 'Valore' nel campo 'Nome' nel file relativo alla
        sotto-unita'idSubUnita' dell'Unita 'idUnita'.
        Input:
          idUnita = Indice Unita [1..16]
          idSubUnita = Indice sub Unita [1..8]
          Nome = nome del campo da scrivere
          Valori = Lista di record del tipo 'S_valoridb' in cui vengono
                   scaricati i valori letti ed il loro tipo
          NByte = Numero totale di byte letti dal file         
        Output:
          true se scrittura andata a buon fine altrimenti false

          
  E' inoltre NECESSARIO inizializzare la funzione 'RichiediPW':
        AnsiString (*RichiediPW)(AnsiString Pw)

  con l'indirizzo di una funzione definita esternamente per la richiesta di una
  PASSWORD. Questa funzione deve essere del tipo:
  
      AnsiString myPasswordRequest(AnsiString pw);
        dove pw =puntatore stringa risultato con la password digitata
        ritorno: puntatore alla stringa risultato con la password digitata

    ES: FGenModParam->RichiediPW =myPasswordRequest;

  ATTENZIONE: Se la funzione 'RichiediPW' non viene inizializzata, nessuna
              password verrà richiesta per l'accesso e la modifica dei dati


  E' possibile associare ai bottoni funzione un comando.
  Questo avviene inizializzando (anche run-time) l'array di funzioni 'Command'
  [0..29]
          void (*Command[30])();
  e mettendo nel fileForm (es: param.txt) alla keyword 'command='
  l'indice del comando da associare al bottone.

  Le funzioni devono essere del tipo:
          void myFunc(void);

  ES: FGenModParam->Command[5] =myFunc;
      e nel 'fileform' all'interno della definizione per es. del bottone
      'btnSalva' con la keyword 'command=5' si farà l'associazione della
      funzione myFunc al click del bottone btnSalva.

*/
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GenModParam.h"
#include <Math.hpp>

#define DEFAULT_LINGUA 0

#define NO_TYPE       0
#define S8_TYPE       1
#define U8_TYPE       2
#define S16_TYPE      3
#define U16_TYPE      4
#define S32_TYPE      5
#define U32_TYPE      6
#define S64_TYPE      7
#define U64_TYPE      8
#define F32_TYPE      9
#define F64_TYPE      10
#define STR_TYPE      11
#define BOOL_TYPE     12

#define DEFAULT_GRID_FONT_SIZE  10
#define DEFAULT_GRID_BK_COLOR   (TColor)clInfoBk
#define DEFAULT_GRID_FIX_COLOR  (TColor)clBtnFace
#define DEFAULT_GRID_SEL_COLOR  (TColor)clNavy
#define DEFAULT_GRID_CHG_COLOR  (TColor)clRed
#define DEFAULT_PANEL_CHG_COLOR (TColor)clYellow
#define DEFAULT_SYSTEM_PASSWORD "11079"

#define DESC_COL      0
#define DEF_COL       1
#define MIN_COL       2
#define MAX_COL       3
#define VALUE_COL     4

#define GMP_DESIGN_DIM      1280
#define GMP_BITXPIXEL       24
#define GMP_PIXXROW         1280
#define GMP_ROWXFRAME       1024

u32 NumParam;

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TFGenModParam *FGenModParam;

static bool Adapt =false;
static u32 UserPelsHeight;
static u32 UserPelsWidth;
static u32 UserMode =0;
static u32 NumLingue;
static u32 ActLingua =0;
static AnsiString *SuffissiLingue;
static AnsiString StrPathDati;
static AnsiString StrPathBmp;
static AnsiString StrFileForm;
static AnsiString StrCaption;
static AnsiString StrName;
static AnsiString StrGlyph;
static AnsiString StrEnable;
static AnsiString StrVisible;
static AnsiString StrCommand;
static AnsiString SystemPassword;
static u32 UnitaSelezionata;
static u32 SubUnitaSelezionata;
static TBitBtn *ActualButton;
static u32 GridFontSize;
static TColor GridBkColor =DEFAULT_GRID_BK_COLOR;
static TColor GridFixColor =DEFAULT_GRID_FIX_COLOR;
static TColor GridSelColor =DEFAULT_GRID_SEL_COLOR;
static TColor GridChgColor =DEFAULT_GRID_CHG_COLOR;
static bool isGridAlternate =true;
static bool isGridCoulored =true;
static bool isSystemPasswordEnabled =true;
static TColor PanelChgColor =DEFAULT_PANEL_CHG_COLOR;
static u8 *TipoParametri =NULL;
static TColor *ColoreParametri;
static bool *Modificato;
static bool isPasswordOK =false;
static TStringList *StrLstParamFile;
static TStringList *StrLstPar;
static u32 NewDescRow;

//---------------------------------------------------------------------------
u32 __fastcall TFGenModParam::ReadCntLingue()
//---------------------------------------------------------------------------
{
  return(NumLingue);
}
//---------------------------------------------------------------------------
u32 __fastcall TFGenModParam::ReadLingua()
//---------------------------------------------------------------------------
{
  return(ActLingua);
}
//---------------------------------------------------------------------------
void __fastcall TFGenModParam::WriteLingua(u32 l)
//---------------------------------------------------------------------------
{
  if(l <NumLingue)
  {
    ActLingua =l;
  }
}

//---------------------------------------------------------------------------
AnsiString* __fastcall TFGenModParam::ReadFileLingue()
//---------------------------------------------------------------------------
{
  return(&StrFileForm);
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::LoadFlagBmp()
//---------------------------------------------------------------------------
{
  AnsiString BmpName =StrPathBmp +SuffissiLingue[ActLingua] +"flag.bmp";
  if(FileExists(BmpName))
  {
    BuLingue->Glyph->LoadFromFile(BmpName);
  }
  else
  {
    BuLingue->Glyph->FreeImage();
  }
}

//---------------------------------------------------------------------------
s8 *ExtractValoreCampo(s8 *Src)
//---------------------------------------------------------------------------
{
  u32 pos;

  pos =0;
  while(pos <StrLen(Src))
  {
    if(Src[pos] ==':' &&Src[pos+1] ==':')
      break;
    else
      ++ pos;
  }
  if(pos <StrLen(Src))
  {
    Src[pos] =0;
  }
  else
  {
    Src[0] =0;
  }
  return(Src);
}

//---------------------------------------------------------------------------
TBitBtn*  __fastcall TFGenModParam::LookForButton(AnsiString ObjName)
//---------------------------------------------------------------------------
{
  TBitBtn *BtnObj =NULL;

  if(strcmp(BtnResBackUp->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnResBackUp;
  if(strcmp(BtnSaveBackUp->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnSaveBackUp;
  if(strcmp(BuLingue->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BuLingue;
  if(strcmp(BtnTast->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnTast;
  if(strcmp(BuDown->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BuDown;
  if(strcmp(BuUp->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BuUp;
  if(strcmp(BuPiu->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BuPiu;
  if(strcmp(BuMeno->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BuMeno;
  if(strcmp(BtnSalva->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnSalva;
  if(strcmp(BtnEsci->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnEsci;
  if(strcmp(Unita1->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita1;
  if(strcmp(Unita2->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita2;
  if(strcmp(Unita3->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita3;
  if(strcmp(Unita4->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita4;
  if(strcmp(Unita5->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita5;
  if(strcmp(Unita6->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita6;
  if(strcmp(Unita7->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita7;
  if(strcmp(Unita8->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita8;
  if(strcmp(Unita9->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita9;
  if(strcmp(Unita10->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita10;
  if(strcmp(Unita11->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita11;
  if(strcmp(Unita12->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita12;
  if(strcmp(Unita13->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita13;
  if(strcmp(Unita14->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita14;
  if(strcmp(Unita15->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita15;
  if(strcmp(Unita16->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =Unita16;
  if(strcmp(BuOk->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BuOk;
  if(strcmp(BtnTastExit->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnTastExit;
  if(strcmp(BtnTastSalva->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnTastSalva;
  if(strcmp(BtnTastCanc->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnTastCanc;
  if(strcmp(BtnGbUnitaEsci->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BtnGbUnitaEsci;
  if(strcmp(BuPrint->Name.c_str(),ObjName.c_str()) ==0)
    BtnObj =BuPrint;
  return(BtnObj);
}

//---------------------------------------------------------------------------
TPanel*  __fastcall TFGenModParam::LookForPanel(AnsiString ObjName)
//---------------------------------------------------------------------------
{
  TPanel *PanelObj =NULL;

  if(strcmp(PanIntest->Name.c_str(),ObjName.c_str()) ==0)
    PanelObj =PanIntest;

  return(PanelObj);
}

//---------------------------------------------------------------------------
AnsiString  __fastcall TFGenModParam::LookForStringa(AnsiString ObjName)
//---------------------------------------------------------------------------
{
  AnsiString StrObj ="";
  
  if(strcmp("FixDesc",ObjName.c_str()) ==0)
  {
    StrObj ="FixDesc";
  }
  else  if(strcmp("FixDefault",ObjName.c_str()) ==0)
  {
    StrObj ="FixDefault";
  }
  else  if(strcmp("FixMin",ObjName.c_str()) ==0)
  {
    StrObj ="FixMin";
  }
  else  if(strcmp("FixMax",ObjName.c_str()) ==0)
  {
    StrObj ="FixMax";
  }
  else  if(strcmp("FixValue",ObjName.c_str()) ==0)
  {
    StrObj ="FixValue";
  }
  return(StrObj);
}

//---------------------------------------------------------------------------
void  __fastcall TFGenModParam::SetPanelProperty(TPanel *Obj)
//---------------------------------------------------------------------------
{
  // ****** set VISIBLE property *******
  if(StrVisible.Length())
  {
    Obj->Visible =(StrVisible.ToIntDef(0) !=0);
  }
  // ****** fill CAPTION field *******
  Obj->Caption =StrCaption;
}

//---------------------------------------------------------------------------
void  __fastcall TFGenModParam::SetStrProperty(AnsiString Obj)
//---------------------------------------------------------------------------
{
                // ****** set VISIBLE property *******
  if(strcmp(Obj.c_str(),"FixDesc") ==0)
  {
    StringGrid1->Cells[DESC_COL][0] =StrCaption;
  }
  else  if(strcmp(Obj.c_str(),"FixDefault") ==0)
  {
    StringGrid1->Cells[DEF_COL][0] =StrCaption;
  }
  else  if(strcmp(Obj.c_str(),"FixMin") ==0)
  {
    StringGrid1->Cells[MIN_COL][0] =StrCaption;
  }
  else  if(strcmp(Obj.c_str(),"FixMax") ==0)
  {
    StringGrid1->Cells[MAX_COL][0] =StrCaption;
  }
  else  if(strcmp(Obj.c_str(),"FixValue") ==0)
  {
    StringGrid1->Cells[VALUE_COL][0] =StrCaption;
  }
}

//---------------------------------------------------------------------------
void  __fastcall TFGenModParam::SetBitBtnProperty(TBitBtn *Obj)
//---------------------------------------------------------------------------
{
                  // ****** set VISIBLE property *******
  if(StrVisible.Length() >0)
  {
    Obj->Visible =(StrVisible.ToIntDef(0) !=0);
  }               // ****** set ENABLE property *******
  if(StrEnable.Length())
  {
    Obj->Enabled =(StrEnable.ToIntDef(0) !=0);
  }               // ****** fill CAPTION field *******
  Obj->Caption =StrCaption;
  if(StrGlyph.Length() >0)
  {
    AnsiString dum = StrPathBmp;
    dum =dum +StrGlyph;
    if(FileExists(dum))
    {             // ****** load BITMAP *******
      Obj->Glyph->LoadFromFile(dum);
    }
  }
  if(StrCommand.Length())
  {               // ****** Set TAG field as switch to COMMAND *****
    Obj->Tag =StrCommand.ToIntDef(0);
  }
}

//---------------------------------------------------------------------------
AnsiString* __fastcall TFGenModParam::LeggiDato(TStringList *SL,
                                            AnsiString campo, AnsiString *val)
//---------------------------------------------------------------------------
{
  AnsiString dum ="";
  if(SL->Count >0)
  {
    for(s32 i =0;i <SL->Count;i ++)
    {
      AnsiString str =SL->Strings[i];
      s32 pos =str.Pos(campo);
      if(pos)
      {
        dum =str.SubString(pos+campo.Length(),str.Length()-pos+campo.Length());
        pos =dum.Pos("::");
        if(pos)
        {
          dum =dum.SubString(pos, dum.Length() -pos);
          break;
        }  
      }
    }
  }
  *val =dum;
  return(val);
}

//---------------------------------------------------------------------------

AnsiString*  __fastcall TFGenModParam::LoadPathDati(AnsiString *PathDati)
{
  TStringList *StrLst;
  AnsiString FileName;

  *PathDati ="";
  FileName =GetCurrentDir() +"\\GenModParam.txt";
  if(FileExists(FileName))
  {
    StrLst =new TStringList();
    StrLst->LoadFromFile(FileName);
    LeggiDato(StrLst, "::path_dati=", PathDati);
    StrLst->Clear();
    delete StrLst;
  }
  return(PathDati);
}

//---------------------------------------------------------------------------
bool  __fastcall TFGenModParam::IsSubUnitaAggiornata(u32 Uid,u32 SubUid)
//---------------------------------------------------------------------------
{
  TStringList *StrLst;
  AnsiString PathDati;
  AnsiString FileName;
  HANDLE FH1;
  HANDLE FH2;
  u32 u;
  u64 len;
  u64 LastWAccess[2];
  u64 FileAccess[2];
  BY_HANDLE_FILE_INFORMATION lpFileInformation;
  bool res =false;

  if(Uid >MAX_NUM_UNITA || SubUid >MAX_NUM_SUBUNITA)
  {
    return(false);
  }
  LoadPathDati(&PathDati);
  if(PathDati.Length() <2)
  {
    return(false);
  }
  FileName =PathDati +"Unita" +IntToStr(Uid) +"_" +IntToStr(SubUid) +".txt";
  FH1 =CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING,
                  FILE_ATTRIBUTE_ARCHIVE,NULL);
  if (FH1 !=INVALID_HANDLE_VALUE)
  {
    try
    {
      res =GetFileInformationByHandle(FH1,&lpFileInformation);
    }
    catch(...)
    {
      res =false;
    }
    if(res)
    {
      res =false;
      LastWAccess[0] =lpFileInformation.ftLastWriteTime.dwLowDateTime;
      LastWAccess[1] =lpFileInformation.ftLastWriteTime.dwHighDateTime;
      FileName =ChangeFileExt(FileName, ".tim");
      FH2 =CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING,
                      FILE_ATTRIBUTE_ARCHIVE,NULL);
      if(FH2 !=INVALID_HANDLE_VALUE)
      {
        len =sizeof(FileAccess);
        try
        {
          ReadFile(FH2,FileAccess,len,&len,NULL);
        }
        catch(...)
        {
          FileAccess[0] =FileAccess[1] =0;
        }
        if(FileAccess[0] !=LastWAccess[0] ||FileAccess[1] !=LastWAccess[1])
        {
          res =true;
        }
        CloseHandle(FH2);
      }
    }
    CloseHandle(FH1);
  }
  return(res);
}
//---------------------------------------------------------------------------
bool  __fastcall TFGenModParam::IsUnitaAggiornata(u32 Uid)
//---------------------------------------------------------------------------
{
  TStringList *StrLst;
  AnsiString PathDati;
  AnsiString FileName;
  HANDLE FH1;
  HANDLE FH2;
  u32 u;
  u64 len;
  u64 LastWAccess[2];
  u64 FileAccess[2];
  BY_HANDLE_FILE_INFORMATION lpFileInformation;
  bool res =false;

  if(Uid >MAX_NUM_UNITA)
  {
    return(false);
  }
  LoadPathDati(&PathDati);
  if(PathDati.Length() <2)
  {
    return(false);
  }
  u =1;
  while(!res &&u <=MAX_NUM_SUBUNITA)
  {
    FileName =PathDati +"Unita" +IntToStr(Uid) +"_" +IntToStr(u) +".txt";
    FH1 =CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING,
                    FILE_ATTRIBUTE_ARCHIVE, NULL);
    if (FH1 !=INVALID_HANDLE_VALUE)
    {
      try
      {
        res =GetFileInformationByHandle(FH1,&lpFileInformation);
      }
      catch(...)
      {
        res =false;
      }
      if(res)
      {
        res =false;
        LastWAccess[0] =lpFileInformation.ftLastWriteTime.dwLowDateTime;
        LastWAccess[1] =lpFileInformation.ftLastWriteTime.dwHighDateTime;
        FileName =ChangeFileExt(FileName ,".tim");
        FH2 =CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING,
                        FILE_ATTRIBUTE_ARCHIVE, NULL);
        if(FH2 !=INVALID_HANDLE_VALUE)
        {
          len =sizeof(FileAccess);
          try
          {
            ReadFile(FH2,FileAccess,len,&len,NULL);
          }
          catch(...)
          {
            FileAccess[0] =FileAccess[1] =0;
          }
          if(FileAccess[0] !=LastWAccess[0] ||FileAccess[1] !=LastWAccess[1])
          {
            res =true;
          }
          CloseHandle(FH2);
        }
      }
      CloseHandle(FH1);
    }
  ++ u;
  }
  return(res);
}
//---------------------------------------------------------------------------
void  __fastcall TFGenModParam::SaveFileDateTime(AnsiString StrName)
//---------------------------------------------------------------------------
{
  AnsiString FileName;
  HANDLE FH1;
  HANDLE FH2;
  u32 su;
  u64 len;
  u64 LastWAccess[2];
  BY_HANDLE_FILE_INFORMATION lpFileInformation;

  for(su =1;su <=MAX_NUM_SUBUNITA;su ++)
  {
    FileName =StrPathDati +StrName +"_" +IntToStr(su) +".txt";
    FH1 =CreateFile(FileName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING,
                    FILE_ATTRIBUTE_ARCHIVE,NULL);
    if(FH1 !=INVALID_HANDLE_VALUE)
    {
      try
      {
        if(GetFileInformationByHandle(FH1,&lpFileInformation))
        {
          LastWAccess[0] =lpFileInformation.ftLastWriteTime.dwLowDateTime;
          LastWAccess[1] =lpFileInformation.ftLastWriteTime.dwHighDateTime;
          FH2 =CreateFile(FileName.c_str(), GENERIC_WRITE, 0, NULL,
                          CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE,NULL);
          if (FH2 !=INVALID_HANDLE_VALUE)
          {
            try
            {
              len =sizeof(LastWAccess);
              WriteFile(FH2,LastWAccess,len,&len,NULL);
            }
            __finally
            {
              CloseHandle(FH2);
            }
          }
        }
      }
      __finally
      {
        CloseHandle(FH1);
      }
    }
  }
}

//---------------------------------------------------------------------------
AnsiString* __fastcall TFGenModParam::LeggiCampo(AnsiString *frase,
                                             AnsiString campo,AnsiString *val)
//---------------------------------------------------------------------------
{
  AnsiString result="";
  if(frase->Length() >0)
  {
    s32 pos =frase->Pos(campo);
    if(pos)
    {
      result =frase->SubString(pos +campo.Length(), frase->Length() -(pos +campo.Length()));
      pos =result.Pos(":");
      if(pos)
      {
        result =result.SubString(1, pos -1);
      }
      else
      {
        result ="";
      }
    }
  }
  *val =result;
  return(val);
}

//---------------------------------------------------------------------------
bool  __fastcall TFGenModParam::GetDataName(u32 idUnita,u32 idSubUnita,
                                AnsiString *Path, u32 NDato, AnsiString *Name)
//---------------------------------------------------------------------------
{
  S_valoridb *Param;
  TStringList *StrLst;
  if(idUnita >MAX_NUM_UNITA || idSubUnita >MAX_NUM_SUBUNITA)
  {
    return(false);
  }
  AnsiString FileName;
  FileName =*Path +"Unita" +IntToStr(idUnita) +"_" +idSubUnita +".txt";
  if(!FileExists(FileName))
  {
    return(false);
  }
  StrLstPar =new TStringList();
  try
  {
    StrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    StrLstPar->Clear();
  }
  NumParam =(u32)StrLstPar->Count;
  if(NumParam <=0 ||NumParam <NDato)
  {
    delete StrLstPar;
    return(false);
  }
  AnsiString frase;
  AnsiString StrValoreCampo;
  bool found =false;
  u32 c =0;
  u32 i =0;
  while(c <NumParam && !found)
  {    // Scorre il file fino al primo valore richiesto
    LeggiFrase(StrLstPar, &c, NumParam, &frase);
    if(frase.Length() >0)
    {
      AnsiString dum =frase;
      LeggiCampo(&dum, "::name=", &StrValoreCampo);
      if(StrValoreCampo.Length() >0)
      {
        if(i ++ ==NDato)
        {
          found =true;
        }
      }
    }
  }
  if(found)
  {
    *Name =StrValoreCampo;
  }  
  return(found);
}

//---------------------------------------------------------------------------
bool  __fastcall TFGenModParam::GetData(u32 idUnita,u32 idSubUnita,
                        AnsiString Nome, u32 NDati,TList *Valori,u32 *NByte)
//---------------------------------------------------------------------------
{
  S_valoridb *Param;
  TStringList *StrLst;
  AnsiString PathDati;
  AnsiString FileName;
  AnsiString frase;
  AnsiString StrValoreCampo;
  AnsiString StrTipoCampo;
  u32 len;
  u32 c;
  bool found =false;
  bool ReadAllData;
  AnsiString dum;

  if(idUnita >MAX_NUM_UNITA || idSubUnita >MAX_NUM_SUBUNITA)
  {
    return(false);
  }
  LoadPathDati(&PathDati);
  if(PathDati.Length() <2)
  {
    return(false);
  }
  found =false;
  FileName =PathDati +"Unita" +IntToStr(idUnita) +"_" +IntToStr(idSubUnita) +".txt";
  if(!FileExists(FileName))
  {
    return(false);
  }
  StrLstPar =new TStringList();
  try
  {
    StrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    StrLstPar->Clear();
  }
  NumParam =(u32)StrLstPar->Count;
  if(NumParam <=0)
  {
    delete StrLstPar;
    return(false);
  }
  ReadAllData =(NDati ==0 || Nome ==NULL);
  *NByte =0;
  c =0;
  if(!ReadAllData)
  {
    found =false;
    while(c <NumParam && !found)
    {    // Scorre il file fino al primo valore richiesto
      LeggiFrase(StrLstPar, &c, NumParam, &frase);
      if(frase.Length() >0)
      {
        dum =frase;
        LeggiCampo(&dum, "::name=", &StrValoreCampo);
        if(StrValoreCampo.Length() >0 && StrValoreCampo ==Nome)
        {
          dum =frase;
          LeggiCampo(&dum, "::value=", &StrValoreCampo);
          if(StrValoreCampo.Length() >0)
          {
            dum =frase;
            LeggiCampo(&dum, "::type=", &StrTipoCampo);
            if(StrTipoCampo.Length() >0)
            {
              Param =new S_valoridb;
              Param->Val =StrValoreCampo;
              Param->Tipo =StrTipoCampo;
              Valori->Add(Param);
              *NByte +=NByteType(&StrTipoCampo);
              -- NDati;
              found =true;
            }
          }
        }
      }
    }
    if(!found)
    {
      delete StrLstPar;
      goto EndGetData;
    }
  }
  else
  {
    NDati =MaxInt;
  }
  while(c <NumParam &&NDati)
  {    // Legge dati
    LeggiFrase(StrLstPar,&c,NumParam,&frase);
    if(frase.Length() >0)
    {
      dum =frase;
      LeggiCampo(&dum, "::name=", &StrValoreCampo);
      if(StrValoreCampo.Length() >0)
      {
        dum =frase;
        LeggiCampo(&dum, "::type=", &StrTipoCampo);
        if(StrTipoCampo.Length() >0)
        {
          Param =new S_valoridb;
          Param->Val =StrValoreCampo;
          Param->Tipo =StrTipoCampo;
          Valori->Add(Param);
          *NByte +=NByteType(&StrTipoCampo);
          -- NDati;
        }
      }
    }
  }
  delete StrLstPar;
  if(!ReadAllData &&NDati >0)
  {
    found =false;
  }
  else
  {
    found =true;
  }
EndGetData:
  return(found);
}

//---------------------------------------------------------------------------
bool  __fastcall TFGenModParam::GetBakData(u32 idUnita,u32 idSubUnita,
                        AnsiString *path, AnsiString *Nome, TList *Valori)
//---------------------------------------------------------------------------
{
  S_valoridb *Param;
  TStringList *StrLst;
  AnsiString PathDati;
  AnsiString FileName;
  AnsiString frase;
  AnsiString StrValoreCampo;
  AnsiString StrTipoCampo;
  u32 len;
  u32 c;
  bool found =false;
  AnsiString dum;

  if(idUnita >MAX_NUM_UNITA || idSubUnita >MAX_NUM_SUBUNITA)
  {
    return(false);
  }
  if(path->Length() <2)
  {
    return(false);
  }
  found =false;
  FileName =*path +"Unita" +IntToStr(idUnita) +"_" +IntToStr(idSubUnita) +".txt";
  if(!FileExists(FileName))
  {
    return(false);
  }
  StrLstPar =new TStringList();
  try
  {
    StrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    StrLstPar->Clear();
  }
  NumParam =(u32)StrLstPar->Count;
  if(NumParam <=0)
  {
    delete StrLstPar;
    return(false);
  }
  c =0;
  while(c <NumParam && !found)
  {    // Scorre il file fino al primo valore richiesto
    LeggiFrase(StrLstPar, &c, NumParam, &frase);
    if(frase.Length() >0)
    {
      dum =frase;
      LeggiCampo(&dum, "::name=", &StrValoreCampo);
      if(StrValoreCampo.Length() >0 && StrValoreCampo ==*Nome)
      {
        dum =frase;
        LeggiCampo(&dum, "::value=", &StrValoreCampo);
        if(StrValoreCampo.Length() >0)
        {
          Param =new S_valoridb;
          Param->Val =StrValoreCampo;
          Param->Tipo =StrTipoCampo;
          Valori->Add(Param);
          found =true;
        }
      }
    }
  }
  delete StrLstPar;
  return(found);
}

//---------------------------------------------------------------------------
bool __fastcall TFGenModParam::SaveData(u32 idUnita,u32 idSubUnita,
                                        AnsiString Nome, AnsiString *Valore)
//---------------------------------------------------------------------------
{
  TStringList *LocalStrLstPar;
  AnsiString FileName;
  AnsiString PathDati;
  AnsiString frase;
  AnsiString valore;
  AnsiString dum;
  u32 NumParam;
  u32 c;
  u32 i;
  u32 j;
  u8 ch;
  bool found =false;

  if(idUnita >MAX_NUM_UNITA || idSubUnita >MAX_NUM_SUBUNITA)
  {
    return(false);
  }
  LoadPathDati(&PathDati);
  if(PathDati.Length() <2)
  {
    return(false);
  }
  FileName =PathDati +"Unita" +IntToStr(idUnita) +"_" +IntToStr(idSubUnita) +".txt";
  if(!FileExists(FileName))
  {
    return(false);
  }
  LocalStrLstPar =new TStringList();
  LocalStrLstPar->Clear();
  try
  {
    LocalStrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    LocalStrLstPar->Clear();
  }
  NumParam =(u32)LocalStrLstPar->Count;
  if(NumParam <=0)
  {
    delete LocalStrLstPar;
    return(false);
  }
  c =0;
  while(c <NumParam && !found)
  {    // Legge dati caratteristici Parametro c-esimo
    frase =LocalStrLstPar->Strings[c];
    if(frase.Length() >0)
    {
      if(frase.Pos("//") !=1  &&frase.Pos("::name="))
      {
        dum =frase;
        LeggiCampo(&dum, "::name=", &valore);
        if(valore.Length() >0 &&valore ==Nome)
        {
          while(c <NumParam && !found)
          {
            frase =LocalStrLstPar->Strings[c];
            if(frase.Length() >0)
            {
              if(frase.Pos("//") !=1  &&frase.Pos("::value="))
              {
                s32 st =frase.Pos("::value=") +StrLen("::value=");
                dum =frase.SubString(1, st -1);
                dum =dum +*Valore +":::";
                found =true;
                LocalStrLstPar->Delete(c);
                LocalStrLstPar->Insert(c, dum);
              }
              ++ c;
            }
          }
        }
      }
    }
    if(!found)
    {
      ++ c;
    }
  }
  if(found)
  {
    try
    {
      LocalStrLstPar->SaveToFile(FileName);
      Application->ProcessMessages();
    }
    catch(...)
    {
      found =false;
    }
  }
  delete LocalStrLstPar;
EndSaveData:
  return(found);
}
//---------------------------------------------------------------------------
bool __fastcall TFGenModParam::SaveBakData(u32 idUnita,u32 idSubUnita,
                       AnsiString *Path, AnsiString *Nome, AnsiString *Valore)
//---------------------------------------------------------------------------
{
  TStringList *LocalStrLstPar;
  AnsiString FileName;
  AnsiString frase;
  AnsiString valore;
  AnsiString dum;
  u32 NumParam;
  u32 c;
  u32 i;
  u32 j;
  u8 ch;
  bool found =false;

  if(idUnita >MAX_NUM_UNITA || idSubUnita >MAX_NUM_SUBUNITA)
  {
    return(false);
  }
  if(Path->Length() <2)
  {
    return(false);
  }
  FileName =*Path +"Unita" +IntToStr(idUnita) +"_" +IntToStr(idSubUnita) +".txt";
  if(!FileExists(FileName))
  {
    return(false);
  }
  LocalStrLstPar =new TStringList();
  LocalStrLstPar->Clear();
  try
  {
    LocalStrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    LocalStrLstPar->Clear();
  }
  NumParam =(u32)LocalStrLstPar->Count;
  if(NumParam <=0)
  {
    delete LocalStrLstPar;
    return(false);
  }
  c =0;
  while(c <NumParam && !found)
  {    // Legge dati caratteristici Parametro c-esimo
    frase =LocalStrLstPar->Strings[c];
    if(frase.Length() >0)
    {
      if(frase.Pos("//") !=1  &&frase.Pos("::name="))
      {
        dum =frase;
        LeggiCampo(&dum, "::name=", &valore);
        if(valore.Length() >0 &&valore ==*Nome)
        {
          while(c <NumParam && !found)
          {
            frase =LocalStrLstPar->Strings[c];
            if(frase.Length() >0)
            {
              if(frase.Pos("//") !=1  &&frase.Pos("::value="))
              {
                s32 st =frase.Pos("::value=") +StrLen("::value=");
                dum =frase.SubString(1, st -1);
                dum =dum +*Valore +":::";
                found =true;
                LocalStrLstPar->Delete(c);
                LocalStrLstPar->Insert(c, dum);
              }
              ++ c;
            }
          }
        }
      }
    }
    if(!found)
    {
      ++ c;
    }
  }
  if(found)
  {
    try
    {
      LocalStrLstPar->SaveToFile(FileName);
      Application->ProcessMessages();
    }
    catch(...)
    {
      found =false;
    }
  }
  delete LocalStrLstPar;
  return(found);
}

//---------------------------------------------------------------------------
AnsiString* __fastcall TFGenModParam::LeggiFrase(TStringList *SL,u32 *r,u32 nr,
                                                AnsiString *s)
//---------------------------------------------------------------------------
{
  AnsiString result;
  bool found =false;
  do
  {
    AnsiString dum =SL->Strings[*r];
    if(dum.Pos("//") !=1)
    {
      result = result +dum;
      found =dum.Pos(":::");
    }
  }while(++ *r <nr &&!found);
  *s =result;
  return(s);
}

//---------------------------------------------------------------------------
bool __fastcall TFGenModParam::LeggiFrasiDefinizione()
//---------------------------------------------------------------------------
{
  AnsiString frase;
  AnsiString FileName;
  AnsiString dum;
  TBitBtn *BitObj;
  TPanel *PanelObj;
  u32 r;
  u32 len;
  u32 nrighe;
  bool found;
  bool res =false;

  if(ActLingua >=NumLingue)
  {
    MessageDlg("Select language do not exists! ",mtInformation,
               TMsgDlgButtons() << mbOK, 0);
    return(false);
  }
  AnsiString suf =SuffissiLingue[ActLingua];
  FileName =StrPathDati +StrFileForm;
  if(FileExists(FileName))
  {
    StrLstPar =new TStringList();
    res =true;
    r =0;
    StrLstPar->LoadFromFile(FileName);
    nrighe =(u32)StrLstPar->Count;
    while(r <nrighe)
    {
      LeggiFrase(StrLstPar, &r, nrighe, &frase);
      if(frase.Length() >0)
      {
        dum =frase;
        LeggiCampo(&dum, "::name=", &StrName);
        dum =frase;
        LeggiCampo(&dum, "::glyph=", &StrGlyph);
        dum =frase;
        LeggiCampo(&dum, "::visible=", &StrVisible);
        dum =frase;
        LeggiCampo(&dum, "::enable=", &StrEnable);
        dum =frase;
        LeggiCampo(&dum, "::command=", &StrCommand);
        LeggiCampo(&frase, "::" +suf +"caption=", &StrCaption);
        if((BitObj =LookForButton(StrName)) !=NULL)
        {
          SetBitBtnProperty(BitObj);
          if(StrEnable =="1" &&StrName.Pos("Unita"))
          {
            SaveFileDateTime(StrName);
          }
        }
        else if((PanelObj =LookForPanel(StrName)) !=NULL)
        {
          SetPanelProperty(PanelObj);
        }
        else
        {
          AnsiString StrObj;
          if((StrObj =LookForStringa(StrName)) !=NULL)
          {
            SetStrProperty(StrObj);
          }
        }
      }
    }
    delete StrLstPar;
  }
  return(res);
}
//---------------------------------------------------------------------------
bool __fastcall TFGenModParam::CaricaDatiForm()
//---------------------------------------------------------------------------
{
  AnsiString FileName;
  TStringList *SL;
  u32 p;
  u32 i;
  u32 j;
  bool res =false;
  FileName =GetCurrentDir() +"\\GenModParam.txt";
  if(!FileExists(FileName))
  {
    FileName ="c:\\GenModParam.txt";
    if(!FileExists(FileName))
    {
      return(res);
    }  
  }
  SL =new TStringList();
  SL->LoadFromFile(FileName);
  i =(u32)SL->Count;
  if(i >0)
  {
    res =true;
    LeggiDato(SL, "::path_dati=", &StrPathDati);
    if(StrPathDati.Length())
    {
      MessageDlg("Keyword <path_dati> wrong or missing",mtInformation,
                 TMsgDlgButtons() << mbOK, 0);
      res =false;
    }
  }
  if(res)
  {
    LeggiDato(SL, "::path_bmp=", &StrPathBmp);
    if(StrPathBmp.Length() ==0)
    {
      MessageDlg("Keyword <path_bmp> wrong or missing",mtInformation,
                 TMsgDlgButtons() << mbOK, 0);
      res =false;
    }
  }
  if(res)
  {
    LeggiDato(SL, "::fileform=", &StrFileForm);
    if(StrFileForm.Length() ==0)
    {
      MessageDlg("Keyword <fileform> wrong or missing",mtInformation,
                 TMsgDlgButtons() << mbOK, 0);
      res =false;
    }
  }
  if(res)
  {
    isSystemPasswordEnabled =true;
    LeggiDato(SL, "::enable_system_password=", &FileName);
    if(FileName.Length() >0)
    {
      isSystemPasswordEnabled =(FileName.ToIntDef(1) !=0);
    }
    SystemPassword =DEFAULT_SYSTEM_PASSWORD;
    LeggiDato(SL, "::system_password=", &FileName);
    if(FileName.Length() >0)
    {
      SystemPassword =FileName;
    }
    GridFontSize =DEFAULT_GRID_FONT_SIZE;
    LeggiDato(SL, "::grid_font_size=", &FileName);
    if(FileName.Length() >0)
    {
      GridFontSize =FileName.ToIntDef(DEFAULT_GRID_FONT_SIZE);
    }
    GridBkColor =DEFAULT_GRID_BK_COLOR;
    LeggiDato(SL, "::grid_bk_color=", &FileName);
    if(FileName.Length() >0)
    {
      GridBkColor =SelectColor(&FileName);
    }
    GridFixColor =DEFAULT_GRID_FIX_COLOR;
    LeggiDato(SL, "::grid_fix_color=", &FileName);
    if(FileName.Length() >0)
    {
      GridFixColor =SelectColor(&FileName);
    }
    PanelChgColor =DEFAULT_PANEL_CHG_COLOR;
    LeggiDato(SL, "::panel_chg_color=", &FileName);
    if(FileName.Length() >0)
    {
      PanelChgColor =SelectColor(&FileName);
    }
    isGridCoulored =true;
    LeggiDato(SL, "::grid_coulored=", &FileName);
    if(FileName.Length() >0)
    {
      isGridCoulored =(FileName.ToIntDef(1) !=0);
    }
    isGridAlternate =true;
    LeggiDato(SL, "::grid_alternate=", &FileName);
    if(FileName.Length() >0)
    {
      isGridAlternate =(FileName.ToIntDef(1) !=0);
    }
  }
  if(res)
  {
    NumLingue =0;
    LeggiDato(SL, "::language=", &FileName);
    if(FileName.Length() ==0)
    {
      MessageDlg("Keyword <language> wrong or missing",mtInformation,
                 TMsgDlgButtons() << mbOK, 0);
      res =false;
    }
    else
    {
      ++ NumLingue;
      while(FileName.Length())
      {
        if(FileName.Pos(","))
        {
          ++ NumLingue;
          FileName =FileName.SubString(1, FileName.Pos(","));
        }
        if(FileName.Pos(":"))
        {
          break;
        }
      }
      SuffissiLingue =new AnsiString[NumLingue +1];
      for(p =0;p <=NumLingue;p ++)
      {
        SuffissiLingue[p] =new s8[5];
      }
      p =0;
      i =0;
      j =0;
      while(p <(u32)FileName.Length())
      {
        if(FileName.Pos(","))
        {
          ++ NumLingue;
          FileName =FileName.SubString(1, FileName.Pos(","));
        }
        if(FileName.Pos(":"))
        {
          break;
        }


        if(FileName[p] !=',' &&FileName[p] !=':')
        {
          SuffissiLingue[i][j ++] =FileName[p];
        }
        else if(FileName[p] ==':')
        {
          SuffissiLingue[i][j] =0;
          break;
        }
        else
        {
          SuffissiLingue[i ++][j] =0;
          j =0;
        }
        ++ p;
      }
      SuffissiLingue[i][j] =0;
    }
  }
  delete SL;
  if(res)
  {
    res =LeggiFrasiDefinizione();
  }
  return(res);
}

//---------------------------------------------------------------------------
__fastcall TFGenModParam::TFGenModParam(TComponent* Owner)
        : TForm(Owner)
{
  LCK_Db =new TCriticalSection();
}

//---------------------------------------------------------------------------
__fastcall TFGenModParam::~TFGenModParam()
{
  delete LCK_Db;
}

//---------------------------------------------------------------------------
bool __fastcall TFGenModParam::ReadAdattaSchermo()
//---------------------------------------------------------------------------
{
  return(Adapt);
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::WriteAdattaSchermo(bool Mode)
//---------------------------------------------------------------------------
{
  Adapt =Mode;
}


//---------------------------------------------------------------------------
void __fastcall TFGenModParam::ResizeScreen()
//---------------------------------------------------------------------------
{
  TDeviceMode *DevMode;
  u32 Mode;

  if(!Adapt)
  {
    return;
  }

  if(GMP_PIXXROW ==UserPelsWidth && GMP_ROWXFRAME ==UserPelsHeight)
  {
    return;
  }

  DevMode =new TDeviceMode;
  DevMode->dmSize =sizeof(DevMode);

  try
  {
    EnumDisplaySettings(NULL,0,DevMode);
    EnumDisplaySettings(NULL,UserMode,DevMode);
    Mode =ChangeDisplaySettings(DevMode, 0);
    switch(Mode)
    {
      case DISP_CHANGE_SUCCESSFUL:
      case DISP_CHANGE_RESTART:
      case DISP_CHANGE_BADFLAGS:
      case DISP_CHANGE_FAILED:
      case DISP_CHANGE_BADMODE:
      case DISP_CHANGE_NOTUPDATED:
      break;
    }
  }
  catch(...)
  {
  }

  delete DevMode;

}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::AdaptScreen()
//---------------------------------------------------------------------------
{
  TDeviceMode *DevMode;
  bool Status;
  u32 Mode;

  if(!Adapt)
  {
    return;
  }

  UserPelsHeight =Screen->Height;
  UserPelsWidth =Screen->Width;

  if(GMP_PIXXROW ==UserPelsWidth && GMP_ROWXFRAME ==UserPelsHeight)
  {
    return;
  }

  DevMode =new TDeviceMode;
  DevMode->dmSize =sizeof(DevMode);

  Mode =0;
  do
  {
    Status =EnumDisplaySettings(NULL,Mode,DevMode);

    if(Status)
    {
      if (DevMode->dmBitsPerPel >=GMP_BITXPIXEL &&
          DevMode->dmPelsWidth ==UserPelsWidth &&
          DevMode->dmPelsHeight ==UserPelsHeight)
      {
        break;
      }
      else
      {
        ++ Mode;
      }
    }
  }while(Status);

  if(Status)
  {
    UserMode =Mode;
  }
  else
  {
    // ERRORE DI MODALITA NON VALIDA!!! ????
    delete DevMode;
    Adapt =false;
    return;
  }

  Mode =0;
  do
  {
    Status =EnumDisplaySettings(NULL,Mode,DevMode);

    if(Status)
    {
      if (DevMode->dmBitsPerPel >=GMP_BITXPIXEL &&
          DevMode->dmPelsWidth ==GMP_PIXXROW &&
          DevMode->dmPelsHeight ==GMP_ROWXFRAME)
      {
        break;
      }
      else
      {
        ++ Mode;
      }
    }
  }while(Status);

  if(!Status)
  {
    // ERRORE DI MODALITA NON VALIDA!!! ????
    delete DevMode;
    Adapt =false;
    return;
  }

  try
  {
    EnumDisplaySettings(NULL,Mode,DevMode);
    Mode =ChangeDisplaySettings(DevMode, 0);
    switch(Mode)
    {
      case DISP_CHANGE_SUCCESSFUL:
      case DISP_CHANGE_RESTART:
      case DISP_CHANGE_BADFLAGS:
      case DISP_CHANGE_FAILED:
      case DISP_CHANGE_BADMODE:
      case DISP_CHANGE_NOTUPDATED:
      break;
    }
  }
  catch(...)
  {
  }

  delete DevMode;
}
//---------------------------------------------------------------------------
s32  __fastcall TFGenModParam::ConvertToByte(P_valoridb par,u8 *pbuf)
//---------------------------------------------------------------------------
{
  s32 nbyte =0;
  s32 i =0;
  u64 val;
  f32 f32val;
  f64 f64val;
  u8 *pfl;
  bool f_int =true;
  bool f32 =true;

  switch(SelectType(&par->Tipo))
  {
    case S8_TYPE:
    case U8_TYPE:
      val =StrToInt64(par->Val);
      nbyte =1;
      break;
    case S16_TYPE:
    case U16_TYPE:
      val =StrToInt64(par->Val);
      nbyte =2;
      break;
    case S32_TYPE:
    case U32_TYPE:
      val =StrToInt64(par->Val);
      nbyte =4;
      break;
    case F32_TYPE:
      f_int =false;
      f32val =StrToFloat(par->Val);
      nbyte =4;
      break;
    case F64_TYPE:
      f_int =false;
      f32 =false;
      f64val =StrToFloat(par->Val);
      nbyte =8;
      break;
  }
  if(f_int)
  {
    while(i <nbyte)
    {
      pbuf[i ++] =(val >>((nbyte -i -1) *8));
    }
//    memcpy(pbuf, &val, nbyte);
  }
  else
  {
    if(f32)
    {
//      memcpy(pbuf, &f32val, nbyte);
      pfl =(u8 *)&f32val;
      pbuf[0] = *(pfl +3);
      pbuf[1] = *(pfl +2);
      pbuf[2] = *(pfl +1);
      pbuf[3] = *pfl;
    }
    else
    {
//      memcpy(pbuf, &f64val, nbyte);
      pfl =(u8 *)&f64val;
      pbuf[0] = *(pfl +7);
      pbuf[1] = *(pfl +6);
      pbuf[2] = *(pfl +5);
      pbuf[3] = *(pfl +4);
      pbuf[4] = *(pfl +3);
      pbuf[5] = *(pfl +2);
      pbuf[6] = *(pfl +1);
      pbuf[7] = *pfl;
    }
  }
  return(nbyte);
}
//---------------------------------------------------------------------------
u8  __fastcall TFGenModParam::SelectType(AnsiString *tp)
//---------------------------------------------------------------------------
{
  u8 res;
  if(*tp =="s8")
  {
    res =S8_TYPE;
  }
  else if(*tp =="u8")
  {
    res =U8_TYPE;
  }
  else if(*tp =="s16")
  {
    res =S16_TYPE;
  }
  else if(*tp =="u16")
  {
    res =U16_TYPE;
  }
  else if(*tp =="s32")
  {
    res =S32_TYPE;
  }
  else if(*tp =="u32")
  {
    res =U32_TYPE;
  }
  else if(*tp =="f32")
  {
    res =F32_TYPE;
  }
  else if(*tp =="f64")
  {
    res =F64_TYPE;
  }
  else if(*tp =="bool") 
  {
    res =BOOL_TYPE;
  }
  else if(*tp =="string") 
  {
    res =STR_TYPE;
  }
  else
  {
    res =NO_TYPE;
  }
  return(res);
}
//---------------------------------------------------------------------------
s32  __fastcall TFGenModParam::NByteType(AnsiString *tp)
//---------------------------------------------------------------------------
{
  s32 res;

  if(*tp =="s8")
  {
    res =1;
  }
  else if(*tp =="u8")
  {
    res =1;
  }
  else if(*tp =="s16")
  {
    res =2;
  }
  else if(*tp =="u16")
  {
    res =2;
  }
  else if(*tp =="s32")
  {
    res =4;
  }
  else if(*tp =="u32")
  {
    res =4;
  }
  else if(*tp =="f32")
  {
    res =4;
  }
  else if(*tp =="f64")
  {
    res =8;
  }
  else if(*tp =="bool")
  {
    res =1;
  }
  else if(*tp =="string")
  {
    res =0;
  }
  else
  {
    res =0;
  }
  return(res);
}

//---------------------------------------------------------------------------
TColor  __fastcall TFGenModParam::SelectColor(AnsiString *cl)
//---------------------------------------------------------------------------
{
  AnsiString SColor =*cl;
  s32 Color;
  TColor Result =DEFAULT_GRID_BK_COLOR;
  s32 p =SColor.Pos(",");
  if(p)
  {
    SColor =SColor.SubString(p, SColor.Length() -p);
    Color =SColor.ToIntDef(0);
    SColor =SColor.SubString(1, p);
    p =SColor.Pos(",");
    if(p)
    {
      SColor =SColor.SubString(p, SColor.Length() -p);
      Color +=(SColor.ToIntDef(0) <<8);
      SColor =SColor.SubString(1, p);
      Color +=(SColor.ToIntDef(0) <<16);
      Result =(TColor)Color;
    }
  }
  return(Result);
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::FormActivate(TObject *Sender)
{
  Modificato =NULL;
  ColoreParametri =NULL;
  TipoParametri =NULL;
  SuffissiLingue =NULL;
  ActualVal =NULL;
  PChangeValue->Visible =false;
  AdaptScreen();
  ChangeScale(Screen->Width,GMP_DESIGN_DIM);
  Width =Screen->Width;
  Height =Screen->Height;
  PanComand->Top =Height -PanComand->Height -4;
  BuOk->Top =PanComand->Top -BuOk->Height -4;
  BuOk->Left =PanComand->Left +PanComand->Width -BuOk->Width -16;
  BuPrint->Top = BuOk->Top;
  BuPrint->Left =BuOk->Left -BuPrint->Width -16;
  PLingua->Top =BuOk->Top;
  PLingua->Left =PanComand->Left +16;
  SystemPassword =new s8[32];

  if(CaricaDatiForm())
  {
    StringGrid1->Color =GridBkColor;
    StringGrid1->Font->Size =Ceil((float)GridFontSize *Screen->Width
                                        /GMP_DESIGN_DIM);
    PChangeValue->Font->Size =StringGrid1->Font->Size;
    PLingua->Visible =false;
    BuPrint->Visible =false;
    BuOk->Visible =false;    
    PLingua->Enabled =false;
    EdtModifyDesc->Visible =false;
    BtnEsci->Enabled =true;
    BtnSalva->Enabled =false;
    BuMeno->Enabled =false;
    BuPiu->Enabled =false;
    BuUp->Enabled =false;
    BuDown->Enabled =false;
    BtnTast->Enabled =false;
    LoadFlagBmp();
    BuLingue->Enabled =true;
    BtnSaveBackUp->Enabled =true;
    BtnResBackUp->Enabled =true;
    isPasswordOK =false;
  }
  else
  {
    Unita1->Visible =false;
    Unita2->Visible =false;
    Unita3->Visible =false;
    Unita4->Visible =false;
    Unita5->Visible =false;
    Unita6->Visible =false;
    Unita7->Visible =false;
    Unita8->Visible =false;
    Unita9->Visible =false;
    Unita10->Visible =false;
    Unita11->Visible =false;
    Unita12->Visible =false;
    Unita13->Visible =false;
    Unita14->Visible =false;
    Unita15->Visible =false;
    Unita16->Visible =false;
    GBUnita->Visible =false;
    StringGrid1->Visible =false;
    BuOk->Visible =false;
    BuPrint->Visible =false;    
    PanTast->Visible =false;
    BtnSalva->Visible =false;
    BuMeno->Visible =false;
    BuPiu->Visible =false;
    BuUp->Visible =false;
    BuDown->Visible =false;
    BtnTast->Visible =false;
    BuLingue->Visible =false;
    BtnSaveBackUp->Visible =false;
    BtnResBackUp->Visible =false;
    PanIntest->Visible =false;
    EdtModifyDesc->Visible =false;
    PLingua->Visible =false;
    PLingua->Enabled =false;
    BtnEsci->Enabled =true;
    BtnEsci->Visible =true;
  }
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::FormClose(TObject *Sender, TCloseAction &Action)
{
  try
  {
    if(TipoParametri !=NULL)
    {
      delete[] TipoParametri;
      TipoParametri =NULL;
    }  
  }
  catch(...){}
  try
  {
    if(Modificato !=NULL)
    {
      delete[] Modificato;
      Modificato =NULL;
    }
  }
  catch(...){}
  try
  {
    if(ColoreParametri !=NULL)
    {
      delete[] ColoreParametri;
      ColoreParametri =NULL;
    }
  }
  catch(...){}
  if(SuffissiLingue !=NULL)
  {
    delete[] SuffissiLingue;
    SuffissiLingue =NULL;
  }
  if(ActualVal !=NULL)
  {
    delete ActualVal;
    ActualVal =NULL;
  }    
  ResizeScreen();
}

//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnActionMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  TimButton->Enabled =false;
  ActualButton =NULL;
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::BtnActionMouseDown(TObject *Sender,
                           TMouseButton Button, TShiftState Shift, int X, int Y)
//---------------------------------------------------------------------------
{
  bool tbtn;

  ActualButton =(TBitBtn *)Sender;
  tbtn =(strcmp(ActualButton->Name.c_str(),"BuPiu") ==0) ||
        (strcmp(ActualButton->Name.c_str(),"BuMeno") ==0);
  if(tbtn && isSystemPasswordEnabled && !isPasswordOK)
  {
    return;
  }
  TimButton->Interval =330;
  TimButton->Enabled =true;
}

//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnActionEnter(TObject *Sender)
{
  ActualButton =(TBitBtn *)Sender;
  if(ActualButton->Tag &&Command[ActualButton->Tag] !=NULL)
    (*Command[ActualButton->Tag])();
}

//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuOkClick(TObject *Sender)
{

  for(s32 i =1;i <StringGrid1->RowCount;i ++)
  {
    if(Modificato[i])
    {
      if(MessageDlg("Salvare le Modifiche ?",mtInformation,
                    TMsgDlgButtons() <<mbOK <<mbNo, 0) ==mrOk)
      {
        BtnSalvaClick(BtnSalva);
      }
      break;
    }
  }
  if(TipoParametri !=NULL)
  {
    delete[] TipoParametri;
    TipoParametri =NULL;
  }
  if(ColoreParametri !=NULL)
  {
    delete[] ColoreParametri;
    ColoreParametri =NULL;
  }
  if(Modificato !=NULL)
  {
    delete[] Modificato;
    Modificato =NULL;
  }  
  StringGrid1->RowCount =2;
  StringGrid1->Visible =false;
  BuOk->Visible =false;
  BuPrint->Visible =false;
  PLingua->Visible =false;
  PChangeValue->Visible =false;
  EdtModifyDesc->Visible =false;
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::LoadGBUnita(u32 Uid, AnsiString GBCaption)
//---------------------------------------------------------------------------
{
  AnsiString frase;
  AnsiString FileName;
  AnsiString dum;
  u32 i;
  u32 cntpar;
  u32 p;
  bool almost_one =false;

  FileName =StrPathDati +StrFileForm;
  if(FileExists(FileName))
  {
    StrLstPar =new TStringList();
    try
    {
      StrLstPar->LoadFromFile(FileName);
    }
    catch(...)
    {
      StrLstPar =NULL;
    }

    if(StrLstPar !=NULL)
    {
      AnsiString BtnName ="Unita" +IntToStr(Uid);
      cntpar =(u32)StrLstPar->Count;
      p =0;
      while(p <cntpar)
      {
        LeggiFrase(StrLstPar, &p, cntpar, &frase);
        if(frase.Length() >0)
        {
          dum =frase;
          LeggiCampo(&dum, "::name=", &StrName);
          if(StrName ==BtnName)
          {
            BtnName ="::" +SuffissiLingue[ActLingua] +"btn1=";
            BtnUnitaA->Visible =false;
            BtnUnitaB->Visible =false;
            BtnUnitaC->Visible =false;
            BtnUnitaD->Visible =false;
            BtnUnitaE->Visible =false;
            BtnUnitaF->Visible =false;
            BtnUnitaG->Visible =false;
            BtnUnitaH->Visible =false;
            i =1;
            do
            {
              BtnName =BtnName.SubString(BtnName.Length()-2, 2);
              BtnName =BtnName +IntToStr(i) +"=";
              dum =frase;
              LeggiCampo(&dum, BtnName, &StrCaption);
              if(StrCaption.Length() >0)
              {
                almost_one =true;
                switch(i)
                {
                  case 1:
                    BtnUnitaA->Caption =StrCaption;
                    BtnUnitaA->Visible =true;
                    break;
                  case 2:
                    BtnUnitaB->Caption =StrCaption;
                    BtnUnitaB->Visible =true;
                    break;
                  case 3:
                    BtnUnitaC->Caption =StrCaption;
                    BtnUnitaC->Visible =true;
                    break;
                  case 4:
                    BtnUnitaD->Caption =StrCaption;
                    BtnUnitaD->Visible =true;
                    break;
                  case 5:
                    BtnUnitaE->Caption =StrCaption;
                    BtnUnitaE->Visible =true;
                    break;
                  case 6:
                    BtnUnitaF->Caption =StrCaption;
                    BtnUnitaF->Visible =true;
                    break;
                  case 7:
                    BtnUnitaG->Caption =StrCaption;
                    BtnUnitaG->Visible =true;
                    break;
                  case 8:
                    BtnUnitaH->Caption =StrCaption;
                    BtnUnitaH->Visible =true;
                    break;
                }
              }
              ++ i;
            }while(StrCaption.Length() >0);
          }
        }
      }
    }
    delete StrLstPar;
  }
  if(almost_one)
  {
    BuLingue->Enabled =false;
    GBUnita->Left =Unita1->Left;
    GBUnita->Top =Unita1->Top;
    GBUnita->Caption =GBCaption;
    GBUnita->Visible =true;
    GBUnita->BringToFront();
    BtnGbUnitaEsci->Visible =true;
    BtnEsci->Enabled =false;
  }
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::BitBtnLoadParam()
//---------------------------------------------------------------------------
{
  AnsiString campo;
  AnsiString frase;
  AnsiString StrValoreCampo;
  AnsiString StrDefault;
  AnsiString dum;
  AnsiString FileName;
  u32 c;
  u32 row;
  u8 *tipi;
  TColor *colorpar;
  bool cs;

  FileName =StrPathDati +"Unita" +IntToStr(UnitaSelezionata) +"_" +IntToStr(SubUnitaSelezionata) +".txt";
  if(!FileExists(FileName))
  {
    return;
  }
  StrLstPar =new TStringList();
  try
  {
    StrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    StrLstPar->Clear();
  }
  NumParam =(u32)StrLstPar->Count;
  if(NumParam <=0)
  {
    delete StrLstPar;
    return;
  }
  tipi =new u8[NumParam];
  colorpar =new TColor[NumParam];
  StringGrid1->RowCount =2;
  row =1;
  c =0;
  while(c <NumParam)
  {    // Legge dati caratteristici Parametro c-esimo
    LeggiFrase(StrLstPar,&c,NumParam,&frase);
    if(frase.Length() >0)
    {
      campo ="::" +SuffissiLingue[ActLingua] +"desc=";
      dum =frase;
      LeggiCampo(&dum, campo, &StrValoreCampo);
      if(StrValoreCampo.Length() >0)
      {
        StringGrid1->Cells[DESC_COL][row] =StrValoreCampo;
      }
      else
      {
        StringGrid1->Cells[DESC_COL][row] ="";
      }
      dum =frase;
      LeggiCampo(&dum, "::type=", &StrValoreCampo);
      if(StrValoreCampo.Length())
      {
        tipi[row] =SelectType(&StrValoreCampo);
      }
      else
      {
        tipi[row] =NO_TYPE; // undefined type
      }
      dum =frase;
      LeggiCampo(&dum, "::color=", &StrValoreCampo);
      if(StrValoreCampo.Length() >0)
      {
        colorpar[row] =SelectColor(&StrValoreCampo);
      }
      else
      {
        colorpar[row] =DEFAULT_GRID_BK_COLOR; // undefined type
      }
      dum =frase;
      LeggiCampo(&dum, "::default=", &StrValoreCampo);
      if(StrValoreCampo.Length())
      {
        StrDefault =StrValoreCampo;
      }
      else
      {
        StrDefault ="";
      }
      StringGrid1->Cells[DEF_COL][row] =StrDefault;
      dum =frase;
      LeggiCampo(&dum, "::min=", &StrValoreCampo);
      if(StrValoreCampo.Length())
      {
        StringGrid1->Cells[MIN_COL][row] =StrValoreCampo;
      }
      else
      {
        StringGrid1->Cells[MIN_COL][row] ="";
      }
      dum =frase;
      LeggiCampo(&dum, "::max=", &StrValoreCampo);
      if(StrValoreCampo.Length())
      {
        StringGrid1->Cells[MAX_COL][row] =StrValoreCampo;
      }
      else
      {
        StringGrid1->Cells[MAX_COL][row] ="";
      }
      dum =frase;
      LeggiCampo(&dum, "::value=", &StrValoreCampo);
      if(StrValoreCampo.Length())
      {
        StringGrid1->Cells[VALUE_COL][row] =StrValoreCampo;
      }
      else
      {
        StringGrid1->Cells[VALUE_COL][row] =StrDefault;
      }
      ++ StringGrid1->RowCount;
      ++ row;
    }
  }
  if(StringGrid1->RowCount >1)
  {
    -- StringGrid1->RowCount;
    ActualVal =new TStringList();
    ActualVal->Add("FixCol");
    TipoParametri =new u8[StringGrid1->RowCount +3];
    ColoreParametri =new TColor[StringGrid1->RowCount +3];
    Modificato =new bool[StringGrid1->RowCount +3];
    for(c =1;c <=(u32)StringGrid1->RowCount;c ++)
    {
      ColoreParametri[c] =colorpar[c];
      TipoParametri[c] =tipi[c];
      Modificato[c] =false;
      ActualVal->Add(StringGrid1->Cells[VALUE_COL][c]);
    }
    BuOk->Top =PanComand->Top -BuOk->Height -6;
    BuPrint->Top =BuOk->Top;
    PLingua->Top =BuOk->Top;
    StringGrid1->Row =1;
    StringGrid1->Top =PanIntest->Top +PanIntest->Height +2;
    StringGrid1->Left =PanIntest->Left;
    StringGrid1->Height =BuOk->Top -StringGrid1->Top -8;
    StringGrid1->Width =PanIntest->Width-2;
    StringGrid1->ColWidths[DESC_COL] =StringGrid1->Width *60 /100;
    StringGrid1->ColWidths[DEF_COL] =StringGrid1->Width *10 /100;
    StringGrid1->ColWidths[MIN_COL] =StringGrid1->Width *10 /100;
    StringGrid1->ColWidths[MAX_COL] =StringGrid1->Width *10 /100;
    StringGrid1->ColWidths[VALUE_COL] =StringGrid1->Width *10 /100;
/*    StringGrid1->Cells[DESC_COL][0] ="Descrizione";
    StringGrid1->Cells[DEF_COL][0] ="Tipico";
    StringGrid1->Cells[MIN_COL][0] ="Minimo";
    StringGrid1->Cells[MAX_COL][0] ="Massimo";
    StringGrid1->Cells[VALUE_COL][0] ="Valore"; */
    StringGrid1->Visible =true;
    StringGrid1->BringToFront();
    BuOk->Visible =true;
    BuPrint->Visible =true;
    PLingua->Visible =true;
    StringGrid1SelectCell((TObject *)StringGrid1,VALUE_COL,StringGrid1->Row,cs);
    BuOk->BringToFront();
    BuPrint->BringToFront();
    PLingua->BringToFront();
    PLingua->Picture->Bitmap =BuLingue->Glyph;
    BuMeno->Enabled =true;
    BuPiu->Enabled =true;
    BuUp->Enabled =true;
    BuDown->Enabled =true;
    BtnTast->Enabled =true;
    BuLingue->Enabled =false;
    BtnSaveBackUp->Enabled =false;
    BtnResBackUp->Enabled =false;
    BtnEsci->Enabled =false;
    BtnSalva->Enabled =false;
    PChangeValue->Visible =true;
    PChangeValue->Color =PanelChgColor;
    PChangeValue->BringToFront();
  }
  delete[] tipi;
  delete[] colorpar;
  delete StrLstPar;
}

//---------------------------------------------------------------------------
void __fastcall TFGenModParam::SaveParam()
//---------------------------------------------------------------------------
{
  TStringList *LocalStrLstPar;
  AnsiString FileName;
  AnsiString frase;
  AnsiString valore;
  u32 NumParam;
  u32 c;
  u32 i;
  u32 r;

  FileName =StrPathDati +"Unita" +IntToStr(UnitaSelezionata) +"_" +IntToStr(SubUnitaSelezionata) +".txt";
  if(!FileExists(FileName))
  {
    return;
  }
  LocalStrLstPar =new TStringList();
  try
  {
    LocalStrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    LocalStrLstPar->Clear();
  }
  NumParam =(u32)LocalStrLstPar->Count;
  if(NumParam <=0)
  {
    delete LocalStrLstPar;
    return;
  }
  c =0;
  r =1;
  while(c <NumParam)
  {    // Legge dati caratteristici Parametro c-esimo
    frase =LocalStrLstPar->Strings[c];
    if(frase.Length() >0)
    {
      s32 p =frase.Pos("::value=");
      if(p &&frase.Pos("//") !=1)
      {
        valore =StringGrid1->Cells[VALUE_COL][r] +":::";
        frase =frase.SubString(p +StrLen("::value="), frase.Length() -(p +StrLen("::value=")));
        frase =frase +valore;
        ActualVal->Strings[r] =StringGrid1->Cells[VALUE_COL][r];
        Modificato[r] =false;
        ++ r;
      }
    }
    LocalStrLstPar->Delete(c);
    LocalStrLstPar->Insert(c ++, frase);
  }
  try
  {
    LocalStrLstPar->SaveToFile(FileName);
  }
  __finally
  {
    delete LocalStrLstPar;
    StringGrid1->Repaint();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFGenModParam::SaveDescription(s8 *Desc,u32 Row)
//---------------------------------------------------------------------------
{
  TStringList *LocalStrLstPar;
  AnsiString FileName;
  AnsiString frase;
  AnsiString valore;
  AnsiString campo;
  AnsiString dum;
  u32 NumParam;
  u32 c;
  u32 i;
  u32 r;
  bool upDate;

  isPasswordOK =(RichiediPW ==NULL) ||RichiediPW(valore) ==SystemPassword;
  if(!isPasswordOK)
  {
    return;
  }
  FileName =StrPathDati +"Unita" +IntToStr(UnitaSelezionata) +"_"+ IntToStr(SubUnitaSelezionata) +".txt";
  if(!FileExists(FileName))
  {
    return;
  }
  LocalStrLstPar =new TStringList();
  try
  {
    LocalStrLstPar->LoadFromFile(FileName);
  }
  catch(...)
  {
    LocalStrLstPar->Clear();
  }
  NumParam =(u32)LocalStrLstPar->Count;
  if(NumParam <=0)
  {
    delete LocalStrLstPar;
    return;
  }
  campo ="::" +SuffissiLingue[ActLingua] +"desc=";
  c =0;
  r =0;
  while(c <NumParam &&r <Row)
  {    // Legge dati caratteristici Parametro c-esimo
    i =c;
    LeggiFrase(LocalStrLstPar,&c,NumParam,&frase);
    if(frase.Length() >1)
    {
      ++ r;
    }
  }
  upDate= false;
  if(r ==Row)
  {
    dum =frase;
    if(dum.Pos(campo))
    { // Campo già presente nel file
      do
      {
        frase =LocalStrLstPar->Strings[c];
        dum =frase;
        if(dum.Pos(campo))
        {
          frase =campo +Desc;
          LocalStrLstPar->Delete(i);
          LocalStrLstPar->Insert(i, frase);
          upDate =true;
        }
        else
        {
          ++ i;
        }
      }while(!upDate &&i <c);
    }
    else
    { // Campo non ancora presente nel file
      do
      {
        frase =LocalStrLstPar->Strings[i];
        dum  =frase;
        if(dum.Pos("::value=")) // campo obbligatorio
        {
          frase =campo +Desc;
          LocalStrLstPar->Insert(i -1,frase);
          upDate =true;
        }
        else
        {
          ++ i;
        }
      }while(!upDate &&i <c);
    }
  }
  try
  {
    if(upDate)
    {
      DeleteFile(FileName);
      LocalStrLstPar->SaveToFile(FileName);
      StringGrid1->Cells[DESC_COL][Row] =Desc;
    }
  }
  __finally
  {
    delete LocalStrLstPar;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita1Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =1),Unita1->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita2Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =2),Unita2->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita3Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =3),Unita3->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita4Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =4),Unita4->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita5Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =5),Unita5->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita6Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =6),Unita6->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita7Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =7),Unita7->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita8Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =8),Unita8->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita9Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =9),Unita9->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita10Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =10),Unita10->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita11Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =11),Unita11->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita12Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =12),Unita12->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita13Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =13),Unita13->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita14Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =14),Unita14->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita15Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =15),Unita15->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::Unita16Click(TObject *Sender)
{
  LoadGBUnita((UnitaSelezionata =16),Unita16->Caption);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
  TStringGrid *SG =(TStringGrid *)Sender;

  PChangeValue->Top =SG->Top +SG->CellRect(VALUE_COL,ARow).Top -2;
  PChangeValue->Left =SG->Left +SG->CellRect(VALUE_COL,ARow).Left;
  PChangeValue->Height =SG->CellRect(VALUE_COL,ARow).Height() +4;
  PChangeValue->Width =SG->CellRect(VALUE_COL,ARow).Width() +2;
  PChangeValue->Caption =SG->Cells[VALUE_COL][ARow];
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::StringGrid1TopLeftChanged(TObject *Sender)
{
  bool cs;

  TStringGrid *SG =(TStringGrid *)Sender;
  if(SG->Row <SG->TopRow || SG->Row >SG->TopRow +SG->VisibleRowCount)
  {
    SG->Row =SG->TopRow;
  }
  StringGrid1SelectCell(Sender,VALUE_COL,SG->Row,cs);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::TimButtonTimer(TObject *Sender)
{
  if(ActualButton ==NULL)
  {
    return;
  }
  TimButton->Interval =50;
  ActualButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnEsciClick(TObject *Sender)
{
  FGenModParam->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnSalvaClick(TObject *Sender)
{
  AnsiString pw;
  isPasswordOK =(RichiediPW ==NULL) ||RichiediPW(pw) ==SystemPassword;
  if(!isPasswordOK)
  {
    return;
  }
  SaveParam();
  BtnSalva->Enabled =false;
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuDownClick(TObject *Sender)
{
  if(StringGrid1->Row <StringGrid1->RowCount -1)
  {
    ++ StringGrid1->Row;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuMenoClick(TObject *Sender)
{
  Variant val;
  Variant bound;
  f64 f_val;
  f64 f_bound;

  if(isSystemPasswordEnabled &&!isPasswordOK)
  {
    AnsiString pw;
    isPasswordOK =(RichiediPW ==NULL) ||RichiediPW(pw) ==SystemPassword;
    if(!isPasswordOK)
      return;
  }
  if(TipoParametri[StringGrid1->Row] !=NO_TYPE)
  {
    switch(TipoParametri[StringGrid1->Row])
    {
      case S8_TYPE:
      case U8_TYPE:
      case S16_TYPE:
      case U16_TYPE:
      case S32_TYPE:
      case U32_TYPE:
        val =StrToInt(PChangeValue->Caption);
        bound =StrToInt(StringGrid1->Cells[MIN_COL][StringGrid1->Row]);
        if(val >bound)
        {
          val =val -1;
          PChangeValue->Caption =VarToStr(val);
        }
        break;
      case F32_TYPE:
      case F64_TYPE:
        f_val =StrToFloatDef(PChangeValue->Caption,123456789);
        if(f_val ==123456789)
        {
          break;
        }
        f_bound =StrToFloatDef(StringGrid1->Cells[MIN_COL][StringGrid1->Row],
                               123456789);
        if(f_bound ==123456789)
        {
          break;
        }
        if(f_val >f_bound)
        {
          f_val =f_val -0.01;
          PChangeValue->Caption =FloatToStrF(f_val,ffGeneral,5,3);
        }
    }
    StringGrid1->Cells[VALUE_COL][StringGrid1->Row] =PChangeValue->Caption;
    Modificato[StringGrid1->Row] =
                                (strcmp(PChangeValue->Caption.c_str(),
                                 ActualVal->Strings[StringGrid1->Row].c_str()));
    BtnSalva->Enabled =false;
    for(s32 i =1;i <=StringGrid1->RowCount;i ++)
    {
      if(Modificato[i])
      {
        BtnSalva->Enabled =true;
        break;
      }
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuPiuClick(TObject *Sender)
{
  Variant val;
  Variant bound;
  f64 f_val;
  f64 f_bound;

  if(isSystemPasswordEnabled &&!isPasswordOK)
  {
    AnsiString pw;
    isPasswordOK =(RichiediPW ==NULL) ||RichiediPW(pw) ==SystemPassword;
    if(!isPasswordOK)
    {
      return;
    }  
  }
  if(TipoParametri[StringGrid1->Row] !=NO_TYPE)
  {
    switch(TipoParametri[StringGrid1->Row])
    {
      case S8_TYPE:
      case U8_TYPE:
      case S16_TYPE:
      case U16_TYPE:
      case S32_TYPE:
      case U32_TYPE:
        val =StrToInt(PChangeValue->Caption);
        bound =StrToInt(StringGrid1->Cells[MAX_COL][StringGrid1->Row]);
        if(val <bound)
        {
          val =val +1;
          PChangeValue->Caption =VarToStr(val);
        }
        break;
      case F32_TYPE:
      case F64_TYPE:
        f_val =StrToFloatDef(PChangeValue->Caption,123456789);
        if(f_val ==123456789)
        {
          break;
        }
        f_bound =StrToFloatDef(StringGrid1->Cells[MAX_COL][StringGrid1->Row],
                               123456789);
        if(f_bound ==123456789)
        {
          break;
        }
        if(f_val <f_bound)
        {
          f_val =f_val +0.01;
          PChangeValue->Caption =FloatToStrF(f_val,ffGeneral,5,3);
        }
    }
    StringGrid1->Cells[VALUE_COL][StringGrid1->Row] =PChangeValue->Caption;
    Modificato[StringGrid1->Row] =
                                (strcmp(PChangeValue->Caption.c_str(),
                                 ActualVal->Strings[StringGrid1->Row].c_str()));
    BtnSalva->Enabled =false;
    for(s32 i =1;i <=StringGrid1->RowCount;i ++)
    {
      if(Modificato[i])
      {
        BtnSalva->Enabled =true;
        break;
      }
    }
  }
}
// ***************************************************************************
// ***************************************************************************
// ****************** TASTIERINO NEUMRICO ************************************
// ***************************************************************************
// ***************************************************************************
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuUpClick(TObject *Sender)
{
  if(StringGrid1->Row >1)
  {
    --StringGrid1->Row;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnTastClick(TObject *Sender)
{
  if(isSystemPasswordEnabled &&!isPasswordOK)
  {
    AnsiString pw;
    isPasswordOK =(RichiediPW ==NULL) ||RichiediPW(pw) ==SystemPassword;
    if(!isPasswordOK)
    {
      return;
    }  
  }
  BuMeno->Enabled =false;
  BuPiu->Enabled =false;
  BuUp->Enabled =false;
  BuDown->Enabled =false;
  BtnTast->Enabled =false;
  BuLingue->Enabled =false;
  BuOk->Enabled =false;
  BuPrint->Enabled =false;
  EditTast->Text =PChangeValue->Caption;
  if((StringGrid1->Row -StringGrid1->TopRow) <
     (StringGrid1->VisibleRowCount >>1))
  {
    PanTast->Top =StringGrid1->Top +StringGrid1->Height -PanTast->Height -40;
  }
  else
  {
    PanTast->Top =StringGrid1->Top +40;
  }
  PanTast->Left =40;
  PanTast->Visible =true;
  PanTast->BringToFront();                                    \
  EditTast->SetFocus();
  EditTast->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::PanTastExit(TObject *Sender)
{
  BuMeno->Enabled =true;
  BuPiu->Enabled =true;
  BuUp->Enabled =true;
  BuDown->Enabled =true;
  BtnTast->Enabled =true;
  BuLingue->Enabled =false;
  BuOk->Enabled =true;
  BuPrint->Enabled =true;
  PanTast->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnTastCancClick(TObject *Sender)
{
  if(EditTast->SelText !="")
  {
    EditTast->ClearSelection();
    EditTast->SetFocus();
  }
  else
  {
    if(EditTast->Text !="")
    {
      if(EditTast->SelStart !=0)
      {
        EditTast->SelStart =EditTast->SelStart -1;
      }
      EditTast->SelLength =1;
      EditTast->ClearSelection();
    }
    EditTast->SetFocus();
  }
}

//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnPiuMenoClick(TObject *Sender)
{
  s8 *dum;

  dum =new s8[StrLen(EditTast->Text.c_str()) +2];
  if(StrPos(EditTast->Text.c_str(),"-") ==NULL)
  {
    StrCopy(dum,"-");
    StrCat(dum,EditTast->Text.c_str());
  }
  else
  {
    dum =StrPos(EditTast->Text.c_str(),"-") +1;
    dum[StrLen(EditTast->Text.c_str()) -1] =0;
  }
  EditTast->Text =dum;
  delete[] dum;
}

//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuTastieraClick(TObject *Sender)
{
  TButton *TB=(TButton *)Sender;
  EditTast->SelText =TB->Caption;
  EditTast->SetFocus();
}

//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnTastSalvaClick(TObject *Sender)
{
  Variant val;
  Variant min;
  Variant max;
  f64 f_val;
  f64 f_min;
  f64 f_max;
  bool isValid =false;

  if(TipoParametri[StringGrid1->Row] !=NO_TYPE &&
     StrLen(EditTast->Text.c_str()) >0)
  {
    switch(TipoParametri[StringGrid1->Row])
    {
      case S8_TYPE:
      case U8_TYPE:
      case S16_TYPE:
      case U16_TYPE:
      case S32_TYPE:
      case U32_TYPE:
        val =StrToIntDef(EditTast->Text,123456789);
        if(val ==123456789)
        {
          break;
        }
        max =StrToIntDef(StringGrid1->Cells[MAX_COL][StringGrid1->Row],123456789);
        if(max ==123456789)
        {
          break;
        }
        min =StrToIntDef(StringGrid1->Cells[MIN_COL][StringGrid1->Row],123456789);
        if(min ==123456789)
        {
          break;
        }
        if(val >=min &&val <=max)
        {
          isValid =true;
        }
        break;
      case F32_TYPE:
      case F64_TYPE:
        f_val =StrToFloatDef(EditTast->Text,123456789);
        if(f_val ==123456789)
        {
          break;
        }
        f_max =StrToFloatDef(StringGrid1->Cells[MAX_COL][StringGrid1->Row],123456789);
        if(f_max ==123456789)
        {
          break;
        }
        f_min =StrToFloatDef(StringGrid1->Cells[MIN_COL][StringGrid1->Row],123456789);
        if(f_min ==123456789)
        {
          break;
        }
        if(f_val >=f_min &&f_val <=f_max)
        {
          isValid =true;
        }
    }
  }

  if(isValid)
  {
    PChangeValue->Caption =EditTast->Text;
    StringGrid1->Cells[VALUE_COL][StringGrid1->Row] =PChangeValue->Caption;
    Modificato[StringGrid1->Row] =
                                (strcmp(PChangeValue->Caption.c_str(),
                                 ActualVal->Strings[StringGrid1->Row].c_str()));
    BtnSalva->Enabled =false;
    for(s32 i =1;i <=StringGrid1->RowCount;i ++)
    {
      if(Modificato[i])
      {
        BtnSalva->Enabled =true;
        break;
      }
    }
  }
  else
  {
    MessageDlg("Range Check Error",mtInformation, TMsgDlgButtons() << mbOK, 0);
  }
  PanTast->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnTastExitClick(TObject *Sender)
{
  PanTast->Visible =false;
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnGbUnitaEsciClick(TObject *Sender)
{
  GBUnita->Visible =false;
  BtnGbUnitaEsci->Visible =false;
  BtnUnitaA->Visible =false;
  BtnUnitaB->Visible =false;
  BtnUnitaC->Visible =false;
  BtnUnitaD->Visible =false;
  BtnUnitaE->Visible =false;
  BtnUnitaF->Visible =false;
  BtnUnitaG->Visible =false;
  BtnUnitaH->Visible =false;
  BtnEsci->Enabled =true;
  BtnSalva->Enabled =false;
  BuMeno->Enabled =false;
  BuPiu->Enabled =false;
  BuUp->Enabled =false;
  BuDown->Enabled =false;
  BtnTast->Enabled =false;
  BuLingue->Enabled =true;
  BtnSaveBackUp->Enabled =true;
  BtnResBackUp->Enabled =true;
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaAClick(TObject *Sender)
{
  SubUnitaSelezionata =1;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaBClick(TObject *Sender)
{
  SubUnitaSelezionata =2;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaCClick(TObject *Sender)
{
  SubUnitaSelezionata =3;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaDClick(TObject *Sender)
{
  SubUnitaSelezionata =4;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaEClick(TObject *Sender)
{
  SubUnitaSelezionata =5;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaFClick(TObject *Sender)
{
  SubUnitaSelezionata =6;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaGClick(TObject *Sender)
{
  SubUnitaSelezionata =7;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BtnUnitaHClick(TObject *Sender)
{
  SubUnitaSelezionata =8;
  BitBtnLoadParam();
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuLingueClick(TObject *Sender)
{
  ++ ActLingua;
  if(ActLingua >=NumLingue)
  {
    ActLingua =0;
  }
  if(CaricaDatiForm())
  {
    PLingua->Visible =false;
    BuPrint->Visible =false;
    BuOk->Visible =false;
    PLingua->Enabled =false;
    EdtModifyDesc->Visible =false;
    BtnEsci->Enabled =true;
    BtnSalva->Enabled =false;
    BuMeno->Enabled =false;
    BuPiu->Enabled =false;
    BuUp->Enabled =false;
    BuDown->Enabled =false;
    BtnTast->Enabled =false;
    LoadFlagBmp();
    BuLingue->Enabled =true;
    BtnSaveBackUp->Enabled =true;
    BtnResBackUp->Enabled =true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::StringGrid1DrawCell(TObject *Sender,
      int ACol, int ARow, TRect &Rect, TGridDrawState State)
{
  TStringGrid *SG;
  TColor c;
  TColor r;
  TColor g;
  TColor b;

  SG =(TStringGrid *)Sender;
  if(State.Contains(gdFixed))
  {
    c =GridFixColor;
  }
  else if(State.Contains(gdSelected))
  {
    c =GridSelColor;
  }
  else if(Modificato[ARow] &&ACol ==VALUE_COL)
  {
    c =GridChgColor;
  }
  else
  {
    if(isGridCoulored)
    {
      c =ColoreParametri[ARow];
    }
    else
    {
      c =GridBkColor;
    }
    if(isGridAlternate &(ARow &1))
    {
      r =(TColor)(c &0xff);
      g =(TColor)((c >>8) &0xff);
      b =(TColor)((c >>16) &0xff);
      r =(TColor)(r +20);
      if(r >255)
      {
        r =(TColor)255;
      }
      g =(TColor)(g +20);
      if(g >255)
      {
        g =(TColor)255;
      }
      b =(TColor)(b +20);
      if(b >255)
      {
        b =(TColor)255;
      }
      c =(TColor)((b <<16) +(g <<8) +r);
    }
  }
  SG->Canvas->Brush->Color =c;
  SG->Canvas->FillRect(Rect);
  SG->Canvas->TextRect(Rect,Rect.Left+2,Rect.Top+2,SG->Cells[ACol][ARow]);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::StringGrid1Click(TObject *Sender)
{
  TPoint mpos =Mouse->CursorPos;
  TStringGrid *SG =(TStringGrid *)Sender;
  if(mpos.x <SG->Left ||mpos.x >(SG->Left +SG->Width) ||
     mpos.y <SG->Top ||mpos.y >(SG->Top +SG->Height))
  {
    return;
  }
  if(EdtModifyDesc->Visible)
  {
    SaveDescription(EdtModifyDesc->Text.c_str(),NewDescRow);
    EdtModifyDesc->Visible =false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::EdtModifyDescKeyPress(TObject *Sender,
      char &Key)
{
  if(Key ==13)
  {
    SaveDescription(EdtModifyDesc->Text.c_str(), NewDescRow);
    EdtModifyDesc->Visible =false;
  }
  else if(Key ==27)
  {
    EdtModifyDesc->Visible =false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::StringGrid1DblClick(TObject *Sender)
{
  TPoint mpos =Mouse->CursorPos;
  TStringGrid *SG =(TStringGrid *)Sender;
  TGridCoord coord=SG->MouseCoord(mpos.x -StringGrid1->Left,
                                  mpos.y -StringGrid1->Top);

  if(coord.X ==DESC_COL &&coord.Y >0)
  {
    NewDescRow =SG->Row;
    EdtModifyDesc->BringToFront();
    TRect Rect =SG->CellRect(DESC_COL,NewDescRow);
    EdtModifyDesc->Top =Rect.Top +SG->Top +SG->GridLineWidth;
    EdtModifyDesc->Left =Rect.Left +SG->Left +SG->GridLineWidth;
    EdtModifyDesc->Height =Rect.Height();
    EdtModifyDesc->Width =Rect.Width();
    EdtModifyDesc->Text =SG->Cells[DESC_COL][NewDescRow];
    EdtModifyDesc->Font->Size =SG->Font->Size;
    EdtModifyDesc->Visible =true;
    EdtModifyDesc->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::PChangeValueClick(TObject *Sender)
{
  BtnTastClick(BtnTast);
}
//---------------------------------------------------------------------------

void __fastcall TFGenModParam::BuPrintClick(TObject *Sender)
{
  if(StringGrid1->RowCount <2)
  {
    return;
  }
  AnsiString pw;
  isPasswordOK =(RichiediPW ==NULL) ||RichiediPW(pw) ==SystemPassword;
  if(!isPasswordOK)
  {
    return;
  }
  TRichEdit *pRich = new TRichEdit(this);
  pRich->Parent = this;
  pRich->Align = alClient;
  pRich->Lines->Clear();
  pRich->Font->Size =GridFontSize;
  s8 *sdum =new s8[1000];
  switch(UnitaSelezionata)
  {
    case 1:
      StrCopy(sdum,Unita1->Caption.c_str());
      break;
    case 2:
      StrCopy(sdum,Unita2->Caption.c_str());
      break;
    case 3:
      StrCopy(sdum,Unita3->Caption.c_str());
      break;
    case 4:
      StrCopy(sdum,Unita4->Caption.c_str());
      break;
    case 5:
      StrCopy(sdum,Unita5->Caption.c_str());
      break;
    case 6:
      StrCopy(sdum,Unita6->Caption.c_str());
      break;
    case 7:
      StrCopy(sdum,Unita7->Caption.c_str());
      break;
    case 8:
      StrCopy(sdum,Unita8->Caption.c_str());
      break;
    case 9:
      StrCopy(sdum,Unita9->Caption.c_str());
      break;
    case 10:
      StrCopy(sdum,Unita10->Caption.c_str());
      break;
    case 11:
      StrCopy(sdum,Unita11->Caption.c_str());
      break;
    case 12:
      StrCopy(sdum,Unita12->Caption.c_str());
      break;
    case 13:
      StrCopy(sdum,Unita13->Caption.c_str());
      break;
    case 14:
      StrCopy(sdum,Unita14->Caption.c_str());
      break;
    case 15:
      StrCopy(sdum,Unita15->Caption.c_str());
      break;
    case 16:
      StrCopy(sdum,Unita16->Caption.c_str());
  }
  StrCat(sdum," - ");
  switch(SubUnitaSelezionata)
  {
    case 1:
      StrCat(sdum,BtnUnitaA->Caption.c_str());
      break;
    case 2:
      StrCat(sdum,BtnUnitaB->Caption.c_str());
      break;
    case 3:
      StrCat(sdum,BtnUnitaC->Caption.c_str());
      break;
    case 4:
      StrCat(sdum,BtnUnitaD->Caption.c_str());
      break;
    case 5:
      StrCat(sdum,BtnUnitaE->Caption.c_str());
      break;
    case 6:
      StrCat(sdum,BtnUnitaF->Caption.c_str());
      break;
    case 7:
      StrCat(sdum,BtnUnitaG->Caption.c_str());
      break;
    case 8:
      StrCat(sdum,BtnUnitaH->Caption.c_str());
      break;
  }
  pRich->Lines->Add(sdum);
  delete[] sdum;
  pRich->Lines->Add("");
  pRich->Lines->Add("");
  for(s32 i=1;i <StringGrid1->RowCount;i ++)
  {
    sdum =new s8[StrLen(StringGrid1->Cells[DESC_COL][i].c_str()) +
                 StrLen(StringGrid1->Cells[VALUE_COL][i].c_str()) +4];
    StrCopy(sdum,StringGrid1->Cells[DESC_COL][i].c_str());
    StrCat(sdum," = ");
    StrCat(sdum,StringGrid1->Cells[VALUE_COL][i].c_str());
    pRich->Lines->Add(sdum);
    delete[] sdum;
  }
  pRich->Print("Parameters");
  delete[] pRich;
}
//---------------------------------------------------------------------------


