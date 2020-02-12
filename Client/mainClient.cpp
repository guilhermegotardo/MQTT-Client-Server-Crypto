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

	result = clientSock.initSocket();

	if(result == SOCK_INITIALIZED)
	{
		Application->NormalizeTopMosts();
		Application->MessageBox(L"Error! Socket Initialized.", L"Error",  MB_OK );
		Application->RestoreTopMosts();
		result = false;
	}

	else if(result == SOCK_INVALID)
	{
		Application->NormalizeTopMosts();
		Application->MessageBox(L"Error! Invalid socket.", L"Error",  MB_OK );
		Application->RestoreTopMosts();
		result = false;
	}

	else
	{
		result = true;
	}

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
	iPAddress = new char[sizeof ipNumber];
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
	delete	ipNumber;
	delete  iPAddress;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BtSendMClick(TObject *Sender)
{
int result;
char sendbuf[8] = "Teste01";


	result = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
	if (result == SOCKET_ERROR)
	{
		closesocket(ConnectSocket);
		WSACleanup();
		Application->Terminate();
	}

	result = shutdown(ConnectSocket, SD_SEND);

	if (result == SOCKET_ERROR)
	{
		closesocket(ConnectSocket);
		WSACleanup();
		Application->Terminate();
	}

	Form1->TextBoxDebug->Text = "Aplicacao Finalizada!";
}
//---------------------------------------------------------------------------

