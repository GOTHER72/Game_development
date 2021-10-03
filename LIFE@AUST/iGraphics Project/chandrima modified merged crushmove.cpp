/*
	author: Chandrima Sarker
*/
# include "headers//iGraphics.h"
# include "headers//bitmap_loader.h"
int girl_x=0,girl_y=300,bag_y=girl_y;
int bag,girlpic1,girlpic2,girlpic3,girlpic4,girlpic5,girlpic6,girlpic7,girlpic8,girlpic9,girlpic10,girlpic11,girlpic12,girlpic13,girlpic14,girlpic15,girlpic16;
int girl[40]={girlpic1,girlpic2,girlpic3,girlpic4,girlpic5,girlpic6,girlpic7,girlpic8,girlpic1,girlpic2,girlpic3,girlpic4,girlpic5,girlpic6,girlpic7,girlpic8,girlpic9,girlpic10,girlpic11,girlpic12,girlpic13,girlpic14,girlpic15,girlpic16,girlpic9,girlpic10,girlpic11,girlpic12,girlpic13,girlpic14,girlpic15,girlpic16};
char index=0;
int pic,bc,flag=0;
int mnk_y=370;
int move_flag;
int check=0;
int bag_x,rect_y=0;
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();
	iShowImage(0,0,1000,610,bc);
	iShowImage(girl_x,girl_y,50,150,girl[index]);
	 if(check==1){
		 iShowImage(girl_x,mnk_y,40,40,bag);
	 }
	iResumeTimer(0);
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
		printf("x=%d y=%d\n", mx,my);
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
		//do something with 'q'
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
	//place your codes for other keys here
}
void change(){
	
	index++;
	if(index<=16)girl_x+=20;
	if(index>16)girl_x-=20;
	if(index==35) index=0;

}
void fall(){

	 
	 //printf("y1 = %d\n",mnk_y);
	 srand(time(0));  
	 move_flag=(rand()%5+1);

	switch(move_flag)
	{
		   
	case 1: if(girl_x >=2 && girl_x <=78){
		      iPauseTimer(0);
			  check=1;
			  mnk_y -= 25;
				
				if(mnk_y <=0){check=0;
				iResumeTimer(0);
				mnk_y =370;
				}

			}
          break;
	case 2: if(girl_x >=79 && girl_x <=132)
			{
				iPauseTimer(0);
				check=1;
				mnk_y -= 25;
				if(mnk_y <=0){check=0;
				iResumeTimer(0);
				mnk_y =370;}
		     
			}
			break;
	case 3: if(girl_x>=133 && girl_x <=160){
		      iPauseTimer(0);
				  check=1;
			 	mnk_y -= 25;
				if(mnk_y <=0){check=0;
				iResumeTimer(0);
				mnk_y =370;}
			}
			break;
	case 4: if(girl_x >=161 && girl_x <=212){
		      iPauseTimer(0);
		   	  check=1;
			  	mnk_y -= 25;
				if(mnk_y <=0){check=0;
				iResumeTimer(0);
				mnk_y =370;}
	
			}
			break;
	case 5: if(girl_x >= 213 && girl_x <=325){
		   
				iPauseTimer(0);
		  		check=1;
				mnk_y -= 25;
				if(mnk_y <=0){check=0;
				iResumeTimer(0);
				mnk_y =370;}
			}
			break;

	}
	

}


int main()
{
	iSetTimer(500,change);
	iSetTimer(35,fall);
	iInitialize(1000, 610, "Ball Demo");

	girl[1]=iLoadImage("images\\f1.png");
	girl[2]=iLoadImage("images\\f2.png");
	girl[3]=iLoadImage("images\\f3.png");
	girl[4]=iLoadImage("images\\f4.png");
	girl[5]=iLoadImage("images\\f5.png");
	girl[6]=iLoadImage("images\\f6.png");
	girl[7]=iLoadImage("images\\f7.png");
	girl[8]=iLoadImage("images\\f8.png");
	girl[9]=iLoadImage("images\\f1.png");
	girl[10]=iLoadImage("images\\f2.png");
	girl[11]=iLoadImage("images\\f3.png");
	girl[12]=iLoadImage("images\\f4.png");
	girl[13]=iLoadImage("images\\f5.png");
	girl[14]=iLoadImage("images\\f6.png");
	girl[15]=iLoadImage("images\\f7.png");
	girl[16]=iLoadImage("images\\f8.png");
	girl[17]=iLoadImage("images\\b1.png");
	girl[18]=iLoadImage("images\\b2.png");
	girl[19]=iLoadImage("images\\b3.png");
	girl[20]=iLoadImage("images\\b4.png");
	girl[21]=iLoadImage("images\\b5.png");
	girl[22]=iLoadImage("images\\b6.png");
	girl[23]=iLoadImage("images\\b7.png");
	girl[24]=iLoadImage("images\\b8.png");
	girl[25]=iLoadImage("images\\b1.png");
	girl[26]=iLoadImage("images\\b2.png");
	girl[27]=iLoadImage("images\\b3.png");
	girl[28]=iLoadImage("images\\b4.png");
	girl[29]=iLoadImage("images\\b5.png");
	girl[30]=iLoadImage("images\\b6.png");
	girl[31]=iLoadImage("images\\b7.png");
	girl[32]=iLoadImage("images\\b8.png");
	girl[33]=iLoadImage("images\\b6.png");
	girl[34]=iLoadImage("images\\b7.png");
	girl[35]=iLoadImage("images\\b8.png");
	bag=iLoadImage("images\\bag.png");
	bc=iLoadImage("images\\bc.png");

	iStart();


	return 0;
}

