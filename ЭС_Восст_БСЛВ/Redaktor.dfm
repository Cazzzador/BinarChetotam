object Form2: TForm2
  Left = 140
  Top = 128
  Width = 517
  Height = 405
  Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1073#1072#1079' '#1079#1085#1072#1085#1080#1081
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 509
    Height = 2
    Align = alTop
    Shape = bsTopLine
  end
  object Bevel2: TBevel
    Left = 0
    Top = 34
    Width = 509
    Height = 2
    Align = alTop
    Shape = bsTopLine
  end
  object Memo1: TMemo
    Left = 0
    Top = 36
    Width = 509
    Height = 304
    Align = alClient
    PopupMenu = PopupMenu2
    ScrollBars = ssBoth
    TabOrder = 0
    OnChange = Memo1Change
  end
  object Panel1: TPanel
    Left = 0
    Top = 2
    Width = 509
    Height = 32
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object SpeedButton6: TSpeedButton
      Left = 5
      Top = 3
      Width = 25
      Height = 25
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1099#1081' '#1092#1072#1081#1083
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033333333B333
        333B33FF33337F3333F73BB3777BB7777BB3377FFFF77FFFF77333B000000000
        0B3333777777777777333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333337F33333337F333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333FF7F33333337FFFBBB0FFFFFFFF0BB37777F3333333777F3BB0FFFFFFFF
        0BBB3777F3333FFF77773330FFFF000003333337F333777773333330FFFF0FF0
        33333337F3337F37F3333330FFFF0F0B33333337F3337F77FF333330FFFF003B
        B3333337FFFF77377FF333B000000333BB33337777777F3377FF3BB3333BB333
        3BB33773333773333773B333333B3333333B7333333733333337}
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton6Click
    end
    object SpeedButton5: TSpeedButton
      Left = 30
      Top = 3
      Width = 25
      Height = 25
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033333333B333
        333B33FF33337F3333F73BB3777BB7777BB3377FFFF77FFFF77333B000000000
        0B3333777777777777333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333337F3FF3FFF7F333330F00F000F07333337F77377737F333330FFFFFFFF
        07333FF7F3FFFF3F7FFFBBB0F0000F0F0BB37777F7777373777F3BB0FFFFFFFF
        0BBB3777F3FF3FFF77773330F00F000003333337F773777773333330FFFF0FF0
        33333337F3FF7F37F3333330F08F0F0B33333337F7737F77FF333330FFFF003B
        B3333337FFFF77377FF333B000000333BB33337777777F3377FF3BB3333BB333
        3BB33773333773333773B333333B3333333B7333333733333337}
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton5Click
    end
    object SpeedButton4: TSpeedButton
      Left = 55
      Top = 3
      Width = 25
      Height = 25
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333330070
        7700333333337777777733333333008088003333333377F73377333333330088
        88003333333377FFFF7733333333000000003FFFFFFF77777777000000000000
        000077777777777777770FFFFFFF0FFFFFF07F3333337F3333370FFFFFFF0FFF
        FFF07F3FF3FF7FFFFFF70F00F0080CCC9CC07F773773777777770FFFFFFFF039
        99337F3FFFF3F7F777F30F0000F0F09999937F7777373777777F0FFFFFFFF999
        99997F3FF3FFF77777770F00F000003999337F773777773777F30FFFF0FF0339
        99337F3FF7F3733777F30F08F0F0337999337F7737F73F7777330FFFF0039999
        93337FFFF7737777733300000033333333337777773333333333}
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton4Click
    end
    object SpeedButton1: TSpeedButton
      Left = 160
      Top = 3
      Width = 25
      Height = 25
      Caption = #1046
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 185
      Top = 3
      Width = 25
      Height = 25
      Caption = #1050
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      OnClick = SpeedButton2Click
    end
    object SpeedButton3: TSpeedButton
      Left = 210
      Top = 3
      Width = 25
      Height = 25
      Caption = #1063
      Flat = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold, fsUnderline]
      ParentFont = False
      OnClick = SpeedButton3Click
    end
    object SpeedButton8: TSpeedButton
      Left = 325
      Top = 3
      Width = 25
      Height = 25
      Hint = #1055#1077#1095#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00300000000000
        00033FFFFFFFFFFFFFFF0888888888888880777777777777777F088888888888
        8880777777777777777F0000000000000000FFFFFFFFFFFFFFFF0F8F8F8F8F8F
        8F80777777777777777F08F8F8F8F8F8F9F0777777777777777F0F8F8F8F8F8F
        8F807777777777777F7F0000000000000000777777777777777F3330FFFFFFFF
        03333337F3FFFF3F7F333330F0000F0F03333337F77773737F333330FFFFFFFF
        03333337F3FF3FFF7F333330F00F000003333337F773777773333330FFFF0FF0
        33333337F3FF7F3733333330F08F0F0333333337F7737F7333333330FFFF0033
        33333337FFFF7733333333300000033333333337777773333333}
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton8Click
    end
    object SpeedButton7: TSpeedButton
      Left = 350
      Top = 3
      Width = 25
      Height = 25
      Hint = #1055#1086#1084#1086#1097#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333FFFFF3333333333F797F3333333333F737373FF333333BFB999BFB
        33333337737773773F3333BFBF797FBFB33333733337333373F33BFBFBFBFBFB
        FB3337F33333F33337F33FBFBFB9BFBFBF3337333337F333373FFBFBFBF97BFB
        FBF37F333337FF33337FBFBFBFB99FBFBFB37F3333377FF3337FFBFBFBFB99FB
        FBF37F33333377FF337FBFBF77BF799FBFB37F333FF3377F337FFBFB99FB799B
        FBF373F377F3377F33733FBF997F799FBF3337F377FFF77337F33BFBF99999FB
        FB33373F37777733373333BFBF999FBFB3333373FF77733F7333333BFBFBFBFB
        3333333773FFFF77333333333FBFBF3333333333377777333333}
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 340
    Width = 509
    Height = 19
    Panels = <
      item
        Text = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1090#1088#1086#1082
        Width = 100
      end
      item
        Width = 25
      end
      item
        Text = #1044#1083#1080#1085#1072' '#1090#1077#1082#1089#1090#1072
        Width = 83
      end
      item
        Width = 35
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'txt'
    Filter = '*.txt|*.txt'
    Left = 64
    Top = 64
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 64
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1090#1100
        ShortCut = 16462
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        ShortCut = 16463
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        ShortCut = 16467
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100
        ShortCut = 16464
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1087#1077#1095#1072#1090#1080
        OnClick = N7Click
      end
      object N9: TMenuItem
        Caption = '-'
      end
      object N8: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        ShortCut = 49240
        OnClick = N8Click
      end
    end
    object N10: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N11: TMenuItem
        Caption = #1054#1090#1084#1077#1085#1080#1090#1100
        ShortCut = 16474
        OnClick = N11Click
      end
      object N12: TMenuItem
        Caption = #1042#1099#1088#1077#1079#1072#1090#1100
        ShortCut = 16472
        OnClick = N12Click
      end
      object N13: TMenuItem
        Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
        ShortCut = 16451
        OnClick = N13Click
      end
      object N14: TMenuItem
        Caption = #1042#1089#1090#1072#1074#1080#1090#1100
        ShortCut = 16470
        OnClick = N14Click
      end
      object N15: TMenuItem
        Caption = #1042#1099#1076#1077#1083#1080#1090#1100' '#1074#1089#1105
        ShortCut = 16449
        OnClick = N15Click
      end
      object N16: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1076#1077#1083#1077#1085#1085#1086#1077
        ShortCut = 16430
        OnClick = N16Click
      end
      object N17: TMenuItem
        Caption = '-'
      end
      object N18: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1074#1089#1105
        OnClick = N18Click
      end
    end
    object N19: TMenuItem
      Caption = #1060#1086#1088#1084#1072#1090
      object N20: TMenuItem
        Caption = #1064#1088#1080#1092#1090
        OnClick = N20Click
      end
      object N21: TMenuItem
        Caption = #1060#1086#1085
        OnClick = N21Click
      end
    end
    object N22: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N23: TMenuItem
        Caption = #1055#1086#1084#1086#1097#1100
        ShortCut = 112
        OnClick = N23Click
      end
      object N24: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = N24Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'txt'
    Filter = '*.txt|*.txt'
    Left = 112
    Top = 64
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 160
    Top = 64
  end
  object PrintDialog1: TPrintDialog
    Left = 208
    Top = 64
  end
  object PrinterSetupDialog1: TPrinterSetupDialog
    Left = 256
    Top = 64
  end
  object PopupMenu1: TPopupMenu
    Left = 304
    Top = 64
    object MenuItem1: TMenuItem
      Caption = #1057#1086#1079#1076#1072#1090#1100
      OnClick = N2Click
    end
    object MenuItem2: TMenuItem
      Caption = #1054#1090#1082#1088#1099#1090#1100
      OnClick = N3Click
    end
    object N28: TMenuItem
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      OnClick = N4Click
    end
    object MenuItem3: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N8Click
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 352
    Top = 64
    object N29: TMenuItem
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      OnClick = N11Click
    end
    object N30: TMenuItem
      Caption = #1042#1099#1088#1077#1079#1072#1090#1100
      OnClick = N12Click
    end
    object N31: TMenuItem
      Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
      OnClick = N13Click
    end
    object N32: TMenuItem
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100
      OnClick = N14Click
    end
  end
end
