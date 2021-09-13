// Created by Parvez Ahammed ID - 200104129

# include "iGraphics.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "bitmap_loader.h"

int loadx;

int frame_width = 1000, frame_height= 610 ;

int play_button,control_button,story_button,about,exit_button;

int screen_play,screen_highscore,screen_control,screen_member,screen_story;

int obstacle_bamboo;

int screen_level_1,screen_resume_game;

int f=0;

int menu_picture,high_score;
int menuBtnX=480;
int menuBtnY=500;
int score = 0;

bool showMenu = false,showGameOver=false,loadMenu=true,monkey_gayeb=false;
bool showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false;

bool showExit=false,showStory=false,showNewGame=false,showResumeGame=false,show2ndMenu=false;

int screen =1;

//! code of tara starts here

int rect_x1, rect_y1;
int rect_x, rect_y;
int rect_dx, rect_dy;

int r=253,g=210,b=191;
int r1=255, g1=107, b1=107;
int r2=69,  g2=82,  b2=108;
int r3=255, g3=107, b3=107;
int r4=69,  g4=82,  b4=108;
int r5=255, g5=107, b5=107;

void collisionCheck();

//! code of parvez starts here

int rect_y_2;
int rect_dy_2 =10;

int rect_y_3;
int rect_dy_3=13;

void screen_change(int,int);
void menu();
void goToMenuOptions();
void showResults();
void image_load();
void newGame()	
														///new game starting ! reseting all the values
{
	showMenu=true,loadMenu=false;
	showPlay=false,showAbout=false,showInst=false,showOption=false,showResult=false,showGameOver=false,show2ndMenu=false;
	showNewGame=false,showResumeGame=false;
}
void iDraw()
{

	iClear();

    if (screen == 1)
    {
        if(showMenu == false && loadMenu==true)				//loading screen
	    {

	        iShowImage(0,0,1000,610,screen);
	        iSetColor(67,77,111);
	        iRectangle(350,150,280,30);
	        iFilledRectangle(350,150,loadx,30);
	        iText(450,120,"Loading . . .");
	        }
	        if(showMenu == true && loadMenu==false && monkey_gayeb==true)			///checking if game load is finished
	        {
		        menu();
	        }
	    goToMenuOptions();	   //calling goToMenuOptions

    }
    if (screen == 2)    iShowImage(0,0,1000,610,screen_highscore);
    if (screen == 3)    iShowImage(0,0,1000,610,screen_play);
    if (screen == 4)    iShowImage(0,0,1000,610,screen_member);
    if (screen == 5)    iShowImage(0,0,1000,610,screen_story);
    if (screen == 6)    iShowImage(0,0,1000,610,screen_control);
    if (screen == 7)  
    {
                iShowImage(0,0,1000,610,screen_level_1);

                //! code of tara start here
                iSetColor(r1,g1,b1);
	            iFilledRectangle(   15,rect_y + 45,60,30);

	            iSetColor(r2,g2,b2);
	            iFilledRectangle(   15,rect_y + 90,60,30);

	            iSetColor(r3,g3,b3);
	            iFilledRectangle(   15,rect_y + 135,60,30);

	            iSetColor(r4,g4,b4);
	            iFilledRectangle(   15,rect_y + 180,60,30);

	            iSetColor(r5,g5,b5);
	            iFilledRectangle(   15,rect_y + 225,60,30);
	
	            iSetColor(255,255,255);
                iFilledRectangle(rect_x1 +15 ,rect_y1+47 ,60,30);

                //! code of parvez

                iShowImage(620,rect_y_2,100,100,obstacle_bamboo);
                iShowImage(680,rect_y_3,100,100,obstacle_bamboo);
                iShowImage(740,rect_y_2,100,100,obstacle_bamboo);
                iShowImage(800,rect_y_3,100,100,obstacle_bamboo);
    }  
    if (screen == 8)    iShowImage(0,0,1000,610,screen_resume_game);
        
	
}
void menu()																///menu background and buttons
{
	
	iShowImage(0,0,1000,610,menu_picture);
	
}
void goToMenuOptions()													//going to any selected option
{
	if(showPlay==true)
	{

		if(f==1)
		{
			menu();
		}
		if(showNewGame && !show2ndMenu)
		{
			iShowImage(0,0,1000,610,menu_picture);
			iShowImage(246,300,175,45,play_button);
			//game starting function calling
		}
		if(showResumeGame && !show2ndMenu)
		{
			menu();
		}
	}

	if(showInst==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(678,373,175,45,control_button);
		
	}
	if(showStory==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(635,415,175,45,story_button);
	}
	if(showExit==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(170,395,175,45,exit_button);
	}
	if(showAbout==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(580,285,175,45,about);
	}
	if(showResult==true)
	{
		iShowImage(0,0,1000,610,menu_picture);
		iShowImage(416,368,175,45,high_score);
		showResults();
	}
}
void showResults()
{

}

void iMouseMove(int mx, int my)
{
	//place your codes here
	//printf("(x,y):%d,%d \n",mx, my); -- this is for debugging the code
}

void iPassiveMouse(int mx, int my)
{
	int mouse_distance_from_center;

	if(monkey_gayeb==true)
	{
		if(mx>=560 && mx<=609 && my>= 347 && my<=380)									///for RESULT
			{
				mouse_distance_from_center =sqrt (   pow((float)585- mx ,2)  +  pow((float)363- my ,2)   );

				if( mouse_distance_from_center < 26)
				{
					showResult=true;
				    showInst=false,showPlay = false,showAbout=false,showMenu=false,showOption=false;
				    f=1;
				//PlaySound(" mouse_hover.wav ", NULL, SND_ASYNC);

				}
				
			}

		else if(mx>=377 && mx<=469 && my>= 257 && my<=333)
			{
				mouse_distance_from_center =sqrt (   pow((float)422- mx ,2)  +  pow((float)293- my ,2)   );
				
				if( mouse_distance_from_center < 46)
				
				{
					showPlay =true;
				    showInst=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
				showNewGame=true;show2ndMenu=false;
				f=1;
				//PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

				}
				
			}
			
		else if(mx>=646 && mx<=686&& my>= 342 && my<=391)
			{
				mouse_distance_from_center =sqrt (   pow((float)671- mx ,2)  +  pow((float)364- my ,2)   );

				if( mouse_distance_from_center < 26)
				{
						showPlay =true;
						showInst =true;
						showPlay=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
				f=1;
				//PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

				}
				
			}
		else if(mx>=609 && mx<=643 && my>= 395 && my<=427)
			{
				mouse_distance_from_center =sqrt (   pow((float)626- mx ,2)  +  pow((float)411- my ,2)   );

				if( mouse_distance_from_center < 21)
				
				{
					showPlay =true;
					showStory=true;
					showInst=false,showPlay=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
					f=1;
					///PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

				}
				
			}
		else if(mx >=530 && mx <= 591 && my >= 270 && my <= 328)  // For teh game creator pop up
		{

			mouse_distance_from_center = sqrt (   pow((float)563- mx ,2)  +  pow((float)292- my ,2)   );

			if( mouse_distance_from_center < 35)
			{
				showPlay=true;
			    showAbout =true;
				showPlay=false,showInst=false,showResult= false,showMenu=false,showOption=false;
				showNewGame=true;show2ndMenu=false;
				f=1;
				//PlaySound("mouse_hover.wav", NULL, SND_ASYNC);

			}
			    
		}
		else if(mx >=320 && mx <= 387 && my >= 354 && my <= 413)
		{	
			mouse_distance_from_center =sqrt (   pow((float)356- mx ,2)  +  pow((float)378- my ,2)   );

			if( mouse_distance_from_center < 35){
				showPlay=true;
			    showExit =true;
				showPlay=false,showInst=false,showResult= false,showAbout=false,showMenu=false,showOption=false;
				showNewGame=true;show2ndMenu=false;
				f=1;
				//PlaySound("mouse_hover.wav ", NULL, SND_ASYNC);

			}

		}
		else
			{
				showPlay =false;
				showNewGame=false;
				showResult=false;
				showPlay = true;
				monkey_gayeb=true;
				showInst =false;
				showStory=false;
				showAbout=false;
				showExit=false;

				f=1;
			}
	}
}

void iMouse(int button, int state, int mx, int my)
{

		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    printf("x= %d\ny= %d\n", mx,my);

             screen_change(mx,my);       
        }
		
}

void screen_change(int mx,int my)
{   
    int mouse_distance_from_center ;

            if(mx>=560 && mx<=609 && my>= 347 && my<=380 && screen == 1)									// for RESULT
			{
				mouse_distance_from_center =sqrt (   pow((float)585- mx ,2)  +  pow((float)363- my ,2)   );
				if( mouse_distance_from_center < 26) screen = 2;
			}
            
            else if(mx>=377 && mx<=469 && my>= 257 && my<=333 && screen == 1)
			{
				mouse_distance_from_center =sqrt (   pow((float)422- mx ,2)  +  pow((float)293- my ,2)   );
				if( mouse_distance_from_center < 46)  screen = 3;	
			}
			
		    else if(mx>=646 && mx<=686&& my>= 342 && my<=391 && screen == 1)
			{
				mouse_distance_from_center =sqrt (   pow((float)671- mx ,2)  +  pow((float)364- my ,2)   );
				if( mouse_distance_from_center < 26)  screen = 6 ;
			}

		    else if(mx>=609 && mx<=643 && my>= 395 && my<=427 && screen == 1)
			{
				mouse_distance_from_center =sqrt (   pow((float)626- mx ,2)  +  pow((float)411- my ,2)   );
				if( mouse_distance_from_center < 21) screen = 5;	
			}

		    else if(mx >=530 && mx <= 591 && my >= 270 && my <= 328 && screen == 1)  
		    {
			    mouse_distance_from_center = sqrt (   pow((float)563- mx ,2)  +  pow((float)292- my ,2)   );
			    if( mouse_distance_from_center < 35) screen = 4;	    
		    }

            else if(mx >=320 && mx <= 387 && my >= 354 && my <= 413 && screen == 1)
		    {	
			    mouse_distance_from_center =sqrt (   pow((float)356- mx ,2)  +  pow((float)378- my ,2)   );
			    if( mouse_distance_from_center < 35) exit(0);    
		    }

            else if( (screen == 2 || screen == 3 || screen == 4 || screen == 5 || screen ==6 ||screen== 7 || screen == 8) && mx >= 21 && mx <= 172 && my >= 553 && my <= 586  ) screen =1 ;
            else if ( mx >= 379 && mx <= 623 && my >= 343 && my <= 396  && screen == 3) screen =7;
            else if ( mx >= 379 && mx <= 623 && my >= 216 && my <= 270  && screen == 3) screen =8;

}

void iKeyboard(unsigned char key)
{
	if (key == 'p')   //p will pause the game
	{
		collisionCheck();
		iPauseTimer(0);
        
	}
	if (key == 'r')  //r will resume the game
	{
		iResumeTimer(0);
	}
    //! code of tara
    if(key == 'l')
	{
		//ball_x -=20;
		collisionCheck();
	}

}

void iSpecialKeyboard(unsigned char key)  //special key that will end the game 
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

}

//! code of tara

void collisionCheck()
{
	rect_y1 +=rect_dy;

	if(rect_y1 > 0 &&  rect_y1 < 45) //0,40
	{
		r1 = 182;
		g1 = 25;
		b1 = 25;
		
	}
   
	if(rect_y1 > 41 && rect_y1 < 82 )//41,82
	{
		r2 = 182;
		g2 = 25;
		b2 = 25;

	}
	if(rect_y1 > 84 && rect_y1 <130)//84,130
	{
		r3 = 182;
		g3 = 25;
		b3 = 25;

	}
	if(rect_y1 > 132 && rect_y1 < 160) //132,160
	{
		r4 = 182;
		g4 = 25;
		b4 = 25;
	}
	if( rect_y1 > 165 && rect_y1 < 178)//165,178
	{
		r5 = 182;
		g5 = 25;
		b5 = 25;
	}

	//printf("collision y=%d\n",rect_y1);
//The blocks turned red when the white block touched their coordinates and the white block is working from bottom to topp 

}

void rectangle_change(){
	
	rect_y1 += rect_dy;
	 if(rect_y1  > 175 || rect_y1 < 0)rect_dy = -rect_dy;
	 

}

void menuLoad()				///menu loading function!
{
	if(loadx<280)
	loadx+=20;
	if(loadx==280)
	{
		showMenu = true;
		loadMenu =false;
		monkey_gayeb=true;
		iPauseTimer(0);
	}
}

void image_load()
{
    screen= iLoadImage("images//screen_load.png");
	play_button      = iLoadImage("images//btn_play.png");  //loading the images
	menu_picture     = iLoadImage("images//joystick.png"); 
	high_score       = iLoadImage("images//btn_high_score.png"); 
	control_button   = iLoadImage("images//btn_control.png");
	story_button     = iLoadImage("images//btn_story.png");
	about            = iLoadImage("images//btn_about.png");
	exit_button      = iLoadImage("images//btn_exit.png");

    screen_play      = iLoadImage("images//screen_play.png");
    screen_highscore = iLoadImage("images//screen_highscore.png");
    screen_control   = iLoadImage("images//screen_control.png");
    screen_member    = iLoadImage("images//screen_member.png");
    screen_story     = iLoadImage("images//screen_story.png");
    screen_level_1   = iLoadImage("images//screen_level_1.png");
    screen_resume_game   = iLoadImage("images//screen_resume.png");

    obstacle_bamboo = iLoadImage("images//bamboo.png");
    


}

void rectangle_change_1(){
	

            rect_y_2 += rect_dy_2;
            rect_y_3 += rect_dy_3;
			
	 if (rect_y_3 +80 > frame_height || rect_y_3 < 0 )  rect_dy_3 = -rect_dy_3;
     if (rect_y_2 +80 > frame_height || rect_y_2 < 0 )  rect_dy_2 = -rect_dy_2;
    

}

int main()
{

	iInitialize(frame_width, frame_height, "Life @ AUST");  //initializing the game frame

    iSetTimer(200,menuLoad);
    
    image_load();
    rect_dy = 7;

    iSetTimer(5, rectangle_change);
    iSetTimer(20, rectangle_change_1);

	

	iStart(); // it will start drawing

	return 0;
}
