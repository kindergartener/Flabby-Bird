#pragma once
#include "render.h"

#include <algorithm>

constexpr int max_pipes = 10;
constexpr int pipe_gap_x = 65;
constexpr int pipe_gap_y = 40;

int pipe_counter = 0;

struct pipe_s
{
	int pipe_num = 0;
	int pipe_x = 0;
	int pipe_y = 0;
};

pipe_s pipes [ max_pipes ] {};
int pipes_on_screen = 0;

int rand_range ( int min, int max ) {
	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;
	do {
		x = rand ( );
	} while ( x >= RAND_MAX - remainder );
	return min + x % n;
}

pipe_s generate_pipe ( ) {
	pipe_counter++;

	if ( !pipes_on_screen ) {
		int pipe_x = Width - PIPE_SPRITE_W - 2;
		int pipe_y = rand_range ( pipe_gap_y + PIPE_SPRITE_H, Height - PIPE_SPRITE_H );

		return pipe_s { pipe_counter, pipe_x, pipe_y };
	}

	int pipe_x = pipes [ pipes_on_screen - 1 ].pipe_x + pipe_gap_x;
	int pipe_y = rand_range ( pipe_gap_y + PIPE_SPRITE_H, Height - PIPE_SPRITE_H );

	return pipe_s { pipe_counter,pipe_x, pipe_y};
}

int last_pipe_crossed = 0;

static void draw_terrain ( int bird_x, int bird_y, int& score, bool& game_over ) {
	if ( !pipes_on_screen ) {
		pipes [ 0 ] = generate_pipe ( );
		pipes_on_screen = std::clamp ( pipes_on_screen + 1, 1, max_pipes );
	}
	else if ( pipes [ pipes_on_screen - 1 ].pipe_x - PIPE_SPRITE_W < bird_x + Width ) {
		if ( pipes_on_screen == max_pipes ) {
			for ( int i = 0; i < max_pipes - 1; i++ )
				pipes [ i ] = pipes [ i + 1 ];

			pipes [ max_pipes - 1 ] = generate_pipe ( );
		}
		else {
			pipes [ pipes_on_screen ] = generate_pipe ( );
		}

		pipes_on_screen = std::clamp ( pipes_on_screen + 1, 1, max_pipes );
	}

	for ( int i = 0; i < pipes_on_screen - 1; i++ ) {
		if ( !pipes [ i ].pipe_x && !pipes [ i ].pipe_y )
			continue;

		// save cpu by not drawing pipes out of screen
		if( pipes [ i ].pipe_x - bird_x + PIPE_SPRITE_W < 0
			|| pipes [ i ].pipe_x - bird_x > Width )
			continue;

		draw_pipe ( pipes [ i ].pipe_x - bird_x, pipes [ i ].pipe_y );
		draw_pipe ( pipes [ i ].pipe_x - bird_x, pipes [ i ].pipe_y - pipe_gap_y, true );

		if ( pipes [ i ].pipe_x - bird_x < PIPE_SPRITE_W / 2 && pipes[i].pipe_num >last_pipe_crossed ) {
			score++;
			last_pipe_crossed = pipes [ i ].pipe_num;
		}

		// check if bird collides with pipe
		if ( bird_x - 1 > ( pipes [ i ].pipe_x - BIRD_SPRITE_W )
			&& bird_x + 2 < ( pipes [ i ].pipe_x + PIPE_SPRITE_W )
			&& (bird_y + 1 <= ( pipes [ i ].pipe_y - pipe_gap_y ) || bird_y - 1 >= ( pipes [ i ].pipe_y - BIRD_SPRITE_H ) ))
			game_over = true;
	}
}