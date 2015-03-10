#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
#include<bios.h>
int i=0;
int x,y=500,j,score=0,l=1,t=0,n=0,ap=100,apch=0,c=0,bk=0,hit=0,miss=0;
char msg[50];
void clear()
{       cleardevice();
	sprintf(msg,"HIT %d",hit);
	outtextxy(1,15,msg);
	*msg=NULL;
	sprintf(msg,"MISS %d",miss);
	outtextxy(500,15,msg);
	*msg=NULL;
	rectangle(150,50,450,450);
	line(150,ap-15,180,ap);
	line(150,ap+15,180,ap);
}
void play()
{	while(j>=0)
	{       fillellipse(x,j,10,10);
		if(bioskey(1))
		{       bk=bioskey(0);
			if(bk==7181)
			{	t=1;
				i=0;
			}
			else if(bk==20480)
			{	ap+=50;
				apch=1;
			}
			else if(bk==18432)
			{	ap-=50;
				apch=1;
			}
		}
		if(230+i==x&&ap==j)
		{       score++;
			hit++;
			clear();
			i=0;
			break;
		}
		else if(j==100)
			miss++;
		if(t==1)
		{	if(apch==1)
			{       i=0;
				apch=0;
			}
			line(200+i,ap,230+i,ap);
			line(230+i,ap,225+i,ap+10);
			line(230+i,ap,225+i,ap-10);
			i=i+50;
		}
		if(60+i==600)
		{	t=0;
			i=0;
		}
		j=j-50;
		delay(300);
		clear();
	 }
}
void main()
{       clrscr();
	int gd=DETECT;
	initgraph(&gd,0,"");
	setbkcolor(1);
	randomize();
	settextstyle(4,0,7);
	delay(1000);
	for(int i=0;i<=424;i+=40)
	{	outtextxy(i,200,"G");
		delay(50);
		cleardevice();
	}
	for(i=0;i<=380;i+=40)
	{	outtextxy(i,200,"N");
		outtextxy(424,200,"G");
		delay(50);
		cleardevice();
	}
	for(i=0;i<=340;i+=40)
	{	outtextxy(i,200,"I");
		outtextxy(380,200,"N");
		outtextxy(424,200,"G");
		delay(50);
		cleardevice();
	}
	for(i=0;i<=300;i+=40)
	{       outtextxy(i,200,"T");
		outtextxy(340,200,"I");
		outtextxy(380,200,"N");
		outtextxy(424,200,"G");
		delay(50);
		cleardevice();
	}
	for(i=0;i<=250;i+=40)
	{       outtextxy(i,200,"O");
		outtextxy(300,200,"T");
		outtextxy(340,200,"I");
		outtextxy(380,200,"N");
		outtextxy(424,200,"G");
		delay(50);
		cleardevice();
	}
	for(i=0;i<=204;i+=30)
	{       outtextxy(i,200,"O");
		outtextxy(250,200,"O");
		outtextxy(300,200,"T");
		outtextxy(340,200,"I");
		outtextxy(380,200,"N");
		outtextxy(424,200,"G");
		delay(50);
		cleardevice();
	}
	for(i=0;i<=160;i+=20)
	{       outtextxy(i,200,"H");
		outtextxy(204,200,"O");
		outtextxy(250,200,"O");
		outtextxy(300,200,"T");
		outtextxy(340,200,"I");
		outtextxy(380,200,"N");
		outtextxy(424,200,"G");
		delay(50);
		cleardevice();
	}
	for(i=0;i<=120;i+=20)
	{       outtextxy(i,200,"S");
		outtextxy(160,200,"H");
		outtextxy(204,200,"O");
		outtextxy(250,200,"O");
		outtextxy(300,200,"T");
		outtextxy(340,200,"I");
		outtextxy(380,200,"N");
		outtextxy(424,200,"G");
		delay(50);
		cleardevice();
	}
	outtextxy(120,200,"S");
	outtextxy(160,200,"H");
	outtextxy(204,200,"O");
	outtextxy(250,200,"O");
	outtextxy(300,200,"T");
	outtextxy(340,200,"I");
	outtextxy(380,200,"N");
	outtextxy(424,200,"G");
	delay(100);
	outtextxy(120,200,"SHOOTING");
	delay(1000);
	settextstyle(1,0,4);
	int menu;
	setbkcolor(0);
	while(1)
	{       cleardevice();
		gotoxy(1,1);
		printf("*******MENU*******\n1.ABOUT\n2.INSTRUCTIONS\n3.DEVELOPERS\n4.START\n5.EXIT\nEnter Your choice:[ ]\b\b");
		menu=getch()-48;
		if(menu==5)
			exit(0);
		if(menu==4)
			break;
		if(menu>4||menu<1)
		{	printf("Enter right choice.");
			delay(500);
		}
		else
		{       cleardevice();
			gotoxy(1,1);
			switch(menu)
			{   	case 1: printf("\t\t\t\tABOUT\n\nThe balloons will be moving from bottom to top.\nThe player should shoot the balloons.\nThe aim of the game is to shoot all the balloons.\n\nPress Enter to skip this menu.");
					getch();
					break;
				case 2: printf("\t\t\t\tINSTRUCTIONS\n\nTo hit the balloons press Enter at right time.\nWhen Enter is pressed the arrow starts moving to hit the balloon.\nthe height of the arrow can be altered up or down.\nThe arrow can be moved up by using up arrow button of keyboard.\nThe arrow can be moved down by using down arrow button of keyboard.\n\nPress Enter to skip This Menu.");
					getch();
					break;
				case 3: printf("\t\t\t\tDEVELOPERS\n\nCSE\nII year\n\nN.Anusha\nB.smitha\nN.deepika\nK.pavaniswarupa\nM.sunithasowjanya\n\nPress Enter to skip this menu.");
					getch();
					break;
			}
		}
	}
	cleardevice();

	clear();
	while(l<=15)
	{       x=180+50*(1+random(5));
		j=y;
		t=0;
		c=random(14)+2;
		setfillstyle(SOLID_FILL,c);
		setcolor(c);
		play();
		i=0;
		l++;
	}
	if(score==1)
	outtextxy(140,200,"YOU WON THE GAME.");
	else
	outtextxy(200,200,"GAME OVER.");
	getch();
}