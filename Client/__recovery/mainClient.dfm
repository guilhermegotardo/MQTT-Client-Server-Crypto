object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 231
  ClientWidth = 505
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelTitle: TLabel
    Left = 192
    Top = 8
    Width = 90
    Height = 18
    Caption = 'Cliente MQTT'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object BtOk: TButton
    Left = 64
    Top = 144
    Width = 49
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = BtOkClick
  end
  object TextBoxIP: TEdit
    Left = 64
    Top = 104
    Width = 73
    Height = 21
    TabOrder = 1
    Text = '127.0.0.1'
  end
  object TextBoxConnect: TEdit
    Left = 64
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Disconnected'
  end
  object TextBoxDebug: TEdit
    Left = 344
    Top = 202
    Width = 161
    Height = 21
    TabOrder = 3
    Text = 'Socket Offline'
  end
  object TextBoxPort: TEdit
    Left = 216
    Top = 104
    Width = 41
    Height = 21
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    Text = '27015'
  end
end