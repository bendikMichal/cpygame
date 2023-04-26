
# include <SDL2/SDL.h>
# include <math.h>
# include <stdbool.h>

# include "../cpygame.h"


SDL_Rect rect_to_sdl_rect (CPG_Rect *rect) {
	SDL_Rect new_rect = {(int)rect->x, (int)rect->y, (int)rect->w, (int)rect->h};
	return new_rect;
}

void rect_set_top (CPG_Rect *rect, float value) {
	rect->y = value;
}
float rect_get_top (CPG_Rect *rect) {
	return rect->y;
}

void rect_set_bottom (CPG_Rect *rect, float value) {
	rect->y = value - rect->h;
}
float rect_get_bottom (CPG_Rect *rect) {
	return rect->y + rect->h;
}

void rect_set_left (CPG_Rect *rect, float value) {
	rect->x = value;
}
float rect_get_left (CPG_Rect *rect) {
	return rect->x;
}

void rect_set_right (CPG_Rect *rect, float value) {
	rect->x = value - rect->w;
}
float rect_get_right (CPG_Rect *rect) {
	return rect->x + rect->w;
}

bool rect_colliderect(CPG_Rect *self, CPG_Rect *rect) {
	return (rect->x - self->w < self->x < rect->x + rect->w) && (rect->y - self->h < self->y < rect->y + rect->h);
}

CPG_Rect rect_Rect (float x, float y, float w, float h) {
	CPG_Rect new_rect = {
		.type = TYPE_CPG_RECT,
			
		.x = x,
		.y = y,
		.w = w,
		.h = h,

		.get_top = &rect_get_top,
		.set_top = &rect_set_top,

		.get_bottom = &rect_get_bottom,
		.set_bottom = &rect_set_bottom,

		.get_left = &rect_get_left,
		.set_left = &rect_set_left,

		.get_right = &rect_get_right,
		.set_right = &rect_set_right,
		
		.colliderect = &rect_colliderect,
		.to_sdl_rect = &rect_to_sdl_rect,
	};

	return new_rect;
}
