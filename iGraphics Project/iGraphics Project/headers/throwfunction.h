int th=0;
int left_chances=9;
int target,object_throwable;
double theta=(th*3.1416)/180;
int return_time=0;
int timer_theta_change,timer_ball_move,timer_speedometer_change;
double throw_object_X=142,throw_object_Y=158;
int sound = 0;
int line=100;
int velocity=15;
int k=2; //for velocity bar
double vx=velocity*cos(theta);
double vy=velocity*sin(theta);
int rotate_count=0;
int p=1,t=1;
int throw_brain;
double line_X=line*cos(theta),line_Y=line*sin(theta);

double g=9.8/100;

int screen_width = 1000;
int screen_height = 610;
int speedometer_X=25,speedometer_Y=100;
bool player=true,throw_ball=false,angle_set_throw=true;

void playGame();
void screen_level_1_throw();
void thetaChange();
void velocityControl();
void VelocityBar();
void  ball_throw_command(unsigned char key);
void ballMove();

void playGame()
{

	if(player==true)
	{

		iLine(152,168,line_X+142,line_Y+158);

		//iShowBMPAlternativeSkipWhite(throw_object_X,throw_object_Y,"kick_1.bmp");
	     iShowImage(throw_object_X,throw_object_Y,50,50,throw_brain);
		if(!angle_set_throw)
		{
			velocityControl();													///calling velocity control bar
		}

	}
}


void screen_level_1_throw()
{

	iLine(152,168,line_X+142,line_Y+158);
	playGame();
}


void thetaChange()
{
	int k=0;
			if(player)
	{

		if(angle_set_throw)
		{
			th=th+p;
			theta=(th*3.1416)/180; //radian to degree
			line_X=line*cos(theta);
			line_Y=line*sin(theta);

			if(th>=90)
			{
				p=-1;
			}
			if(th<=0)
			{
				k++;
				p=1;
			}
			//printf("th= %d\nk=%d\n",th,k);
		}
	}

}

void velocityControl()										//velocity bar with different colours for ball throughing
{

	iSetColor(253,210,191);
	iFilledRectangle(25,100,60,30);//20,15

	iSetColor(255,107,107);
	iFilledRectangle(25,115,60,25);//20,10

	iSetColor(253,210,191);
	iFilledRectangle(25,125,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,135,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,145,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,155,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,165,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,175,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,185,60,25);

	iSetColor(255,107,107);
	iFilledRectangle(25,195,60,25);

	iSetColor(253,210,191);
	iFilledRectangle(25,205,60,25);

	iSetColor(255,255,255);
	iFilledRectangle(speedometer_X,speedometer_Y,60,15);			//white rectangle up down at velocity bar
}


void VelocityBar()								///in this function white rectangle goes up and down and after pressing space the final velocity is set for cat
{
	speedometer_Y=speedometer_Y+k;
	if(speedometer_Y>=212)
	{
		k=-2;
	}
	if(speedometer_Y<=100)
	{
		k=2;
	}
	if(throw_ball)
	{
		iPauseTimer(timer_speedometer_change);
		if(speedometer_Y>=100 && speedometer_Y<=115)
		{
			velocity=5;
		}if(speedometer_Y>=116 && speedometer_Y<=125)
		{
			velocity=7;
		}if(speedometer_Y>=126 && speedometer_Y<=135)
		{
			velocity=9;
		}if(speedometer_Y>=136 && speedometer_Y<=145)
		{
			velocity=11;
		}if(speedometer_Y>=146 && speedometer_Y<=155)
		{
			velocity=13;
		}if(speedometer_Y>=156 && speedometer_Y<=165)
		{
			velocity=15;
		}if(speedometer_Y>=166 && speedometer_Y<=175)
		{
			velocity=17;
		}if(speedometer_Y>=176 && speedometer_Y<=185)
		{
			velocity=19;
		}if(speedometer_Y>=186 && speedometer_Y<=195)
		{
			velocity=21;
		}if(speedometer_Y>=196 && speedometer_Y<=205)
		{
			velocity=23;
		}if(speedometer_Y>=206 && speedometer_Y<=215)
		{
			velocity=25;
		}

		printf(" velocity = %d\n",velocity);
	}


	//printf(" velocity = %d\n",velocity);
}


void  ball_throw_command(unsigned char key)
{
	if(player==true)
	{
		if(!angle_set_throw)
		{
			if (key == ' ')
			{

				throw_ball=true;

				printf("%d\n",left_chances);
				left_chances--;
				if(left_chances == 0 )
				{
					user_point_appender(game_point);
					if (game_point >= 1)
					{
						screen = 17;
						PlaySound("music\\levelup.wav",NULL,SND_ASYNC);
						throw_ball=false;
					}
					else if (game_point == 0 )
					{
						screen = 16;
						PlaySound("music\\Game over.wav",NULL,SND_ASYNC);
						throw_ball=false;
					}

					left_chances = 9;
					game_point = 0;
				}

			}
		}
		else
		{
			if (key == ' ')
			angle_set_throw=false;

		}
	}

}
void ballMove()						//ball moving function
{

	if(throw_ball)
	{
		vx=velocity*cos(theta);
		vy=velocity*sin(theta);
		throw_object_X = 142 + (vx*t);							//position of ball
		throw_object_Y=158+(vy*t-(0.5*g*t*t));
		if(return_time==0)
		t++;
		if(return_time==1)
		t--;

		//printf("\nTh X = %lf  Th Y = %lf\n", throw_object_X,throw_object_Y);

		if(throw_object_X + 50>=560 && throw_object_X + 50<=610 &&  throw_object_Y+50>=obstacle_me_y && throw_object_Y+50<=obstacle_me_y+50)
		{
			PlaySound("music\\fail.wav",NULL,SND_ASYNC);
			//printf("ME");
			return_time=1;
			sound = 1;
		}
		if(throw_object_X + 50>=620 && throw_object_X + 50<=670 && throw_object_Y+50>=obstacle_cse1203_y && throw_object_Y+50<=obstacle_cse1203_y+50)
		{
			PlaySound("music\\fail.wav",NULL,SND_ASYNC);
			//printf("cse");
			return_time=1;
			sound = 1;
		}
			if(throw_object_X + 50>=680 && throw_object_X + 50<=730 && throw_object_Y+50>=obstacle_cse1205_y && throw_object_Y+50<=obstacle_cse1205_y+50)
		{
			PlaySound("music\\fail.wav",NULL,SND_ASYNC);
			//printf("cse");
			return_time=1;
			sound = 1;
		}
			if(throw_object_X + 50>=740 && throw_object_X + 50<=790 && throw_object_Y+50>=obstacle_eee_y&&throw_object_Y+50<=obstacle_eee_y+50)
		{
			PlaySound("music\\fail.wav",NULL,SND_ASYNC);
			//printf("eee");
			return_time=1;
			sound = 1;
		}
			if(throw_object_X + 50>=800 && throw_object_X + 50<=850 && throw_object_Y+50>=obstacle_math_y&&throw_object_Y+50<=obstacle_math_y+50)
		{
			PlaySound("music\\fail.wav",NULL,SND_ASYNC);
			//printf("math");
			return_time=1;
			sound = 1;
		}
		if(throw_object_X + 50<= 1000 && throw_object_X +50>=870 && throw_object_Y+50<=390 && throw_object_Y +50>=230)   ////Target
		{
			PlaySound("music\\cg4.wav",NULL,SND_ASYNC);
			//printf("\nTARGET IF\n");
			//printf("Yoo Worked out!!");
			throw_object_X=142;
			throw_object_Y=158;
			throw_ball=false;
			t=1;th=0;
            if(throw_object_X==142 && throw_object_Y==158) book_state = 1;
			game_point+=10;
			iResumeTimer(timer_speedometer_change);
			speedometer_X=25,speedometer_Y=100;

			player=true,angle_set_throw=true;

		}

		if(throw_object_Y<=0||throw_object_X>1000||throw_object_Y>=610)
		{
			//printf("\nelse\n");
			if(sound == 0)
			PlaySound("music\\fail.wav",NULL,SND_ASYNC);
			return_time=0;
			throw_object_X=142;
			throw_object_Y=158;
			throw_ball=false;
			if(throw_object_X==142 && throw_object_Y==158) book_state = 1;
			t=1;th=0;
			iResumeTimer(timer_speedometer_change);
			speedometer_X=25,speedometer_Y=100;
			player=true,angle_set_throw=true;
			sound = 0;
		}

	}

}
