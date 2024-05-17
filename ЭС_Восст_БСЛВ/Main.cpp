//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <ctype.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include "Main.h"
#include "Trassa.h"
#include "Redaktor.h"
#include "About.h"
#include <excel_2k.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma link "CSPIN"

#define MaxIsh 100

using namespace std;

class CIshod
  {
   public:
     enum { MAX=1000 };
     int nomer;
     AnsiString name;
     float opr;
     float py[MAX];
     float pn[MAX];
  };

CIshod Ishod[MaxIsh];
CIshod temp;

TForm1 *Form1;
const MaxSv=1000;
bool flagclose=false;
int colstr, lenstr, w, q, vp=0;
float ku, pq, pa, pna;
float MatOpr[MaxSv][MaxIsh], VecKu[MaxSv];

int stepen(int kkk);

void TForm1::NewBase()
{
 Memo1->Lines->Clear();
 Memo2->Lines->Clear();
 Memo3->Lines->Clear();
 Memo4->Lines->Clear();
 Memo5->Lines->Clear();
 Memo6->Lines->Clear();
 vp=0;
 RadioButton1->Enabled=false;
 RadioButton2->Enabled=false;
 Edit1->Text="0";
 N13->Enabled=false;
 N16->Enabled=false;
 N15->Enabled=false;
 SpeedButton2->Enabled=false;
 N11->Enabled=true;
 Button1->Enabled=false;
 Edit1->Enabled=false;
 SpeedButton3->Enabled=false;
}

void TForm1::StopBase()
{
  NewBase();

    if (Form2->Memo1->Lines->Count > 0) Form2->Memo1->Clear();
    Form2->Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
    Form3->Memo1->Lines->Clear();
    Form3->Memo1->Lines->Add("��������� ��������� �����������:");
    colstr=Form2->Memo1->Lines->Count;  // ���������� ����� � ���� ������
    int i=0;
    while (Form2->Memo1->Lines->Strings[i]!="")
    {
     Memo5->Lines->Add(Form2->Memo1->Lines->Strings[i]);
     i++;
    }
    i++;
    w=-1;  /* ���������� ��������; -1 ��� ����,
              ����� �� ������� ������ "�������:" */
    while (Form2->Memo1->Lines->Strings[i]!="")
    {
     w++;
     Memo1->Lines->Add(Form2->Memo1->Lines->Strings[i]);
     i++;
    }
    i++;
    q=0; // ���������� ��������� �������
    while (Form2->Memo1->Lines->Strings[i]!="")
    {
     q++;
     lenstr=Form2->Memo1->Lines->Strings[i].Length();
     int j=1;
     AnsiString stroka="";
     Ishod[q-1].name="";
     while (Form2->Memo1->Lines->Strings[i][j]!=',')
     {
      Ishod[q-1].name+=Form2->Memo1->Lines->Strings[i][j];
      j++;
     }
     j++;

     bool flagz=true;
     int kk=0;
     stroka="";
     while (Form2->Memo1->Lines->Strings[i][j]!=',')
     {
      if (Form2->Memo1->Lines->Strings[i][j]==' ');
      else
        {
         stroka+=Form2->Memo1->Lines->Strings[i][j];
         kk++;
         if (Form2->Memo1->Lines->Strings[i][j]=='.')
           {
            flagz=false;
            stroka="";
            kk=0;
           }
        }
      j++;
     }
     Ishod[q-1].nomer=q;
     if (flagz) Ishod[q-1].opr=StrToFloat(stroka);
     else Ishod[q-1].opr=StrToFloat(stroka)/stepen(kk);
     flagz=true;
     MatOpr[0][q-1]=Ishod[q-1].opr;

     AnsiString nmemo; nmemo.printf("%.7f",Ishod[q-1].opr);
     Memo2->Lines->Add(" "+IntToStr(Ishod[q-1].nomer)+" "+Ishod[q-1].name+" (p="+nmemo+")");
     Form3->Memo1->Lines->Add(" "+IntToStr(Ishod[q-1].nomer)+" "+Ishod[q-1].name+" (p="+nmemo+")");

     for (int t=0; t<w; t++)
     {
      Ishod[q-1].py[t]=11;
      Ishod[q-1].pn[t]=11;
     }
     int tt=0;

     for (int t=0; t<w; t++)
     {
      stroka="";
      if (j>lenstr) break;
      else j++;
      if (j>lenstr) break;
      while (Form2->Memo1->Lines->Strings[i][j]!=',')
        {
         if (Form2->Memo1->Lines->Strings[i][j]==' ');
         else stroka+=Form2->Memo1->Lines->Strings[i][j];
         if (j>lenstr) break;
         else j++;
         if (j>lenstr) break;
        }
      tt=StrToInt(stroka);
      stroka="";
      if (j>lenstr) break;
      else j++;
      if (j>lenstr) break;
      kk=0;
      while (Form2->Memo1->Lines->Strings[i][j]!=',')
      {
       if (Form2->Memo1->Lines->Strings[i][j]==' ');
       else
         {
          stroka+=Form2->Memo1->Lines->Strings[i][j];
          kk++;
          if (Form2->Memo1->Lines->Strings[i][j]=='.')
           {
            flagz=false;
            stroka="";
            kk=0;
           }
         }
       if (j>lenstr) break;
       else j++;
       if (j>lenstr) break;
      }
      if (flagz) Ishod[q-1].py[tt-1]=StrToFloat(stroka);
      else Ishod[q-1].py[tt-1]=StrToFloat(stroka)/stepen(kk);
      flagz=true;

      stroka="";
      if (j>lenstr) break;
      else j++;
      if (j>lenstr) break;
      kk=0;
      while (Form2->Memo1->Lines->Strings[i][j]!=',')
      {
       if (Form2->Memo1->Lines->Strings[i][j]==' ');
       else
         {
          stroka+=Form2->Memo1->Lines->Strings[i][j];
          kk++;
          if (Form2->Memo1->Lines->Strings[i][j]=='.')
           {
            flagz=false;
            stroka="";
            kk=0;
           }
         }
       if (j>lenstr) break;
       else j++;
       if (j>lenstr) break;
      }
      if (flagz) Ishod[q-1].pn[tt-1]=StrToFloat(stroka);
      else Ishod[q-1].pn[tt-1]=StrToFloat(stroka)/stepen(kk);
      flagz=true;
     }

     i++;
    }
    N10->Enabled=true;
    SpeedButton1->Enabled=true;
    Form1->StatusBar1->Panels->operator [](1)->Text = IntToStr(w);
    Form1->StatusBar1->Panels->operator [](3)->Text = IntToStr(q);
    Button2->Enabled=true;
    N6->Enabled=true;
    SpeedButton4->Enabled=true;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
 Form2->Memo1->Lines->Clear();
 Form2->ShowModal();
}
//---------------------------------------------------------------------------

int stepen(int kkk)
{
 int step=1;
 for (int qq=1; qq<=kkk; qq++)
   step=step*10;
 return step;
}

void __fastcall TForm1::N5Click(TObject *Sender)
{
 if (Memo2->Modified)
   {
    int res = Application->MessageBoxA("������ ������������ � ������� ����� ������! ��������� �������� ������������?",
      "��������� ���������", MB_YESNOCANCEL | MB_ICONWARNING);
    if (res == IDYES)
      {
       N6->Click();
       NewBase();
      }
    if (res == IDNO) NewBase();
    if (res == IDCANCEL) return;
   }
 OpenDialog1->FileName = " ";
 if (OpenDialog1->Execute())
   {
    if (Form2->Memo1->Lines->Count > 0) Form2->Memo1->Clear();
    Form2->Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
    Form3->Memo1->Lines->Clear();
    Form3->Memo1->Lines->Add("��������� ��������� �����������:");
    colstr=Form2->Memo1->Lines->Count;  // ���������� ����� � ���� ������
    int i=0;
    while (Form2->Memo1->Lines->Strings[i]!="")
    {
     Memo5->Lines->Add(Form2->Memo1->Lines->Strings[i]);
     i++;
    }
    i++;
    w=-1;  /* ���������� ��������; -1 ��� ����,
              ����� �� ������� ������ "�������:" */
    while (Form2->Memo1->Lines->Strings[i]!="")
    {
     w++;
     Memo1->Lines->Add(Form2->Memo1->Lines->Strings[i]);
     i++;
    }
    i++;
    q=0; // ���������� ��������� �������
    while (Form2->Memo1->Lines->Strings[i]!="")
    {
     q++;
     lenstr=Form2->Memo1->Lines->Strings[i].Length();
     int j=1;
     AnsiString stroka="";
     Ishod[q-1].name="";
     while (Form2->Memo1->Lines->Strings[i][j]!=',')
     {
      Ishod[q-1].name+=Form2->Memo1->Lines->Strings[i][j];
      j++;
     }
     j++;

     bool flagz=true;
     int kk=0;
     stroka="";
     while (Form2->Memo1->Lines->Strings[i][j]!=',')
     {
      if (Form2->Memo1->Lines->Strings[i][j]==' ');
      else
        {
         stroka+=Form2->Memo1->Lines->Strings[i][j];
         kk++;
         if (Form2->Memo1->Lines->Strings[i][j]=='.')
           {
            flagz=false;
            stroka="";
            kk=0;
           }
        }
      j++;
     }
     Ishod[q-1].nomer=q;
     if (flagz) Ishod[q-1].opr=StrToFloat(stroka);
     else Ishod[q-1].opr=StrToFloat(stroka)/stepen(kk);
     flagz=true;
     MatOpr[0][q-1]=Ishod[q-1].opr;

     AnsiString nmemo; nmemo.printf("%.7f",Ishod[q-1].opr);
     Memo2->Lines->Add(" "+IntToStr(Ishod[q-1].nomer)+" "+Ishod[q-1].name+" (p="+nmemo+")");
     Form3->Memo1->Lines->Add(" "+IntToStr(Ishod[q-1].nomer)+" "+Ishod[q-1].name+" (p="+nmemo+")");

     for (int t=0; t<w; t++)
     {
      Ishod[q-1].py[t]=11;
      Ishod[q-1].pn[t]=11;
     }
     int tt=0;

     for (int t=0; t<w; t++)
     {
      stroka="";
      if (j>lenstr) break;
      else j++;
      if (j>lenstr) break;
      while (Form2->Memo1->Lines->Strings[i][j]!=',')
        {
         if (Form2->Memo1->Lines->Strings[i][j]==' ');
         else stroka+=Form2->Memo1->Lines->Strings[i][j];
         if (j>lenstr) break;
         else j++;
         if (j>lenstr) break;
        }
      tt=StrToInt(stroka);
      stroka="";
      if (j>lenstr) break;
      else j++;
      if (j>lenstr) break;
      kk=0;
      while (Form2->Memo1->Lines->Strings[i][j]!=',')
      {
       if (Form2->Memo1->Lines->Strings[i][j]==' ');
       else
         {
          stroka+=Form2->Memo1->Lines->Strings[i][j];
          kk++;
          if (Form2->Memo1->Lines->Strings[i][j]=='.')
           {
            flagz=false;
            stroka="";
            kk=0;
           }
         }
       if (j>lenstr) break;
       else j++;
       if (j>lenstr) break;
      }
      if (flagz) Ishod[q-1].py[tt-1]=StrToFloat(stroka);
      else Ishod[q-1].py[tt-1]=StrToFloat(stroka)/stepen(kk);
      flagz=true;

      stroka="";
      if (j>lenstr) break;
      else j++;
      if (j>lenstr) break;
      kk=0;
      while (Form2->Memo1->Lines->Strings[i][j]!=',')
      {
       if (Form2->Memo1->Lines->Strings[i][j]==' ');
       else
         {
          stroka+=Form2->Memo1->Lines->Strings[i][j];
          kk++;
          if (Form2->Memo1->Lines->Strings[i][j]=='.')
           {
            flagz=false;
            stroka="";
            kk=0;
           }
         }
       if (j>lenstr) break;
       else j++;
       if (j>lenstr) break;
      }
      if (flagz) Ishod[q-1].pn[tt-1]=StrToFloat(stroka);
      else Ishod[q-1].pn[tt-1]=StrToFloat(stroka)/stepen(kk);
      flagz=true;
     }

     i++;
    }
    N10->Enabled=true;
    SpeedButton1->Enabled=true;
    Form1->StatusBar1->Panels->operator [](1)->Text = IntToStr(w);
    Form1->StatusBar1->Panels->operator [](3)->Text = IntToStr(q);
    Button2->Enabled=true;
    N6->Enabled=true;
    SpeedButton4->Enabled=true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 if (Memo2->Modified)
   {
    int res = Application->MessageBoxA("������� �������� �������. ��������� ���������?",
      "��������� ���������", MB_YESNOCANCEL | MB_ICONWARNING);
    if (res == IDYES) N6->Click();
    if (res == IDCANCEL) return;
   }
 flagclose = true;
// if (Form5->Action) Form5->Close();
 Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
 if (flagclose==false)
   {
    if (Memo2->Modified)
      {
       int res = Application->MessageBoxA("������� �������� �������. ��������� ���������?",
         "��������� ���������", MB_YESNO | MB_ICONWARNING);
       if (res == IDYES) N6->Click();
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
 Button3->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
 N10->Enabled=false;
 Button1->Enabled=true;
 Edit1->Enabled=true;
 Memo3->Lines->Clear();
 Memo3->Font->Color=clRed;
 Memo3->Font->Size=10;
 Memo3->Lines->Strings[0]=Memo1->Lines->Strings[1];
 N15->Enabled=true;
 SpeedButton2->Enabled=true;
 N10->Enabled=false;
 SpeedButton1->Enabled=false;
 N11->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 try
 {
  ku=StrToFloat(Edit1->Text);
  if ((ku!=-5)&&(ku!=-4)&&(ku!=-3)&&(ku!=-2)&&(ku!=-1)&&(ku!=0)&&(ku!=1)&&(ku!=2)&&(ku!=3)&&(ku!=4)&&(ku!=5))
     MessageBoxA(0,"������� ���������� �������� ������������ �����������, ������� ������ ��������� �������� �� -5 �� +5 � ����� 1",
                  "������ ����� ������������",MB_OK);
  else
  {
  Memo4->Lines->Add(Memo1->Lines->Strings[vp+1]);
  Memo2->Lines->Clear();
  Form3->Memo1->Lines->Add("");
  Form3->Memo1->Lines->Add(Memo1->Lines->Strings[vp+1]);
  vp++;
  VecKu[vp-1]=ku;
  Form3->Memo1->Lines->Add("����������� ����������� ������ ������������ "+FloatToStr(ku));
  Form3->Memo1->Lines->Add("");
  pq=(ku+5)/10;
  for (int i=0; i<q; i++)
    {
     if (((Ishod[i].py[vp-1]*Ishod[i].opr+Ishod[i].pn[vp-1]*(1-Ishod[i].opr))!=0)&&
        (((1-Ishod[i].py[vp-1])*Ishod[i].opr+(1-Ishod[i].pn[vp-1])*(1-Ishod[i].opr))!=0))
       {
        pa=Ishod[i].py[vp-1]*Ishod[i].opr/(Ishod[i].py[vp-1]*Ishod[i].opr+Ishod[i].pn[vp-1]*(1-Ishod[i].opr));
        pna=(1-Ishod[i].py[vp-1])*Ishod[i].opr/((1-Ishod[i].py[vp-1])*Ishod[i].opr+(1-Ishod[i].pn[vp-1])*(1-Ishod[i].opr));
        if ((ku!=0)&&(Ishod[i].py[vp-1]!=11)&&(Ishod[i].pn[vp-1]!=11))
          {
           AnsiString oldopr; oldopr.printf("%.7f",Ishod[i].opr);
           Ishod[i].opr=pa*pq+pna*(1-pq);
           MatOpr[vp][i]=Ishod[i].opr;
           AnsiString smemo; smemo.printf("%.7f",Ishod[i].opr);
           Memo2->Lines->Add(" "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
           Form3->Memo1->Lines->Add("  "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
           Form3->Memo1->Lines->Add("  p=p(E/H)*p(H)/(p(E/H)*p(H)+p(E/��H)*(1-p(H))) * p(Q) + (1-p(E/H))*p(H)/((1-p(E/H))*p(H)+(1-p(E/��H))*(1-p(H))) * (1-p(Q)),  ���:");
           Form3->Memo1->Lines->Add("    p(H)="+oldopr);
           smemo.printf("%.7f",Ishod[i].py[vp-1]);
           Form3->Memo1->Lines->Add("    p(E/H)="+smemo);
           smemo.printf("%.7f",Ishod[i].pn[vp-1]);
           Form3->Memo1->Lines->Add("    p(E/��H)="+smemo);
           Form3->Memo1->Lines->Add("    p(Q)=(Q+5)/10, ��� ���� �� ������ ������������ Q="+FloatToStr(ku));
          }
        else
          {
           MatOpr[vp][i]=Ishod[i].opr;
           AnsiString smemo; smemo.printf("%.7f",Ishod[i].opr);
           Memo2->Lines->Add(" "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
           Form3->Memo1->Lines->Add("  "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
           Form3->Memo1->Lines->Add("  ������ ������������� �� ������ �� ���������!");
           Form3->Memo1->Lines->Add("  ������������� ����������� ����� ���������!");
          }
       }
     else
       {
        MatOpr[vp][i]=Ishod[i].opr;
        AnsiString smemo; smemo.printf("%.7f",Ishod[i].opr);
        Memo2->Lines->Add(" "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
        Form3->Memo1->Lines->Add("  "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
        Form3->Memo1->Lines->Add("  ������ ������������� �� ������ �� ���������!");
        Form3->Memo1->Lines->Add("  ������������� ����������� ����� ���������!");
       }
     Form3->Memo1->Lines->Add("");
    }
  Memo3->Lines->Clear();
  Memo3->Lines->Strings[0]=Memo1->Lines->Strings[vp+1];
  if (vp>=w)
    {
     Button1->Enabled=false;
     Edit1->Enabled=false;
     Memo3->Lines->Clear();
     Memo3->Lines->Add("������������ ����������!");
     N13->Enabled=true;
     N16->Enabled=true;
     RadioButton1->Enabled=true;
     RadioButton2->Enabled=true;
     if (RadioButton1->Checked==true) RadioButton1Click(Sender);
     if (RadioButton2->Checked==true) RadioButton2Click(Sender);
     SpeedButton4->Enabled=true;
    }
   SpeedButton3->Enabled=true;
  }
 }
 catch(EConvertError &e)
 {
  MessageBoxA(0, "����� �� �������� ������! ������� ���������� ��������!","������ ����� ������������" , MB_OK);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
 Memo2->Lines->Clear();
 for (int t=0; t<q-1; t++)
   for (int i=q-1; i>t; i--)
     if (Ishod[i].opr>Ishod[i-1].opr)
       {
        temp=Ishod[i-1];
        Ishod[i-1]=Ishod[i];
        Ishod[i]=temp;
       }
 for (int i=0; i<q; i++)
   {
    AnsiString smemo; smemo.printf("%.7f",Ishod[i].opr);
    Memo2->Lines->Add(" "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
 Memo2->Lines->Clear();
 for (int t=0; t<q-1; t++)
   for (int i=q-1; i>t; i--)
     if (Ishod[i].nomer<Ishod[i-1].nomer)
       {
        temp=Ishod[i-1];
        Ishod[i-1]=Ishod[i];
        Ishod[i]=temp;
       }
 for (int i=0; i<q; i++)
   {
    AnsiString smemo; smemo.printf("%.7f",Ishod[i].opr);
    Memo2->Lines->Add(" "+IntToStr(Ishod[i].nomer)+" "+Ishod[i].name+" (p="+smemo+")");
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 SaveDialog1->Title = "��������� ���";
 if (SaveDialog1->Execute())
   {
    Memo6->Lines->Add("�������� ������������ � ���������� �������� 1.01");
    Memo6->Lines->Add("");
    Memo6->Lines->Add("-------------------------------------------");
    Memo6->Lines->Add("");
    Memo6->Lines->AddStrings(Memo5->Lines);
    Memo6->Lines->Add("");
    Memo6->Lines->Add("-------------------------------------------");
    Memo6->Lines->Add("");
    Memo6->Lines->Add("������������ �������:");
    Memo6->Lines->AddStrings(Memo4->Lines);
    Memo6->Lines->Add("");
    Memo6->Lines->Add("-------------------------------------------");
    Memo6->Lines->Add("");
    Memo6->Lines->Add("���������� ������������:");
    Memo6->Lines->AddStrings(Memo2->Lines);
    Memo6->Lines->SaveToFile(SaveDialog1->FileName);
    Memo2->Modified = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
 Button2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{
 Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
 N5->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
 Button2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
 N10->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
 N15->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N15Click(TObject *Sender)
{
 StopBase();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
 Button3->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
 Form4->ShowModal();
}
//---------------------------------------------------------------------------

void TForm1::MakeReport()
{
    // ��������� Excel
    ExcelInit("");

    // ���������� � ���� ���������
    Rang = Sh.OlePropertyGet("Range", "A1:L1");
    Rang.OlePropertyGet("Interior").OlePropertySet("ColorIndex",3);

    Rang = Sh.OlePropertyGet("Range", "A1:L1");
    Rang.OlePropertySet("HorizontalAlignment",3);

    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",1).OlePropertySet("ColumnWidth", 22);
    toExcelCell(1,1,String("������ �������"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",2).OlePropertySet("ColumnWidth", 30);
    toExcelCell(1,2,String("������ ������������"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",3).OlePropertySet("ColumnWidth", 15);
    toExcelCell(1,3,String("���. ���-�� P(H)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",4).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,4,String("Py"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",5).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,5,String("Pn"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",6).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,6,String("P(H/E)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",7).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,7,String("P(��H/E)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",8).OlePropertySet("ColumnWidth", 3);
    toExcelCell(1,8,String("��"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",9).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,9,String("P(Q)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",10).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,10,String("P(��Q)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",11).OlePropertySet("ColumnWidth", 18);
    toExcelCell(1,11,String("�����. ���. Exel"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",12).OlePropertySet("ColumnWidth", 18);
    toExcelCell(1,12,String("�����. ���. ��"));

    int aa=1;

    // ���������� � ���� ������
   for (int j=0; j<w; j++)
    {
    for(int i=0; i<q; i++)
      {
       if (j==w-1)
         {
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,1).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,2).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,3).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,4).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,5).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,6).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,7).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,8).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,9).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,10).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,11).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
          Sh.OlePropertyGet("Cells", j*q+i+2+aa,12).OlePropertyGet("Interior").OlePropertySet("ColorIndex",8);
         }
    //   Sh.OlePropertyGet("Cells", j*q+i+2+aa,1).OlePropertySet("HorizontalAlignment", 3);
    //   Sh.OlePropertyGet("Cells", j*q+i+2+aa,2).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,3).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,4).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,5).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,6).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,7).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,8).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,9).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,10).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,11).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", j*q+i+2+aa,12).OlePropertySet("HorizontalAlignment", 3);
       AnsiString strexel = IntToStr(i+1)+" "+Ishod[i].name;
       toExcelCell(j*q+i+2+aa, 1, String(strexel));
       strexel = IntToStr(j+1)+" "+Memo1->Lines->Strings[j+1];
       toExcelCell(j*q+i+2+aa, 2, String(strexel));
       toExcelCell(j*q+i+2+aa, 3, Variant(MatOpr[j][i]));
       toExcelCell(j*q+i+2+aa, 4, Variant(Ishod[i].py[j]));
       toExcelCell(j*q+i+2+aa, 5, Variant(Ishod[i].pn[j]));
       App.OlePropertyGet("Cells", j*q+i+2+aa, 6).OlePropertySet("Formula", String("=C"+IntToStr(j*q+i+2+aa)+"*D"+IntToStr(j*q+i+2+aa)
           +"/(C"+IntToStr(j*q+i+2+aa)+"*D"+IntToStr(j*q+i+2+aa)+"+(1-C"+IntToStr(j*q+i+2+aa)+")*E"+IntToStr(j*q+i+2+aa)+")").c_str());
       App.OlePropertyGet("Cells", j*q+i+2+aa, 7).OlePropertySet("Formula", String("=C"+IntToStr(j*q+i+2+aa)+"*(1-D"+IntToStr(j*q+i+2+aa)
           +")/(C"+IntToStr(j*q+i+2+aa)+"*(1-D"+IntToStr(j*q+i+2+aa)+")+(1-C"+IntToStr(j*q+i+2+aa)+")*(1-E"+IntToStr(j*q+i+2+aa)+"))").c_str());
       toExcelCell(j*q+i+2+aa, 8, Variant(VecKu[j]));
       toExcelCell(j*q+i+2+aa, 9, Variant((VecKu[j]+5)/10));
       toExcelCell(j*q+i+2+aa, 10, Variant((1-(VecKu[j]+5)/10)));
       if (VecKu[j]!=0)
         App.OlePropertyGet("Cells", j*q+i+2+aa, 11).OlePropertySet("Formula", String("=F"+IntToStr(j*q+i+2+aa)+"*I"+IntToStr(j*q+i+2+aa)
             +"+G"+IntToStr(j*q+i+2+aa)+"*J"+IntToStr(j*q+i+2+aa)).c_str());
       else toExcelCell(j*q+i+2+aa, 11, Variant(MatOpr[j][i]));
       toExcelCell(j*q+i+2+aa, 12, Variant(MatOpr[j+1][i]));
      }
    aa++;
    }
    // ������ ��� �������
    if(!App.IsEmpty())App.OlePropertySet("Visible",true);

    // ��������� ��� �� ����� � ���� Trassirovka.xls
    try
    {
      App.OlePropertyGet("WorkBooks",1).OleProcedure("SaveAs","F:\\My University\\2008\\PES\\���������� �������\\Trassirovka3");
    }
    catch(...)
    {
      ShowMessage("�� �������� ��������� ��������� ��������� !");
    }
        // ����� ��� ������� � ����� �������, ���� ��������� �� ����� - ������� ���� ����
  /*   try{
       App.OlePropertyGet("WorkBooks",1).OleProcedure("Close");
       }catch(...){
          ShowMessage("�� �������� ���� ������� Excel.");
      }  */
    Sh.Clear();    // ����������� �������
    App.Clear();
}
//------------------------------------------------------------------------

void __fastcall TForm1::ExcelInit(String File)
{
  // ���� Excel ������� - ������������ � ����
  try {
   App=Variant::GetActiveObject("Excel.Application");
  } catch(...) {
     // Excel �� ������� - ��������� ���
     try { App=Variant::CreateObject("Excel.Application"); } catch (...) {
      Application->MessageBox("���������� ������� Microsoft Excel!"
      "�������� Excel �� ���������� �� ����������.","������",MB_OK+MB_ICONERROR);
  } }
  try {
    if(File!="")
     App.OlePropertyGet("WorkBooks").OleProcedure("Open",File.c_str());
    else
     App.OlePropertyGet("WorkBooks").OleProcedure("add");

    Sh=App.OlePropertyGet("WorkSheets",1);
  } catch(...) {
    Application->MessageBox("������ �������� ����� Microsoft Excel!",
                                         "������",MB_OK+MB_ICONERROR);
  }
}
//----------------------------------------------------------------

void __fastcall TForm1::toExcelCell(int Row,int Column, AnsiString data)
{
  try {
    Variant  cur = Sh.OlePropertyGet("Cells", Row,Column);
    cur.OlePropertySet("Value", data.c_str());
  } catch(...) { ; }
}
//------------------------------------------------------------------------

void __fastcall TForm1::toExcelCell(int Row,int Column, Variant data)
{
  try {
    Variant  cur = Sh.OlePropertyGet("Cells", Row,Column);
    cur.OlePropertySet("Value", data);
  } catch(...) { ; }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N16Click(TObject *Sender)
{
 MakeReport();
}
//---------------------------------------------------------------------------

void TForm1::MakeReportTemp()
{
    // ��������� Excel
    ExcelInit("");

    // ���������� � ���� ���������
    Rang = Sh.OlePropertyGet("Range", "A1:L1");
    Rang.OlePropertyGet("Interior").OlePropertySet("ColorIndex",3);

    Rang = Sh.OlePropertyGet("Range", "A1:L1");
    Rang.OlePropertySet("HorizontalAlignment",3);

    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",1).OlePropertySet("ColumnWidth", 22);
    toExcelCell(1,1,String("������ �������"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",2).OlePropertySet("ColumnWidth", 30);
    toExcelCell(1,2,String("������ ������������"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",3).OlePropertySet("ColumnWidth", 15);
    toExcelCell(1,3,String("���. ���-�� P(H)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",4).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,4,String("Py"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",5).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,5,String("Pn"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",6).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,6,String("P(H/E)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",7).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,7,String("P(��H/E)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",8).OlePropertySet("ColumnWidth", 3);
    toExcelCell(1,8,String("��"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",9).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,9,String("P(Q)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",10).OlePropertySet("ColumnWidth", 13);
    toExcelCell(1,10,String("P(��Q)"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",11).OlePropertySet("ColumnWidth", 18);
    toExcelCell(1,11,String("�����. ���. Exel"));
    Sh.OlePropertyGet("Columns").OlePropertyGet("Item",12).OlePropertySet("ColumnWidth", 18);
    toExcelCell(1,12,String("�����. ���. ��"));

    // ���������� � ���� ������

    int j=vp-1;

    for(int i=0; i<q; i++)
      {
       Sh.OlePropertyGet("Cells", i+3,3).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,4).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,5).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,6).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,7).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,8).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,9).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,10).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,11).OlePropertySet("HorizontalAlignment", 3);
       Sh.OlePropertyGet("Cells", i+3,12).OlePropertySet("HorizontalAlignment", 3);
       AnsiString strexel = IntToStr(i+1)+" "+Ishod[i].name;
       toExcelCell(i+3, 1, String(strexel));
       strexel = IntToStr(j+1)+" "+Memo1->Lines->Strings[j+1];
       toExcelCell(i+3, 2, String(strexel));
       toExcelCell(i+3, 3, Variant(MatOpr[j][i]));
       toExcelCell(i+3, 4, Variant(Ishod[i].py[j]));
       toExcelCell(i+3, 5, Variant(Ishod[i].pn[j]));
       App.OlePropertyGet("Cells", i+3, 6).OlePropertySet("Formula", String("=C"+IntToStr(i+3)+"*D"+IntToStr(i+3)
           +"/(C"+IntToStr(i+3)+"*D"+IntToStr(i+3)+"+(1-C"+IntToStr(i+3)+")*E"+IntToStr(i+3)+")").c_str());
       App.OlePropertyGet("Cells", i+3, 7).OlePropertySet("Formula", String("=C"+IntToStr(i+3)+"*(1-D"+IntToStr(i+3)
           +")/(C"+IntToStr(i+3)+"*(1-D"+IntToStr(i+3)+")+(1-C"+IntToStr(i+3)+")*(1-E"+IntToStr(i+3)+"))").c_str());
       toExcelCell(i+3, 8, Variant(VecKu[j]));
       toExcelCell(i+3, 9, Variant((VecKu[j]+5)/10));
       toExcelCell(i+3, 10, Variant((1-(VecKu[j]+5)/10)));
       if (VecKu[j]!=0)
         App.OlePropertyGet("Cells", i+3, 11).OlePropertySet("Formula", String("=F"+IntToStr(i+3)+"*I"+IntToStr(i+3)
             +"+G"+IntToStr(i+3)+"*J"+IntToStr(i+3)).c_str());
       else toExcelCell(i+3, 11, Variant(MatOpr[j][i]));
       toExcelCell(i+3, 12, Variant(MatOpr[j+1][i]));
      }

    // ������ ��� �������
    if(!App.IsEmpty())App.OlePropertySet("Visible",true);

    // ��������� ��� �� ����� � ���� Trassirovka.xls
    try
    {
      App.OlePropertyGet("WorkBooks",1).OleProcedure("SaveAs","F:\\My University\\2008\\PES\\���������� �������\\Trassirovka3");
    }
    catch(...)
    {
      ShowMessage("�� �������� ��������� ��������� ��������� !");
    }
        // ����� ��� ������� � ����� �������, ���� ��������� �� ����� - ������� ���� ����
  /*   try{
       App.OlePropertyGet("WorkBooks",1).OleProcedure("Close");
       }catch(...){
          ShowMessage("�� �������� ���� ������� Excel.");
      }  */
    Sh.Clear();    // ����������� �������
    App.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
 MakeReportTemp();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
 MessageDlg("������ � ��������� ���������� ������� ����� ����������� � ����������� �������!", mtInformation, TMsgDlgButtons() << mbOK, 0);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton7Click(TObject *Sender)
{
 N8->Click();        
}
//---------------------------------------------------------------------------

