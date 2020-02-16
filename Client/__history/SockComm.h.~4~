//---------------------------------------------------------------------------

#ifndef SockCommH
#define SockCommH
//---------------------------------------------------------------------------
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string.h>

#define SOCK_N_INITIALIZED 0x01
#define SOCK_INITIALIZED 0x02
#define SOCK_INVALID 0x03
#define SOCK_OK 0x04

class SockComm
{
private:
	WSADATA wsaData;
	SOCKET ConnectSocket;
	struct addrinfo *sockResult = {},
					*ptr = {},
					hints = {};
	bool sockInitialized;

public:
	__fastcall SockComm();
	__fastcall ~SockComm();
	__fastcall int initSocket();
	__fastcall int restartSocket();
	__fastcall int closeSocket();
	__fastcall int deleteSocket();
	__fastcall int connectToServer();
	__fastcall int disconnectServer();
	__fastcall int sendMsgToServer();


};
