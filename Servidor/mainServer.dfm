object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 231
  ClientWidth = 505
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelTitle: TLabel
    Left = 240
    Top = 8
    Width = 45
    Height = 19
    Caption = 'Server'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object textBoxStatus: TEdit
    Left = 72
    Top = 32
    Width = 137
    Height = 21
    TabOrder = 0
    Text = 'Server Offline'
  end
  object BtOn: TButton
    Left = 72
    Top = 72
    Width = 49
    Height = 25
    Caption = 'Connect'
    TabOrder = 1
    OnClick = BtOnClick
  end
  object textBoxDebug: TEdit
    Left = 408
    Top = 202
    Width = 89
    Height = 21
    TabOrder = 2
    Text = 'Debug'
  end
end
