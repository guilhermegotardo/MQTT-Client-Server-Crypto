//---------------------------------------------------------------------------

#pragma hdrstop

#include "SockComm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


__fastcall 	SockComm::SockComm()
{
	sockInitialized = SOCK_N_INITIALIZED;
}

__fastcall  SockComm::~SockComm()
{

}
__fastcall int SockComm::initSocket()
{
int result;
	sockResult = NULL;
	ptr = NULL;
	result = WSAStartup(MAKEWORD(2,2), &wsaData);

	if(sockInitialized == SOCK_INITIALIZED)
	{
		result = SOCK_INITIALIZED;
	}

	else if(result != 0)
	{
		sockInitialized = false;
		result = SOCK_INVALID;
	}

	else
	{
		ZeroMemory(&hints, sizeof(hints) );
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		sockInitialized = true;

		result = SOCK_OK;
	}

	ConnectSocket = INVALID_SOCKET;

	return result;
}


__fastcall	int SockComm::restartSocket()
{

}

__fastcall	int SockComm::closeSocket()
{

}

__fastcall	int SockComm::deleteSocket()
{

}

__fastcall	int SockComm::connectToServer()
{


}

__fastcall	int SockComm::disconnectServer()
{

}

