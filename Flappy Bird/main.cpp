#include "render.h"
#include "terrain.h"
#include "controller.h"

#include <time.h>
#include <thread>

int score = 0;
float bird_x = 6;
float bird_y = Height / 2 - BIRD_SPRITE_H / 2;
bool game_over = false;
bool pressed_space = false;

void main ( ) {
	srand ( time(nullptr));

	UseDoubleBuffering ( true );

	std::thread ( handle_input ).detach ( );

start_game:
	score = 0;
	bird_x = 6;
	bird_y = Height / 2 - BIRD_SPRITE_H / 2;
	game_over = false;
	pressed_space = false;
	bird_velocity_y = 0;
	pipe_counter = 0;
	memset ( pipes, 0, sizeof( pipes ) );
	pipes_on_screen = 0;
	last_pipe_crossed = 0;

	while ( true ) {
		char last_key = LastKey ( );

		if ( last_key == VK_SPACE )
			pressed_space = true;

		// physics
		if(!game_over && pressed_space )
			apply_gravity ( bird_y );

		if ( bird_y > Height*1.20 )
			game_over = true;

		// render
		draw_background ( );

		draw_bird ( 6, bird_y );
		
		draw_terrain ( bird_x, bird_y, score, game_over );

		// post processing or ui
		if ( !pressed_space ) {
			std::string start_text = "Press Space to Start!";
			int start_text_w = MeasureString ( start_text );
			DrawString ( Width / 2 - start_text_w / 2, Height / 2 - 3, start_text, White, true );
		}

		draw_ui ( score );

		if ( game_over ) { 
			DrawRectangle (Width/2 - ( Width / 4 )/2, Height/2 - ( Height / 4 )/2, Width/4, Height/4, 0xffded793, true);
			DrawRectangle ( Width / 2 - ( Width / 4 ) / 2, Height / 2 - ( Height / 4 ) / 2, Width / 4, Height / 4, 0xff58414d, false );
			
			std::string score_text = "Score: " + std::to_string ( score );
			int score_text_w = MeasureString ( score_text );
			DrawString ( Width / 2 - score_text_w / 2, Height / 2 - 6 + 1, score_text, 0xffedeca3, false );
			DrawString ( Width / 2 - score_text_w / 2, Height / 2 - 6, score_text, 0xfffe7a5b, false );

			std::string retry_text = "Retry";
			int retry_text_w = MeasureString ( retry_text );
			DrawRectangle ( Width / 2 - retry_text_w / 2 - 2 - 1, Height / 2 + 3 - 2, retry_text_w + 4 + 1, 6 + 3 + 1, 0xff000000, true );
			DrawRectangle ( Width / 2 - retry_text_w / 2 - 2 - 1, Height / 2 + 3 - 2, retry_text_w + 4, 6 + 3, 0xff58414d, true );
			DrawString ( Width / 2 - retry_text_w / 2 - 1, Height / 2 + 3, retry_text, 0xfffe7a5b, false );

			if ( LeftMousePressed ( )
				&& MouseX ( ) >= Width / 2 - retry_text_w / 2 - 2 - 1
				&& MouseY ( ) >= Height / 2 + 3 - 2
				&& MouseX ( ) <= Width / 2 - retry_text_w / 2 - 2 - 1 + retry_text_w + 4
				&& MouseY ( ) <= Height / 2 + 3 - 2 + 6 + 3 + 1 ) {
				goto start_game;
			}
		}

		Present ( );

		if(!game_over&& pressed_space )
			bird_x++;

		Wait ( 1000 / 60 );
	}
}