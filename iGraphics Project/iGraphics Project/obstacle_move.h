/**================================================================================================
 *!                               This variables are related to book changes
 *================================================================================================**/

int obstacle_cse_1203,obstacle_cse_1205,obstacle_eee_1241,obstacle_me_1211,obstacle_math_1219;
int obstacle_cse1203_y, obstacle_cse1205_y ,obstacle_eee_y, obstacle_me_y,obstacle_math_y ;

int obstacle_cse1203_dy = 5;
int obstacle_cse1205_dy = 7;
int obstacle_eee_dy =9;
int obstacle_me_dy =11;
int obstacle_math_dy =13;

int obstacle_book_flag =1;


/**================================================================================================
 *!                                        Variables for showing the points
 *================================================================================================**/

int game_point = 0 ;
char game_point_char[10];

int left_chances = 0 ;
char left_chances_char[10];


int frame_width = 1000, frame_height= 610 ;
void rectangle_change_1(){

			if(obstacle_book_flag % 5 == 1 )
			{
				obstacle_math_y += obstacle_math_dy;
				if (obstacle_math_y +60 > frame_height || obstacle_math_y < 0 ) 
				{
					obstacle_math_dy = -obstacle_math_dy;
					obstacle_book_flag+=1;

					game_point+=1;
				} 
			}

			if (obstacle_book_flag % 5 == 2)
			{
				obstacle_eee_y += obstacle_eee_dy;
				if (obstacle_eee_y +60 > frame_height || obstacle_eee_y   < 0 ) 
				{
					obstacle_eee_dy = -obstacle_eee_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}

			if (obstacle_book_flag % 5== 3)
			{
				 obstacle_cse1205_y += obstacle_cse1205_dy;
				if (obstacle_cse1205_y +60 > frame_height || obstacle_cse1205_y   < 0 ) 
				{
					obstacle_cse1205_dy = -obstacle_cse1205_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}

			if (obstacle_book_flag  % 5 == 4)
			{
				 obstacle_cse1203_y += obstacle_cse1203_dy;
				if (obstacle_cse1203_y +60 > frame_height || obstacle_cse1203_y  < 0 ) 
				{
					obstacle_cse1203_dy = -obstacle_cse1203_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}
			if (obstacle_book_flag % 5 == 0 )
			{
				 obstacle_me_y += obstacle_me_dy;
				if (obstacle_me_y +60 > frame_height || obstacle_me_y  < 0 ) 
				{
					obstacle_me_dy = -obstacle_me_dy;
					obstacle_book_flag+=1;
					game_point+=1;
				} 
			}


}