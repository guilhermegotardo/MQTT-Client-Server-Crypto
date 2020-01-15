//---------------------------------------------------------------------------

#ifndef mainServerH
#define mainServerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelTitle;
	TEdit *textBoxStatus;
	TButton *BtOn;
	TEdit *textBoxDebug;
	void __fastcall BtOnClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	__fastcall ~TForm2();
	WSADATA wsaData;
	struct addrinfo *sockResult = {},
				*ptr = {},
				hints = {};

	SOCKET ListenSocket;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
