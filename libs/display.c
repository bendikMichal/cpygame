
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

/*
 * Have to include cpygame in order to have access to cpg
 * 
 */
# include "../cpygame.h"

static CPG_Window def_window = {
	.fill = &window_fill,
	.blit = &window_blit,
	.type = TYPE_CPG_WINDOW
};

CPG_Window display_set_mode(int size[2], int falgs) {
	SDL_Window *sdl_window = SDL_CreateWindow("Cpygame Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, size[0], size[1], SDL_WINDOW_OPENGL);

	static SDL_Renderer *renderer;
	renderer = SDL_CreateRenderer(sdl_window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	CPG_Window window = def_window;

	window.window = sdl_window;
	window.renderer = renderer;

	cpg.window = window;

	return window;
}

void display_set_caption(char *title) {
	SDL_SetWindowTitle(cpg.window.window, title);
}

void display_update() {
	SDL_RenderPresent(cpg.window.renderer);
}
