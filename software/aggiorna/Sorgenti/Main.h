//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPServer.hpp>
#include <IdTCPClient.hpp>
#include <IdIcmpClient.hpp>
#include "Gk_type.h"

#define WM_START	        WM_USER +1
#define WM_START_APPLICATION  	WM_USER +2
#define WM_UPGRADE_APPLICATION	WM_USER +3
#define WM_START_SHUTDOWN       WM_USER +4
#define WM_DISK_OK              WM_USER +5
#define WM_WAIT_DISK            WM_USER +6

#define WM_PCNAME               WM_USER +7

#define WM_DISK_SECONDARY       WM_USER +108

#define GKS30_COD 30

#define   MAX_DRIVE_UNIT  10
#define   SHUT_DOWN       31

#define   DISKPART            "diskpart.exe"  

#define   GRAFIKSCAN2100      1
#define   GRAFIKSCAN3000      0
#define   EWFCONFIG           "rundll32.exe ewfdll.dll,ConfigureEwf"
#define   SHARE_RAMDSK_B      "net share B=B:\ /UNLIMITED"
#define   SHARE_RAMDSK_M      "net share M=M:\ /UNLIMITED"
#define   RAMDISK_M_CREATE    "imdisk -a -s 850M -m M: -p \"/fs:ntfs /q /y\""
#define   RAMDISKM_DELETE     "imdisk -d -m M:"
#define   RAMDISK_M           "M:\\"
#define   SECONDARY_HDD       "Z:\\"
#define   FORMAT_SECOND_HDD   "D:\Format_secondary.lnk"
#define   EXIST_SHARE_B       "\\\\127.0.0.1\\B"
#define   DISKPART_FORMAT_HDD "D:\\SecondaryHDD\\SecondaryHDD.cmd"
#define   REGEWF_1            "D:\\EWF\\Arc.reg";
#define   REGEWF_2            "D:\\EWF\\PVDisk.reg";
#define   WAIT_TIME           200

#define   GK_SCRN_W           1280
#define   GK_SCRN_H           1024


//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
  TMemo *Memo1;
  TImage *ImgDownLoad;
  TLabel *LProgramName;
  TAnimate *Animate1;
  TBitBtn *BBtnOK;
  TBitBtn *BBtnCancel;
  TBitBtn *BtnExit;
  TBitBtn *BtnShut;
  TIdTCPServer *Server;
  TTimer *StatrProgram;
  TLabel *Label1;
  TPanel *PanelComputerName;
  TBitBtn *BitBtnComputerName;
  TEdit *EditNumeroCommessa;
  TLabel *Label3;
  TEdit *EditAnnoCommessa;
  TLabel *Label5;
  TTimer *TimerComputerName;
  TEdit *EditLetteraCommessa;
  TLabel *Label6;
  TLabel *Label8;
  TEdit *EditImpianto;
  TLabel *Label9;
  TLabel *Label10;
  TLabel *Label11;
  TLabel *Label4;
  TLabel *Label12;
  TLabel *Label2;
  TLabel *Label7;
  TPanel *PanelNomeComputer;
        TCheckBox *ChkBoxFormat;
        TTimer *TimerSharing;
        TButton *Button1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormActivate(TObject *Sender);
  void __fastcall Memo1Click(TObject *Sender);
  void __fastcall BBtnOKClick(TObject *Sender);
  void __fastcall BBtnCancelClick(TObject *Sender);
  void __fastcall BtnShutClick(TObject *Sender);
  void __fastcall ServerConnect(TIdPeerThread *AThread);
  void __fastcall ServerExecute(TIdPeerThread *AThread);
  void __fastcall ServerDisconnect(TIdPeerThread *AThread);
  void __fastcall BtnExitClick(TObject *Sender);
  void __fastcall EditNumeroCommessaMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  void __fastcall BitBtnComputerNameClick(TObject *Sender);
  void __fastcall EditAnnoCommessaClick(TObject *Sender);
  void __fastcall TimerComputerNameTimer(TObject *Sender);
  void __fastcall EditLetteraCommessaClick(TObject *Sender);
  void __fastcall EditImpiantoMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall TimerSharingTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);

  private:	// User declarations
  	void __fastcall Msg_Start(TMessage *Message);
  	void __fastcall Msg_StartApplication(TMessage *Message);
  	void __fastcall Msg_UpgradeApplication(TMessage *Message);
  	void __fastcall Msg_ShutDownApplication(TMessage *Message);
  	void __fastcall Msg_DiskOk(TMessage *Message);
  	void __fastcall Msg_WaitDisk(TMessage *Message);
        void __fastcall Msg_PCName(TMessage *Message);
        void __fastcall Msg_DiskSecondary(TMessage *Message);

    int __fastcall InitializeProgramData();
    void __fastcall CreaFileVersione(int prog);
    void __fastcall CopiaDll(AnsiString DirDll);
    void __fastcall RipristinaFileDati(int prog);
    void __fastcall BackupFileDati(int prog);
    bool __fastcall FindUpGradeFile();
    bool __fastcall DiskPresent();
    u32 __fastcall  CrcRoll(u32 Crc);
    void __fastcall ShutDownTesta();

  private:
    TIdIcmpClient *pingclient;
    s32 ping_answer;
    s8 buff[1000];
    bool __fastcall isComputerNameAssigned();
    AnsiString __fastcall MacAddress();
    void __fastcall SetMAC();
    void __fastcall IdIcmpClientReply(TComponent* ASender, const TReplyStatus &AReplyStatus);
    bool isStaticIpAvailable(AnsiString ip, s32 prog_id);
    bool ReadStaticIpAddressUsed(s32 prog_id, s32 addr, AnsiString* ip, AnsiString* descr);

  public:		// User declarations
    __fastcall TFormMain(TComponent* Owner);

	virtual void __fastcall Dispatch(void *Message)
	{
		switch(((PMessage)Message)->Msg)
		{
			case WM_START:
				Msg_Start((TMessage *)Message);
				break;

			case WM_START_APPLICATION:
				Msg_StartApplication((TMessage *)Message);
				break;

			case WM_UPGRADE_APPLICATION:
				Msg_UpgradeApplication((TMessage *)Message);
				break;

			case WM_START_SHUTDOWN:
				Msg_ShutDownApplication((TMessage *)Message);
				break;

			case WM_DISK_OK:
				Msg_DiskOk((TMessage *)Message);
				break;

			case WM_WAIT_DISK:
				Msg_WaitDisk((TMessage *)Message);
				break;

                        case WM_PCNAME:
                                Msg_PCName((TMessage *)Message);
                                break;

                        case WM_DISK_SECONDARY:
                                Msg_DiskSecondary((TMessage *)Message);
                                break;
			default:
				TForm::Dispatch(Message);
		}
	}
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
