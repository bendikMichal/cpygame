
# ifndef _TRANSFORM_H
# define _TRANSFORM_H

# include <SDL2/SDL_render.h>

# define ROTATIONS (int[][2]){{0, 0}, {1, 0}, {1, 1}, {0, 1}}

typedef struct {
	
	SDL_Texture* (* rotate)(SDL_Texture *, int);

} Transform;

SDL_Texture* transform_rotate (SDL_Texture *texture, int angle);

# endif
