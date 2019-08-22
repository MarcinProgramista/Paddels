//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *backGround;
        TImage *ball;
        TTimer *TimerBall;
        TImage *paddelLeft;
        TTimer *TimerLeftPaddelTop;
        TTimer *TimerLeftPaddelBottom;
        TImage *paddelRight;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall TimerLeftPaddelTopTimer(TObject *Sender);
        void __fastcall TimerLeftPaddelBottomTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
