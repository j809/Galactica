#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

void loading()
{
   clrscr();
   int gdriver = DETECT, gmode;
   int midx, midy,radius=80;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   for(int io=0;io<79;io++)
		cout<<"=";
   gotoxy(1,25);
   for(io=0;io<79;io++)
		cout<<"=";
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(GREEN);
   settextstyle(6,HORIZ_DIR,1);
   outtextxy(235,100,"Transaction in Progress");
   settextstyle(0,HORIZ_DIR,1);
   outtextxy(midx-25,midy+5,"LOADING");
   delay(1150);
   int arr[101];
  for (int l=0;l<101;l++)
	arr[l]=l;
   for (int i=0,j=1,k=1;i<=360&&k<101;i+=18,j+=18,k+=5)
   {
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	pieslice(midx, midy+30, 5+i, 8+i, radius);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);
	pieslice(midx, midy+30, 0+j, 10+j, 60);
	setcolor(GREEN);
	outtextxy(midx-25,midy+5,"LOADING");
	gotoxy(43,18);
	cout<<"%";
	gotoxy(40,18);
	cout<<arr[k-1];
	if(k==96)
	cout<<"\b\b\b"<<100;
	delay(200);
   }
   closegraph();
}
