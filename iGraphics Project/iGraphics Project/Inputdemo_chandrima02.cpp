# include "iGraphics.h"

char str[100], str2[100];
int len;
int mode;
typedef struct UserDetails det;
//int count=0;
int oldUser=3;
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
	FILE *f1;
	int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			int id=1,count=0;
			f1=fopen("Details001.txt","r");
			int j=0;
			while(fscanf(f1, "%s%lf%d%lf",&user[j].nam,&user[j].level,&user[j].life,&user[j].cgpa) != EOF){
				user[j].autoGenID=id+count;
				fscanf(f1,"%s%lf%d%lf",&user[j].nam,&user[j].level,&user[j].life,&user[j].cgpa);
				count++;
				//printf("%d\n%s\n%lf\n%d\n%lf\n",user[j].autoGenID,user[j].nam,user[j].level,user[j].life,user[j].cgpa);
				j++;
			}
		fclose(f1);
			int k=100,t=0;
			for(int l=0;l<25;l++){
				
				t=strcmp(user[l].nam,str2);
				//if(user[l].nam!= NULL)
				//printf("user input= %s\nFile name=%s\n", str2,user[l].nam);
					if(t==0){
					k=l;
					break;
					}
			}
			
			
			if(k!=100){
				printf("\nOLD USER\nID: %d\nName: %s\nLevel: %lf\nLife: %d\nCgpa: %lf\n",user[k].autoGenID,user[k].nam,user[k].level,user[k].life,user[k].cgpa);
			}
	
			
			
			else{
					printf("NEW USER\n");

				f1=fopen("Details001.txt","a");
				fprintf(f1,"%s\n%lf\n%d\n%lf\n",str2,1.1,100,00);
				oldUser++;
				
				fclose(f1);
				int id=1,count=0;
				f1=fopen("Details.txt","r");
				j=0;
				while(fscanf(f1, "%s%lf%d%lf",&user[j].nam,&user[j].level,&user[j].life,&user[j].cgpa) != EOF){
				user[j].autoGenID=id+count;
				fscanf(f1,"%s%lf%d%lf",&user[j].nam,&user[j].level,&user[j].life,&user[j].cgpa);
				count++;
				j++;}
				fclose(f1);
				
			}

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
