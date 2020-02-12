//---------------------------------------------------------------------------

#ifndef mainClientH
#define mainClientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "SockComm.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string.h>


#define SOCK_N_INITIALIZED 0x01
#define SOCK_INITIALIZED 0x02
#define SOCK_INVALID 0x03
#define SOCK_OK 0x04



//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelTitle;
	TButton *BtOk;
	TEdit *TextBoxIP;
	TEdit *TextBoxConnect;
	TEdit *TextBoxDebug;
	TEdit *TextBoxPort;
	TEdit *TextBoxSendM;
	TButton *BtSendM;
	void __fastcall BtOkClick(TObject *Sender);
	void __fastcall BtSendMClick(TObject *Sender);


private:	// User declarations

public:
	__fastcall TForm1(TComponent* Owner);
	__fastcall ~TForm1();
	WSADATA wsaData;
	struct addrinfo *sockResult = {},
				*ptr = {},
				hints = {};
	SOCKET ConnectSocket;
    SockComm clientSock;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
