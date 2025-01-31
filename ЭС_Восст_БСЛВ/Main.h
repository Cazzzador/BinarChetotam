//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TBevel *Bevel1;
        TMenuItem *N11;
        TPanel *Panel1;
        TBevel *Bevel2;
        TStatusBar *StatusBar1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TBevel *Bevel4;
        TMemo *Memo5;
        TPanel *Panel2;
        TPanel *Panel4;
        TPanel *Panel3;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TMemo *Memo2;
        TGroupBox *GroupBox1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TPanel *Panel6;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N14;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton1;
        TMenuItem *N15;
        TSpeedButton *SpeedButton2;
        TLabel *Label6;
        TSplitter *Splitter1;
        TPanel *Panel5;
        TPanel *Panel7;
        TLabel *Label5;
        TMemo *Memo1;
        TMemo *Memo6;
        TSplitter *Splitter2;
        TPanel *Panel8;
        TMemo *Memo3;
        TLabel *Label3;
        TPanel *Panel9;
        TLabel *Label4;
        TMemo *Memo4;
        TSplitter *Splitter3;
        TMenuItem *N16;
        TSpeedButton *SpeedButton3;
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
private:	// User declarations
        void __fastcall ExcelInit(String File);
        void __fastcall toExcelCell(int c1,int c2, String data);
        void __fastcall toExcelCell(int c1,int c2, Variant data);
        Variant App,Sh,Rang;
        void MakeReport();
        void MakeReportTemp();
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void TForm1::NewBase();
        void TForm1::StopBase();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
