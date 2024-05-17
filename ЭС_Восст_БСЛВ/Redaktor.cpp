//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Redaktor.h"
#include "Main.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
bool flag1=false, flag2=false, flag3=false;
int i=0;
bool flagclosered=false;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N2Click(TObject *Sender)
{
 if (Memo1->Modified)
   {
    int res = Application->MessageBoxA("Текущий файл изменён. Сохранить изменения?",
      "Сообщение программы", MB_YESNOCANCEL | MB_ICONWARNING);
    if (res == IDYES) SpeedButton4Click(Sender);
    if (res == IDCANCEL) return;
   }
 if (Memo1->Lines->Count > 0) Memo1->Clear();
 Form2->Memo1->Visible = true;
 SaveDialog1->FileName = " ";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender)
{
 if (Memo1->Modified)
   {
    int res = Application->MessageBoxA("Текущий файл изменён. Сохранить изменения?",
      "Сообщение программы", MB_YESNOCANCEL | MB_ICONWARNING);
    if (res == IDYES) SpeedButton4Click(Sender);
    if (res == IDCANCEL) return;
   }
 OpenDialog1->FileName = " ";
 if (OpenDialog1->Execute())
   {
    if (Memo1->Lines->Count > 0) Memo1->Clear();
    Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
    SaveDialog1->FileName = OpenDialog1->FileName;
   }
 Form2->Memo1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N4Click(TObject *Sender)
{
 if (SaveDialog1->FileName != " ")
   {
    Memo1->Lines->SaveToFile(SaveDialog1->FileName);
    Memo1->Modified = false;
   }
 else Form2->N5Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N5Click(TObject *Sender)
{
 SaveDialog1->Title = "Сохранить как";
 if (SaveDialog1->Execute())
   {
    Memo1->Lines->SaveToFile(SaveDialog1->FileName);
    Memo1->Modified = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N6Click(TObject *Sender)
{
 if (PrintDialog1->Execute())
   {
    Printer()->BeginDoc();
    Memo1->PaintTo(Printer()->Handle, 10, 10);
    Printer()->EndDoc();
   };
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N7Click(TObject *Sender)
{
 if (PrinterSetupDialog1->Execute());
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N8Click(TObject *Sender)
{
 if (Memo1->Modified)
   {
    int res = Application->MessageBoxA("Текущий файл изменён. Сохранить изменения?",
      "Сообщение программы", MB_YESNOCANCEL | MB_ICONWARNING);
    if (res == IDYES) SpeedButton4Click(Sender);
    if (res == IDCANCEL) return;
   }
 flagclosered = true;
// if (Form3->Action) Form3->Close();
 Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton6Click(TObject *Sender)
{
 N2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton5Click(TObject *Sender)
{
 N3->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton4Click(TObject *Sender)
{
 N4->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N11Click(TObject *Sender)
{
 SendMessage(Memo1->Handle, WM_UNDO, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N12Click(TObject *Sender)
{
 Memo1->CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N13Click(TObject *Sender)
{
 Memo1->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N14Click(TObject *Sender)
{
 Memo1->PasteFromClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N15Click(TObject *Sender)
{
 Memo1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N16Click(TObject *Sender)
{
 Memo1->ClearSelection();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N18Click(TObject *Sender)
{
 Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N20Click(TObject *Sender)
{
 if (FontDialog1->Execute())
   Form2->Memo1->Font = FontDialog1->Font;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N21Click(TObject *Sender)
{
 TColor fonflag;
 i=i+1;
 if (i==1) fonflag=clBlack;
 else if (i==2) fonflag=clBlue;
 else if (i==3) fonflag=clRed;
 else if (i==4) fonflag=clGreen;
 else if (i==5) fonflag=clYellow;
 else
   {
    i=0;
    fonflag=clWhite;
   }
 Memo1->Color = fonflag;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton1Click(TObject *Sender)
{
 if (!flag1&&!flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold;
    flag1=true;
   }
 else if (!flag1&&flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsItalic;
    flag1=true;
   }
 else if (!flag1&&!flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsUnderline;
    flag1=true;
   }
 else if (!flag1&&flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsItalic << fsUnderline;
    flag1=true;
   }
 else if (flag1&&flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsItalic << fsUnderline;
    flag1=false;
   }
 else if (flag1&&flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsItalic;
    flag1=false;
   }
 else if (flag1&&!flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsUnderline;
    flag1=false;
   }
 else
   {
    Memo1->Font->Style = TFontStyles();
    flag1=false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SpeedButton2Click(TObject *Sender)
{
 if (!flag1&&!flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsItalic;
    flag2=true;
   }
 else if (flag1&&!flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsItalic;
    flag2=true;
   }
 else if (!flag1&&!flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsItalic << fsUnderline;
    flag2=true;
   }
 else if (flag1&&!flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsItalic << fsUnderline;
    flag2=true;
   }
 else if (flag1&&flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsUnderline;
    flag2=false;
   }
 else if (flag1&&flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold;
    flag2=false;
   }
 else if (!flag1&&flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsUnderline;
    flag2=false;
   }
 else
   {
    Memo1->Font->Style = TFontStyles();
    flag2=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton3Click(TObject *Sender)
{
 if (!flag1&&!flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsUnderline;
    flag3=true;
   }
 else if (flag1&&!flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsUnderline;
    flag3=true;
   }
 else if (!flag1&&flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsItalic << fsUnderline;
    flag3=true;
   }
 else if (flag1&&flag2&&!flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold << fsItalic << fsUnderline;
    flag3=true;
   }
 else if (flag1&&flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsItalic << fsBold;
    flag3=false;
   }
 else if (!flag1&&flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsItalic;
    flag3=false;
   }
 else if (flag1&&!flag2&&flag3)
   {
    Memo1->Font->Style = TFontStyles()<< fsBold;
    flag3=false;
   }
 else
   {
    Memo1->Font->Style = TFontStyles();
    flag3=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton8Click(TObject *Sender)
{
 if (PrintDialog1->Execute())
   {
    Printer()->BeginDoc();
    Memo1->PaintTo(Printer()->Handle, 10, 10);
    Printer()->EndDoc();
   };
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
 if (flagclosered==false)
   {
    if (Memo1->Modified)
      {
       int res = Application->MessageBoxA("Текущий файл изменён. Сохранить изменения?",
         "Сообщение программы", MB_YESNO | MB_ICONWARNING);
       if (res == IDYES) N4->Click();
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Memo1Change(TObject *Sender)
{
 Form2->StatusBar1->Panels->operator [](1)->Text = Form2->Memo1->Lines->Count;
 Form2->StatusBar1->Panels->operator [](3)->Text = Form2->Memo1->GetTextLen();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
 Memo1->Lines->Clear();
 if (Form1->Memo2->Lines->Count!=0) Form1->StopBase();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N24Click(TObject *Sender)
{
 MessageDlg("Программа для создания и редактирования баз знаний", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N23Click(TObject *Sender)
{
 MessageDlg("Помощь в программе для создания и редактирования баз знаний будет реализована в последующих версиях!", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

