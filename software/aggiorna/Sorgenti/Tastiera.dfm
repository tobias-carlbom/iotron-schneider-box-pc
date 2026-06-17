object FormTastiera: TFormTastiera
  Left = 222
  Top = 300
  BorderStyle = bsNone
  ClientHeight = 221
  ClientWidth = 714
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object PanTastiera: TPanel
    Left = 0
    Top = 0
    Width = 714
    Height = 235
    Align = alTop
    BevelInner = bvLowered
    BevelWidth = 2
    Color = clNavy
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object BuQ: TButton
      Left = 441
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'Q'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = BuQClick
    end
    object BuW: TButton
      Left = 577
      Top = 152
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'W'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = BuQClick
    end
    object BuE: TButton
      Left = 302
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'E'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = BuQClick
    end
    object BuR: TButton
      Left = 510
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'R'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = BuQClick
    end
    object BuT: TButton
      Left = 19
      Top = 152
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'T'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = BuQClick
    end
    object BuY: TButton
      Left = 510
      Top = 152
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'Y'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = BuQClick
    end
    object BuU: TButton
      Left = 88
      Top = 152
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'U'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = BuQClick
    end
    object BuI: TButton
      Left = 577
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'I'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = BuQClick
    end
    object BuO: TButton
      Left = 302
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'O'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      OnClick = BuQClick
    end
    object BuP: TButton
      Left = 371
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'P'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = BuQClick
    end
    object BuA: TButton
      Left = 19
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'A'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
      OnClick = BuQClick
    end
    object BuS: TButton
      Left = 577
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'S'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 11
      OnClick = BuQClick
    end
    object BuD: TButton
      Left = 230
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'D'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 12
      OnClick = BuQClick
    end
    object BuF: TButton
      Left = 371
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'F'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 13
      OnClick = BuQClick
    end
    object BuG: TButton
      Left = 441
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'G'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 14
      OnClick = BuQClick
    end
    object BuH: TButton
      Left = 510
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'H'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 15
      OnClick = BuQClick
    end
    object BuJ: TButton
      Left = 644
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'J'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 16
      OnClick = BuQClick
    end
    object BuK: TButton
      Left = 19
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'K'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 17
      OnClick = BuQClick
    end
    object BuL: TButton
      Left = 88
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'L'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 18
      OnClick = BuQClick
    end
    object BuZ: TButton
      Left = 230
      Top = 152
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'Z'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 19
      OnClick = BuQClick
    end
    object BuX: TButton
      Left = 441
      Top = 152
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'X'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 20
      OnClick = BuQClick
    end
    object BuC: TButton
      Left = 158
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'C'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 21
      OnClick = BuQClick
    end
    object BuV: TButton
      Left = 158
      Top = 152
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'V'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 22
      OnClick = BuQClick
    end
    object BuB: TButton
      Left = 88
      Top = 14
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'B'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 23
      OnClick = BuQClick
    end
    object BuN: TButton
      Left = 230
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'N'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 24
      OnClick = BuQClick
    end
    object BuM: TButton
      Left = 158
      Top = 83
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'M'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 25
      OnClick = BuQClick
    end
    object BtnCancel: TBitBtn
      Left = 645
      Top = 83
      Width = 60
      Height = 131
      Cursor = crHandPoint
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 26
      OnClick = BtnCancelClick
      Kind = bkCancel
      Layout = blGlyphTop
    end
  end
end
