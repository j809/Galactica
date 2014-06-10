#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void welcome()
{
	clrscr ();
	int gdriver=DETECT, gmode;
	initgraph(&gdriver, &gmode,"C:\\turboc3\\bgi");
	setbkcolor(BROWN);
	int maxx, maxy;
	int poly[8];
	maxx = getmaxx();
	maxy = getmaxy();

	   poly[0] = 20;        /* 1st vertex */
	 poly[1] = maxy / 2;

	   poly[2] = maxx - 20; /* 2nd */
	   poly[3] = 20;

	   poly[4] = maxx - 50; /* 3rd */
	   poly[5] = maxy - 20;

	   poly[6] = maxx / 2;
	   poly[7] = maxy / 2;

      setfillstyle(4, getmaxcolor());

      /* draw a filled polygon */
      fillpoly(4, poly);

	setcolor(BLUE);
	int i=1;
	outtextxy(1,1,"*");
	delay (1000);
	while (i<30)
	{	outtextxy(1,i*15,"*");
		delay(75);
		cout<<endl;
		i++;
	}
	i=1;
	outtextxy(630,1,"*");
	while (i<30)
	{	outtextxy(630,i*15,"*");
		delay(75);
		i++;
	}
	for (i=1;i<604;i++)
	{
		outtextxy(i+10,1,"_");
		outtextxy(i+10,439,"_");
		delay(5);
	}
	int midx=(getmaxx()/2),midy=(getmaxy()/2);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,6);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	pieslice(getmaxx()/2,getmaxy()/2,0,360,100);
	setcolor(BLACK);
	fillellipse(getmaxx()/2,getmaxy()/2,200,50);
	setcolor(RED);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(midx,midy,"GALACTICA");

	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	outtextxy(midx,midy/3,"Hotel Galactica Welcomes You");
	setcolor(BLUE+BLINK);
	delay(50);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(midx,420,"Press ENTER to continue");
	getche();
	closegraph();
}
