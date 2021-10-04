
/*Created by		//!Tabassum Tara lamia - 200104128  Parvez Ahammed - 200104129 Chandrima sarker shipra 200104131 */

/**================================================================================================
 *!                                       Must needed header files
 *================================================================================================**/
#include "headers//iGraphics.h"
#include "headers//bitmap_loader.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/**================================================================================================
 *!                                 Header files created by the developers
 *================================================================================================**/


#include "headers//variables.h"
#include "headers//file_handler.h"
#include "headers//resume_user.h"
#include "headers//obstacle_move.h"
#include "headers//obstacle_image_shower.h"
#include "headers//throwfunction.h"
#include "headers//screen_change.h"
#include "headers//menu.h"
#include "headers//text_manager.h"
#include "headers//keyboard_control.h"
#include "character_renderer_combine.h"

void file_handler();
void resume_file_handler();

void iDraw()
{

	iClear();
	
	//file_scanner();
    if (screen == 1 || screen ==14 )
    {
        if(showMenu == false && loadMenu==true)				//loading screen
	    {

	        iShowImage(0,0,1000,610,screen);
	        iSetColor(67,77,111);
	        iRectangle(350,150,280,30);
	        iFilledRectangle(350,150,loadx,30);
	        iText(450,120,"Loading . . .");
	        }
	        if(showMenu == true && loadMenu==false && monkey_gayeb==true) //checking if game load is finished
	        {
		        menu();
	        }
	    goToMenuOptions();	   //calling goToMenuOptions
    }
    if (screen == 2)
	{
		 				iShowImage(0,0,1000,610,screen_highscore);
						iSetColor(255,255,255);
		 				high_score_shower();
	}
    if (screen == 3)    iShowImage(0,0,1000,610,screen_play);
    if (screen == 4)    iShowImage(0,0,1000,610,screen_member);
    if (screen == 5)    iShowImage(0,0,1000,610,screen_story);
    if (screen == 6)    iShowImage(0,0,1000,610,screen_control);
    if (screen == 7)
    {
                		iShowImage(0,0,1000,610,screen_level_1);
						show_obstacle_image();
   						changable_text();
                		screen_level_1_throw(); 
						instruction_move();
    }
    if (screen == 8)     iShowImage(0,0,1000,610,screen_resume_game);
	if (screen == 9)     iShowImage(0,0,1000,610,screen_member_light);
	if (screen == 10)    iShowImage(0,0,1000,610,screen_control_light);
	if (screen == 11)    iShowImage(0,0,1000,610,screen_story_light);
	if (screen == 12)
	{
						iShowImage(0,0,1000,610,screen_highscore_light);
						iSetColor(67,77,111);
						high_score_shower();
		
	}    
	if (screen == 13)    iShowImage(0,0,1000,610,screen_play_light);
	if (screen == 14)	 iShowImage(0,0,1000,610,joystick_light);
	
	if (screen == 15)
	{
		iShowImage(0,0,1000,610,screen_input);
		left_chances = 10;
		game_point = 0;
		if(mode == 1) {
		iSetColor(255, 255, 255);
		iText(300, 300, player_name,GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	if (screen == 16 ) iShowImage(0,0,screen_width,screen_height,screen_game_over);
	if (screen == 17 ) iShowImage(0,0,screen_width,screen_height,screen_go_level_2);
	if (screen == 18 )
	{
		iShowImage(0,0,screen_width,screen_height,screen_level_2);
		book_state=1;
		show_obstacle_image_2();
   		changable_text();
        screen_level_1_throw();
		instruction_move();
		if(checkvalue==1){
		printf("Throw %d\nAngle %d\nplayer %d", throw_ball,angle_set_throw,player);
		checkvalue=2;
		}
	}

	if (screen == 19 )
	{
		iShowImage(0,0,screen_width,screen_height,screen_level_3);

	// for the character render
		// iShowImage(230,40,150,35,pic_1);//needed
		// sad_happy_bar();//needed
		// iShowImage(girl_x,girl_y,50,150,girl[index]);
	 	// if(check==1){
		//  iShowImage(bag_x,bag_y,40,40,bag);
	 	// }

		book_state=1;
		show_obstacle_image_3();
   		changable_text();
        screen_level_1_throw();
		instruction_move();
	
	}
	if (screen == 20 ) 
	{
		iShowImage(0,0,screen_width,screen_height,screen_go_level_3);
		
	}
	if (screen == 21 ) 
	{	
		
		iShowImage(0,0,screen_width,screen_height,screen_certificate);
		certificate_text();
		
	}
	if (screen == 22 ) 
	{	
		
		iShowImage(0,0,screen_width,screen_height,screen_input_resume);
		if(mode == 1) {
		iSetColor(255, 255, 255);
		iText(300, 300, resume_player_name,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
	}
	if (screen == 23 ) iShowImage(0,0,screen_width,screen_height,screen_name_not_found);

	if (screen == 24 ) iShowImage(0,0,screen_width,screen_height,screen_append_data);
		
	

}

void iMouseMove(int mx, int my)
{
	//place your codes here
	//printf("(x,y):%d,%d \n",mx, my); -- this is for debugging the code
}

void iPassiveMouse(int mx, int my)
{
	//printf("x= %d\ty= %d\t screen = %d\n", mx,my,screen);
	if(monkey_gayeb==true || screen == 14 )
	{
		menu_hover(mx,my);
	}
}

void iMouse(int button, int state, int mx, int my)
{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
		    printf("x= %d\ty= %d\t screen = %d\t Total game point %d \n", mx,my,screen,total_game_point);
            screen_change(mx,my);
        }

		if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		{
		printf("x= %d\ty= %d\t screen = %d\n", mx,my,screen);
		}
}

void iKeyboard(unsigned char key)
{
	keyboard_control(key);
	
}

void iSpecialKeyboard(unsigned char key)  //special key that will end the game
{

	if (key == GLUT_KEY_END)	exit(0);

}

void file_handler()
{
	//file_line_counter();
	file_scanner();
	point_array_modified = sort_decreasing_order(point_array);
	highest_score_printer();
}

void resume_file_handler()
{
	resume_user_counter();
    resume_file_scanner();
	//resume_file_data_printer();
    
    //resume_data_assigner();
}

void timer_control()
{
	iSetTimer(200,menuLoad);
	timer_instruction_text_move = iSetTimer(20 ,instructions_text_move);
	timer_theta_change=iSetTimer(10,thetaChange);
    timer_ball_move=iSetTimer(30,ballMove);
    timer_speedometer_change=iSetTimer(10,VelocityBar);
	timer_obstacle_change = iSetTimer(20, rectangle_change_1);
}




int main()
{
	
	iInitialize(frame_width, frame_height, "Life @ AUST");  //initializing the game frame
	//iSetTimer(20,file_handler);

	


	file_handler();
	resume_file_handler();
	newGame();
	image_load();
	timer_control();

	// for the character render
	// load_crush_image();
	// load_stressbar_image();

	iStart(); // it will start drawing
	return 0;
}



