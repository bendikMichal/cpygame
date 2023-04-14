
# include <stdio.h>
# include <math.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

# include "../cpygame.h"



SDL_Texture *image_load(char img_path[512]){
	// function returns pointer
	SDL_Surface *image;
	image = IMG_Load(img_path);
	if (!image) {
		printf("\n No such file or directory %s, continuing...", img_path);
	}
	// here pointer *texture
	SDL_Texture *texture = SDL_CreateTextureFromSurface(cpg.window.renderer, image);

	SDL_FreeSurface(image);

	// note there is no &, because texture is already a pointer therefore we don't need it
	return texture;
}
