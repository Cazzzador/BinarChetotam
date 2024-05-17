//---------------------------------------------------------------------------

#ifndef RedaktorH
#define RedaktorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TOpenDialog *OpenDialog1;
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
        TMenuItem *N11;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N14;
        TMenuItem *N15;
        TMenuItem *N16;
        TMenuItem *N17;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *N21;
        TMenuItem *N22;
        TMenuItem *N23;
        TMenuItem *N24;
        TBevel *Bevel1;
        TPanel *Panel1;
        TBevel *Bevel2;
        TStatusBar *StatusBar1;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton7;
        TSaveDialog *SaveDialog1;
        TFontDialog *FontDialog1;
        TPrintDialog *PrintDialog1;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TPopupMenu *PopupMenu1;
        TMenuItem *MenuItem1;
        TMenuItem *MenuItem2;
        TMenuItem *N28;
        TMenuItem *MenuItem3;
        TPopupMenu *PopupMenu2;
        TMenuItem *N29;
        TMenuItem *N30;
        TMenuItem *N31;
        TMenuItem *N32;
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall N18Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall Memo1Change(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall N23Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
