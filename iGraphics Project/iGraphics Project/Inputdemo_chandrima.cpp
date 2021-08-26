# include "iGraphics.h"

char str[100], str2[100];
int len;
int mode;
typedef struct UserDetails det;
int count=0;
struct UserDetails{
	int autoGenID;
	char nam[100];
	double level;
	int life;
	double cgpa;
};

void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(50, 250, 250, 30);
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();

	drawTextBox();
	if(mode == 1)
	{
		iSetColor(255, 255, 255);
		iText(55, 260, str);
	}

	iText(10, 10, "Click to activate the box, enter to finish.");
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
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/


/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(mx >= 50 && mx <= 300 && my >= 250 && my <= 280 && mode == 0)
		{
			mode = 1;
		}
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
	det user[100];
	user[0].autoGenID=001;
	strcpy(user[0].nam,"Tara");
	user[0].level=1.2;
	user[0].life=100;
	user[0].cgpa=3.00;
	

    user[1].autoGenID=002;
	strcpy(user[1].nam,"Parvez");
	user[1].level=1.2;
	user[1].life=100;
	user[1].cgpa=3.00;
	
     
	user[2].autoGenID=003;
	strcpy(user[2].nam, "Shipra");
    user[2].level=1.1;
	user[2].life=100;
	user[2].cgpa=3.00;
	
	FILE *f1;
	
 
	
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			
			f1=fopen("Details.txt","a");
		    for(int j=0;j<3;j++){
				fprintf(f1,"ID: %d\nName: %s\nLevel: %lf\nLife: %d\nCgpa: %lf\n",user[j].autoGenID,user[j].nam,user[j].level,user[j].life,user[j].cgpa);
			}
			fclose(f1);
			f1=fopen("Details.txt","r");
			for(int j=0;j<3;j++){
				fscanf(f1,"%d%s%lf%d%lf",&user[j].autoGenID,&user[j].nam,&user[j].level,&user[j].life,&user[j].cgpa);
				//printf("%d%s%lf%d%lf",user[j].autoGenID,user[j].nam,user[j].level,user[j].life,user[j].cgpa);
			}
		
			int k,t=0;
			for(int j=0;j<3;j++){
				//t=strcmp(user[j].nam,str2);
				t=strcmp(user[j].nam,str2);
					if(t==0){
					k=j;
					break;
					}
			}
			fclose(f1);
			if(k==5){
				printf("NEW USER\n");

				//f1=fopen("Details.txt","a");
				//fprintf(f1,"%d\nName: %s\nLevel: %lf\nLife: %d\nCgpa: %lf\n",user[j].autoGenID,user[j].nam,user[j].level,user[j].life,user[j].cgpa);
			}
			else
				printf("\nOLD USER\nName: %s\nLevel: %lf\nLife: %d\nCgpa: %lf\n",user[k].nam,user[k].level,user[k].life,user[k].cgpa);
			

			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}

	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
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

int main()
{
	//place your own initialization codes here.

	len = 0;
	mode = 0;
	str[0]= 0;
	iInitialize(400, 400, "TextInputDemo");
	iStart();
	return 0;
}
