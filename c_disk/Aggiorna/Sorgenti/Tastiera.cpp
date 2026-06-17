//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tastiera.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTastiera *FormTastiera;
//---------------------------------------------------------------------------
__fastcall TFormTastiera::TFormTastiera(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTastiera::BuQClick(TObject *Sender)
{
  TButton *button =(TButton *)Sender;
  result =button->Caption;
  Close();
}
//---------------------------------------------------------------------------
AnsiString __fastcall TFormTastiera::GetResult()
{
  return result;
}
//---------------------------------------------------------------------------
void __fastcall TFormTastiera::BtnCancelClick(TObject *Sender)
{
  Close();  
}
//---------------------------------------------------------------------------

void __fastcall TFormTastiera::FormActivate(TObject *Sender)
{
  result ="";
}
//---------------------------------------------------------------------------



