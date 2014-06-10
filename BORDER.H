#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void border ()
{
	textcolor(WHITE);
	for(int i=0;i<79;i++)
		cprintf("=");
	gotoxy(1,25);
	for(i=0;i<79;i++)
		cprintf("=");
	gotoxy(1,1);
}