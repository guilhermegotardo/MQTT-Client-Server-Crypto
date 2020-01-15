//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainServer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	int result;
	sockResult = NULL;
	ptr = NULL;
	Form2->textBoxDebug->Text = "construtor";
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

	ListenSocket = INVALID_SOCKET;
}
//---------------------------------------------------------------------------
TForm2::~TForm2()
{
	closesocket(ListenSocket);
	WSACleanup();
	delete ptr;
    delete sockResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::BtOnClick(TObject *Sender)
{
int result;

	result = getaddrinfo(NULL, "27015", &hints, &sockResult);
	if(result != 0)
	{
		WSACleanup();
		Application->Terminate();

	}

	else
	{
		ListenSocket = socket(sockResult->ai_family, sockResult->ai_socktype, sockResult->ai_protocol);
	}

	result = bind( ListenSocket, sockResult->ai_addr, (int)sockResult->ai_addrlen);

	if (result == SOCKET_ERROR)
	{
		freeaddrinfo(sockResult);
		closesocket(ListenSocket);
		WSACleanup();
		Application->Terminate();
	}
	else
	{
		Form2->textBoxDebug->Text = result;
		freeaddrinfo(sockResult);
	}

	result = listen( ListenSocket, SOMAXCONN );

	if (result == SOCKET_ERROR)
	{
		freeaddrinfo(sockResult);
		closesocket(ListenSocket);
		WSACleanup();
		Application->Terminate();
	}

	Form2->textBoxStatus->Text = "Server Online";
}
//---------------------------------------------------------------------------


