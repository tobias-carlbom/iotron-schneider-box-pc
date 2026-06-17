object FGenModParam: TFGenModParam
  Left = 1
  Top = 0
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsNone
  Caption = ' '
  ClientHeight = 803
  ClientWidth = 1042
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object PLingua: TImage
    Left = 78
    Top = 585
    Width = 90
    Height = 46
  end
  object PanComand: TPanel
    Left = 0
    Top = 702
    Width = 1025
    Height = 98
    BevelInner = bvLowered
    BevelWidth = 2
    Color = clBlack
    TabOrder = 1
    object BtnEsci: TBitBtn
      Left = 923
      Top = 13
      Width = 92
      Height = 72
      Cursor = crHandPoint
      Caption = 'BtnEsci'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = BtnEsciClick
      OnEnter = BtnActionEnter
    end
    object BtnSalva: TBitBtn
      Left = 819
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BtnSalva'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = BtnSalvaClick
      OnEnter = BtnActionEnter
    end
    object BtnTast: TBitBtn
      Left = 299
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BtnTast'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = BtnTastClick
      OnEnter = BtnActionEnter
    end
    object BtnResBackUp: TBitBtn
      Left = 7
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BtnResBackUp'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnEnter = BtnActionEnter
    end
    object BtnSaveBackUp: TBitBtn
      Left = 104
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BtnSaveBackUp'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnEnter = BtnActionEnter
    end
    object BuDown: TBitBtn
      Left = 410
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BuDown'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = BuDownClick
      OnEnter = BtnActionEnter
      OnMouseDown = BtnActionMouseDown
      OnMouseUp = BtnActionMouseUp
    end
    object BuUp: TBitBtn
      Left = 507
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BuUp'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = BuUpClick
      OnEnter = BtnActionEnter
      OnMouseDown = BtnActionMouseDown
      OnMouseUp = BtnActionMouseUp
    end
    object BuPiu: TBitBtn
      Left = 618
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BuPiu'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = BuPiuClick
      OnEnter = BtnActionEnter
      OnMouseDown = BtnActionMouseDown
      OnMouseUp = BtnActionMouseUp
    end
    object BuMeno: TBitBtn
      Left = 715
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BuMeno'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      OnClick = BuMenoClick
      OnEnter = BtnActionEnter
      OnMouseDown = BtnActionMouseDown
      OnMouseUp = BtnActionMouseUp
    end
    object BuLingue: TBitBtn
      Left = 202
      Top = 13
      Width = 91
      Height = 73
      Cursor = crHandPoint
      Caption = 'BuLingue'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = BuLingueClick
      OnEnter = BtnActionEnter
    end
  end
  object BtnAction: TButton
    Left = 0
    Top = 0
    Width = 14
    Height = 20
    Caption = 'BtnAction'
    TabOrder = 2
    Visible = False
    OnEnter = BtnActionEnter
    OnMouseDown = BtnActionMouseDown
    OnMouseUp = BtnActionMouseUp
  end
  object Unita1: TBitBtn
    Left = 13
    Top = 46
    Width = 235
    Height = 52
    Caption = 'Unita1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Unita1Click
  end
  object Unita2: TBitBtn
    Left = 13
    Top = 104
    Width = 235
    Height = 53
    Caption = 'Unita2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = Unita2Click
  end
  object Unita3: TBitBtn
    Left = 13
    Top = 163
    Width = 235
    Height = 52
    Caption = 'Unita3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = Unita3Click
  end
  object Unita4: TBitBtn
    Left = 13
    Top = 221
    Width = 235
    Height = 53
    Caption = 'Unita4'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = Unita4Click
  end
  object Unita5: TBitBtn
    Left = 13
    Top = 280
    Width = 235
    Height = 52
    Caption = 'Unita5'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = Unita5Click
  end
  object Unita6: TBitBtn
    Left = 13
    Top = 338
    Width = 235
    Height = 53
    Caption = 'Unita6'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = Unita6Click
  end
  object Unita7: TBitBtn
    Left = 13
    Top = 397
    Width = 235
    Height = 52
    Caption = 'Unita7'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    OnClick = Unita7Click
  end
  object Unita8: TBitBtn
    Left = 13
    Top = 455
    Width = 235
    Height = 53
    Caption = 'Unita8'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    OnClick = Unita8Click
  end
  object Unita9: TBitBtn
    Left = 267
    Top = 46
    Width = 234
    Height = 52
    Caption = 'Unita9'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 11
    OnClick = Unita9Click
  end
  object Unita10: TBitBtn
    Left = 267
    Top = 104
    Width = 234
    Height = 53
    Caption = 'Unita10'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 12
    OnClick = Unita10Click
  end
  object Unita11: TBitBtn
    Left = 267
    Top = 163
    Width = 234
    Height = 52
    Caption = 'Unita11'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 13
    OnClick = Unita11Click
  end
  object Unita12: TBitBtn
    Left = 267
    Top = 221
    Width = 234
    Height = 53
    Caption = 'Unita12'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 14
    OnClick = Unita12Click
  end
  object Unita13: TBitBtn
    Left = 267
    Top = 280
    Width = 234
    Height = 52
    Caption = 'Unita13'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 15
    OnClick = Unita13Click
  end
  object Unita14: TBitBtn
    Left = 267
    Top = 338
    Width = 234
    Height = 53
    Caption = 'Unita14'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 16
    OnClick = Unita14Click
  end
  object Unita15: TBitBtn
    Left = 267
    Top = 397
    Width = 234
    Height = 52
    Caption = 'Unita15'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 17
    OnClick = Unita15Click
  end
  object Unita16: TBitBtn
    Left = 267
    Top = 455
    Width = 234
    Height = 53
    Caption = 'Unita16'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 18
    OnClick = Unita16Click
  end
  object BuOk: TBitBtn
    Left = 20
    Top = 521
    Width = 52
    Height = 52
    Caption = 'BuOk'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 19
    OnClick = BuOkClick
  end
  object PanIntest: TPanel
    Left = 0
    Top = 0
    Width = 1042
    Height = 33
    Align = alTop
    Alignment = taLeftJustify
    BevelInner = bvLowered
    Caption = 'PanIntest'
    Color = clNavy
    Font.Charset = ANSI_CHARSET
    Font.Color = clLime
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 20
  end
  object StringGrid1: TStringGrid
    Left = 74
    Top = 545
    Width = 109
    Height = 34
    BiDiMode = bdLeftToRight
    Color = clInfoBk
    DefaultColWidth = 20
    FixedCols = 0
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Pitch = fpFixed
    Font.Style = []
    Options = [goVertLine, goHorzLine, goRowSelect]
    ParentBiDiMode = False
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    Visible = False
    OnClick = StringGrid1Click
    OnDblClick = StringGrid1DblClick
    OnDrawCell = StringGrid1DrawCell
    OnSelectCell = StringGrid1SelectCell
    OnTopLeftChanged = StringGrid1TopLeftChanged
    ColWidths = (
      39
      21
      20
      20
      20)
  end
  object PChangeValue: TPanel
    Left = 104
    Top = 520
    Width = 92
    Height = 20
    BevelInner = bvLowered
    BevelWidth = 3
    Caption = 'PChangeValue'
    Color = clYellow
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 21
    Visible = False
    OnClick = PChangeValueClick
  end
  object PanTast: TPanel
    Left = 507
    Top = 46
    Width = 521
    Height = 247
    BevelInner = bvLowered
    BevelWidth = 2
    Color = clNavy
    DragCursor = crDefault
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 22
    Visible = False
    OnExit = PanTastExit
    object EditTast: TEdit
      Left = 13
      Top = 26
      Width = 240
      Height = 39
      Cursor = crHandPoint
      AutoSelect = False
      AutoSize = False
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -28
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      MaxLength = 5
      ParentFont = False
      TabOrder = 12
      Text = '   '
    end
    object BtnTastCanc: TBitBtn
      Left = 98
      Top = 91
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = 'BtnTastCanc'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = BtnTastCancClick
    end
    object BtnTastSalva: TBitBtn
      Left = 13
      Top = 91
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = 'BtnTastSalva'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = BtnTastSalvaClick
    end
    object BuZero: TButton
      Left = 182
      Top = 169
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '0'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = BuTastieraClick
    end
    object BuUno: TButton
      Tag = 1
      Left = 267
      Top = 169
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '1'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = BuTastieraClick
    end
    object BuDue: TButton
      Tag = 2
      Left = 351
      Top = 169
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '2'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = BuTastieraClick
    end
    object BuTre: TButton
      Tag = 3
      Left = 436
      Top = 169
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '3'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = BuTastieraClick
    end
    object BuQuattro: TButton
      Tag = 4
      Left = 267
      Top = 91
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '4'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = BuTastieraClick
    end
    object BuCinque: TButton
      Tag = 5
      Left = 351
      Top = 91
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '5'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = BuTastieraClick
    end
    object BuSei: TButton
      Tag = 6
      Left = 436
      Top = 91
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '6'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      OnClick = BuTastieraClick
    end
    object BuSette: TButton
      Tag = 7
      Left = 267
      Top = 13
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '7'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = BuTastieraClick
    end
    object BuOtto: TButton
      Tag = 8
      Left = 351
      Top = 13
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '8'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
      OnClick = BuTastieraClick
    end
    object BuNove: TButton
      Tag = 9
      Left = 436
      Top = 13
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '9'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 11
      OnClick = BuTastieraClick
    end
    object BuPoint: TButton
      Left = 182
      Top = 91
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = ','
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 13
      OnClick = BuTastieraClick
    end
    object BtnTastExit: TBitBtn
      Left = 13
      Top = 169
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = 'BtnTastExit'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 14
      OnClick = BtnTastExitClick
    end
    object BtnPiuMeno: TButton
      Left = 98
      Top = 169
      Width = 72
      Height = 66
      Cursor = crHandPoint
      Caption = '-/+'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -32
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 15
      OnClick = BtnPiuMenoClick
    end
  end
  object EdtModifyDesc: TEdit
    Left = 202
    Top = 520
    Width = 85
    Height = 21
    TabOrder = 24
    Text = 'EdtModifyDesc'
    OnKeyPress = EdtModifyDescKeyPress
  end
  object BuPrint: TBitBtn
    Left = 20
    Top = 579
    Width = 52
    Height = 52
    Caption = 'BuPrint'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 25
    OnClick = BuPrintClick
  end
  object GBUnita: TGroupBox
    Left = 514
    Top = 195
    Width = 501
    Height = 501
    Caption = 'GBUnita'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 23
    Visible = False
    object BtnUnitaA: TBitBtn
      Left = 39
      Top = 20
      Width = 235
      Height = 52
      Caption = 'BtnUnitaA'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Visible = False
      OnClick = BtnUnitaAClick
    end
    object BtnUnitaB: TBitBtn
      Left = 39
      Top = 79
      Width = 235
      Height = 52
      Caption = 'BtnUnitaB'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = BtnUnitaBClick
    end
    object BtnUnitaC: TBitBtn
      Left = 39
      Top = 137
      Width = 235
      Height = 52
      Caption = 'BtnUnitaC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnClick = BtnUnitaCClick
    end
    object BtnUnitaD: TBitBtn
      Left = 39
      Top = 196
      Width = 235
      Height = 52
      Caption = 'BtnUnitaD'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Visible = False
      OnClick = BtnUnitaDClick
    end
    object BtnUnitaE: TBitBtn
      Left = 39
      Top = 254
      Width = 235
      Height = 52
      Caption = 'BtnUnitaE'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Visible = False
      OnClick = BtnUnitaEClick
    end
    object BtnUnitaF: TBitBtn
      Left = 39
      Top = 313
      Width = 235
      Height = 52
      Caption = 'BtnUnitaF'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      Visible = False
      OnClick = BtnUnitaFClick
    end
    object BtnUnitaG: TBitBtn
      Left = 39
      Top = 371
      Width = 235
      Height = 52
      Caption = 'BtnUnitaG'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      Visible = False
      OnClick = BtnUnitaGClick
    end
    object BtnUnitaH: TBitBtn
      Left = 39
      Top = 430
      Width = 235
      Height = 52
      Caption = 'BtnUnitaH'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      Visible = False
      OnClick = BtnUnitaHClick
    end
    object BtnGbUnitaEsci: TBitBtn
      Left = 358
      Top = 390
      Width = 98
      Height = 85
      Cursor = crHandPoint
      Caption = 'BtnGbUnitaEsci'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      OnClick = BtnGbUnitaEsciClick
    end
  end
  object TimButton: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TimButtonTimer
    Left = 96
    Top = 640
  end
end
