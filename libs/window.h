
# ifndef _WINDOW_H
# define _WINDOW_H


#include <SDL2/SDL_render.h>

typedef struct CPG_Window {
	SDL_Window *window;
	SDL_Renderer *renderer;
	int type;

	void (*blit)(SDL_Texture*, int[2]);
	void (*fill)(int[3]);

} CPG_Window;

/* void blit(, int pos[2]); */

// surface will require self to be passed as there are multiple instances
void window_blit(SDL_Texture *texture, int pos[2]);
void window_fill(int color[3]);

# endif
