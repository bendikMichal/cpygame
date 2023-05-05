
# include <stdio.h>
# include <SDL2/SDL.h>
# include <math.h>

# include "../cpygame.h"
#include "Type.h"

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
			draw_rect_window(ToCPG_Window(obj), color, rect);
			break;

		case TYPE_CPG_SURFACE: ;
			draw_rect_surface(ToCPG_Surface(obj), color, rect);
			break;
	
		deafult:
			printf("Failed to draw rect as provided is not of a type CPG_Window or CPG_Surface");
	}
}

void draw_circle(CPG_Obj *obj, int color[3], CPG_Circle circle, int border) {
	switch (obj->type) {
		case TYPE_CPG_WINDOW: ;
			draw_circle_window((CPG_Window *)obj, color, circle, border);
			break;

		case TYPE_CPG_SURFACE: ;
			draw_circle_surface((CPG_Surface *)obj, color, circle, border);
			break;
	
		deafult:
			printf("Failed to draw rect as provided is not of a type CPG_Window or CPG_Surface");
	}
}

void draw_circle_surface(CPG_Surface *surface, int color[3], CPG_Circle c, int border) {

	SDL_SetRenderTarget(cpg.window.renderer, surface->surface);

	draw_circle_window(NULL, color, c, border);

	SDL_SetRenderTarget(cpg.window.renderer, NULL);
}

void draw_circle_window(CPG_Window *window, int color[3], CPG_Circle c, int border) {

	int sx = c.x - c.r;
	int sy = c.y - c.r;

	SDL_SetRenderDrawColor(cpg.window.renderer, color[0], color[1], color[2], 255);

	if (border) {

		// unfill
		while (sx <= c.x && sy <= c.y) {
			if (round(sqrt(pow(abs((int)c.x - sx), 2) + pow(abs((int)c.y - sy), 2))) == c.r) {
				SDL_RenderDrawPoint(cpg.window.renderer, sx, sy);
				SDL_RenderDrawPoint(cpg.window.renderer, (c.x - sx) + c.x, sy);
				SDL_RenderDrawPoint(cpg.window.renderer, sx, (c.y - sy) + c.y);
				SDL_RenderDrawPoint(cpg.window.renderer, (c.x - sx) + c.x, (c.y - sy) + c.y);
			}	

			sx ++;
			if (sx > c.x) {
				sx = c.x - c.r;
				sy ++;
			}
		}

	}
	else {

		// fill
		while (sx <= c.x && sy <= c.y) {
			if (round(sqrt(pow(abs((int)c.x - sx), 2) + pow(abs((int)c.y - sy), 2))) <= c.r) {
				SDL_RenderDrawPoint(cpg.window.renderer, sx, sy);
				SDL_RenderDrawPoint(cpg.window.renderer, (c.x - sx) + c.x, sy);
				SDL_RenderDrawPoint(cpg.window.renderer, sx, (c.y - sy) + c.y);
				SDL_RenderDrawPoint(cpg.window.renderer, (c.x - sx) + c.x, (c.y - sy) + c.y);
			}	

			sx ++;
			if (sx > c.x) {
				sx = c.x - c.r;
				sy ++;
			}
		}
	}
}

