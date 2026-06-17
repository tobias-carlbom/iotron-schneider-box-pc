//---------------------------------------------------------------------------

#ifndef GenModParamH
#define GenModParamH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <System.hpp>
#include <SyncObjs.hpp>
#include <Io.h>
#include <dstring.h>
#include <CustomizeDlg.hpp>
#include <Grids.hpp>

#include "Gk_type.h"
#include <Grids.hpp>
#include <CustomizeDlg.hpp>

#define MAX_NUM_UNITA           16
#define MAX_NUM_SUBUNITA        8


typedef struct S_valoridb
{
  AnsiString Val;
  AnsiString Tipo;
} S_valoridb;

typedef S_valoridb* P_valoridb;

typedef void (*Command)();

class TFGenModParam : public TForm
{
__published:	// IDE-managed Components
        TPanel *PanComand;
        TBitBtn *BtnEsci;
        TBitBtn *BtnSalva;
        TBitBtn *BtnTast;
        TBitBtn *BtnResBackUp;
        TBitBtn *BtnSaveBackUp;
        TBitBtn *BuDown;
        TBitBtn *BuUp;
        TBitBtn *BuPiu;
        TBitBtn *BuMeno;
        TBitBtn *BuLingue;
        TButton *BtnAction;
        TBitBtn *Unita1;
        TBitBtn *Unita2;
        TBitBtn *Unita3;
        TBitBtn *Unita4;
        TBitBtn *Unita5;
        TBitBtn *Unita6;
        TBitBtn *Unita7;
        TBitBtn *Unita8;
        TBitBtn *Unita9;
        TBitBtn *Unita10;
        TBitBtn *Unita11;
        TBitBtn *Unita12;
        TBitBtn *Unita13;
        TBitBtn *Unita14;
        TBitBtn *Unita15;
        TBitBtn *Unita16;
        TBitBtn *BuOk;
        TPanel *PanIntest;
        TStringGrid *StringGrid1;
        TPanel *PChangeValue;
        TTimer *TimButton;
        TPanel *PanTast;
        TEdit *EditTast;
        TBitBtn *BtnTastCanc;
        TBitBtn *BtnTastSalva;
        TButton *BuZero;
        TButton *BuUno;
        TButton *BuDue;
        TButton *BuTre;
        TButton *BuQuattro;
        TButton *BuCinque;
        TButton *BuSei;
        TButton *BuSette;
        TButton *BuOtto;
        TButton *BuNove;
        TButton *BuPoint;
        TBitBtn *BtnTastExit;
        TGroupBox *GBUnita;
        TBitBtn *BtnUnitaA;
        TBitBtn *BtnUnitaB;
        TBitBtn *BtnUnitaC;
        TBitBtn *BtnUnitaD;
        TBitBtn *BtnUnitaE;
        TBitBtn *BtnUnitaF;
        TBitBtn *BtnUnitaG;
        TBitBtn *BtnUnitaH;
        TBitBtn *BtnGbUnitaEsci;
        TEdit *EdtModifyDesc;
        TBitBtn *BuPrint;
        TImage *PLingua;
        TButton *BtnPiuMeno;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Unita1Click(TObject *Sender);
        void __fastcall BuOkClick(TObject *Sender);
        void __fastcall Unita2Click(TObject *Sender);
        void __fastcall Unita3Click(TObject *Sender);
        void __fastcall Unita4Click(TObject *Sender);
        void __fastcall Unita5Click(TObject *Sender);
        void __fastcall Unita6Click(TObject *Sender);
        void __fastcall Unita7Click(TObject *Sender);
        void __fastcall Unita8Click(TObject *Sender);
        void __fastcall Unita9Click(TObject *Sender);
        void __fastcall Unita10Click(TObject *Sender);
        void __fastcall Unita11Click(TObject *Sender);
        void __fastcall Unita12Click(TObject *Sender);
        void __fastcall Unita13Click(TObject *Sender);
        void __fastcall Unita14Click(TObject *Sender);
        void __fastcall Unita15Click(TObject *Sender);
        void __fastcall Unita16Click(TObject *Sender);
        void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall StringGrid1TopLeftChanged(TObject *Sender);
        void __fastcall TimButtonTimer(TObject *Sender);
        void __fastcall BtnActionMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall BtnActionMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall BtnEsciClick(TObject *Sender);
        void __fastcall BtnSalvaClick(TObject *Sender);
        void __fastcall BtnActionEnter(TObject *Sender);
        void __fastcall BuDownClick(TObject *Sender);
        void __fastcall BuMenoClick(TObject *Sender);
        void __fastcall BuPiuClick(TObject *Sender);
        void __fastcall BuUpClick(TObject *Sender);
        void __fastcall BtnTastClick(TObject *Sender);
        void __fastcall PanTastExit(TObject *Sender);
        void __fastcall BtnTastCancClick(TObject *Sender);
        void __fastcall BuTastieraClick(TObject *Sender);
        void __fastcall BtnTastSalvaClick(TObject *Sender);
        void __fastcall BtnTastExitClick(TObject *Sender);
        void __fastcall BtnGbUnitaEsciClick(TObject *Sender);
        void __fastcall BtnUnitaAClick(TObject *Sender);
        void __fastcall BtnUnitaBClick(TObject *Sender);
        void __fastcall BtnUnitaCClick(TObject *Sender);
        void __fastcall BtnUnitaDClick(TObject *Sender);
        void __fastcall BtnUnitaEClick(TObject *Sender);
        void __fastcall BtnUnitaFClick(TObject *Sender);
        void __fastcall BtnUnitaGClick(TObject *Sender);
        void __fastcall BtnUnitaHClick(TObject *Sender);
        void __fastcall BuLingueClick(TObject *Sender);
        void __fastcall StringGrid1DrawCell(TObject *Sender,int ACol,int ARow,
                                            TRect &Rect,TGridDrawState State);
        void __fastcall StringGrid1Click(TObject *Sender);
        void __fastcall EdtModifyDescKeyPress(TObject *Sender, char &Key);
        void __fastcall StringGrid1DblClick(TObject *Sender);
        void __fastcall PChangeValueClick(TObject *Sender);
        void __fastcall BuPrintClick(TObject *Sender);
        void __fastcall BtnPiuMenoClick(TObject *Sender);


private:	// User declarations
        TCriticalSection *LCK_Db;
        TStringList *ActualVal;
        void __fastcall AdaptScreen();
        void __fastcall ResizeScreen();
        bool __fastcall CaricaDatiForm();
        AnsiString* __fastcall LeggiCampo(AnsiString *frase,AnsiString campo,
                                          AnsiString *val);
        AnsiString* __fastcall LeggiDato(TStringList *SL,AnsiString campo,
                                                             AnsiString *val);               
        TBitBtn*  __fastcall LookForButton(AnsiString BtnName);
        TPanel*  __fastcall LookForPanel(AnsiString ObjName);
        AnsiString  __fastcall LookForStringa(AnsiString ObjName);        
        void  __fastcall SetPanelProperty(TPanel *Obj);
        void  __fastcall SetBitBtnProperty(TBitBtn *Obj);
        void  __fastcall SetStrProperty(AnsiString Obj);        
        void  __fastcall SaveFileDateTime(AnsiString StrName);

protected:
        AnsiString*  __fastcall LoadPathDati(AnsiString *PathDati);
        bool __fastcall ReadAdattaSchermo();
        void __fastcall WriteAdattaSchermo(bool Mode);
        u32 __fastcall ReadCntLingue();
        u32 __fastcall ReadLingua();
        void __fastcall WriteLingua(u32 l);
        AnsiString* __fastcall ReadFileLingue();
        void __fastcall LoadFlagBmp();
        AnsiString* __fastcall LeggiFrase(TStringList *SL,u32 *r,u32 nr,
                                                AnsiString *s);
        bool __fastcall LeggiFrasiDefinizione();        
        void __fastcall BtnClick(TObject *Sender);
        void __fastcall BitBtnLoadParam();
        void __fastcall LoadGBUnita(u32 Uid, AnsiString GBCaption);        
        void __fastcall SaveParam();
        void __fastcall SaveDescription(s8 *Desc,u32 Row);        
        u8  __fastcall  SelectType(AnsiString *tp);
        TColor  __fastcall SelectColor(AnsiString *cl);

public:		// User declarations
        __fastcall TFGenModParam(TComponent* Owner);
        virtual __fastcall ~TFGenModParam();
        __property bool AdattaSchermo={read=ReadAdattaSchermo,
                                       write=WriteAdattaSchermo};
        __property u32 CntLingue={read=ReadCntLingue};
        __property u32 Lingua={read=ReadLingua, write=WriteLingua};
        __property AnsiString FileLingue={read=ReadFileLingue};
        bool __fastcall IsUnitaAggiornata(u32 Uid);
        bool __fastcall IsSubUnitaAggiornata(u32 Uid,u32 SubUid);
        bool __fastcall SaveData(u32 idUnita,u32 idSubUnita,AnsiString Nome,
                                 AnsiString *Valore);
        bool __fastcall SaveBakData(u32 idUnita,u32 idSubUnita,AnsiString *Path,
                                 AnsiString *Nome, AnsiString *Valore);
        bool  __fastcall GetData(u32 idUnita,u32 idSubUnita,AnsiString Nome,
                                         u32 NDati, TList *Valori,u32 *NByte);
        bool  __fastcall GetBakData(u32 idUnita,u32 idSubUnita,
                          AnsiString *path, AnsiString *Nome, TList *Valori);

        bool  __fastcall GetDataName(u32 idUnita,u32 idSubUnita,
                                AnsiString *Path, u32 NDato, AnsiString *Name);
        s32  __fastcall NByteType(AnsiString *tp);
        s32  __fastcall ConvertToByte(P_valoridb par,u8 *pbuf);

        void (*Command[30])();
        AnsiString(*RichiediPW)(AnsiString Pw);
};
//---------------------------------------------------------------------------
extern PACKAGE TFGenModParam *FGenModParam;
//---------------------------------------------------------------------------
#endif
