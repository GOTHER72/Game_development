int play_button,control_button,story_button,about,exit_button;

int screen_play,screen_highscore,screen_control,screen_member,screen_story;

int screen_member_light,screen_control_light,screen_story_light ,screen_highscore_light,screen_play_light,joystick_light;

int screen_level_1,screen_resume_game;
int menu_picture,high_score;

int obstacle_bamboo;

int screen;

#include "iGraphics.h"



void image_load()
{
    screen           = iLoadImage("images//screen_load.png");
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
    screen_resume_game  = iLoadImage("images//screen_resume.png");

    obstacle_bamboo = iLoadImage("images//bamboo.png");

	screen_member_light = iLoadImage("images//screen_member_light.png");
	screen_control_light = iLoadImage("images//screen_control_light.png");
	screen_story_light = iLoadImage("images//screen_story_light.png");
	screen_highscore_light = iLoadImage("images//screen_highscore_light.png");
	screen_play_light = iLoadImage("images//screen_play_light.png");
	joystick_light = iLoadImage("images//joystick_light.png");
    
}