
#ifndef _FONT_H
#define _FONT_H

# include <SDL2/SDL_ttf.h>
# include <stdbool.h>

typedef struct Font {
	TTF_Font *font;
	TTF_Font* (*SysFont) (char*, int);
	SDL_Texture* (*render) (char*, bool, SDL_Color);

} Font;

TTF_Font* font_SysFont(char *font, int size);
SDL_Texture* font_render(char *text, bool antialias, SDL_Color color);

#endif
