// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'UTastiera.pas' rev: 6.00

#ifndef UTastieraHPP
#define UTastieraHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IniFiles.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Utastiera
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFTastiera;
class PASCALIMPLEMENTATION TFTastiera : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* PanEdit;
	Stdctrls::TEdit* EditText;
	Extctrls::TPanel* PanTastiera;
	Stdctrls::TButton* BuESC;
	Stdctrls::TButton* BuDEL;
	Buttons::TBitBtn* BtnCapsLock;
	Extctrls::TPanel* PLedCapsLock;
	Stdctrls::TButton* BuQ;
	Stdctrls::TButton* BuW;
	Stdctrls::TButton* BuE;
	Stdctrls::TButton* BuR;
	Stdctrls::TButton* BuT;
	Stdctrls::TButton* BuY;
	Stdctrls::TButton* BuU;
	Stdctrls::TButton* BuI;
	Stdctrls::TButton* BuO;
	Stdctrls::TButton* BuP;
	Stdctrls::TButton* BuA;
	Stdctrls::TButton* BuS;
	Stdctrls::TButton* BuD;
	Stdctrls::TButton* BuF;
	Stdctrls::TButton* BuG;
	Stdctrls::TButton* BuH;
	Stdctrls::TButton* BuJ;
	Stdctrls::TButton* BuK;
	Stdctrls::TButton* BuL;
	Buttons::TBitBtn* BtnOK;
	Stdctrls::TButton* BuZ;
	Stdctrls::TButton* BuX;
	Stdctrls::TButton* BuC;
	Stdctrls::TButton* BuSpace;
	Stdctrls::TButton* BuV;
	Stdctrls::TButton* BuB;
	Stdctrls::TButton* BuN;
	Stdctrls::TButton* BuM;
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall InserisciCarattere(AnsiString Carattere);
	void __fastcall BuTastClick(System::TObject* Sender);
	void __fastcall BuSpaceClick(System::TObject* Sender);
	void __fastcall BuESCClick(System::TObject* Sender);
	void __fastcall BuECommClick(System::TObject* Sender);
	void __fastcall BuDELClick(System::TObject* Sender);
	void __fastcall BuShiftMouseDown(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall BuShiftMouseUp(System::TObject* Sender, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall BtnCapsLockClick(System::TObject* Sender);
	void __fastcall BtnOKClick(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall EditTextKeyPress(System::TObject* Sender, char &Key);
	
public:
	int TipoTast;
	AnsiString Risultato;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TFTastiera(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFTastiera(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFTastiera(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFTastiera(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint PASSWORD = 0x1;
static const Shortint GENERIC = 0x2;
extern PACKAGE TFTastiera* FTastiera;

}	/* namespace Utastiera */
using namespace Utastiera;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// UTastiera
