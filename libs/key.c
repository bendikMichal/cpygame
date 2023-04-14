
# include <SDL2/SDL.h>

# include "../cpygame.h"

const Uint8* key_get_pressed () {
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	return keys;
}
