//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainClient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	int result;
	sockResult = NULL;
	ptr = NULL;
	Form1->LabelTitle->Caption = "construtor";
	result = WSAStartup(MAKEWORD(2,2), &wsaData);

	if(result != 0)
	{
		 Application->Terminate();
	}

	else
	{
		ZeroMemory( &hints, sizeof(hints) );
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
	}
	ConnectSocket = INVALID_SOCKET;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtOkClick(TObject *Sender)
{
int result;

	Form1->LabelTitle->Caption = "teste";

	result = getaddrinfo(NULL, "27015", &hints, &sockResult);
	if(result != 0)
	{
		Application->Terminate();
	}

	else
	{
	   ptr=sockResult;
       ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
	ptr->ai_protocol);
	}

	if (ConnectSocket == INVALID_SOCKET)
	{
		freeaddrinfo(sockResult);
		WSACleanup();
		Application->Terminate();
	}
	Form1->TextBoxDebug->Text = "Socket Online";


}
//---------------------------------------------------------------------------


