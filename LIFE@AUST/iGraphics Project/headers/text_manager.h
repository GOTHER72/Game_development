void instruction_move()
{
	iSetColor(255, 255, 255);
	if (instruction_move_flag ==1)  iText(instruction_move_x , 10, "Press p to stop the books",GLUT_BITMAP_TIMES_ROMAN_24);
	else if (instruction_move_flag ==2) iText(instruction_move_x , 10, "Press space to use your brain  just throw it!",GLUT_BITMAP_TIMES_ROMAN_24);
}

void instructions_text_move()

{
	instruction_move_x -= instruction_move_dx;
	if( instruction_move_x < 0 && instruction_move_flag == 1 )
	{
		instruction_move_x = 1000;
		instruction_move_flag = 2;

	}
	else if( instruction_move_x < 0 && instruction_move_flag == 2 )
	{
		instruction_move_x = 1000;
		instruction_move_flag = 1;
	}
		
}

void changable_text(){

	std::sprintf(game_point_char, "%d", game_point);
    iText(106, 495, game_point_char,GLUT_BITMAP_TIMES_ROMAN_24);

	std::sprintf(left_chances_char, "%d", left_chances-1);
    iText(270, 495, left_chances_char,GLUT_BITMAP_TIMES_ROMAN_24);
}
