//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TastieraNumerica.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTastieraNumerica *FormTastieraNumerica;
//---------------------------------------------------------------------------
__fastcall TFormTastieraNumerica::TFormTastieraNumerica(TComponent* Owner)
  : TForm(Owner)
{
  // Crea lucchetto di accesso ai dati
  Lck =new TCriticalSection();
  // Inizializza la posizione dell'angolo in alto a sinistra del tastierino
  // sul display (vedi prop. TopLeft)
  topleft.x =(Screen->Width -PanTast->Width) >>1;
  topleft.y =(Screen->Height -PanTast->Height) >>1;
  Left =topleft.x;
  Top =topleft.y;
  // Dimensiona la form come il pannello del tastierino
  Width =PanTast->Width;
  Height =PanTast->Height;
  //posiziona il pannello del tastierino nella form
  PanTast->Left =0;
  PanTast->Top =0;
  // Inizializza i limiti del valore impostabile
  limiteinf =0;
  limitesup =MaxInt;
}
//---------------------------------------------------------------------------
void __fastcall TFormTastieraNumerica::FormActivate(TObject *Sender)
{
  // posiziona la form sul display (vedi prop. TopLeft)
  Left =TopLeft.x;
  Top =TopLeft.y;
  // Evidenzia il valore della stringa da modificare
  if(EditTast->Text.Length())
  {
    EditTast->SelectAll();
  }  
}

//******************************************************************************
// GESTIONE PANNELLO "PanTast"
//******************************************************************************
//------------------------------------------------------------------------------
// Evento OnClick tasti 0-9
//------------------------------------------------------------------------------
void __fastcall TFormTastieraNumerica::BuTastClick(TObject *Sender)
{
  TButton *Button =(TButton *)Sender;
  EditTast->SelText =Button->Caption;
  EditTast->SetFocus();
}
//------------------------------------------------------------------------------
// Evento OnClick tasto "BtnTastCanc"
//------------------------------------------------------------------------------
void __fastcall TFormTastieraNumerica::BtnTastCancClick(TObject *Sender)
{
  if(EditTast->SelText.Length())
  {
    EditTast->ClearSelection();
    EditTast->SetFocus();
  }
  else
  {
    if(EditTast->Text.Length())
    {
      if(EditTast->SelStart >0)
      {
        EditTast->SelStart =EditTast->SelStart -1 ;
      }
      EditTast->SelLength =1;
      EditTast->ClearSelection();
    }
    EditTast->SetFocus();
  }
}
//------------------------------------------------------------------------------
// Evento OnClick tasto "BtnTastSalva"
//------------------------------------------------------------------------------
void __fastcall TFormTastieraNumerica::BtnTastSalvaClick(TObject *Sender)
{
  Lck->Acquire();
  // quantità nulla
  valore ="";
  f32 v =EditTast->Text.ToDouble();
  if(v >=limiteinf && v <=limitesup)
  {
    valore =EditTast->Text;
  }
  Lck->Release();
  Close();
}
//------------------------------------------------------------------------------
// Evento OnClick tasto "BtnTastEsci"
//------------------------------------------------------------------------------
void __fastcall TFormTastieraNumerica::BtnTastEsciClick(TObject *Sender)
{
  Close();
}






//---------------------------------------------------------------------------
void __fastcall TFormTastieraNumerica::SetTopLeft(TPoint P)
// **************************************************************************
//Assegna la posizione dell'angolo in alto a sinistra del tastierino sul display
{
  // Acquisisce le risorse
  Lck->Acquire();
  // Verifica la validità del posizionamento
  s32 v =P.x;
  if((v +PanTast->Width) >Screen->Width)
  {
    P.x =Screen->Width -PanTast->Width;
  }
  v =P.y;
  if((v +PanTast->Height) >Screen->Height)
  {
    P.y =Screen->Height -PanTast->Height;
  }
  // asegna il posizionamento
  topleft =P;
  // rilascia le risorse
  Lck->Release();
}
// **************************************************************************
TPoint __fastcall TFormTastieraNumerica::GetTopLeft()
// **************************************************************************
{
  // Acquisisce le risorse
  Lck->Acquire();
  // Legge il valore del posizionamento
  TPoint Result =topleft;
  // rilascia le risorse
  Lck->Release();
  return(Result);
}
// **************************************************************************
void __fastcall TFormTastieraNumerica::SetValore(AnsiString V)
// **************************************************************************
{
  Lck->Acquire();
  valore =V;
  EditTast->Text =valore;
  Lck->Release();
}
// **************************************************************************
AnsiString __fastcall TFormTastieraNumerica::GetValore()
// **************************************************************************
{
  Lck->Acquire();
  AnsiString Result =valore;
  Lck->Release();
  return(Result);
}
// **************************************************************************
void __fastcall TFormTastieraNumerica::SetLimiteInf(f32 V)
// **************************************************************************
{
  Lck->Acquire();
  limiteinf =V;
  Lck->Release();
}
// **************************************************************************
void __fastcall TFormTastieraNumerica::SetLimiteSup(f32 V)
// **************************************************************************
{
  Lck->Acquire();
  limitesup =(V <limiteinf) ? limiteinf :V;
  Lck->Release();
}

void __fastcall TFormTastieraNumerica::Button12Click(TObject *Sender)
{
  s8 *dum =new s8[StrLen(EditTast->Text.c_str()) +2];
  if(StrPos(EditTast->Text.c_str(),"-") ==NULL)
  {
    StrCopy(dum, "-");
    StrCat(dum, EditTast->Text.c_str());
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

