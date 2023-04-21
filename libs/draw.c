
# include <stdio.h>
# include <SDL2/SDL.h>

# include "../cpygame.h"

void draw_rect_window(CPG_Window *window, int color[3], CPG_Rect rect) {
	printf("Window \n");
}

void draw_rect_surface(CPG_Surface *surface, int color[3], CPG_Rect rect) {
	printf("Suface \n");

}

void draw_rect_switch(int *type, int color[3], CPG_Rect rect) {
	switch (*type) {
		case TYPE_CPG_WINDOW:
			draw_rect_window((CPG_Window *)type, color, rect);
			break;

		case TYPE_CPG_SURFACE:
			draw_rect_surface((CPG_Surface *)type, color, rect);
			break;
	
		deafult:
			printf("Failed to draw rect as provided is not of a type CPG_Window or CPG_Surface");
	}
}

