void keyboard_control(unsigned char key)

{
    
	if(mode == 1 && screen == 15)
	{
        if(key == '\r')
		{
			mode = 3;
			screen = 7;
			
			total_game_point =0;
			game_point =0;

			strcpy(details[total_user+1].name, player_name);
			printf("%s\n", details[total_user+1].name);
			user_name_appender();

			for(int i = 0; i < length; i++)
				player_name[i] = 0;
			length = 0;


		}
		else
		{
			player_name[length] = key;
			length++;
		}
	}

	if(mode == 1 && screen == 22)
	{
        if(key == '\r')
		{
			mode = 3;
			screen = 7;
			
			// total_game_point =0;
			// game_point =0;

			// strcpy(details[total_user+1].name, player_name);
			printf("%s\n", resume_player_name);
			// user_name_appender();

			for(int i = 0; i < length; i++)
				resume_player_name[i] = 0;

			length = 0;


		}
		else
		{
			player_name[length] = key;
			length++;
		}
	}

	if (key == 'p' && (screen == 7 || screen == 19))
	{
			book_state =0;
	}

	if ( key == 's' && screen == 7 && book_state == 1 ) user_point_appender(game_point);

	if(screen == 7 ||screen == 18 || screen == 19)
	{
		ball_throw_command(key);
	}



	if(key == 'x')
	{
		//do something with 'x'
		user_point_appender(game_point);
		exit(0);
	}
}