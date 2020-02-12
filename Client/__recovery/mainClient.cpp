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

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtOkClick(TObject *Sender)
{
int result;

	result = clientSock.connectToServer(Form1->TextBoxPort->Text,Form1->TextBoxIP->Text);
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


//---------------------------------------------------------------------------

