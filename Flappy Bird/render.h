#pragma once

#include "text.h"

#include <cmath>
#include <Windows.h>

constexpr int BIRD_SPRITE_W = 17;
constexpr int BIRD_SPRITE_H = 12;
constexpr int PIPE_SPRITE_W = 19;
constexpr int PIPE_SPRITE_H = 12;

constexpr int INVIS = 0xffff00ff;
constexpr int PIPE_GREEN = 0xff65db21;
constexpr int PIPE_GREEN2 = 0xff2ac225;

static Color bird [ BIRD_SPRITE_H ] [ BIRD_SPRITE_W ] = {
	{ INVIS,  INVIS,  INVIS,  INVIS,  INVIS,  INVIS,  Black,  Black,  Black,  Black,  Black,  Black,  INVIS,  INVIS,  INVIS,  INVIS,  INVIS, },
{ INVIS,  INVIS,  INVIS,  INVIS,  Black,  Black,  White,  White,  White,  Black,  White,  White,  Black,  INVIS,  INVIS,  INVIS,  INVIS, },
{ INVIS,  INVIS,  INVIS,  Black,  White,  White,  Yellow,  Yellow,  Black,  White,  White,  White,  White,  Black,  INVIS,  INVIS,  INVIS, },
{ INVIS,  Black,  Black,  Black,  Black,  Yellow,  Yellow,  Yellow,  Black,  White,  White,  White,  Black,  White,  Black,  INVIS,  INVIS, },
{ Black,  White,  White,  White,  White,  Black,  Yellow,  Yellow,  Black,  White,  White,  White,  Black,  White,  Black,  INVIS,  INVIS, },
{ Black,  White,  White,  White,  White,  White,  Black,  Yellow,  Yellow,  Black,  White,  White,  White,  White,  Black,  INVIS,  INVIS, },
{ Black,  Yellow,  White,  White,  White,  Yellow,  Black,  Yellow,  Yellow,  Yellow,  Black,  Black,  Black,  Black,  Black,  Black,  INVIS, },
{ INVIS,  Black,  Yellow,  Yellow,  Yellow,  Black,  Yellow,  Yellow,  Yellow,  Black,  LightRed,  LightRed,  LightRed,  LightRed,  LightRed,  LightRed,  Black, },
{ INVIS,  INVIS,  Black,  Black,  Black,  Brown,  Brown,  Brown,  Black,  LightRed,  Black,  Black,  Black,  Black,  Black,  Black,  INVIS, },
{ INVIS,  INVIS,  Black,  Brown,  Brown,  Brown,  Brown,  Brown,  Brown,  Black,  LightRed,  LightRed,  LightRed,  LightRed,  LightRed,  Black,  INVIS, },
{ INVIS,  INVIS,  INVIS,  Black,  Black,  Brown,  Brown,  Brown,  Brown,  Brown,  Black,  Black,  Black,  Black,  Black,  INVIS,  INVIS, },
{ INVIS,  INVIS,  INVIS,  INVIS,  INVIS,  Black,  Black,  Black,  Black,  Black,  INVIS,  INVIS,  INVIS,  INVIS,  INVIS,  INVIS,  INVIS, },
};

static Color pipe [ PIPE_SPRITE_H ] [ PIPE_SPRITE_W ] = {
	{ Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black },
{ Black, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, Black },
{ Black, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, Black },
{ Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, Black },
{ Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, Black },
{ Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, Black },
{ Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, Black },
{ Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, Black },
{ Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, Black },
{ Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black },
{ INVIS, INVIS, Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, Black, INVIS, INVIS },
{ INVIS, INVIS, Black, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN2, PIPE_GREEN, PIPE_GREEN, Black, INVIS, INVIS },
};

static void draw_background ( ) {
	Clear ( LightCyan );

}

static void draw_bird ( int x, int y ) {
	for ( int i = 0; i < BIRD_SPRITE_H; i++ ) {
		for ( int j = 0; j < BIRD_SPRITE_W; j++ ) {
			if ( bird [ i ] [ j ] == INVIS )
				continue;
			SetPixel ( j + x, i + y, bird [ i ] [ j ] );
		}
	}

}

static void draw_pipe ( int x, int y, bool inverted = false ) {
	for ( int i = 0; inverted ? ( i > -PIPE_SPRITE_H ) : ( i < PIPE_SPRITE_H ); inverted ? i-- : i++ ) {
		for ( int j = 0; j < PIPE_SPRITE_W; j++ ) {
			if ( pipe [ abs ( i ) ] [ j ] == INVIS )
				continue;

			SetPixel ( j + x, i + y, pipe [ abs ( i ) ] [ j ] );
		}
	}

	for ( int i = 0; inverted ? ( i > -Height * 2 ) : ( i < Height * 2 ); i += ( inverted ? -2 : 2 ) ) {
		int new_y = y + ( inverted ? -12 : 12 ) + i;
		int new_y1 = y + ( inverted ? -13 : 13 ) + i;

		if ( new_y > Height || new_y < 0 )
			break;

		for ( int j = 0; j < PIPE_SPRITE_W; j++ ) {
			if ( pipe [ 10 ] [ j ] == INVIS )
				continue;

			SetPixel ( j + x, new_y, pipe [ 10 ] [ j ] );
		}

		for ( int j = 0; j < PIPE_SPRITE_W; j++ ) {
			if ( pipe [ 11 ] [ j ] == INVIS )
				continue;

			SetPixel ( j + x, new_y1, pipe [ 11 ] [ j ] );
		}
	}
}

static void draw_ui ( int score ) {
	std::string score_str = std::to_string ( score );
	int score_w = MeasureString ( score_str );
	DrawString ( Width / 2 - score_w / 2, 2, score_str, White, true );
}