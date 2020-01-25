//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainClient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
	int result;
	sockResult = NULL;
	ptr = NULL;
	result = WSAStartup(MAKEWORD(2,2), &wsaData);


	if(result != 0)
	{
		 Application->Terminate();
	}

	else
	{
		ZeroMemory(&hints, sizeof(hints) );
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
	}
	ConnectSocket = INVALID_SOCKET;
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
	freeaddrinfo(sockResult);
	WSACleanup();
	delete ptr;
	delete sockResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtOkClick(TObject *Sender)
{
int result, portNmbInt = 0;
char *iPAddress;
sockaddr_in clientService;
AnsiString  *portNumber, *ipNumber;


	ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	portNumber = new AnsiString(Form1->TextBoxPort->Text);
	ipNumber = new AnsiString(Form1->TextBoxIP->Text);
	iPAddress = ipNumber->c_str();

	if (ConnectSocket == INVALID_SOCKET)
	{
		WSACleanup();
		Application->Terminate();
	}

	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr(iPAddress);
	clientService.sin_port = htons(portNumber->ToInt());

	result = connect( ConnectSocket,(SOCKADDR *)&clientService, sizeof(clientService) );

	if(result == SOCKET_ERROR)
	{
		WSACleanup();
		Application->Terminate();
	}

	Form1->TextBoxConnect->Text = "Connected";

	delete  portNumber;
}
//---------------------------------------------------------------------------


