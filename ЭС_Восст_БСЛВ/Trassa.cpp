//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Trassa.h"
#include "Main.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm3 *Form3;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
 Form3->Close();
}
//---------------------------------------------------------------------------


