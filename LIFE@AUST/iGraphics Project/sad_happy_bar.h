int all_pic[50];
int pic,pic_1;
int flag_1=1;
int i;

/**================================================================================================
 *!                                        crush move
 *================================================================================================**/

int girl_x=0,girl_y=300,bag_y=girl_y;
int bag;
int girl[40];
char index=0;
int bc,life_bar=0;
int check=0;
int bag_x,character_y=140;
int crush_change_timer,bag_move_timer;
void bag_move();
void change();
void timer();
void load_crush_image();


void sad_happy_bar(){
	if(flag_1==1){
		iShowImage(228,53,15,15,all_pic[0]);
	}
	
	if(flag_1==2){
		iShowImage(245,53,15,15,all_pic[1]);
	}
	if(flag_1==3){
		iShowImage(260,53,15,15,all_pic[2]);
	}
	if(flag_1==4){
		iShowImage(274,53,15,15,all_pic[3]);
	}
	if(flag_1==5){
		iShowImage(288,53,15,15,all_pic[4]);
	}
	if(flag_1==6){
		iShowImage(304,53,15,15,all_pic[5]);
	}
	if(flag_1==7){
		iShowImage(321,53,15,15,all_pic[6]);
	}
	if(flag_1==8){
		iShowImage(333,53,15,15,all_pic[7]);
	}
	if(flag_1==9){
		iShowImage(349,53,15,15,all_pic[8]);
	}
	if(flag_1==10){
		iShowImage(364,53,15,15,all_pic[9]);
	}

	
}
void stress_bar_control(unsigned char key){

	if(key == 'j' && flag_1==1 || flag_1==i)
	{
		//do something with 'q'
		//iPauseTimer(0);
		
		flag_1++;
		i=flag_1;

	}

}

/**================================================================================================
 *!                                        crush move
 *================================================================================================**/


void change(){

	index++;

	if(index<=15)girl_x+=20;

	if(index>15)girl_x-=20;

	if(index==34) {
            index=0;
            girl_x=0;
	}

}

void bag_move(){

	if(bag_x>120 && bag_x<161 && bag_y<=190 && bag_y>180)
		flag_1++;

	if(girl_x==60||girl_x==140||girl_x==260){

     
	   iPauseTimer(crush_change_timer);
	   check=1;
	   bag_x=girl_x;
	   bag_y-=10;

		
		if(bag_y<=0) {

			check=0;
			iResumeTimer(crush_change_timer);
			bag_y=girl_y;
		}
	}

}
void timer(){
	crush_change_timer=iSetTimer(300,change);
	
	bag_move_timer=iSetTimer(30,bag_move);
}
void load_crush_image(){
	
	girl[0]=iLoadImage("images\\f1.png"); //front walk start
	girl[1]=iLoadImage("images\\f2.png");
	girl[2]=iLoadImage("images\\f3.png");
	girl[3]=iLoadImage("images\\f4.png");
	girl[4]=iLoadImage("images\\f5.png");
	girl[5]=iLoadImage("images\\f6.png");
	girl[6]=iLoadImage("images\\f7.png");
	girl[7]=iLoadImage("images\\f8.png");
	girl[8]=iLoadImage("images\\f1.png");
	girl[9]=iLoadImage("images\\f2.png");
	girl[10]=iLoadImage("images\\f3.png");
	girl[11]=iLoadImage("images\\f4.png");
	girl[12]=iLoadImage("images\\f5.png");
	girl[13]=iLoadImage("images\\f6.png");
	girl[14]=iLoadImage("images\\f7.png");
	girl[15]=iLoadImage("images\\f8.png"); //front walk end
	girl[16]=iLoadImage("images\\b1.png"); //back walk start
	girl[17]=iLoadImage("images\\b2.png");
	girl[18]=iLoadImage("images\\b3.png");
	girl[19]=iLoadImage("images\\b4.png");
	girl[20]=iLoadImage("images\\b5.png");
	girl[21]=iLoadImage("images\\b6.png");
	girl[22]=iLoadImage("images\\b7.png");
	girl[23]=iLoadImage("images\\b8.png");
	girl[24]=iLoadImage("images\\b1.png");
	girl[25]=iLoadImage("images\\b2.png");
	girl[26]=iLoadImage("images\\b3.png");
	girl[27]=iLoadImage("images\\b4.png");
	girl[28]=iLoadImage("images\\b5.png");
	girl[29]=iLoadImage("images\\b6.png");
	girl[30]=iLoadImage("images\\b7.png");
	girl[31]=iLoadImage("images\\b8.png");
	girl[32]=iLoadImage("images\\b6.png");
	girl[33]=iLoadImage("images\\b7.png");
	girl[34]=iLoadImage("images\\b8.png"); //back walk end
	bag=iLoadImage("images\\bag.png");
	bc=iLoadImage("images\\bc.png");

}