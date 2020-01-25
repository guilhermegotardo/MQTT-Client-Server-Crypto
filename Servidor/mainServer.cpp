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
char recvbuf[512];
int recvbuflen = 512;
sockaddr_in service;
AnsiString *recText;


	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (ListenSocket == INVALID_SOCKET) {
		WSACleanup();
		Application->Terminate();
	}

	service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);

	result = bind( ListenSocket, (SOCKADDR*)&service, sizeof(service));

	if (result == SOCKET_ERROR)
	{
		closesocket(ListenSocket);
		WSACleanup();
		Application->Terminate();
	}

	result = listen( ListenSocket, SOMAXCONN );

	if (result == SOCKET_ERROR)
	{
		closesocket(ListenSocket);
		WSACleanup();
		Application->Terminate();
	}

	while(1)
	{
		AcceptSocket = accept(ListenSocket, NULL, NULL);
		if (AcceptSocket > 0)
		{
			Form2->textBoxStatus->Text = "Conectado ao cliente";
			break;
		}

	}

	do
	{
		result = recv(AcceptSocket, recvbuf, recvbuflen, 0);

		if ( result > 0 )
		{
			Form2->textBoxDebug->Text = recvbuf;
		}

	} while( result > 0 );


}
//---------------------------------------------------------------------------


