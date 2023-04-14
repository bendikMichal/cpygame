
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# include "../cpygame.h"

int* mouse_get_pos() {
	Uint32 buttons;
	SDL_PumpEvents(); 

	static int pos[] = {0, 0};
	buttons = SDL_GetMouseState(&pos[0], &pos[1]);

	return pos;
}
