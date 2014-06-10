#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

class bills
{
	int roomnum;
	long roombill,barbill,bill;
	float hotelbill;
	public:
	friend restbill;
	bills()
	{
		roombill=barbill=hotelbill=bill=0;
	}
	void bar_bill(int);
	void room_bill();
	void net_bill(int &);
	int num()
	{ return roomnum; }
	int &numadd()
	{ return roomnum; }
	long ret_bill()
	{ return bill; }
	long ret_room()
	{ return roombill; }
	float ret_res()
	{ return hotelbill; }
	float &ret_resadd()
	{ return hotelbill; }
	long ret_bar()
	{ return barbill; }
	void setroom(int a)
	{ roomnum=a; }

}ob_bills;

fstream rest_det;

class restbill
{       public:
	int roomno;
	float hotelbill;
	void change()
	{	roomno=ob_bills.roomnum;
		hotelbill=ob_bills.hotelbill;
	}
}obfile;

void mainmenu();
void homescreen();
void counter();
char cha;
class southindian
	{
		char name[80];
		char displayprice[10];
		long double price;
		int qty;
	 public:
		char *retname(){ return name; }
		char *retdprice(){ return displayprice; }
		long double retprice(){ return price; }
		int retqty(){ return qty; }
		int &retaddqty(){ return qty; }
	}ob0[8],obm[7][8]={{
		"1. Plain Dosa",			"Rs. 50.00",50,0,
		"2. Masala Dosa",			"Rs. 55.00",55,0,
		"3. Spring Dosa",			"Rs. 70.00",70,0,
		"4. Plain Rava Dosa",			"Rs. 55.00",55,0,
		"5. Masala Rava Dosa",			"Rs. 65.00",65,0,
		"6. Chataka Idli",			"Rs. 45.00",45,0,
		"7. Mendu Vada",			"Rs. 50.00",50,0,
		"8. Uttapam",				"Rs. 45.00",45,0},
		{"1. Paneer Tikka Masala",		"Rs. 100.00",100,0,
		"2. Kadhai Masala",			"Rs. 95.00",95,0,
		"3. Tava Masala",			"Rs. 90.00",90,0,
		"4. Angoori Paneer Masala",		"Rs. 100.00",100, 0,
		"5. Cheese Paneer Masala",		"Rs. 105.00",105,0,
		"6. Bhindi Masala",			"Rs. 85.00",85,0,
		"7. Mutter Paneer",			"Rs. 90.00",90,0,
		"8. Special Galactican Punjabi",	"Rs. 115.00",115,0},
		{"1. Veg. Burger",			"Rs. 30.00",30,0,
		"2. Hotdog",				"Rs. 40.00",40,0,
		"3. Chinese Samosa (2 pieces)",		"Rs. 35.00",35,0,
		"4. Pani Puri(6 pieces)",		"Rs. 15.00",15,0,
		"5. Aloo Chaat",			"Rs. 40.00",40,0,
		"6. Paav Bhaji",			"Rs. 50.00",50,0,
		"7. Chole Bhature",			"Rs. 50.00",50,0,
		"8. Spicy Cutlets (2 pieces)", 		"Rs. 35.00",35,0},
		{"1. Butter Roti",			"Rs. 15.00",15,0,
		"2. Plain Roti",			"Rs. 10.00",10,0,
		"3. Rumali Roti", 			"Rs. 25.00",25,0,
		"4. Aloo Paneer Paratha",		"Rs. 35.00",35,0,
		"5. Methi ke Theple",			"Rs.15.00",15,0,
		"6. Mixed Veg. Paratha",		"Rs. 40.00",40,0,
		"7. Pyaz ki Roti",			"Rs. 20.00",20,0,
		"8. Tandoori Naan",			"Rs. 17.00",17,0},
		{"1. Gulab Jamun(per piece)",		"Rs. 10.00",10,0,
		"2. Rasgulla(per piece)",		"Rs. 8.00",8,0,
		"3. Basudi",				"Rs. 30.00",30,0,
		"4. Lassi",				"Rs. 20.00",20,0,
		"5. Shrikhand",				"Rs. 25.00",25,0,
		"6. Indian Alaska(sweet, per piece)",	"Rs. 18.00",18,0,
		"7. Chocolate Brownie(per piece)",	"Rs. 30.00",30,0,
		"8. Mixed Fruit Pudding",		"Rs. 35.00",35,0},
		{"1. Mixed Fried Rice",			"Rs. 70.00",70,0,
		"2. Gujarati Khichadi",			"Rs. 65.00",65,0,
		"3. Manchurian Chinese",		"Rs. 90.00",90,0,
		"4. Chinese Dragon Rice",		"Rs. 85.00",85,0,
		"5. Veg. Biryani",			"Rs. 82.00",82,0,
		"6. Veg. Pulao",			"Rs. 80.00",80,0,
		"7. Jeera Rice",			"Rs. 65.00",65,0,
		"8. Kashmiri Pulao",			"Rs. 75.00",75,0},
		{"1. Sweet Corn Soup",			"Rs. 70.00",70,0,
		"2. Vegetable Soup",			"Rs. 75.00",75,0,
		"3. Carrot Soup",			"Rs. 80.00",80,0,
		"4. Cream & Tomato Soup",		"Rs. 75.00",75,0,
		"5. Tangy Tomato & Noodles Soup",	"Rs. 85.00",85,0,
		"6. Tender Coconut",			"Rs. 70.00",70,0,
		"7. Manchurian Soup",			"Rs. 85.00",85,0,
		"8. Hot & Sour Soup",			"Rs. 70.00",70,0}};


void wrongchoice()
{       gotoxy(25,14);
	textcolor(RED);
	cprintf("Wrong Choice! Please Enter your choice again.");
	delay(3000);
	clrscr();
}

void bills()
{
	clrscr();
	textcolor(WHITE);
	for(int i=0;i<79;i++)
		cprintf("=");
	gotoxy(1,25);
	for(i=0;i<79;i++)
		cprintf("=");
	gotoxy(1,1);
	textcolor(CYAN);
	gotoxy(32,3);
	cprintf(" RESTAURANT BILL");
	gotoxy(1,6);
	textcolor(GREEN);
	cprintf(" Item ");
	gotoxy(33,6);
	cprintf(" Quantity ");
	gotoxy(66,6);
	cprintf(" Price");
	gotoxy(1,8);
	int m=8;
	for(int j=0;j<7;j++)
	{
		for(int io=0;io<8;io++)
		if(obm[j][io].retqty()!=0)
		{
		cout<<"  "<<obm[j][io].retname()+3;
		gotoxy(37,m);
		cout<<obm[j][io].retqty();
		gotoxy(63,m);
		cout<<obm[j][io].retprice()*obm[j][io].retqty();
		cout<<endl;
		m++;
		}
	}
	cout<<"  ";
	for(int kl=0;kl<65;kl++)
	cprintf("-");
	gotoxy(1,m+1);
	cprintf("   Total");
	gotoxy(37,m+1);
	cprintf("=");
	gotoxy(63,m+1);
	cout<<ob_bills.ret_res();
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
	cout<<" ";
	cout<<"\b";
	goto returntobill;
	}
}

void food();

void punjabi();

void mainmenu()
{     	clrscr();
	obfile.change();
	rest_det.open("rest.dat",ios::in|ios::out|ios::binary);
	rest_det.read((char*)&obfile,sizeof(obfile));
	textcolor(WHITE);
	for(int i=0;i<79;i++)
		cprintf("=");
	gotoxy(1,25);
	for(i=0;i<79;i++)
		cprintf("=");
	textcolor(BLUE);
	gotoxy(37,4);
	cprintf("Main Menu");
	textcolor(GREEN);
	char arr[7][40]={"[1]. South Indian Food","[2]. Punjabi Food","[3]. Snacks","[4]. Rotis & Parathas","[5]. Deserts & Sweets","[6]. Rice dishes","[7]. Soups"};
	for(i=0;i<7;i++)
	{
		gotoxy(33,i+6);
		cprintf(arr[i]);
	}
	textcolor(YELLOW);
	gotoxy(28,20);
	cprintf("Select your choice to continue: ");
	gotoxy(28,22);
	textcolor(GREEN);
	cprintf("Press E or e to go to Main Screen.");
	textcolor(YELLOW);
	cha=getche();
	switch(cha)
	{
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
			food();
	break;
	case 'e':
	case 'E':
			obfile.change();
			rest_det.open("rest.dat",ios::in|ios::out|ios::binary);
			rest_det.write((char*)&obfile,sizeof(obfile));
			homescreen();
	break;
	default :       wrongchoice();
			mainmenu();
	}
	gotoxy(25,22);
}

void food()
{       label:
	clrscr();
	textcolor(WHITE);
	for(int i=0;i<79;i++)
		cprintf("=");
	gotoxy(1,25);
	for(i=0;i<79;i++)
		cprintf("=");
	textcolor(GREEN);
	gotoxy(5,3);
	cprintf("Name");
	gotoxy(65,3);
	cprintf("Price");
	textcolor(BLUE);
	for (int j=0;j<7;j++)
		if(int (cha-49)==j)
			for (int k=0;k<8;k++)
			ob0[k]=obm[j][k];
	for (i=0;i<8;i++)
		{       gotoxy(3,i+5);
			cprintf(ob0[i].retname());
			gotoxy(65,i+5);
			cprintf(ob0[i].retdprice());
		}
	textcolor(GREEN);
	gotoxy(20,23);
	cprintf("Press R or r to return to Restaurant Main Menu.");
	gotoxy(10,16);
	textcolor(YELLOW);
	cprintf("Select your choice to continue: ");
	int choice;
	choice=getche();
	if ((choice>'0'&&choice<'9')||(choice=='R'||'r'))
	{       if(choice>'0'&&choice<'9')
		{	gotoxy(10,18);
			cprintf("Are you sure want to order it?(y/n): ");
			char ch1=getche();
			if(ch1=='y')
			{       obm[int(cha-49)][int(choice-49)].retaddqty()++;
				ob_bills.ret_resadd()+=obm[int(cha-49)][int(choice-49)].retprice();
				gotoxy(10,20);
				cprintf("Do you want to order more(y/n): ");
				char ch2=getche();
				if(ch2=='y')
					food();
				else if(ch2=='n')
					mainmenu();
				else
			{	wrongchoice();
					food();
				}
			}
			else if (ch1=='n')
				goto label;
			else
			{	wrongchoice();
				food();
			}
		}
		else
			mainmenu();
	 }
	 else
	 {	wrongchoice();
		food();
	 }
}

