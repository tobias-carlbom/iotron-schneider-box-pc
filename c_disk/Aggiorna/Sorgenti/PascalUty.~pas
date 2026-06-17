unit PascalUty;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Forms,
  Dialogs, StdCtrls, Buttons, ExtCtrls, Sockets, SyncObjs,
  TlHelp32, IniFiles;



procedure SystemShutDown(Mode: integer); stdcall;
function WinExecNoWait (Programma: String; PathEseguibile: string): integer;
function WinExecAndWait (ProgName: String; PathEseguibile: string): Integer;
function WinExecAndWaitMinimized(ProgName: String; PathEseguibile: string): integer;

procedure WinExecnotwait32(FileName: string; Visibility: Integer);
function WinExecAndWait32(FileName: string; Visibility: Integer): Longword;

function processExists(exeFileName: string): Boolean;
function ChangeDisplay(WResolution, HResolution, Depth: DWORD) : Boolean;

implementation

//******************************************************************************
// Gestione uscita da Windows NT 4
procedure SystemShutDown(Mode: integer); stdcall;
//******************************************************************************
var
  hToken: Cardinal;
  tkp:  TOKEN_PRIVILEGES;
  error: AnsiString;
  TTPold: TOKEN_PRIVILEGES;
  len: DWord;
const SE_SHUTDOWN_NAME = 'SeShutdownPrivilege'; // costante per uscita da NT 4
begin
// Get a token for this process.
if (not OpenProcessToken(GetCurrentProcess,TOKEN_ADJUST_PRIVILEGES or TOKEN_QUERY, hToken)) then begin
  error := 'OpenProcessToken';
  end;

// Get the LUID for the shutdown privilege.
LookupPrivilegeValue(nil, SE_SHUTDOWN_NAME, tkp.Privileges[0].Luid);
tkp.PrivilegeCount := 1; // one privilege to set
tkp.Privileges[0].Attributes := SE_PRIVILEGE_ENABLED;
// Get the shutdown privilege for this process.

AdjustTokenPrivileges(hToken, False, tkp, sizeof(tkp), TTPold, Len);

// Cannot test the return value of AdjustTokenPrivileges.
if (GetLastError() <> ERROR_SUCCESS) then begin
  error := 'AdjustTokenPrivileges';
  end;

// 1 = Forcefully close apps, shutdown and leave system at shutoff point
if (mode = 1) then begin
  if (not ExitWindowsEx(EWX_SHUTDOWN or EWX_FORCE, 0)) then   begin
    error := 'ExitWindowsEx';
    end;
  end;

// 2 = Forcefully close apps, shutdown and reboot
if(mode = 2) then begin
  if (not ExitWindowsEx(EWX_REBOOT or EWX_FORCE, 0)) then   begin
    error := 'ExitWindowsEx';
    end;
  end;

// 3 = Forcefully close apps, and logoff
if(mode = 3) then begin
  if (not ExitWindowsEx(EWX_LOGOFF or EWX_FORCE, 0)) then begin
    error := 'ExitWindowsEx';
    end;
  end;
end;

//******************************************************************************
function WinExecNoWait (Programma: String; PathEseguibile: string): integer;
//******************************************************************************
{ Esegue un programma ma non attende il termine. }
var
  StartupInfo: TStartupInfo;
  ProcessInfo: TProcessInformation;
  dum: string;
begin
  if not DirectoryExists(PChar(PathEseguibile)) then
  begin
    result :=-2; { errore direttorio inesistente}
    exit;
  end;
  SetCurrentDirectory(PChar(PathEseguibile));
  dum :=PathEseguibile +Programma;
  if not FileExists(PChar(dum)) then
  begin
    result :=-3; { errore programma inesistente}
    exit;
  end;
  FillChar(StartupInfo, Sizeof(StartupInfo),#0);
  FillChar(ProcessInfo, Sizeof(StartupInfo),#0);

  StartupInfo.cb :=Sizeof(StartupInfo);
  StartupInfo.lpDesktop :=nil;
  StartupInfo.wShowWindow :=SW_SHOWDEFAULT;
  StartupInfo.dwFlags :=STARTF_USESTDHANDLES;

  if CreateProcess(nil, PChar(Programma), nil, nil, false,
                   CREATE_NEW_CONSOLE or CREATE_DEFAULT_ERROR_MODE,
                   getEnvironmentStrings, nil, StartupInfo, ProcessInfo) then
    result :=0
  else
    result :=-1; { errore nell'esecuzione del programma }
end;

//******************************************************************************
function WinExecAndWait (ProgName: String; PathEseguibile: string): Integer;
//******************************************************************************
{ Esegue un programma e ne attende il risultato(o il termine). }
var
  esito: cardinal;
  StartupInfo: TStartupInfo;
  ProcessInfo: TProcessInformation;
begin
  SetCurrentDirectory(PChar(PathEseguibile));
  FillChar(StartupInfo, Sizeof(StartupInfo),#0);
  FillChar(ProcessInfo, Sizeof(StartupInfo),#0);

  StartupInfo.cb :=Sizeof(StartupInfo);
  StartupInfo.lpDesktop :=nil;
  StartupInfo.wShowWindow :=SW_SHOWDEFAULT;
  StartupInfo.dwFlags :=STARTF_FORCEONFEEDBACK;

  if CreateProcess(nil, PChar(ProgName), nil, nil, false,
                   CREATE_NEW_CONSOLE or CREATE_DEFAULT_ERROR_MODE,
                   getEnvironmentStrings, nil, StartupInfo, ProcessInfo) then
  begin
    WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
    GetExitCodeProcess(ProcessInfo.hProcess, esito);
    Result :=esito;
  end
  else
    result :=-1; { errore nell'esecuzione del programma }
end;
//******************************************************************************
function WinExecAndWaitMinimized(ProgName: String; PathEseguibile: string): Integer;
//******************************************************************************
{ Esegue un programma e ne attende il risultato(o il termine). }
var
  esito: cardinal;
  StartupInfo: TStartupInfo;
  ProcessInfo: TProcessInformation;
begin
  SetCurrentDirectory(PChar(PathEseguibile));
  FillChar(StartupInfo, Sizeof(StartupInfo),#0);
  FillChar(ProcessInfo, Sizeof(StartupInfo),#0);

  StartupInfo.cb :=Sizeof(StartupInfo);
  StartupInfo.lpDesktop :=nil;
  StartupInfo.wShowWindow :=SW_MINIMIZE	;
  StartupInfo.dwFlags :=STARTF_FORCEONFEEDBACK or STARTF_USESHOWWINDOW;

  if CreateProcess(nil, PChar(ProgName), nil, nil, false,
                   CREATE_NEW_CONSOLE or CREATE_DEFAULT_ERROR_MODE,
                   getEnvironmentStrings, nil, StartupInfo, ProcessInfo) then
  begin
    WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
    GetExitCodeProcess(ProcessInfo.hProcess, esito);
    Result :=esito;
  end
  else
    result :=-1; { errore nell'esecuzione del programma }
end;

procedure WinExecnotwait32(FileName: string; Visibility: Integer);
var
  zAppName: array[0..512] of Char;
  zCurDir: array[0..255] of Char;
  WorkDir: string;
  StartupInfo: TStartupInfo;
  ProcessInfo: TProcessInformation;
begin
  StrPCopy(zAppName, FileName);
  GetDir(0, WorkDir);
  StrPCopy(zCurDir, WorkDir);
  FillChar(StartupInfo, SizeOf(StartupInfo), #0);
  StartupInfo.cb          := SizeOf(StartupInfo);
  StartupInfo.dwFlags     := STARTF_USESHOWWINDOW;
  StartupInfo.wShowWindow := Visibility;
  CreateProcess(nil,
    zAppName, // pointer to command line string
    nil, // pointer to process security attributes
    nil, // pointer to thread security attributes
    False, // handle inheritance flag
    CREATE_NEW_CONSOLE or // creation flags
    NORMAL_PRIORITY_CLASS,
    nil, //pointer to new environment block
    nil, // pointer to current directory name
    StartupInfo, // pointer to STARTUPINFO
    ProcessInfo) // pointer to PROCESS_INF
end;

function WinExecAndWait32(FileName: string; Visibility: Integer): Longword;
var
  zAppName: array[0..512] of Char;
  zCurDir: array[0..255] of Char;
  WorkDir: string;
  StartupInfo: TStartupInfo;
  ProcessInfo: TProcessInformation;
begin
  StrPCopy(zAppName, FileName);
  GetDir(0, WorkDir);
  StrPCopy(zCurDir, WorkDir);
  FillChar(StartupInfo, SizeOf(StartupInfo), #0);
  StartupInfo.cb          := SizeOf(StartupInfo);
  StartupInfo.dwFlags     := STARTF_USESHOWWINDOW;
  StartupInfo.wShowWindow := Visibility;
  if not CreateProcess(nil,
    zAppName, // pointer to command line string
    nil, // pointer to process security attributes
    nil, // pointer to thread security attributes
    False, // handle inheritance flag
    CREATE_NEW_CONSOLE or // creation flags
    NORMAL_PRIORITY_CLASS,
    nil, //pointer to new environment block
    nil, // pointer to current directory name
    StartupInfo, // pointer to STARTUPINFO
    ProcessInfo) // pointer to PROCESS_INF
    then Result := WAIT_FAILED
  else
  begin
    WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
    GetExitCodeProcess(ProcessInfo.hProcess, Result);
    CloseHandle(ProcessInfo.hProcess);
    CloseHandle(ProcessInfo.hThread);
  end;
end;

function processExists(exeFileName: string): Boolean;
var
  ContinueLoop: BOOL;
  FSnapshotHandle: THandle;
  FProcessEntry32: TProcessEntry32;
begin
  FSnapshotHandle := CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  FProcessEntry32.dwSize := SizeOf(FProcessEntry32);
  ContinueLoop := Process32First(FSnapshotHandle, FProcessEntry32);
  Result := False;
  while Integer(ContinueLoop) <> 0 do
  begin
    if ((UpperCase(ExtractFileName(FProcessEntry32.szExeFile)) =
      UpperCase(ExeFileName)) or (UpperCase(FProcessEntry32.szExeFile) =
      UpperCase(ExeFileName))) then
    begin
      Result := True;
    end;
    ContinueLoop := Process32Next(FSnapshotHandle, FProcessEntry32);
  end;
  CloseHandle(FSnapshotHandle);
end;

function ChangeDisplay(WResolution, HResolution, Depth: DWORD) : Boolean;
var
  i: Integer;
  DevMode: TDevMode;
begin
  Result := False;
  i:=0;
  while EnumDisplaySettings(nil,i,DevMode) do
  begin
    with DevMode do
    begin
      if (dmPelsWidth = WResolution)
         and (dmPelsHeight = HResolution)
         and (dmBitsPerPel = Depth) then
         begin
           ////////////////////////////////////////
           DevMode.dmLogPixels := 120;
           ///////////////////////////////////////
           if ChangeDisplaySettings(DevMode,CDS_UPDATEREGISTRY)
             = DISP_CHANGE_SUCCESSFUL then
           begin
             Result := True;
             Break;
           end;
         end;
      Inc(i);
    end;
  end;
end;

end.
