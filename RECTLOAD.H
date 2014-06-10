#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void load1()
{
   clrscr ();
   int gdriver = DETECT, gmode;
   int midx, midy,j;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   for(int io=0;io<79;io++)
		cout<<"=";
   gotoxy(1,30);
   for(io=0;io<79;io++)
		cout<<"=";
   setcolor(GREEN);
   settextstyle(0,HORIZ_DIR,1);
   outtextxy(250,20,"BILLING COUNTER");
   settextstyle(0,HORIZ_DIR,1);
   setcolor(LIGHTBLUE);
   outtextxy(100,60,"We hope you enjoyed your stay at Hotel Galactica and");
   outtextxy(150,80,"wish for the opportunity to serve you again.");
   outtextxy(280,100,"Thank You.");
   outtextxy(150,120,"Please wait while we calculate your bill ");
   setcolor(GREEN);
   setfillstyle(0,BLACK);
  bar3d(midx-65, midy-16, midx+65,midy+10, 1, 1);
  settextstyle(0,HORIZ_DIR,1);
  outtextxy(270,200,"Calculating...");
  setcolor(BLUE);
  settextstyle(0,HORIZ_DIR,1);
  int arr[101];
  for (int i=0;i<101;i++)
	arr[i]=i;
  textcolor(RED);
  gotoxy(42,17);
  cout<<"%";
  delay(1500);
  for (j=1,i=0;j<101;j+=5,i+=5)
  {
	gotoxy(39,17);
	cout<<arr[i];
	if(j==96)
	cout<<"\b\b\b"<<100;
	outtextxy(255+j,232," Þ");
	delay(200);
  }
  closegraph();
}
