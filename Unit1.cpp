//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int vertical = 8;
int horizontal = -8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
  ball->Left += horizontal;
  ball->Top += vertical;

  if(ball->Top-5 <= backGround->Top) vertical = -vertical;
  if(ball->Top + ball->Width + 5 >= backGround->Height) vertical = -vertical;
  if(ball->Left <=  paddelLeft->Width + 15)
  {
    TimerBall->Enabled = false;
    ball->Visible = false;
  }
}
//---------------------------------------------------------------------------
