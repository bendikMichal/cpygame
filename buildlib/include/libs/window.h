
#include <SDL2/SDL_render.h>

typedef struct Window {
	SDL_Window *window;
	SDL_Renderer *renderer;

	void (*blit)(SDL_Texture*, int[2]);
	void (*fill)(int[3]);

} Window;

/* void blit(, int pos[2]); */

// surface will require self to be passed as there are multiple instances
void window_blit(SDL_Texture *texture, int pos[2]);
void window_fill(int color[3]);


