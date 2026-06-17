object FTastiera: TFTastiera
  Left = 205
  Top = 191
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = []
  BorderStyle = bsNone
  ClientHeight = 338
  ClientWidth = 782
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object PanTastiera: TPanel
    Left = 0
    Top = 102
    Width = 782
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
      Left = 83
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuW: TButton
      Left = 152
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuE: TButton
      Left = 222
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuR: TButton
      Left = 291
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuT: TButton
      Left = 361
      Top = 16
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'T'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = BuTastClick
    end
    object BuY: TButton
      Left = 430
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuU: TButton
      Left = 500
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuI: TButton
      Left = 569
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuO: TButton
      Left = 639
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuP: TButton
      Left = 708
      Top = 16
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
      OnClick = BuTastClick
    end
    object BuA: TButton
      Left = 83
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuS: TButton
      Left = 152
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuD: TButton
      Left = 222
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuF: TButton
      Left = 291
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuG: TButton
      Left = 361
      Top = 86
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'G'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 14
      OnClick = BuTastClick
    end
    object BuH: TButton
      Left = 430
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuJ: TButton
      Left = 500
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuK: TButton
      Left = 569
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuL: TButton
      Left = 639
      Top = 86
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
      OnClick = BuTastClick
    end
    object BuZ: TButton
      Left = 83
      Top = 155
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
      OnClick = BuTastClick
    end
    object BuX: TButton
      Left = 152
      Top = 155
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
      OnClick = BuTastClick
    end
    object BuC: TButton
      Left = 222
      Top = 155
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
      OnClick = BuTastClick
    end
    object BuSpace: TButton
      Left = 361
      Top = 155
      Width = 128
      Height = 60
      Cursor = crHandPoint
      Caption = 'Space'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 22
      OnClick = BuSpaceClick
    end
    object BuV: TButton
      Left = 291
      Top = 155
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
      TabOrder = 23
      OnClick = BuTastClick
    end
    object BuB: TButton
      Left = 500
      Top = 155
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
      TabOrder = 24
      OnClick = BuTastClick
    end
    object BuN: TButton
      Left = 569
      Top = 155
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
      TabOrder = 25
      OnClick = BuTastClick
    end
    object BuM: TButton
      Left = 639
      Top = 155
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
      TabOrder = 26
      OnClick = BuTastClick
    end
    object BuESC: TButton
      Left = 13
      Top = 16
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'ESC'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 27
      OnClick = BuESCClick
    end
    object BuDEL: TButton
      Left = 13
      Top = 85
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Caption = 'DEL'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 28
      OnClick = BuDELClick
    end
    object BtnOK: TBitBtn
      Left = 709
      Top = 86
      Width = 60
      Height = 131
      Cursor = crHandPoint
      Caption = 'Ok'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 29
      OnClick = BtnOKClick
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      Layout = blGlyphTop
      NumGlyphs = 2
    end
    object BtnCapsLock: TBitBtn
      Left = 13
      Top = 155
      Width = 60
      Height = 60
      Cursor = crHandPoint
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 30
      OnClick = BtnCapsLockClick
      Glyph.Data = {
        0A030000424D0A03000000000000760000002800000024000000210000000100
        0400000000009402000000000000000000001000000010000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000FFFFFFF0000000000000FFFFFFFFFFFFFFFF0000FFFFF000000000000000
        00FFFFFFFFFFFFFF0000FFFFF00FFFFFFFFFFFFF00FFFFFFFFFFFFFF0000FFFF
        00FFFFFFF0FFFFFFF00FFFFFFFFFFFFF0000FFFF00FFFFFFF0FFFFFFF00FFFFF
        FFFFFFFF0000FFF00FFFFFFFF0FFFFFFFF00FFFFFFFFFFFF0000FFF00FFFFF0F
        F0FF0FFFFF00FFFFFFFFFFFF0000FFF00FFFFF00F0F00FFFFF00FFFFFFFFFFFF
        0000FFF00FFFFFF00000FFFFFF00FFFFFFFFFFFF0000FFF00FFFFFFF000FFFFF
        FF00FFFFFFFFFFFF0000FFF00FFFFFFFF0FFFFFFFF00FFFFFFFFFFFF0000FFF0
        0FFFFFFFFFFFFFFFFF00FFFFFFFFFFFF0000FFF00FFFFFFFFFFFFFFFFF00FFFF
        FFFFFFFF0000FF00000000000000000000000FFFFFFFFFFF0000FF0000000000
        0000000000000FFFFFFFFFFF0000FFFF00F0FFFFFFFFFFF0F00FFFFFFFFFFFFF
        0000FFFF00F0FFFFFFFFFFF0F00FFFFFFFFFFFFF0000FFFF00F0FFFFFFFFFFF0
        F00FFFFFFFFFFFFF0000FFFF00F0FFFFFFFFFFF0F00FFFFFFFFFFFFF0000FFFF
        F00F0FFFFFFFFF0F00FFFFFFFFFFFFFF0000FFFFF00F0FFFFFFFFF0F00FFFFFF
        FFFFFFFF0000FFFFF00F0FFFFFFFFF0F00FFFFFFFFFFFFFF0000FFFFFF00F0FF
        FFFFF0FF0FFFFFFFFFFFFFFF0000FFFFFF00F0FFFFFFF0F00FFFFFFFFFFFFFFF
        0000FFFFFFF00F0000000F00FFFFFFFFFFFFFFFF0000FFFFFFFF00FFFFFFF00F
        FFFFFFFFFFFFFFFF0000FFFFFFFFF000000000FFFFFFFFFFFFFFFFFF0000FFFF
        FFFFFF0000000FFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFF0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFF0000}
      Layout = blGlyphBottom
    end
    object PLedCapsLock: TPanel
      Left = 55
      Top = 162
      Width = 11
      Height = 12
      BevelInner = bvRaised
      Color = clGray
      TabOrder = 31
    end
  end
  object PanEdit: TPanel
    Left = 0
    Top = 0
    Width = 782
    Height = 102
    Align = alTop
    BevelInner = bvLowered
    BevelWidth = 2
    Color = clNavy
    TabOrder = 1
    object EditText: TEdit
      Left = 239
      Top = 44
      Width = 282
      Height = 37
      AutoSelect = False
      AutoSize = False
      Color = clWhite
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Courier New'
      Font.Style = [fsBold]
      MaxLength = 15
      ParentFont = False
      PasswordChar = '*'
      TabOrder = 0
      Text = 'EditText'
      OnKeyPress = EditTextKeyPress
    end
  end
end
