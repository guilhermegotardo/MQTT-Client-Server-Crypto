//---------------------------------------------------------------------------

#ifndef mainClientH
#define mainClientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelTitle;
	TButton *BtOk;
	TEdit *TextBoxIP;
	TEdit *TextBoxPort;
	TEdit *TextBoxConnect;
	void __fastcall BtOkClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
