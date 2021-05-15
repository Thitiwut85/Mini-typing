## **สวัสดี นี่คือเกม Mini-Typing**
คุณอยากลองเล่นเกมที่พัฒนามาจากภาษา C ไหม?
เราขอเสนอเกมฝึกพิมพ์ ที่สร้างขึ้นมาเพื่อความสนุกและเพิ่มทักษะในการพิมพ์ของคุณให้มากขึ้น

## **ภายในตัวเกมมีอะไรบ้าง?**
* ใช้แค่การพิมพ์อย่างเดียวในการเล่นเกมนี้
* ผู้เล่นสามารถเลือกระดับความยากของเกมได้ตามใจชอบ 
* สามารถเลือกระยะเวลาในการเล่นได้ 
* มีฟังก์ชันสำหรับรีเซ็ตสถิติของผู้เล่นที่เคยเล่นไว้ 
* ในตัวเกมจะมีตัวอักษรปรากฎขึ้นมาให้ผู้เล่นพิมพ์ตามให้ถูกต้อง ถ้าผู้เล่นพิมพ์ผิดจะมีการแสดงข้อความขึ้นว่าผู้เล่นพิมพ์ไม่ครบตามเวลาหรือพิมพ์ผิด 
แต่ถ้าชนะจะขึ้นว่าหมดเวลา พร้อมกับแสดงคะแนนกับเหรียญที่ได้และความเร็วว่าพิมพ์ได้กี่ตัวอักษรใน 1 นาที



## Code บางส่วน


```markdown
void startgame()
{       int score=0,level=1,mode=100,count=0;
	clock_t begin;int time_spent,speed;
	int r,letter,ch, ee;
	delay(500);
	system("cls");
	srand(time(NULL)) ; //initilizes random function and seed with time
	x=2;
	pos;
	setcolor(12);
	printf("Select Difficulty");pos;
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
			gotoxy(28,9);
			printf("time spent = %d sec",time_spent);
			
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
				printf("score = %d",score);//prints score
				gotoxy(37,10);
				printf("time spent = %d sec",time_spent);//prints time spent during game

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
		printf("You lost! Game Over!");
		else
		{       setcolor(11);
			printf("Times up! Game over!");
			pos;
			setcolor(13);
			if((speed>=40)&&(speed<=50))
			{	printf("Good Work !Keep it up!");pos;

				printf("You got silver medal");
			}
			else
			if(speed>50)
			{
				printf("Nice try! You got Gold medal");
			}
			else
			printf("Sorry no medal! you need practise..");
		}
		pos;
		printf("Total score is : %d",score);
		pos;

		printf("Your net speed = %d letter per minute",speed);

		getscore(score,speed,level);//เอาข้อมูลกับคะแนนลงไฟล์
		++x;
		pos;
		printf("1. play again");pos;
		printf("2. main menu");pos;
		printf("3. exit"); pos;
		printf("Enter your choice :");
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
```
## **ตัวอย่างภาพในเกม**

![Image](https://cdn.discordapp.com/attachments/814903344803741728/843160109030572052/Main_menu.PNG)
<br /> <br />
<br /> <br />
![Image](https://cdn.discordapp.com/attachments/814903344803741728/843160112759177236/Select_Difficulty.PNG)
<br /> <br />
<br /> <br />
![Image](https://cdn.discordapp.com/attachments/814903344803741728/843162349270990848/Time_set.PNG)
<br /> <br />
<br /> <br />
