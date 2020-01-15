//---------------------------------------------------------------------------

#ifndef mainClientH
#define mainClientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelTitle;
	TButton *BtOk;
	TEdit *TextBoxIP;
	TEdit *TextBoxPort;
	TEdit *TextBoxConnect;
	TEdit *TextBoxDebug;
	void __fastcall BtOkClick(TObject *Sender);



private:	// User declarations

public:
	__fastcall TForm1(TComponent* Owner);
	__fastcall ~TForm1();
	WSADATA wsaData;
	struct addrinfo *sockResult = {},
				*ptr = {},
				hints = {};
	SOCKET ConnectSocket;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
