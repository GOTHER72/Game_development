
int screen =1;

void screen_change(int mx,int my)
{   
    int mouse_distance_from_center ;

            if(mx>=560 && mx<=609 && my>= 347 && my<=380 && (screen == 1 ||screen==14))									// for RESULT
			{
				mouse_distance_from_center =sqrt (   pow((float)585- mx ,2)  +  pow((float)363- my ,2)   );
				if( mouse_distance_from_center < 26) screen = 2;
			}
            
            else if(mx>=377 && mx<=469 && my>= 257 && my<=333 && (screen == 1 ||screen==14))
			{
				mouse_distance_from_center =sqrt (   pow((float)422- mx ,2)  +  pow((float)293- my ,2)   );
				if( mouse_distance_from_center < 46)  screen = 3;	
			}
			
		    else if(mx>=646 && mx<=686&& my>= 342 && my<=391 && (screen == 1 ||screen==14))
			{
				mouse_distance_from_center =sqrt (   pow((float)671- mx ,2)  +  pow((float)364- my ,2)   );
				if( mouse_distance_from_center < 26)  screen = 6 ;
			}

		    else if(mx>=609 && mx<=643 && my>= 395 && my<=427 && (screen == 1 ||screen==14))
			{
				mouse_distance_from_center =sqrt (   pow((float)626- mx ,2)  +  pow((float)411- my ,2)   );
				if( mouse_distance_from_center < 21) screen = 5;	
			}

		    else if(mx >=530 && mx <= 591 && my >= 270 && my <= 328 && (screen == 1 ||screen==14))  
		    {
			    mouse_distance_from_center = sqrt (   pow((float)563- mx ,2)  +  pow((float)292- my ,2)   );
			    if( mouse_distance_from_center < 35) screen = 4;	    
		    }

            else if(mx >=320 && mx <= 387 && my >= 354 && my <= 413 && (screen == 1 ||screen==14))
		    {	
			    mouse_distance_from_center =sqrt (   pow((float)356- mx ,2)  +  pow((float)378- my ,2)   );
			    if( mouse_distance_from_center < 35) exit(0);    
		    }

            else if( screen >= 2 &&  screen <= 13  && mx >= 21 && mx <= 172 && my >= 553 && my <= 586  )  screen = 1 ;

            else if ( mx >= 379 && mx <= 623 && my >= 343 && my <= 396  && (screen == 3 || screen == 13)) screen = 7;
            else if ( mx >= 379 && mx <= 623 && my >= 216 && my <= 270  && (screen == 3 || screen == 13)) screen = 8;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 4) screen =9;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 9) screen =4;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 6) screen =10;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 10) screen =6;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 5) screen =11;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 11) screen =5;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 2) screen =12;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 12) screen =2;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 3) screen =13;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 13) screen =3;

			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 1) screen  =14;
			else if ( mx >= 797 && mx <= 891 && my >= 542 && my <= 586  && screen == 14) screen =1;


}

// void screen_show(int screen){
//     if (screen == 1)
//     {
//         if(showMenu == false && loadMenu==true)				//loading screen
// 	    {

// 	        iShowImage(0,0,1000,610,screen);
// 	        iSetColor(67,77,111);
// 	        iRectangle(350,150,280,30);
// 	        iFilledRectangle(350,150,loadx,30);
// 	        iText(450,120,"Loading . . .");
// 	        }
// 	        if(showMenu == true && loadMenu==false && monkey_gayeb==true)			///checking if game load is finished
// 	        {
// 		        menu();
// 	        }
// 	    goToMenuOptions();	   //calling goToMenuOptions

//     }
//     if (screen == 2)    iShowImage(0,0,1000,610,screen_highscore);
//     if (screen == 3)    iShowImage(0,0,1000,610,screen_play);
//     if (screen == 4)    iShowImage(0,0,1000,610,screen_member);
//     if (screen == 5)    iShowImage(0,0,1000,610,screen_story);
//     if (screen == 6)    iShowImage(0,0,1000,610,screen_control);
//     if (screen == 7)  
//     {
//                 iShowImage(0,0,1000,610,screen_level_1);

//                 //! code of tara start here
//                 iSetColor(r1,g1,b1);
// 	            iFilledRectangle(   15,rect_y + 45,60,30);

// 	            iSetColor(r2,g2,b2);
// 	            iFilledRectangle(   15,rect_y + 90,60,30);

// 	            iSetColor(r3,g3,b3);
// 	            iFilledRectangle(   15,rect_y + 135,60,30);

// 	            iSetColor(r4,g4,b4);
// 	            iFilledRectangle(   15,rect_y + 180,60,30);

// 	            iSetColor(r5,g5,b5);
// 	            iFilledRectangle(   15,rect_y + 225,60,30);
	
// 	            iSetColor(255,255,255);
//                 iFilledRectangle(rect_x1 +15 ,rect_y1+47 ,60,30);

//                 //! code of parvez

//                 iShowImage(620,rect_y_2,100,100,obstacle_bamboo);
//                 iShowImage(680,rect_y_3,100,100,obstacle_bamboo);
//                 iShowImage(740,rect_y_2,100,100,obstacle_bamboo);
//                 iShowImage(800,rect_y_3,100,100,obstacle_bamboo);
//     }  
//     if (screen == 8)    iShowImage(0,0,1000,610,screen_resume_game);
// 	if (screen == 9)    iShowImage(0,0,1000,610,screen_member_light);
// 	if (screen == 10)    iShowImage(0,0,1000,610,screen_control_light);
// 	if (screen == 11)    iShowImage(0,0,1000,610,screen_story_light);
// 	if (screen == 12)    iShowImage(0,0,1000,610,screen_highscore_light);
// 	if (screen == 13)    iShowImage(0,0,1000,610,screen_play_light);
// 	if (screen == 14)    iShowImage(0,0,1000,610,joystick_light);
// }