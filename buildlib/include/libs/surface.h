
# ifndef _SURFACE_H
# define _SURFACE_H

# include <SDL2/SDL_render.h>

typedef struct CPG_Surface {
	// order of these is very important, wrong orderwill crash the lib
	int type;
	
	void (*blit) (struct CPG_Surface, SDL_Texture*, int[2]);
	void (*fill) (struct CPG_Surface, int[3]);

	SDL_Texture* surface;

} CPG_Surface;

CPG_Surface surface_Surface(int size[2]);
void surface_blit(CPG_Surface self, SDL_Texture *src, int pos[2]);
void surface_fill(CPG_Surface self, int color[3]);

#endif
