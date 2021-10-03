/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include "bitmap_loader.h"
#include<iostream>
#include "sad_happy_bar.h"

int ball_x, ball_y;
int dx, dy;

int count=2;


/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();

    //iSetColor(0,0,0);
	iShowImage(0,0,1000,610,pic);//given 

	iShowImage(230,40,150,35,pic_1);//needed

	sad_happy_bar();//needed


	//iShowBMPAlternativeSkipWhite(150,300,"Asset_9.bmp");
	
	

	iSetColor(255, 255, 255);
	iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

	{
		//place your codes here
		printf("x1=%d\ny=%d\n",mx,my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
//150x,y300
void iKeyboard(unsigned char key)
{

	stress_bar_control(key);
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}



/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}

void load_stressbar_image()
{
	pic_1=iLoadImage("stress_bar.png");

	//pic_2=iLoadImage("b6.png");
	all_pic[0]=iLoadImage("b8.png");
	all_pic[1]=iLoadImage("b7.png");
	all_pic[2]=iLoadImage("b6.png");
    all_pic[3]=iLoadImage("b5.png");
	all_pic[4]=iLoadImage("b4.png");
	all_pic[5]=iLoadImage("b3.png");
    all_pic[6]=iLoadImage("b2.png");
	all_pic[7]=iLoadImage("b1.png");
	all_pic[8]=iLoadImage("b9.png");
	all_pic[9]=iLoadImage("bag.png");


}

void ballChange(){
	ball_x += dx;
	ball_y += dy;

	if(ball_x > 400 || ball_x < 0)dx = -dx;
	if(ball_y > 400 || ball_y < 0)dy = -dy;
}

int main()
{
	//place your own initialization codes here. 
	
	//iSetTimer(5,change);
	//iSetTimer(35,fall);

	iInitialize(1000, 610, "Level two Demo");
	pic=iLoadImage("Level_3.png");
	//load_stressbar_image();
	iStart();

//hehe
	return 0;
}
