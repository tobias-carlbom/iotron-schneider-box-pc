//---------------------------------------------------------------------------

#ifndef TastieraNumericaH
#define TastieraNumericaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <SyncObjs.hpp>

#include "Gk_type.h"

//---------------------------------------------------------------------------
class TFormTastieraNumerica : public TForm
{
__published:	// IDE-managed Components
  TPanel *PanTast;
  TEdit *EditTast;
  TBitBtn *BtnTastEsci;
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
  void __fastcall FormActivate(TObject *Sender);
  void __fastcall BuTastClick(TObject *Sender);
  void __fastcall BtnTastCancClick(TObject *Sender);
  void __fastcall BtnTastSalvaClick(TObject *Sender);
  void __fastcall BtnTastEsciClick(TObject *Sender);
  void __fastcall Button12Click(TObject *Sender);

  
private:	// User declarations
  TCriticalSection *Lck;
  TPoint topleft;
  AnsiString valore;
  f32 limiteinf;
  f32 limitesup;

protected:
  void __fastcall SetTopLeft(TPoint P);  
  TPoint __fastcall GetTopLeft();
  void __fastcall SetValore(AnsiString V);
  AnsiString __fastcall GetValore();
  void __fastcall SetLimiteInf(f32 V);
  void __fastcall SetLimiteSup(f32 V);


public:		// User declarations
  // Questa proprietà permette di posizionare l'angolo inalto a sinistra del
  // tastierino numerico sul display
  __property TPoint TopLeft={read=GetTopLeft, write=SetTopLeft};
  // Setta il limite inferiore del valore impostabile
  __property f32 LimiteInf={write=SetLimiteInf};
  // Setta il limite superiore del valore impostabile
  __property f32 LimiteSup={write=SetLimiteSup};
  // valore iniziale e terminale della funzione
  // write=il valore impostato viene visualizzato nella edit Box del tastierino
  // read=nuovo valore inserito dall'operatore
  __property AnsiString Valore={read=GetValore, write=SetValore};

  __fastcall TFormTastieraNumerica(TComponent* Owner);


  
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTastieraNumerica *FormTastieraNumerica;
//---------------------------------------------------------------------------
#endif
