

# include <SDL2/SDL_ttf.h>
# include <stdbool.h>
# include <stdio.h>

# include "../cpygame.h"

TTF_Font* font_SysFont(char *font, int size) {
	TTF_Font *fnt = TTF_OpenFont(font, size);
	if (fnt == NULL) {
		printf("Failed to load font: %s \n", font);
	}
	cpg.font.font = fnt;
	return fnt;
}

SDL_Texture* font_render(char *text, bool antialias, SDL_Color color) {

	SDL_Surface* srf = TTF_RenderText_Solid(cpg.font.font, text, color); 
	SDL_Texture* tex = SDL_CreateTextureFromSurface(cpg.window.renderer, srf);

	SDL_FreeSurface(srf);
	return tex;
}
