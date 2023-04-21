

# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# include "../cpygame.h"



CPG_Surface surface_Surface(int size[2]) {
	SDL_Texture *newSurf = SDL_CreateTexture(cpg.window.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size[0], size[1]); 

	CPG_Surface surf = {
		.surface = newSurf,
		.blit = &surface_blit,
		.fill = &surface_fill,
		.type = TYPE_CPG_SURFACE
	};
	return surf;
}

void surface_blit(CPG_Surface self, SDL_Texture *src, int pos[2]) {
	SDL_SetRenderTarget(cpg.window.renderer, self.surface);

	// this works because window_blit renders to current target not window specificaly
	window_blit(src, pos);

	// set target back to window
	SDL_SetRenderTarget(cpg.window.renderer, NULL);
}

void surface_fill(CPG_Surface self, int color[3]) {
	SDL_SetRenderTarget(cpg.window.renderer, self.surface);

	// this works because window_blit renders to current target not window specificaly
	window_fill(color);

	// set target back to window
	SDL_SetRenderTarget(cpg.window.renderer, NULL);
}



