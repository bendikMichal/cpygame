
# ifndef _IMAGE_H
# define _IMAGE_H

# include <SDL2/SDL.h>

typedef struct Image {
	SDL_Texture* (*load)(char [512]);

} Image;



SDL_Texture *image_load(char img_path[512]);

# endif
