// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PascalUty.pas' rev: 6.00

#ifndef PascalUtyHPP
#define PascalUtyHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IniFiles.hpp>	// Pascal unit
#include <TlHelp32.hpp>	// Pascal unit
#include <SyncObjs.hpp>	// Pascal unit
#include <Sockets.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Pascaluty
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __stdcall SystemShutDown(int Mode);
extern PACKAGE int __fastcall WinExecNoWait(AnsiString Programma, AnsiString PathEseguibile);
extern PACKAGE int __fastcall WinExecAndWait(AnsiString ProgName, AnsiString PathEseguibile);
extern PACKAGE int __fastcall WinExecAndWaitMinimized(AnsiString ProgName, AnsiString PathEseguibile);
extern PACKAGE void __fastcall WinExecnotwait32(AnsiString FileName, int Visibility);
extern PACKAGE unsigned __fastcall WinExecAndWait32(AnsiString FileName, int Visibility);
extern PACKAGE bool __fastcall processExists(AnsiString exeFileName);
extern PACKAGE bool __fastcall ChangeDisplay(unsigned WResolution, unsigned HResolution, unsigned Depth);

}	/* namespace Pascaluty */
using namespace Pascaluty;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PascalUty
