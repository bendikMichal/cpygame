
# include <stdio.h>
# include <math.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# include "../cpygame.h"

void window_blit(SDL_Texture *texture, int pos[2]){

	SDL_Point size;
	size.x = 64;
	size.y = 48;
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	SDL_Rect src = {0, 0, size.x, size.y};
	SDL_Rect dest = {pos[0], pos[1], size.x, size.y};
	
	SDL_RenderCopy(cpg.window.renderer, texture, &src, &dest);
}

void window_fill(int color[3]) {

	SDL_SetRenderDrawColor(cpg.window.renderer, color[0], color[1], color[2], 255);

	SDL_RenderClear(cpg.window.renderer);
}
