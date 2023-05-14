
# ifndef _RECT_H
# define _RECT_H

# include <SDL2/SDL_rect.h>
# include <stdbool.h>

# ifndef _TYPE_H
# define _TYPE_H

# include "Type.h"

# endif

typedef struct CPG_Rect {
	int type;

	float x, y;
	float w, h;

	void (*set_top) (struct CPG_Rect*, float);
	float (*get_top) (struct CPG_Rect*);

	void (*set_bottom) (struct CPG_Rect*, float);
	float (*get_bottom) (struct CPG_Rect*);

	void (*set_left) (struct CPG_Rect*, float);
	float (*get_left) (struct CPG_Rect*);

	void (*set_right) (struct CPG_Rect*, float);
	float (*get_right) (struct CPG_Rect*);

	bool (*colliderect) (struct CPG_Rect*, struct CPG_Rect*);
	SDL_Rect (*to_sdl_rect) (struct CPG_Rect*);

} CPG_Rect;

SDL_Rect rect_to_sdl_rect (CPG_Rect *rect);

void rect_set_top (CPG_Rect *rect, float value);
float rect_get_top (CPG_Rect *rect);

void rect_set_bottom (CPG_Rect *rect, float value);
float rect_get_bottom (CPG_Rect *rect);

void rect_set_left (CPG_Rect *rect, float value);
float rect_get_left (CPG_Rect *rect);

void rect_set_right (CPG_Rect *rect, float value);
float rect_get_right (CPG_Rect *rect);

bool rect_colliderect(CPG_Rect *self, CPG_Rect *rect);

CPG_Rect rect_Rect (float x, float y, float w, float h);

# endif
