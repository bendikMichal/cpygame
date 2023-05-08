
# ifndef _WINDOW_H
# define _WINDOW_H


#include <SDL2/SDL_render.h>

typedef struct CPG_Window {
	// order of these is very important, wrong orderwill crash the lib
	int type;

	void (*blit)(SDL_Texture*, int[2]);
	void (*scaled_blit)(SDL_Texture*);
	void (*blit_rot)(SDL_Texture*, int[2], int);
	void (*fill)(int[3]);

	SDL_Window *window;
	SDL_Renderer *renderer;
} CPG_Window;

/* void blit(, int pos[2]); */

// surface will require self to be passed as there are multiple instances
void window_blit(SDL_Texture *texture, int pos[2]);
void window_scaled_blit(SDL_Texture *texture);
void window_blit_rot(SDL_Texture *texture, int pos[2], int angle);
void window_fill(int color[3]);

# endif
