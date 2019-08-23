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
int sumOfBounds = 0;
int sumOfPointsLeftPlayer = 0;
int sumOfPointsRightPlayer = 0;
AnsiString sum_of_bounds;
AnsiString sum_of_points_left_player = "0";
AnsiString sum_of_points_right_player = "0";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
  /*Application->MessageBox("Witaj w grze Pingpong.\n\n"
                          "Lewy gracz steruje wciskaj¹c klawisze A oraz Z.\n"
                          "Lewy gracz steruje wciskaj¹c strza³ki góra oraz dó³.\n\n"
                          "Dla urozmaicenia zabawy:\n"
                          "Kiedy odbijesz pi³kê na œrodku paletki, wówczas zmieniasz jej k¹t odbicia i pi³ka przyœpieszy.\n"
                          "Im d³u¿ej obijasz, tym pi³ka szybciej przemieszcza siê.\n"
                          "Mo¿esz dowolnie zmienia pole gry.\n\n"
                          "Mi³ej zabawy","Pingpong", MB_OK); */
         Label4->Visible =  true;
         Label4->Left =  backGround->Width/2 - Label4->Width/2;
         Button3->Left =  backGround->Width/2 - Button3->Width/2;
         ball->Left = 500;
         ball->Top = 200;
         TimerBall->Enabled = false;
         paddelLeft->Left = 50;
         paddelRight->Left =  backGround->Width - 50;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
  Label4->Visible =  false;
  Button3->Visible =  false;
  paddelLeft->Left = 50;
  paddelRight->Left =  backGround->Width - 50;
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
    ball->Visible = false;
    Button1->Left =  backGround->Width/2-Button1->Width/2;
    Button2->Left =  backGround->Width/2 - Button2->Width/2;
    Label1->Left =  backGround->Width/2 - Label1->Width/2;
    Label2->Left =  backGround->Width/2 - Label2->Width/2;
    Label3->Left =  backGround->Width/2 - Label3->Width/2;
    Button1->Visible = true;
    Button2->Visible = true;
    Label1->Caption = "Punkt dla gracza prawego >";
    Label1->Visible =  true;
    sum_of_bounds = IntToStr(sumOfBounds);
    Label2->Caption = "Iloœæ odbiæ: " + sum_of_bounds;
    Label2->Visible =  true;
    sumOfPointsRightPlayer += 1;
    sum_of_points_right_player = IntToStr(sumOfPointsRightPlayer);
    Label3->Caption = sum_of_points_left_player + ":" + sum_of_points_right_player;
    Label3->Visible =  true;

  }
  //fault on right side
  if(ball->Left >=  paddelRight->Width +paddelRight->Left + 10)
  {
    TimerBall->Enabled = false;
    ball->Visible = false;
    Button1->Left =  backGround->Width/2-Button1->Width/2;
    Button2->Left =  backGround->Width/2 - Button2->Width/2;
    Label1->Left =  backGround->Width/2 - Label1->Width/2;
    Label2->Left =  backGround->Width/2 - Label2->Width/2;
    Label3->Left =  backGround->Width/2 - Label3->Width/2;;
    Button1->Visible = true;
    Button2->Visible = true;
    Label1->Caption = "< Punkt dla gracza lewego";
    Label1->Visible =  true;
    sumOfPointsLeftPlayer += 1;
    sum_of_bounds = IntToStr(sumOfBounds);
    Label2->Caption = "Iloœæ odbiæ: " + sum_of_bounds;
    Label2->Visible =  true;
    sum_of_points_left_player = IntToStr(sumOfPointsLeftPlayer);
    Label3->Caption = sum_of_points_left_player + ":" + sum_of_points_right_player;
    Label3->Visible =  true;
  }
  else if(ball->Left <= paddelLeft->Left && ball->Top >= paddelLeft->Top -ball->Width/2 &&
          ball->Top < paddelLeft->Top + paddelLeft->Height)
       {
        if (ball->Top == paddelLeft->Top + paddelLeft->Height/2 - ball->Width/2 )
        {
          vertical -=9;
          TimerBall->Interval --;
        }
           sumOfBounds = sumOfBounds + 1;
            TimerBall->Interval--;
           if(horizontal < 0 ) horizontal = -horizontal;
           else if(vertical == 0) vertical = -8;
       }
  else if(ball->Left >= paddelRight->Left-16 && ball->Top >= paddelRight->Top -ball->Width/2 &&
           ball->Top < paddelRight->Top + paddelRight->Height)
       {
        if (ball->Top == paddelRight->Top + paddelRight->Height/2 - ball->Width/2 )
        {
          vertical +=9;
          TimerBall->Interval--;
        }
         sumOfBounds = sumOfBounds + 1;
          TimerBall->Interval--;
          if(horizontal < backGround->Width ) horizontal = -horizontal;
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   if( Application->MessageBox("Czy napewno chcesz zacz¹æ od nowa?",
				"PotwierdŸ", MB_YESNO | MB_ICONQUESTION) == IDYES)
   {

      Button1->Visible = false;
      ball->Left = 320;
      ball->Top = 280;
      ball->Visible = true;
      TimerBall->Enabled = true;
      Label1->Visible =  false;
      Label2->Visible =  false;
      sumOfBounds = 0;
      Label3->Visible =  false;
      sumOfPointsLeftPlayer = 0;
      sumOfPointsRightPlayer = 0;
      Button2->Visible = false;
      Label3->Caption = "0:0";
      sum_of_points_left_player = "0";
      sum_of_points_right_player = "0";
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
      Button1->Visible = false;
      ball->Left = 320;
      ball->Top = 280;
      ball->Visible = true;
      TimerBall->Enabled = true;
      Label1->Visible =  false;
      Label2->Visible =  false;
      sumOfBounds = 0;
      Label3->Visible =  false;
      Button2->Visible = false;
      Label4->Visible =  false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   Label3->Caption = "0:0";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
      ball->Visible = true;
      TimerBall->Enabled = true;
      Label1->Visible =  false;
      Label2->Visible =  false;
      sumOfBounds = 0;
      Label3->Visible =  false;
      sumOfPointsLeftPlayer = 0;
      sumOfPointsRightPlayer = 0;
      Button2->Visible = false;
      Label3->Caption = "0:0";
      sum_of_points_left_player = "0";
      sum_of_points_right_player = "0";
}
//---------------------------------------------------------------------------

