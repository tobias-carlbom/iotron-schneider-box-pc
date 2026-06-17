//---------------------------------------------------------------------------

#ifndef TastieraH
#define TastieraH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormTastiera : public TForm
{
__published:	// IDE-managed Components
  TPanel *PanTastiera;
  TButton *BuQ;
  TButton *BuW;
  TButton *BuE;
  TButton *BuR;
  TButton *BuT;
  TButton *BuY;
  TButton *BuU;
  TButton *BuI;
  TButton *BuO;
  TButton *BuP;
  TButton *BuA;
  TButton *BuS;
  TButton *BuD;
  TButton *BuF;
  TButton *BuG;
  TButton *BuH;
  TButton *BuJ;
  TButton *BuK;
  TButton *BuL;
  TButton *BuZ;
  TButton *BuX;
  TButton *BuC;
  TButton *BuV;
  TButton *BuB;
  TButton *BuN;
  TButton *BuM;
  TBitBtn *BtnCancel;
  void __fastcall BuQClick(TObject *Sender);
  void __fastcall BtnCancelClick(TObject *Sender);
  void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
  AnsiString result;
public:		// User declarations
  __fastcall TFormTastiera(TComponent* Owner);
  AnsiString __fastcall GetResult();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTastiera *FormTastiera;
//---------------------------------------------------------------------------
#endif
