#pragma once

float bird_velocity_y = 0;

static void handle_input ( ) {
	bool pressed = false;

	while ( true) {
		if ( !pressed && GetAsyncKeyState ( VK_SPACE ) ) {
			bird_velocity_y = -2.5; //impulse
			pressed = true;
		}
		else if ( !GetAsyncKeyState ( VK_SPACE ) ) {
			pressed = false;
		}

		Wait (1 );
	}
}

static void apply_gravity ( float& bird_y ) {
	bird_velocity_y += 0.25; //gravity coefficient
	bird_y += bird_velocity_y;
	
}