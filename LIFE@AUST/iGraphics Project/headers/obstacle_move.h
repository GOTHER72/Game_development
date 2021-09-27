/**================================================================================================
 *!                                    This is the logic for the obstacles to move 
 *================================================================================================**/
void rectangle_change_1(){
	if(screen==7||screen==18)
	{

	srand(time(0));  

	obstacle_book_flag = (rand()%5 +1) ; // generating a rand number from 1 to 5


	switch (obstacle_book_flag * book_state )  // here if the book state is 0 obstacles will stand still 
	{

	// different cases for different obstacle to move	
	case 1 :	obstacle_math_y += speed ;
				
				if(obstacle_math_y ==0||obstacle_math_y ==560)
				PlaySound("music\\obstacle.wav",NULL,SND_ASYNC);

				if (obstacle_math_y +60 > frame_height || obstacle_math_y -10 < 0 )  speed = -speed;
				break;
				
	case 2 :	obstacle_eee_y += speed;

				if(obstacle_eee_y==0||obstacle_eee_y ==560)
				PlaySound("music\\obstacle.wav",NULL,SND_ASYNC);
			
				if (obstacle_eee_y +60 > frame_height || obstacle_eee_y -10  < 0 ) speed = -speed;	
				break;
	
	case 3 :	obstacle_cse1205_y += speed;
				
				if(obstacle_cse1205_y ==0||obstacle_cse1205_y  ==560)
				PlaySound("music\\obstacle.wav",NULL,SND_ASYNC);
				
				if (obstacle_cse1205_y +60 > frame_height || obstacle_cse1205_y -10  < 0 )  speed = -speed;
				break;
	
	case 4: 	obstacle_cse1203_y += speed;
					
				if(obstacle_cse1203_y ==0||obstacle_cse1203_y  ==560)
				PlaySound("music\\obstacle.wav",NULL,SND_ASYNC);

				if (obstacle_cse1203_y +60 > frame_height || obstacle_cse1203_y -10 < 0 ) speed = -speed;
				break;

	case 5:   	obstacle_me_y += speed;

				if(obstacle_me_y  ==0||obstacle_me_y ==560)
				PlaySound("music\\obstacle.wav",NULL,SND_ASYNC);

				if (obstacle_me_y +60 > frame_height || obstacle_me_y -10 < 0 ) speed = -speed;
				break;

	default:
		break;
	}
	}
	
}