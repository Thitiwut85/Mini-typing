#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<direct.h>
#include<stdlib.h>

static int x=1;//used for x cursor co-ordinate
#define pos gotoxy(33,x++) /*for cursor movement*/
#define ln  printf(".......................");
//.......................................................................................................................................................................
 COORD coord={0,0};
 void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//.......................................................................................................................................................................
void delay(unsigned int mseconds)//ฟังก์ชันดีเลย์
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}
//.......................................................................................................................................................................
void setcolor(int ForgC) //ฟังก์ชันเปลี่ยนสี
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }

//.................................................................................................................................................................................
void sett();//เวลาที่เล่น
int t=30;
int c=0;

char name[15];
void getscore(int score,int speed,int level);
void startgame();
void scoreboard();
void About_Game();
void help();
//...............................................................................................................................................................................
void rectangle(int x,int y,int l,int b)//สร้างสี่เหลี่ยม
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}

//................................................................................................................................................................................
int main()//ฟังก์ชันหลัก
{       int ch;

	time_t t;
	time(&t);
//	rectangle(0,0,70,15);
	x=1;
	system("cls");//cls คือเคลียร์หน้าจอ
	pos;
	setcolor(15) ;
	printf("Speed Typing");
	setcolor(10) ;
	pos;
	printf("%s",ctime(&t));
	pos;
    ln pos;
	if(c==0)
	   {	printf("Enter player's name::");
		gets(name);
	   }
	   c++;
	pos;ln pos;
		printf("#..MAIN MENU..#");pos;
		for(int testing=1; testing<=16; testing++){//ตรงนี้ไว้ดูสีว่าเลขไหน สีอะไร
			setcolor(testing) ;
			printf("%d ", testing);
		}
		setcolor(10) ;
		pos;
		ln
		pos;
		printf("1.Startgame");
		pos;
		printf("2.Scoreboard");
		pos;
		printf("3.Set the time limit::");
		pos;
		printf("4.Help");
		pos;
		printf("5.About game");
		pos;
		printf("0.Exit");
		pos;
		printf("Enter your choice::");
		scanf("%d",&ch);
		pos;
		switch(ch)
		{       case 1:startgame();break;
			case 2:scoreboard();break;
			case 3:sett();main();
			case 4:help();break;
			case 5:About_Game();break;
			case 0:system("cls");gotoxy(17,10);printf("Thank for Playing");delay(1000);exit(1);
			default:main();
		}

getch();
}

//.......................................................................................................................................................................
void startgame()
{       int score=0,level=1,mode=100,count=0;
	clock_t begin;int time_spent,speed;

	int r,letter,ch, ee;
//rectangle(0,0,70,15);
	delay(500);

	system("cls");
	srand(time(NULL)) ; //initilizes random function and seed with time
	x=2;
	pos;
	setcolor(12);
	printf("#Select Difficulty#");pos;
	ln
	pos;
	printf("1.Easy");
	pos;
	printf("2.Normal");
	pos;
	printf("3.Hard");
	pos;
	printf("4.Back to main menu");
	pos;
	scanf("%d",&level);
	if(level==4)
	main();

	else

	{   if(level==1)    //ถ้า level 1 คือตัวใหญ่
	    	mode=65;
	    if(level==2)    //ถ้า level 2 คือตัวเล็ก
			mode=97;
		int randx, randy;
		begin=clock();
		while(1)
		{       system("cls");
			time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

			if(time_spent>=t)
			break;
			r=rand()%1000;
			if(level==3){    //ถ้า level 3 คือตัวเล็กกับตัวใหญ่
				ee=rand()%2;
				if(ee==0){
					mode = 65;
				}
				else{
					mode=97;
				}

			}
			r=r%26+mode;
			
			gotoxy(20,8);
			printf("....Type the following character....");
			gotoxy(37,9);
			printf("time spent=%d sec",time_spent);
			
			randx = rand()%108;
			randx++;
			randy = rand()%27;
			while(randy < 10){
				randy = rand()%27;
			}
			gotoxy(randx,randy);
			printf(" %c",r); //prints random character
			letter=getch();

			if(letter!=r)
			break;
			else
			{       count++;
				score=score+10;
				gotoxy(28,10);
				printf("score=%d",score);//prints score
				gotoxy(37,10);
				printf("time spent=%d sec",time_spent);//prints time spent during game

				if(level==1)
				delay(400);
				if(level==2)
				delay(200);
				if(level==3)
				delay(100);
			}
		}
		gotoxy(26,x);

		delay(400);

		setcolor(5);
		++x;
		pos;
		speed=(count*60)/time_spent ;

		if(time_spent<t-1)
		printf("You  are looser!loser!loser!Game Over!");
		else
		{       setcolor(11);
			printf("Times up !Game over!");
			pos;
			setcolor(13);
			if((speed>=40)&&(speed<=50))
			{	printf("Good Work !Keep it up!");pos;

				printf("You got silver medal");
			}
			else
			if(speed>50)
			{
				printf("Nice work! You got Gold medal");
			}
			else
			printf("Sorry no medal! you need practise..");
		}
		pos;
		printf("Total score is ::%d",score);
		pos;

		printf("Your net speed=%d letter per minute",speed);

		getscore(score,speed,level);//เอาข้อมูลกับคะแนนลงไฟล์
		++x;
		pos;
		printf("1.# play again #");pos;
		printf("2.# main menu #");pos;
		printf("3.exit"); pos;
		printf("Enter your choice::");
		scanf("%d",&ch);
		switch(ch)
		{
		      case 1:startgame();break;//recursive call
		      case 2:main();break;
		      case 3:system("cls");gotoxy(17,10);printf("Thank for Playing");delay(1000);exit(1);
		      default:pos;printf("wrong choice!");pos;
				main();
		}

	}

}

//.......................................................................................................................................................................
void sett()  //set time limit
{
	int ch;
	system("cls");
	//rectangle(0,0,70,15);
	setcolor(11);
	x=5;
	pos;
	printf("Set the time limit for game::");
	pos;
	ln
	pos;
	printf("press 0 for 30 second") ;pos;
	printf("press 1 for 1 minute"); pos;
	printf("press 2 for 2 minute");pos;
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:t=30;break;
		case 1:t=60;break;
		case 2:t=120;break;
		default:main();
	}
}

//........................................................................
void help()//คำแนะนำในการใช้
{
	system("cls");
	//rectangle(0,0,70,15);
	setcolor(14);
	gotoxy(40,4);
	printf("#......Rules of the Game......#");gotoxy(15,6);
	printf("=> Enter your name as player name");gotoxy(15,7);
	printf("=> Set the time limit under option 3 in main menu(default limit is 30 sec)");gotoxy(15,8);
	printf("=> select the level and get started :");gotoxy(15,9);
	printf("=> Characters are displayed and random, you have to type them as fast as you can..");gotoxy(15,10);
	printf("=> Avoid incorrect typing otherwise game will be over..");
	getch();main();
}

//.......................................................................................................................................................................
void About_Game()
{       system("cls");
	gotoxy(7,7);
	printf("Hello, this game is mini project");gotoxy(7,8);
	printf("Thank for credit from  Shashi Kumar");
    getch();
    main();
}
//.........................................................................
void getscore(int score,int speed,int level)//ฟังก์ชันเอาคะแนนลงไฟล์
{
	FILE *fp1, *fp2;
	fp1=fopen("scoreboard.txt","a");
	fp2=fopen("scoreboard_copy.txt","a");
	pos;
	if(fp1==NULL)
		printf("error in opening file");
	if(fp2==NULL)
		printf("error in opening file");
	fprintf(fp1,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,level);
	fprintf(fp2,"\nname=%s   score=%d    speed=%d    level=%d",name,score,speed,level);
	fclose(fp1);
	fclose(fp2);
	pos;
	printf("score updated");
}

//.......................................................................................................................................................................
void scoreboard()//ฟังก์ชันหน้าโชว์คะแนน
{       int ch,x=12, y=4;
	FILE *fp1, *fp2;
    char file1[] ="scoreboard.txt";
    char file2[] ="scoreboard_copy.txt";
    char curr;
    int del, line_number = 0;
	system("cls");
	printf("\t\t\t....The scores are...\n");
	fp1 = fopen(file1,"r");
    fp2 = fopen(file2, "r");
	while((ch=fgetc(fp2))!=EOF){	
		printf("%c",ch);
		if(ch == '\n'){
			gotoxy(x,y);
			y++;
		}
	}
	printf("\n\nEnter the line number you want to delete : ");
    scanf("%d", &del);
    fp1 = fopen(file1,"r");
    fp2 = fopen(file2, "w");
    curr = getc(fp1);
    if(curr!=EOF) {line_number =1;}
    while(1){
      if(del != line_number)
        putc(curr, fp2);
        curr = getc(fp1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }
    fclose(fp1);
    fclose(fp2);
	getch();
	main();
}