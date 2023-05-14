
# include <stdio.h>
# include <stdbool.h>

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_events.h>
# include <SDL2/SDL_mouse.h>

# include "../cpygame.h"

int* mouse_get_pos() {
	Uint32 buttons;
	SDL_PumpEvents(); 

	static int pos[] = {0, 0};
	buttons = SDL_GetMouseState(&pos[0], &pos[1]);

	return pos;
}

bool* mouse_get_pressed() {
	static bool mouse[3] = {false, false, false};
	mouse[0] = false;
	mouse[1] = false;
	mouse[2] = false;

	if (cpg.event.event.type == SDL_MOUSEBUTTONDOWN) {
		if (cpg.event.event.button.button == SDL_BUTTON_LEFT) mouse[0] = true;
		if (cpg.event.event.button.button == SDL_BUTTON_MIDDLE) mouse[1] = true;
		if (cpg.event.event.button.button == SDL_BUTTON_RIGHT) mouse[2] = true;
	}

	return mouse;
}
