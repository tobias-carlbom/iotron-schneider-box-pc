//==============================================================================
// FILE UTastiera.pas - tastiera per impostazioni
//==============================================================================

unit UTastiera;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, Buttons, ExtCtrls, Inifiles;

const
  PASSWORD =1;
  GENERIC =2;

  
type
  TFTastiera = class(TForm)

    PanEdit:       TPanel;
      EditText:    TEdit;

    PanTastiera:     TPanel;
      BuESC:         TButton;
      BuDEL:         TButton;
      BtnCapsLock:   TBitBtn;
      PLedCapsLock:  TPanel;
      BuQ:           TButton;
      BuW:           TButton;
      BuE:           TButton;
      BuR:           TButton;
      BuT:           TButton;
      BuY:           TButton;
      BuU:           TButton;
      BuI:           TButton;
      BuO:           TButton;
      BuP:           TButton;
      BuA:           TButton;
      BuS:           TButton;
      BuD:           TButton;
      BuF:           TButton;
      BuG:           TButton;
      BuH:           TButton;
      BuJ:           TButton;
      BuK:           TButton;
      BuL:           TButton;
      BtnOK:         TBitBtn;
      BuZ:           TButton;
      BuX:           TButton;
      BuC:           TButton;
      BuSpace:       TButton;
      BuV:           TButton;
      BuB:           TButton;
      BuN:           TButton;
      BuM:           TButton;

    procedure FormActivate(Sender: TObject);
    procedure InserisciCarattere(Carattere: String);
    procedure BuTastClick(Sender: TObject);
    procedure BuSpaceClick(Sender: TObject);
    procedure BuESCClick(Sender: TObject);
    procedure BuECommClick(Sender: TObject);
    procedure BuDELClick(Sender: TObject);
    procedure BuShiftMouseDown(Sender: TObject; Button: TMouseButton;
              Shift: TShiftState; X, Y: Integer);
    procedure BuShiftMouseUp(Sender: TObject; Button: TMouseButton;
              Shift: TShiftState; X, Y: Integer);
    procedure BtnCapsLockClick(Sender: TObject);
    procedure BtnOKClick(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure EditTextKeyPress(Sender: TObject; var Key: Char);

  private
    { Private declarations }
  public
    { Public declarations }
    TipoTast:  Integer;
    Risultato: String;
  end;

var
  FTastiera: TFTastiera;

implementation


//******************************************************************************
// DEFINIZIONE VARIABILI DELLA UNIT
//******************************************************************************

var
  SelEdit:           Tedit;
  LcBl_ShiftEnabled: Boolean = False;

{$R *.DFM}

//******************************************************************************
// GESTIONE FORM "FTastiera"
//******************************************************************************

//------------------------------------------------------------------------------
// Evento FormActivate "FTastiera"
//------------------------------------------------------------------------------
procedure TFTastiera.FormActivate(Sender: TObject);
begin
  SelEdit :=EditText;
  SelEdit.PasswordChar :=#0;
  SelEdit.MaxLength :=12;
  PanEdit.Visible :=True;
  SelEdit.Text :='';
  SelEdit.SelText :=Risultato;
  SelEdit.SetFocus;
end;

//------------------------------------------------------------------------------
// Aggiunta di un carattere al testo
//------------------------------------------------------------------------------
procedure TFTastiera.InserisciCarattere(Carattere: String);
begin
  if LcBl_ShiftEnabled then
  begin
    SelEdit.SelText := Carattere;
  end
  else
  begin
    SelEdit.SelText := LowerCase(Carattere);
  end;
  SelEdit.SetFocus;
end;

//------------------------------------------------------------------------------
// Evento OnClick tasti "Bu1", "Bu2", "Bu3", "Bu4", "Bu5", "Bu6", "Bu7", "Bu8",
// "Bu9", "Bu0", "BuQ", "BuW", "BuE", "BuR", "BuT", "BuY", "BuU", "BuI", "BuO",
// "BuP", "BuA", "BuS", "BuD", "BuF", "BuG", "BuH", "BuJ", "BuK", "BuL", "BuZ",
// "BuX", "BuC", "BuV"
//------------------------------------------------------------------------------
procedure TFTastiera.BuTastClick(Sender: TObject);
begin
  InserisciCarattere((Sender as TButton).Caption);
end;

//------------------------------------------------------------------------------
// Evento OnClick tasto "BuSpace"
//------------------------------------------------------------------------------
procedure TFTastiera.BuSpaceClick(Sender: TObject);
begin
  InserisciCarattere(' ');
end;

//------------------------------------------------------------------------------
// Evento OnClick tasto "BuESC"
//------------------------------------------------------------------------------
procedure TFTastiera.BuESCClick(Sender: TObject);
begin
  Risultato := Chr(27);
  Close;
end;

//------------------------------------------------------------------------------
// Evento OnClick tasto "BuEComm"
//------------------------------------------------------------------------------
procedure TFTastiera.BuECommClick(Sender: TObject);
begin
  InserisciCarattere('&');
end;

//------------------------------------------------------------------------------
// Evento OnClick tasto "BuDEL"
//------------------------------------------------------------------------------
procedure TFTastiera.BuDELClick(Sender: TObject);
begin
  if SelEdit.SelText <> '' then
  begin
    SelEdit.ClearSelection;
    SelEdit.SetFocus;
  end
  else
  begin
    if SelEdit.Text <> '' then
    begin
      if SelEdit.SelStart <> 0 then
      begin
        SelEdit.SelStart := SelEdit.SelStart - 1;
      end;
      SelEdit.SelLength := 1;
      SelEdit.ClearSelection;
    end;
    SelEdit.SetFocus;
  end;
end;

//------------------------------------------------------------------------------
// Evento OnMouseDown tasto "BuShift"
//------------------------------------------------------------------------------
procedure TFTastiera.BuShiftMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  LcBl_ShiftEnabled := True;
end;

//------------------------------------------------------------------------------
// Evento OnMouseUp tasto "BuShift"
//------------------------------------------------------------------------------
procedure TFTastiera.BuShiftMouseUp(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  SelEdit.SetFocus;
  LcBl_ShiftEnabled := False;
end;

//------------------------------------------------------------------------------
// Evento OnClick tasto "BuCapsLock"
//------------------------------------------------------------------------------
procedure TFTastiera.BtnCapsLockClick(Sender: TObject);
begin
  SelEdit.SetFocus;
  LcBl_ShiftEnabled := not LcBl_ShiftEnabled;
  if LcBl_ShiftEnabled then
  begin
    PLedCapsLock.Color := clLime
  end
  else
  begin
    PLedCapsLock.Color := clGray;
  end;
end;

//------------------------------------------------------------------------------
// Evento OnClick tasto "BuOK"
//------------------------------------------------------------------------------
procedure TFTastiera.BtnOKClick(Sender: TObject);
begin
  Risultato := SelEdit.Text;
  Close;
end;

procedure TFTastiera.FormKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
   if Key =13 then
   begin
     BtnOKClick(nil);
   end;
end;

procedure TFTastiera.EditTextKeyPress(Sender: TObject; var Key: Char);
begin
   if Key =Char(13) then
   begin
     BtnOKClick(nil);
   end;
end;

end.
