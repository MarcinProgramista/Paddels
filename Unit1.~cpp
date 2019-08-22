//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int vertical = -8;
int horizontal = -8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{                                                                                
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
  TimerBall->Enabled = true;
   ball->Visible = true;
  ball->Left += horizontal;
  ball->Top += vertical;
   //bounce from the top
  if(ball->Top-5 <= backGround->Top) vertical = -vertical;
  //bounce from the bottom
  if(ball->Top + ball->Width + 5 >= backGround->Height) vertical = -vertical;

  //fault on left side
  if(ball->Left <=  paddelLeft->Width + 15)
  {
    TimerBall->Enabled = false;
    ball->Visible = false;
  }
  //fault on right side
  if(ball->Left >=  paddelRight->Width +paddelRight->Left + 15)
  {
    TimerBall->Enabled = false;
    ball->Visible = false;
    Button1->Visible = true;
  }
  else if(ball->Left <= paddelLeft->Left && ball->Top >= paddelLeft->Top -ball->Width/2 &&
          ball->Top < paddelLeft->Top + paddelLeft->Height)
       {
           if(horizontal < 0 ) horizontal = -horizontal;
           else if(vertical == 0) vertical = -8;
       }
  else if(ball->Left >= paddelRight->Left && ball->Top >= paddelRight->Top -ball->Width/2 &&
           ball->Top < paddelRight->Top + paddelRight->Height)
       {
         horizontal = -horizontal;
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerLeftPaddelTopTimer(TObject *Sender)
{
  if(paddelLeft->Top >10 )paddelLeft->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerLeftPaddelBottomTimer(TObject *Sender)
{
  if(paddelLeft->Top + paddelLeft->Height < backGround->Height-10 ) paddelLeft->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == 'A' || Key == 'a' ) TimerLeftPaddelTop->Enabled = true;
     if (Key == 'Z' || Key == 'z' ) TimerLeftPaddelBottom->Enabled = true;
     if (Key == VK_UP ) TimerRightPaddelTop->Enabled = true;
     if (Key == VK_DOWN ) TimerRightPaddelBottom->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if (Key == 'A' || Key == 'a' ) TimerLeftPaddelTop->Enabled = false;
     if (Key == 'Z' || Key == 'z' ) TimerLeftPaddelBottom->Enabled = false;
     if (Key == VK_UP ) TimerRightPaddelTop->Enabled = false;
     if (Key == VK_DOWN ) TimerRightPaddelBottom->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerRightPaddelTopTimer(TObject *Sender)
{
   if(paddelRight->Top >10 )paddelRight->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerRightPaddelBottomTimer(TObject *Sender)
{
  if(paddelRight->Top + paddelRight->Height < backGround->Height-10 ) paddelRight->Top +=10;
}
//---------------------------------------------------------------------------


