
#include <stdio.h>
#include <stdlib.h>
# include "iGraphics.h"

int rect_x, rect_y ;
int rect_dx, rect_dy =7;

int rect_y_2;
int rect_dy_2 =10;

int rect_y_3;
int rect_dy_3=13;

int frame_width = 1000;
int frame_height = 610;



void iDraw()
{
	//place your drawing codes here	

	iClear();
   
	

	
	iSetColor(144, 13, 255);
    iFilledRectangle(335,rect_y_2,30,80);
	iFilledRectangle(395,rect_y_3,30,80);
    iFilledRectangle(575,rect_y_2,30,80);
	iFilledRectangle(675,rect_y_3,30,80);

	
    
    

	
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
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'p'
		iPauseTimer(0);
	}
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
	
}

void rectangle_change_1(){
	

			rect_y += rect_dy;
            rect_y_2 += rect_dy_2;
            rect_y_3 += rect_dy_3;
			 
	 if(rect_y+80 > frame_height || rect_y < 0)  rect_dy = -rect_dy;
	 if (rect_y_3 +80 > frame_height || rect_y_3 < 0 )  rect_dy_3 = -rect_dy_3;
     if (rect_y_2 +80 > frame_height || rect_y_2 < 0 )  rect_dy_2 = -rect_dy_2;
    

}




int main()
{
	iSetTimer(20, rectangle_change_1);


	iInitialize(frame_width , frame_height, " Greed island");
	iStart();


	return 0;
}

