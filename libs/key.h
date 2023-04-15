
#ifndef _KEY_H
#define _KEY_H

# include <SDL2/SDL_stdinc.h>

const Uint8* key_get_pressed ();

typedef struct Key {
	const Uint8* (*get_pressed)();

} Key;

#endif
