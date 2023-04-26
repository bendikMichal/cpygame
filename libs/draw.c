
# include <stdio.h>
# include <SDL2/SDL.h>

# include "../cpygame.h"

void draw_rect_window(CPG_Window *window, int color[3], CPG_Rect rect) {
	SDL_Rect temp = {rect.x, rect.y, rect.w, rect.h};

	SDL_SetRenderDrawColor(cpg.window.renderer, color[0], color[1], color[2], 255);
	SDL_RenderFillRect(cpg.window.renderer, &temp);
}

void draw_rect_surface(CPG_Surface *surface, int color[3], CPG_Rect rect) {
	SDL_SetRenderTarget(cpg.window.renderer, surface->surface);

	draw_rect_window(NULL, color, rect);

	SDL_SetRenderTarget(cpg.window.renderer, NULL);
}

void draw_rect(CPG_Obj *obj, int color[3], CPG_Rect rect) {
	switch (obj->type) {
		case TYPE_CPG_WINDOW: ;
			draw_rect_window((CPG_Window *)obj, color, rect);
			break;

		case TYPE_CPG_SURFACE: ;
			draw_rect_surface((CPG_Surface *)obj, color, rect);
			break;
	
		deafult:
			printf("Failed to draw rect as provided is not of a type CPG_Window or CPG_Surface");
	}
}

/* void draw_rect_switch(int *type, int color[3], CPG_Rect rect) { */
/* 	switch (*type) { */
/* 		case TYPE_CPG_WINDOW: ; */
/* 			draw_rect_window((CPG_Window *)type, color, rect); */
/* 			break; */

/* 		case TYPE_CPG_SURFACE: ; */
/* 			draw_rect_surface((CPG_Surface *)type, color, rect); */
/* 			break; */
	
/* 		deafult: */
/* 			printf("Failed to draw rect as provided is not of a type CPG_Window or CPG_Surface"); */
/* 	} */
/* } */

