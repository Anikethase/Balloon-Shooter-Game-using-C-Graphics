

/*  Program for to Made a Balloon Shooter game */
/*   Main Program for this  */

/*	Aniket V. Hase(652)		*/

	#include<stdio.h>
	#include<graphics.h>
	#include<conio.h>
	#include<stdlib.h>
	#include<dos.h>
	#include<string.h>
	#include<time.h>

	void main_screen();        //  All Function Prototypes...
	void level_1();
	void level_2();
	void level_3();
	void draw_screen1();
	void draw_screen2();
	void draw_shaft(int, int, int);
	void draw_balloon(int, int, int);
	void show_score (int, int, int, int, int);
	void Sound();
	void Sound_1();

	int i, point;
	int chance, success, score, chance_end, level;
	int shaft_x, shaft_y, shaft_color;
	int balloon_x, balloon_y, balloon_color;
	union REGS ii,oo;

	int main()
		{
			int graphdriver = DETECT, graphmode;
			initgraph(&graphdriver, &graphmode,"C:\\TC\\BGI");
			main_screen();		//  Function Call to main_screen..
			getch();
			closegraph();

			return 0;
		}

	//  Function Program of Main Screen of Balloon Shooter Game...

 void main_screen()
	{
		int i;
		settextstyle(8,HORIZ_DIR,1);
		setcolor(15);
		outtextxy(150,100, "**  WELCOME IN BALLOON SHOOTER GAME  **");
		setcolor(9);
		outtextxy(390,200,"** Presented By **");
		settextstyle(0,HORIZ_DIR,0);
		outtextxy(410,240,"Aniket V. Hase");
		outtextxy(410,260,"Atul R. Punde");
		outtextxy(410,280,"Vrushabh N. Shinde");
		setcolor(14);
		outtextxy(100,350,"Press 'S' To Play The Game...");

		s :if(getch()=='s' || getch()=='S')
			{
				nosound();
				level_1();     // Function Call to level_1..
			}
		else
			{
					setcolor(5);
					outtextxy (150,370," Sorry, You Enters Wrong Key. ");
					outtextxy (150,380, "--> Please Press 'S' for Play the Game..");
				 goto s;
			}
		nosound();
		getch();
	}


	//  Function Program to Draw Screen for level 1..

	void draw_screen1()
		{
			int i;
			setfillstyle(1,15);
			bar(0,0,150,20);
			setcolor(1);
			outtextxy(30,5,"Score Board");
			setfillstyle(1,2);
			bar(0,20,150,250);
			setcolor(15);
			outtextxy(30,40,"Total Chance");
			outtextxy(30,80,"Success");
			outtextxy(30,120,"Score");
			outtextxy(30,160,"Level");
			setcolor(1);
			setfillstyle(1,15);
			bar(0,255,150,275);
			outtextxy(30,260,"Control key");
			setfillstyle(1,2);
			bar(0,275,150,479);

			setcolor(15);
			outtextxy(30,290,"UP");
			setcolor(0);
			for(i=0;i<=5;i++)
				{
					line (100-i,285+i,100+i,285+i);
				}
			line(100,290,100,300);

			setcolor(15);
			outtextxy(30,330,"DOWN");
			setcolor(0);
			for(i=0;i<=5;i++)
				{
					line(95+i,330+i,105-i,330+i);
				}
			line(100,320,100,330);

			setcolor(15);
			outtextxy(30,370,"Shoot");
			setcolor(0);
			outtextxy(100,370,"Enter");

			setcolor(15);
			outtextxy(30,410,"Exit");
			setcolor(0);
			outtextxy(100,410,"Esc");
			setfillstyle(1,1);
			bar(151,0,639,479);
	}

	//	Function Program for Draw Screen for level 2..

	void draw_screen2()
		{
			int i;
			setfillstyle(1,15);
			bar(0,0,150,20);
			setcolor(1);
			outtextxy(30,5,"Score Board");
			setfillstyle(1,3);
			bar(0,20,150,250);
			setcolor(15);
			outtextxy(30,40,"Total Chance");
			outtextxy(30,80,"Success");
			outtextxy(30,120,"Score");
			outtextxy(30,160,"Level");
			setcolor(1);
			setfillstyle(1,15);
			bar(0,255,150,275);
			outtextxy(30,260,"Control key");
			setfillstyle(1,3);
			bar(0,275,150,479);

			setcolor(15);
			outtextxy(30,290,"UP");
			setcolor(0);
			for(i=0;i<=5;i++)
				{
					line (100-i,285+i,100+i,285+i);
				}
			line(100,290,100,300);

			setcolor(15);
			outtextxy(30,330,"DOWN");
			setcolor(0);
			for(i=0;i<=5;i++)
				{
					line(95+i,330+i,105-i,330+i);
				}
			line(100,320,100,330);

			setcolor(15);
			outtextxy(30,370,"Shoot");
			setcolor(0);
			outtextxy(100,370,"Enter");

			setcolor(15);
			outtextxy(30,410,"Exit");
			setcolor(0);
			outtextxy(100,410,"Esc");
			setfillstyle(1,1);
			bar(151,0,639,479);
	}

	//  Function Program for Draw Score..

	void show_score(int chance,int success,int score ,int level,int color)
		{
			char str[5];
			setcolor(color);

			gcvt(chance,5,str);  ///  gcvt() is inbuilt function described in stdlib.h...
			outtextxy(70,60,str);
			gcvt(success,5,str);  //  gcvt() uses for buffer the string..
			outtextxy(70,100,str);
			gcvt(score,5,str);
			outtextxy(70,140,str);
			gcvt(level,5,str);
			outtextxy(70,180,str);

		}

	//   Function Program for Draw Shaft..

	void draw_shaft(int x, int y, int color)
		{
			setcolor(color);
			rectangle(x-1,y-1,x-30,y+1);
			line(x,y,x-30,y);
			line(x,y,x-6,y-4);
			line(x,y,x-6,y+4);

		}

 //  Function Program to Draw Balloon..

 void draw_balloon( int x,int y,int c)
		{
			int i;
			setcolor(c);
			setfillstyle(1,c);
			sector(x,y,0,180,10,10);
			for(i=0;i<=13;i++)
					line(x-10+i,y+i,x+10-i,y+i);
		}


	//	Function Program For Sound

	void Sound()
	{
		for(i=100;i<2000;i=i+100)    //Sound Notification At Beginning Of Each Level
			{
				sound(i);
				delay(100);
				nosound();
			}
	}

	void Sound_1()
	{
		for(i=200;i<2000;i=i+200)    //Sound Notification At Beginning Of Each Level
			{
				sound(i);
				delay(100);
				nosound();
			}
	}

 //  Function Program for Level 1...

 void level_1()
		{
			clrscr();
			setcolor(9);
			settextstyle(8,HORIZ_DIR,1);
			outtextxy(150,100,"** Welcome in Level 1 **");
			setcolor(14);
			outtextxy(120,200,"Press Any Key To Continue...");
			getch();
			settextstyle(0,HORIZ_DIR,0);
			Sound();
			draw_screen1(); 		 ///   Function Call to draw_screen..
			chance=0; success=0; score=0; chance_end=0; level=1;
			shaft_x=185; shaft_y=200; shaft_color=15;
			balloon_x=400; balloon_y=400; balloon_color=14;

			show_score (chance,success,score,level,0);       // Show initial score..
			draw_shaft(shaft_x,shaft_y,shaft_color);     //		Function Call to draw_shaft..
			draw_balloon(balloon_x,balloon_y,balloon_color);		//	Function Call to draw_balloon..

			while(1)
				{
					chance_end=0;		//initialize chance..
					while(!chance_end)
						{
									 // while not chance end..
									 // Until a key is hited ,move the balloon up..
							 while (!kbhit())
									{
										delay(20);		// delay() used for	wait 20 miliseconds..
										balloon_color=1;	//	To irrage balloon with screen color
										draw_balloon(balloon_x,balloon_y,balloon_color);  // Function Call to draw_balloon..
										balloon_y--;      	// 	Move up and draw in new place
										balloon_color=14;
										draw_balloon(balloon_x,balloon_y,balloon_color);  //  Function Call to draw_balloon...
									}

								ii.h.ah=0;
								int86(22,&ii,&oo);
								if(oo.h.al==0)
									{
												//	if the pressed key was a function key..
											switch(oo.h.ah)
												{
													case 72:	 // 72 for Press up button..
														{
															shaft_color=1; 	//	Arrange shaft from old place..
															draw_shaft(shaft_x,shaft_y,shaft_color);	//	Function Call to draw_shaft..
																		 //	draw shaft in new place..
															shaft_y-=5;
															shaft_color=15;
															draw_shaft(shaft_x,shaft_y,shaft_color);
															break;
														}
													case 80:	 //	80 for Press down button..
														{
															shaft_color=1;
															draw_shaft(shaft_x,shaft_y,shaft_color);		//	 Function Call to draw_shaft..
															shaft_y+=5;
															shaft_color=15;
															draw_shaft(shaft_x,shaft_y,shaft_color);	//	Function Call to draw_shaft..
															break;
														}
												}	//	End of switch(oo.h.ah)..
									}	//	End of if()..
								else
									{
										 switch(oo.h.al)
											 {
													case 13: {	// ASCII Value for enter key is 13..
																		// Press enter key to hit balloon..
														// Now do while loop for move both balloon and shaft until the balloon is being hitted, or the shaft goes outside of boundary..
													do{
														 delay(20);
														 balloon_color=1;
														 draw_balloon(balloon_x,balloon_y,balloon_color);	//	Function Call to draw_balloon..
														 balloon_y--;
														 balloon_color=14;
														 draw_balloon(balloon_x,balloon_y,balloon_color);	//	Function Call to draw_balloon..
														 shaft_color=1;
														 draw_shaft(shaft_x,shaft_y,shaft_color);	//	Function Call to draw_shaft..
														 shaft_x+=5;
														 shaft_color=15;
														 draw_shaft(shaft_x,shaft_y,shaft_color);  	//	Function Call to draw_shaft..
																 //	check if baloon is hitted
														 if(shaft_x>balloon_x-10 && shaft_x<balloon_x+10 && shaft_y>balloon_y-10 && shaft_y<balloon_y+10)
															 {
																	 for(i=800;i<=1000;i+=20)
																			{
																				 sound(1000);
																				 delay(5);
																			}
																	 nosound();
																	 balloon_color=1;
																	 draw_balloon(balloon_x,balloon_y,balloon_color);	//	Function Call to draw_balloon..
																	 shaft_color=1;
																	 draw_shaft(shaft_x,shaft_y,shaft_color);		//	Function Call to draw_shaft..
																	 show_score(chance,success,score,level,3); 	//	Function Call to show_score..
																	 chance++;
																	 success++;
																	 score+=10;
																	 point=score;
																	 show_score(chance,success,score,level,1); //	Function Call to show_score..
																	 chance_end=1;
																//	set position of the shaft and balloon for next chance
																	 shaft_x=185;
																	 shaft_y=200; 		//	get a random x coordinate of Shaft whether it must be between 300 and 600..
																		if (point>=50)
																				{
																					level_2();
																				}
																		do{
																					balloon_x=rand()%600;
																			}while(balloon_x<300);
																		balloon_y=400;	//	y is fixed
															 }
														 else
														//	check if balloon or shaft over the boundaries..
															 if (shaft_x>640 || balloon_y<0)
																	{
																	//	irrage both balloon and shaft..
																		 balloon_color=1;
																		 draw_balloon(balloon_x,balloon_y,balloon_color);	//	Function Call to draw_balloon..
																		 shaft_color=1;
																		 draw_shaft(shaft_x,shaft_y,shaft_color); //	Function Call to draw_shaft..
																		 show_score(chance,success,score,level,3); //	Function Call to show_score..
																		 chance++;
																		 show_score(chance,success,score,level,0); //	Function Call to show_score..
																		 chance_end=1;
																		 shaft_x=185;
																		 shaft_y=200;
																		 do{
																					 balloon_x=rand()%600;
																		 }while(balloon_x<300);
																		 balloon_y=400;
																	}	//	End of if..
															}	while(!chance_end);
														break;
													}	//	End of case 13 :
													case 27:     //	ESC key...
														{
															 closegraph();
															 exit(1);
														}
											 }	//	End of switch(oo.h.al)..
									}	//	End of else..
						}	//	End of while(!chance_end)..
				}	//	End of while(1)..
		}	//	End of level_1..

	//	Function Program for Level 2 ...

	void level_2()
		{
			char ch;
	//		char string[10];
			chance=0, success=0, score=0, chance_end=0, level=2;
			shaft_x=185, shaft_y=200, shaft_color=15;
			balloon_x=400, balloon_y=400, balloon_color=14;

			setcolor(1);
			clrscr();
			Sound_1();
			setcolor(1);
			settextstyle(8,HORIZ_DIR,1);
			outtextxy(250,130,"**Level 1 Over**");
			setcolor(14);
			outtextxy(180,250,"--> Press Any Key To Continue...");
			getch();
			clrscr();
			settextstyle(8,HORIZ_DIR,1);
			setcolor(9);
			outtextxy(150,100, "**  Welcome in level TWO  **");

			setcolor(14);
			outtextxy(100,200," --> Press '2' for Play level Two <-- ");
			settextstyle(0,HORIZ_DIR,0);
		r:	if(getch()=='2')
				{
					nosound();
					Sound();
					draw_screen2();

				//	show initial score..
					show_score (chance,success,score,level,0);
					draw_shaft(shaft_x,shaft_y,shaft_color);
					draw_balloon(balloon_x,balloon_y,balloon_color);

					while(1)
					 {
						chance_end=0;	//	initialize chance..
						while (!chance_end)
							{
							//	while not chance end..
							//	until a key is hited ,move the balloon up..
								while (!kbhit())
								 {
									delay(10);	//	wait 10 milliseconds
									balloon_color=1;	// To irrage balloon with screen colour..
									draw_balloon(balloon_x,balloon_y,balloon_color);
								//	move up and draw in new place..
									balloon_y--;
									balloon_color=14;
									draw_balloon(balloon_x,balloon_y,balloon_color);
								 }
								ii.h.ah=0;
								int86(22,&ii,&oo);
								if(oo.h.al==0)
									{
									//	if the pressed key was a function key..
										switch(oo.h.ah)
											{
												 case 72: 	//	for up key..
													{
													//	irrage shaft from old place..
														shaft_color=1;
														draw_shaft(shaft_x,shaft_y,shaft_color);
													//	draw shaft in new place..
														shaft_y=5;
														shaft_color=15;
														draw_shaft(shaft_x,shaft_y,shaft_color);
														break;
													}
												 case 80: 	//	for down Key..
													{
														 shaft_color=1;
														 draw_shaft(shaft_x,shaft_y,shaft_color);
														 shaft_y+=5;
														 shaft_color=15;
														 draw_shaft(shaft_x,shaft_y,shaft_color);
														 break;
													}
											}
									}
								else
									{
										switch(oo.h.al)
											 {
												case 13:	//	enter key was pressed to hit balloon..
													{
													//	move both balloon and shaft until the balloon is being hitted, or the shaft goes outside of boundary..
														do{
															delay(10);
															balloon_color=1;
															draw_balloon(balloon_x,balloon_y,balloon_color);
															balloon_y--;
															balloon_color=14;
															draw_balloon(balloon_x,balloon_y,balloon_color);
															shaft_color=1;
															draw_shaft(shaft_x,shaft_y,shaft_color);
															shaft_x+=5;
															shaft_color=15;
															draw_shaft(shaft_x,shaft_y,shaft_color);
														 //	check if balloon is hitted..
															if(shaft_x>balloon_x-10 && shaft_x<balloon_x+10 && shaft_y>balloon_y-10 && shaft_y<balloon_y+10)
															 {
																 for(i=800;i<=1000;i+=20)
																			{
																				 sound(1000);
																				 delay(8);
																			}
																nosound();
																balloon_color=1;
																draw_balloon(balloon_x,balloon_y,balloon_color);
																shaft_color=1;
																draw_shaft(shaft_x,shaft_y,shaft_color);
																show_score(chance,success,score,level,3);
																chance++;
																success++;
																score+=10;
																point=score;
																show_score(chance,success,score,level,1);
																chance_end=1;
															//	set position of the shaft and balloon for next chance..
																shaft_x=185;
																shaft_y=200;	//	get a random x coordinate of balloon whether it must be between 300 and 600
																if(point>=100)
																	{
																		level_3();
																	}		//	End of if(point>=100)
																do{
																		 balloon_x=rand()%600;
																	}while(balloon_x<300);
																balloon_y=400;	//	y is fixed..
															 }
															 else
															//	Check if balloon or shaft over the boundaries..
																if (shaft_x>640 || balloon_y<0)
																 {
																//	Irrage both balloon and shaft
																	balloon_color=1;
																	draw_balloon(balloon_x,balloon_y,balloon_color);
																	shaft_color=1;
																	draw_shaft(shaft_x,shaft_y,shaft_color);
																	show_score(chance,success,score,level,3);
																	chance++;
																	show_score(chance,success,score,level,0);
																	chance_end=1;
																	shaft_x=185;
																	shaft_y=200;
																	do{
																		 balloon_x=rand()%600;
																		}while(balloon_x<300);
																	balloon_y=400;
																 }
														}while(!chance_end);
													 break;
													}
												case 27:
													{
														closegraph();
														exit(1);
													}
											}	//  End of switch(oo.h.al)..
									}	//	End od else..
							}	//	End of while(!chance_end)..
					 }	// End of while(1)..
				}	// End of if(getch=='2')..
			else
				{
					setcolor(5);
					outtextxy(100,300,"--> Wrong Key ! Please Enter The Right Key");
					goto r;
				}	//	End of else...
			nosound();
			getch();
			closegraph();

		}	// End of level_2..


	//	Function Program for Level 3 ...

	void level_3()
		{
			char ch;
			char string[5];
			chance=0, success=0, score=0, chance_end=0, level=3;
			shaft_x=185, shaft_y=200, shaft_color=15;
			balloon_x=400, balloon_y=400, balloon_color=14;

			setcolor(1);
			clrscr();
			Sound_1();
			setcolor(1);
			settextstyle(8,HORIZ_DIR,1);
			outtextxy(250,130,"** Level 2 Over **");
			setcolor(14);
			outtextxy(180,250,"--> Press Any Key To Continue...");
			getch();
			clrscr();
			settextstyle(8,HORIZ_DIR,1);
			setcolor(9);
			outtextxy(150,100, "** Welcome in level THREE **");

			setcolor(14);
			outtextxy(100,200," --> Press '3' for Play level Three <-- ");
			settextstyle(0,HORIZ_DIR,0);
		r:	if(getch()=='3')
				{
					nosound();
					Sound();
					draw_screen1();

				//	show initial score..
					show_score (chance,success,score,level,0);
					draw_shaft(shaft_x,shaft_y,shaft_color);
					draw_balloon(balloon_x,balloon_y,balloon_color);

					while(1)
					 {
						chance_end=0;	//	initialize chance..
						while (!chance_end)
								{
							//	while not chance end..
							//	until a key is hited ,move the balloon up..
								while (!kbhit())
								 {
									delay(7);	//	wait 7 milliseconds
									balloon_color=1;	// To irrage balloon with screen colour..
									draw_balloon(balloon_x,balloon_y,balloon_color);
								//	move up and draw in new place..
									balloon_y--;
									balloon_color=14;
									draw_balloon(balloon_x,balloon_y,balloon_color);
								 }
								ii.h.ah=0;
								int86(22,&ii,&oo);
								if(oo.h.al==0)
									{
									//	if the pressed key was a function key..
										switch(oo.h.ah)
											{
												 case 72: 	//	for up key..
													{
													//	irrage shaft from old place..
														shaft_color=1;
														draw_shaft(shaft_x,shaft_y,shaft_color);
													//	draw shaft in new place..
														shaft_y=5;
														shaft_color=15;
														draw_shaft(shaft_x,shaft_y,shaft_color);
														break;
													}
												 case 80: 	//	for down Key..
													{
														 shaft_color=1;
														 draw_shaft(shaft_x,shaft_y,shaft_color);
														 shaft_y+=5;
														 shaft_color=15;
														 draw_shaft(shaft_x,shaft_y,shaft_color);
														 break;
													}
											}
									}
								else
									{
										switch(oo.h.al)
											 {
												case 13:	//	enter key was pressed to hit balloon..
													{
													//	move both balloon and shaft until the balloon is being hitted, or the shaft goes outside of boundary..
														do{
															delay(7);
															balloon_color=1;
															draw_balloon(balloon_x,balloon_y,balloon_color);
															balloon_y--;
															balloon_color=14;
															draw_balloon(balloon_x,balloon_y,balloon_color);
															shaft_color=1;
															draw_shaft(shaft_x,shaft_y,shaft_color);
															shaft_x+=5;
															shaft_color=15;
															draw_shaft(shaft_x,shaft_y,shaft_color);
														 //	check if balloon is hitted..
															if(shaft_x>balloon_x-10 && shaft_x<balloon_x+10 && shaft_y>balloon_y-10 && shaft_y<balloon_y+10)
															 {
																 for(i=800;i<=1000;i+=20)
																			{
																				 sound(1000);
																				 delay(8);
																			}
																nosound();
																balloon_color=1;
																draw_balloon(balloon_x,balloon_y,balloon_color);
																shaft_color=1;
																draw_shaft(shaft_x,shaft_y,shaft_color);
																show_score(chance,success,score,level,3);
																chance++;
																success++;
																score+=10;
																point=score;
																show_score(chance,success,score,level,1);
																chance_end=1;
															//	set position of the shaft and balloon for next chance..
																shaft_x=185;
																shaft_y=200;	//	get a random x coordinate of baloon whether it must be between 300 and 600..
																if(chance>=15)
																	{
																		clrscr();
																		setcolor(14);
																		settextstyle(10,HORIZ_DIR,1);
																		outtextxy(200,100,"**  G A M E  O V E R  **");
																		settextstyle(8,HORIZ_DIR,1);
																		outtextxy(250, 150, "Your Score : ");
																		gcvt(score,5,string);
																		outtextxy(400,150,string);
																		Sound_1();
																		setcolor(1);
																		outtextxy(150,200,"Would You Want To Play Again??");
																		outtextxy(180,300,"--> Press 'Y' To Play");
																			settextstyle(0,HORIZ_DIR,0);
																		if(getch()=='y' || getch()=='Y')
																				level_1();
																		else
																			{
																				getch();
																				closegraph();
																				exit(1);
																			}
																	}		//	End of if(point>=100)
																do{
																	 balloon_x=rand()%600;
																	}while(balloon_x<300);
																balloon_y=400;	//	y is fixed..
															 }
															 else
															//	Check if balloon or shaft over the boundaries..
																if (shaft_x>640|| balloon_y<0)
																 {
																//	Irrage both balloon and shaft
																	balloon_color=1;
																	draw_balloon(balloon_x,balloon_y,balloon_color);
																	shaft_color=1;
																	draw_shaft(shaft_x,shaft_y,shaft_color);
																	show_score(chance,success,score,level,3);
																	chance++;
																	show_score(chance,success,score,level,0);
																	chance_end=1;
																	shaft_x=185;
																	shaft_y=200;
																	do{
																		 balloon_x=rand()%600;
																		}while(balloon_x<300);
																	balloon_y=400;
																 }
														}while(!chance_end);
													 break;
													}
												case 27:
													{
														closegraph();
														exit(1);
													}
											}	//  End of switch(oo.h.al)..
									}	//	End od else..
							}	//	End of while(!chance_end)..
					 }	// End of while(1)..
				}	// End of if(getch=='3')..
			else
				{
					setcolor(5);
					outtextxy(100,300,"--> Wrong Key ! Please Enter The Right Key");
					goto r;
				}	//	End of else...
			nosound();
			getch();
			closegraph();

		}	// End of level_3..

