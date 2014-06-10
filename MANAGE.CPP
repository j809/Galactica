#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
#include<graphics.h>
#include"WELCOME.H"
#include"CIRLOAD.H"
#include"BORDER.H"
#include"RECTLOAD.H"
#include"HOTEL.H"


// List Of Functions
void book_a_room();
void homescreen();
void customer();
void mainmenu();
void customercare();
void room();
void bar();
void proceed();
void counter();
void roombilldisplay();
void barbilldisplay();
void end();
void check();
void storeall();
void getall(int);

// Structures
struct typroom
{
	char type[80];
	int tariff;
	int roomnum;
}roomselect[]={ " Single Bed",2000,0,
	" Double Bed ",3000,0,
	" Cottage  ",3500,0,
	" Suite    ",4500,0,
	" Penthouse",6500,0
	};

struct barmenu
{
	char name[100];
	int price;
	int qty;
	int roomnum;
}ob_bar[]={" Whiskey ",1000,0,0,
	" Beer ",975,0,0,
	" Scotch ",1134,0,0,
	" Rum  ",450,0,0,
	" Vodka",580,0,0,
	" Gin ",235,0,0,
	" Iced Tea ",50,0,0,
	" Lime Water (sweet)",30,0,0,
	" Lime Water (sour) ",30,0,0
	};

void loads()
{
   clrscr ();
   int gdriver = DETECT, gmode;
   int midx, midy,j;
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
   setbkcolor(BROWN);
   setcolor(GREEN);
   setfillstyle(0,BLACK);
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   bar3d(midx-65, midy-16, midx+65,
	 midy+10, 1, 1);
   settextstyle(0,HORIZ_DIR,1);
   outtextxy(275,200,"Loading...");
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
	if(j==36||j==56)
		delay(600);
	if(j<36)
		delay(200);
	if(j>36)
		delay(50);
  }
  delay(200);
  closegraph();
}


int rtype,k=0;
//Classes
class details
{
	char area[50],city[50],state[50],id[100];
	char houno[100],name[50],sex[2],pin[50],roomtype[50];
	int stay;
	long contactno;

	public:
	int roomnum;
	void form();
	void customercare();
	int num()
	{ return roomnum; }
	int sty()
	{ return stay; }
	void access_sty(int k)
	{ stay=k; }
	void access_roomnum(int a)
	{ roomnum=a; }
}ob_details;

void bills::bar_bill(int choice)
{
	for(int k=0;k<9;k++)
	{
		if((choice-1)==k)
		{
		barbill=barbill+ob_bar[k].price;
		ob_bar[k].qty++;
		}
	}
}
void bills::room_bill()
{
	roombill=(roomselect[rtype].tariff)*k;
}
void bills::net_bill(int &t)
{
	bill=roombill+barbill+hotelbill;
	gotoxy(6,6);
	textcolor(BLUE);
	cprintf(" Type ");
	gotoxy(39,6);
	cprintf(" Amount ");
	gotoxy(1,8);

	textcolor(WHITE);
	int h=0;
	char bill_name[3][50]={"Room Bill","Bar Bill","Hotel Bill"};
	int qwe[3]={roombill,barbill,hotelbill};

	for(;h<3;h++)
	{
	cprintf("  ");
	cprintf(bill_name[h]);
	gotoxy(41,t);
	cout<<qwe[h];
	cout<<endl<<endl;
	t+=2;
	}
}

fstream room_det,bar_det,typroom_det,barmenu_det;

void main()
{
	welcome();
	loads();
	clrscr();
	border();
	textcolor(GREEN);
	gotoxy(32,3);
	cprintf(" HOTEL GALACTICA");
	textcolor(YELLOW);
	gotoxy(31,5);
	cprintf("1. New guest");
	gotoxy(31,6);
	cprintf("2. Present Guest");
	gotoxy(31,8);
	textcolor(BLUE);
	cprintf("Enter your status : ");
	choice:
	char status=getche();
	if(status=='1')
	book_a_room();
	else if(status=='2')
	check();
	else
	{
	gotoxy(51,8);
	cprintf(" ");
	cprintf("\b");
	goto choice;
	}
	getch();
}

void book_a_room()
{
	label2:
	clrscr();
	border();
	textcolor(RED);
	gotoxy(27,3);
	cprintf(" Select your room type ");
	textcolor(GREEN);
	gotoxy(24,5);
	cprintf(" Type ");
	gotoxy(48,5);
	cprintf("Tariff");
	textcolor(YELLOW);
	int pos=7;
	for(int i=0;i<5;i++)
	{
	gotoxy(22,pos);
	cout<<i+1<<".";
	cprintf(roomselect[i].type);
	gotoxy(46,pos);
	cprintf("Rs. ");
	cout<<roomselect[i].tariff;
	pos++;
	}
	gotoxy(21,14);
	cprintf(" What kind of room would you like - ");
	char ch=getche();
	ch=ch-48;
	rtype=ch-1;
	char che;
	if(ch<=5 && ch>0)
	{
	gotoxy(1,15);
	cprintf("   Are you sure? (press 'y' to confirm or any other key to choose again) : ");
	che=getche();
		if(che=='y')
		{
		ob_details.form();
		homescreen();
		}
		else
		goto label2;
	}
	else
	{
	gotoxy(20,16);
	textcolor(RED);
	cprintf(" Not Available ");
	delay(2000);
	goto label2;
	}
}

void details:: form()
{
	clrscr();
	border();
	gotoxy(24,3);
	textcolor(BLUE);
	cprintf(" Please fill the following form : ");

	textcolor(GREEN);
	gotoxy(1,5);
	cprintf("   Name :");
	gotoxy(1,7);
	cprintf("   Sex (m/f) :");
	gotoxy(1,9);
	cprintf("   Address :");
	gotoxy(9,10);
	cprintf(" House No. :");
	gotoxy(9,11);
	cprintf(" Area :");
	gotoxy(9,12);
	cprintf(" City : ");
	gotoxy(9,13);
	cprintf(" State : ");
	gotoxy(9,14);
	cprintf(" Pin : ");
	gotoxy(1,16);
	cprintf("   Duration of stay ( nights)  : ");
	gotoxy(1,18);
	cprintf("   Contact Number : ");
	gotoxy(1,20);
	cprintf("   Email ID : ");

	gotoxy(11,5);
	cin>>name;
	label:
	gotoxy(16,7);
	textcolor(YELLOW);
	sex[0]=getche();
	if(sex[0]=='m' || sex[0]=='f'|| sex[0]=='M'|| sex[0]=='F')
	{
		gotoxy(22,10);
		gets(houno);
		gotoxy(17,11);
		gets(area);
		gotoxy(17,12);
		gets(city);
		gotoxy(18,13);
		gets(state);

		int len0,flag;
		labelm:
		gotoxy(16,14);
		cin>>pin;
		len0=strlen(pin);
		flag=len0;
		for(int i=0;i<len0;i++)
		{	if((pin[i]>47&&pin[i]<58))
				flag--;
			else
			flag=1000;
		}
		if(flag!=0)
		{
		for(int j=0;j<len0;j++)
			cprintf("\b");
		gotoxy(16,14);
		textcolor(RED);
		cprintf("Enter digits!!");
		textcolor(YELLOW);
		delay(800);
		gotoxy(16,14);
		cprintf("              ");
		gotoxy(16,14);
		goto labelm;
		}
		gotoxy(36,16);
		cin>>stay;
		gotoxy(21,18);
		cin>>contactno;
		gotoxy(15,20);
		gets(id);
	}
	else
	{
	gotoxy(16,7);
	cprintf(" ");
	cprintf("\b");
	goto label;
	}

	gotoxy(1,22);
	textcolor(LIGHTBLUE);
	randomize();
	label2:

	int roomnum=random(150)+1;
	ob_details.access_roomnum(roomnum);
	ob_bills.setroom(roomnum);
	roomselect[rtype].roomnum=roomnum;
	for(int o=0;o<9;o++)
	ob_bar[o].roomnum=roomnum;

	cprintf("   Welcome to Hotel Galactica ");
	if(sex[0]=='m')
	cprintf("Mr. ");
	else
	cprintf("Mrs. ");
	cout<<name;
	cprintf(". You are alotted room number ");
	cout<<roomnum<<".";
	gotoxy(1,23);
	cprintf("   Please enjoy your stay . ");
	delay(5000);

}

void homescreen()
{
	clrscr();
	border();
	textcolor(GREEN);
	gotoxy(32,3);
	cprintf("   WELCOME ");
	gotoxy(1,5);
	textcolor(YELLOW);
	cprintf("    1. Customer");
	gotoxy(1,7);
	cprintf("    2. Restaurant");
	gotoxy(1,9);
	cprintf("    3. Customer care centre ");
	gotoxy(1,11);
	cprintf("    4. New Guest ");
	gotoxy(1,14);
	textcolor(BLUE);
	cprintf("   Select your choice : ");
	lable2:
	char ch=getche();
	switch(ch)
	{
	case '1': customer(); break;
	case '2': mainmenu(); break;
	case '3': ob_details.customercare();break;
	case '4': check(); break;
	default:gotoxy(25,14);
		cprintf(" ");
		cprintf("\b");
		goto lable2;
	}
}

void customer()
{
	clrscr();
	border();
	gotoxy(1,3);
	textcolor(YELLOW);
	cprintf("   Your satisfaction is our guarantee. ");
	gotoxy(1,6);
	textcolor(BLUE);
	cprintf("   1. Go to room \n\n");
	gotoxy(1,8);
	cprintf("   2. Order Room Service \n\n");
	gotoxy(1,10);
	cprintf("   3. Go to Bar \n\n\n");
	gotoxy(1,13);
	textcolor(RED);
	cprintf("   What would you like to do ? ");
	char ch1;
	choice2:
	ch1=getche();
	switch(ch1)
	{
	case '1': room();break;
	case '2': mainmenu();break;
	case '3': bar(); break;
	default:  gotoxy(32,13);
		  cprintf(" ");
		  cprintf("\b");
		  goto choice2;
	}
}
void details::customercare()
{
	clrscr();
	border();
	gotoxy(17,2);
	textcolor(BLUE);
	cprintf(" This is the information you provided us ");
	gotoxy(1,4);
	textcolor(GREEN);
	cprintf("   Name :");
	gotoxy(1,6);
	cprintf("   Sex (m/f) :");
	gotoxy(1,8);
	cprintf("   Address :");
	gotoxy(9,9);
	cprintf(" House No. :");
	gotoxy(9,10);
	cprintf(" Area :");
	gotoxy(9,11);
	cprintf(" City : ");
	gotoxy(9,12);
	cprintf(" State : ");
	gotoxy(9,13);
	cprintf(" Pin : ");
	gotoxy(1,15);
	cprintf("   Duration of stay ( nights )  : ");
	gotoxy(1,16);
	cprintf("   Contact Number : ");
	gotoxy(1,17);
	cprintf("   Email ID : ");
	textcolor(YELLOW);
	gotoxy(11,4);
	cprintf(name);
	gotoxy(16,6);
	cprintf(sex);
	gotoxy(22,9);
	cprintf(houno);
	gotoxy(17,10);
	cprintf(area);
	gotoxy(17,11);
	cprintf(city);
	gotoxy(18,12);
	cprintf(state);
	gotoxy(16,13);
	cprintf(pin);
	gotoxy(35,15);
	cout<<stay;
	gotoxy(21,16);
	cout<<contactno;
	gotoxy(15,17);
	cprintf(id);
	gotoxy(1,20);
	cprintf("   You are alotted room number ");
	cout<<roomnum;
	gotoxy(25,23);
	textcolor(RED);
	cprintf(" Press 'R' or 'r' to return : ");

	char chae;
	label10:
	chae=getche();
	if(chae=='R'||chae=='r')
	homescreen();
	else
	{
	gotoxy(55,23);
	cprintf(" ");
	cprintf("\b");
	goto label10;
	}

}

void storeall()
{
	room_det.open("room.dat",ios::in|ios::out|ios::ate|ios::binary);
	room_det.write((char*)&ob_details,sizeof(ob_details));
	bar_det.open("bar.dat",ios::in|ios::out|ios::ate|ios::binary);
	bar_det.write((char*)&ob_bills,sizeof(ob_bills));
	typroom_det.open("struct_typroom.dat",ios::in|ios::out|ios::ate|ios::binary);
	typroom_det.write((char*)&roomselect,sizeof(roomselect));
	barmenu_det.open("struct_bar.dat",ios::in|ios::out|ios::ate|ios::binary);
	barmenu_det.write((char*)&ob_bar,sizeof(ob_bar));
}

void room()
{
	clrscr();
	k++;
	border();
	gotoxy(32,3);
	textcolor(LIGHTGREEN);
	cprintf("  ROOM ");
	cout<<ob_details.num();
	gotoxy(1,6);
	textcolor(YELLOW);
	cprintf("   Coming to the room signifies 1 day is over.");
	gotoxy(1,7);
	if(ob_details.sty()-k==1)
	{
	cprintf("   You have ");
	cout<<ob_details.sty()-k;
	cprintf(" day left. Enjoy your stay. ");
	}
	else if(ob_details.sty()-k>1)
	{
	cprintf("   You have ");
	cout<<ob_details.sty()-k;
	cprintf(" days left. Enjoy your stay. ");
	}
	else
	{
	cprintf("   Your stay is over. Please proceed to the billing counter. ");
	delay(5000);
	proceed();
	}
	if(ob_details.sty()!=k)
	{
	gotoxy(1,10);
	textcolor(RED);
	cprintf("   Would you like to check out now? (y/n) : ");
	char chae;
	label11:
	chae=getche();
		if(chae=='n'||chae=='N')
		homescreen();
		else if(chae=='y' || chae=='Y')
		{
		ob_details.access_sty(k);
		proceed();
		}
		else
		{
		gotoxy(45,10);
		cprintf(" ");
		cprintf("\b");
		goto label11;
		}
	}
}

void bar()
{
	label3:
	clrscr();
	border();
	int w=7;
	char choice;
	textcolor(RED);
	gotoxy(32,3);
	cprintf(" MENU ");
	gotoxy(1,5);
	textcolor(GREEN);
	cprintf("   Drink ");
	gotoxy(38,5);
	cprintf(" Price ");
	textcolor(BLUE);
	for(int j=0;j<9;j++)
	{
	gotoxy(1,w);
	cout<<"   "<<j+1<<".";
	cprintf(ob_bar[j].name);
	gotoxy(37,w);
	cout<<"Rs. "<<ob_bar[j].price;
	w+=1;
	}
	textcolor(YELLOW);
	gotoxy(1,17);
	cprintf("   What would you like to have : ");
	choice=getche();
	choice=choice-48;
	int a=choice;
	if(a>0 && a<=9)
	{
		gotoxy(1,19);
		cprintf("   Enjoy your ");
		cprintf(ob_bar[a].name);

		ob_bills.bar_bill(a);

		textcolor(YELLOW);
		gotoxy(1,20);
		cprintf("   Would you like another drink? (y/n) : ");
		char q;
		label4:
		q=getche();
		if(q=='y' || q=='Y')
		goto label3;
		else if(q=='n' || q=='N')
		{
		gotoxy(1,22);
		cprintf("   We hope you enjoyed being at GALACTICA BAR.");
		gotoxy(1,23);
		cprintf("   Do come again");
		delay(3000);
		homescreen();
		}
		else
		{
		gotoxy(42,20);
		cprintf(" ");
		cprintf("\b");
		goto label4;
		}
	}
	else
	{
	gotoxy(35,24);
	cprintf(" ");
	cprintf("\b");
	goto label3;
	}
}
int ol=0;
void proceed()
{
	ol++;
	clrscr();
	border();
	ob_bills.room_bill();
	gotoxy(32,2);
	textcolor(GREEN);
	cprintf("  THANK YOU!! ");
	textcolor(YELLOW);
	gotoxy(1,4);
	cprintf("   Hotel Galactica and its staff thank you for choosing to stay with us.");
	gotoxy(1,5);
	cprintf("   We sincerely hope that you enjoyed your stay here.");
	textcolor(BLUE);
	gotoxy(1,7);
	cprintf("   Proceeding to the billing counter ");
		for(;ol<4;ol++)
		{	for(int lo=0;lo<3;lo++)
			{
			cprintf(".");
			delay(750);
			}
			if(ol!=3)
			{
			clrscr();
			proceed();
			}
			else
			{
			delay(750);
			counter();
			}
		}

}

void counter()
{
	clrscr();
	border();
	int t=8;
	textcolor(GREEN);
	gotoxy(28,3);
	cprintf(" BILLING COUNTER - ROOM ");
	cout<<ob_details.num();

	ob_bills.net_bill(t);
	cprintf("  ");
	for(int li=0;li<45;li++)
	cprintf("-");
	gotoxy(1,t+1);
	cprintf("   Total");
	gotoxy(22,t+1);
	cprintf("=");
	gotoxy(41,t+1);
	cout<<ob_bills.ret_bill();
	cout<<endl<<endl;
	t+=2;
	t=18;
	textcolor(YELLOW);
	gotoxy(1,17);
	cprintf("   Press 1 to display Room Bill.");
	gotoxy(1,18);
	cprintf("   Press 2 to display Restaurant Bill.");
	gotoxy(1,19);
	cprintf("   Press 3 to display Bar Bill.");
	gotoxy(1,20);
	cprintf("   Press 4 to move ahead and complete transaction ");
	gotoxy(1,22);
	textcolor(RED);
	cprintf("   Select your choice : ");
	char billchoice;
	billchoice2:
	billchoice=getche();
	switch(billchoice)
	{
	case '1': roombilldisplay(); break;
	case '2': bills(); break;
	case '3': barbilldisplay();  break;
	case '4': end();break;
	default:  gotoxy(25,22);
		  cprintf(" ");
		  cprintf("\b");
		  goto billchoice2;
	}

}
void roombilldisplay()
{
	clrscr();
	border();
	gotoxy(25,3);
	textcolor(CYAN);
	cprintf(" ROOM BILL - ROOM ");
	cout<<ob_details.num();

	gotoxy(1,5);
	textcolor(GREEN);
	cprintf("   Chosen Room Type : ");
	cout<<roomselect[rtype].type;
	gotoxy(1,6);
	cprintf("   Nightly Tariff : ");
	cout<<roomselect[rtype].tariff;
	gotoxy(1,7);
	cprintf("   No. of nights stayed = ");
	cout<<k;
	gotoxy(1,9);
	cprintf("   Therefore, Room Bill = ");
	cout<<ob_bills.ret_room();
	textcolor(RED);
	gotoxy(1,12);
	cprintf("   Press 'r' or 'R' to return : ");
	char tobillscreen;
	returntobill:
	tobillscreen=getche();
	if(tobillscreen=='r'|| tobillscreen=='R')
	counter();
	else
	{
	gotoxy(33,12);
	cprintf(" ");
	cprintf("\b");
	goto returntobill;
	}

}

void barbilldisplay()
{
	clrscr();
	border();
	textcolor(CYAN);
	gotoxy(32,3);
	cprintf(" BAR BILL");
	gotoxy(1,6);
	textcolor(GREEN);
	cprintf("   Drink ");
	gotoxy(33,6);
	cprintf(" Quantity ");
	gotoxy(66,6);
	cprintf(" Price");
	gotoxy(1,8);
	int m=8;
	for(int j=0;j<9;j++)
	{
		if(ob_bar[j].qty!=0)
		{
		cprintf("  ");
		cout<<ob_bar[j].name;
		gotoxy(37,m);
		cout<<ob_bar[j].qty<<"            ";
		gotoxy(63,m);
		cout<<ob_bar[j].price*ob_bar[j].qty;
		cout<<endl;
		m++;
		}
	}
	cprintf("  ");
	for(int kl=0;kl<65;kl++)
	cprintf("-");
	gotoxy(1,m+1);
	cprintf("   Total");
	gotoxy(37,m+1);
	cprintf("=");
	gotoxy(63,m+1);
	cout<<ob_bills.ret_bar();
	textcolor(RED);
	gotoxy(1,m+3);
	cprintf("   Press 'r' or 'R' to return : ");
	char tobillscreen;
	returntobill:
	tobillscreen=getche();
	if(tobillscreen=='r'|| tobillscreen=='R')
	counter();
	else
	{
	gotoxy(33,m+3);
	cprintf(" ");
	cprintf("\b");
	goto returntobill;
	}
}

void end()
{
	clrscr();
	border();
	loading();
	clrscr();
	border();
	gotoxy(25,10);
	textcolor(RED);
	cprintf(" Transaction completed. Do return to us.");
	gotoxy(30,12);
	cprintf(" Have a safe journey!! ");

	room_det.close();
	bar_det.close();
	typroom_det.close();
	barmenu_det.close();


	delay(8000);
	exit(0);

}

void check()
{
	clrscr();
	border();
	textcolor(RED);
	int flag=0;
	room_det.open("room.dat",ios::in|ios::binary);
	gotoxy(13,11);
	cprintf(" Please enter your room number : ");
	int roomno;
	cin>>roomno;
	for(int i=0;(!room_det.eof());i++)
	{	room_det.read((char*)&ob_details,sizeof(ob_details));
		if(roomno==ob_details.num())
		{
		cout<<" Welcome back! ";
		getall(roomno);
		flag++;
		homescreen();
		}
	}
	if(flag==1)
	{
	cprintf(" \nSorry, no guest in the hotel has been alotted this number. ");
	delay(2000);
	main();
	}
}

void getall(int room)
{
	bar_det.open("bar.dat",ios::in|ios::binary);
	while(bar_det.read((char*)&ob_bills,sizeof(ob_bills)))
	{
		if(room==ob_bills.num())
		break;
	}
	typroom_det.open("struct_typroom.dat",ios::in|ios::binary);
	while(typroom_det.read((char*)&roomselect,sizeof(roomselect)))
	{
		if(roomselect[rtype].roomnum==room)
		break;
	}

	barmenu_det.open("struct_bar.dat",ios::in|ios::binary);
	while(barmenu_det.read((char*)&ob_bar,sizeof(ob_bar)))
	{
		if(ob_bar[0].roomnum==room)
		break;
	}


}

