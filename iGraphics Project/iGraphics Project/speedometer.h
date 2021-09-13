

//! code of tara

void collisionCheck()
{
	rect_y1 +=rect_dy;

	if(rect_y1 > 0 &&  rect_y1 < 45) //0,40
	{
		r1 = 182;
		g1 = 25;
		b1 = 25;
		
	}
   
	if(rect_y1 > 41 && rect_y1 < 82 )//41,82
	{
		r2 = 182;
		g2 = 25;
		b2 = 25;

	}
	if(rect_y1 > 84 && rect_y1 <130)//84,130
	{
		r3 = 182;
		g3 = 25;
		b3 = 25;

	}
	if(rect_y1 > 132 && rect_y1 < 160) //132,160
	{
		r4 = 182;
		g4 = 25;
		b4 = 25;
	}
	if( rect_y1 > 165 && rect_y1 < 178)//165,178
	{
		r5 = 182;
		g5 = 25;
		b5 = 25;
	}

	//printf("collision y=%d\n",rect_y1);
//The blocks turned red when the white block touched their coordinates and the white block is working from bottom to topp 

}

void rectangle_change_1(){
	

    rect_y_2 += rect_dy_2;
    rect_y_3 += rect_dy_3;
	 if (rect_y_3 +80 > frame_height || rect_y_3 < 0 )  rect_dy_3 = -rect_dy_3;
     if (rect_y_2 +80 > frame_height || rect_y_2 < 0 )  rect_dy_2 = -rect_dy_2;
    
}