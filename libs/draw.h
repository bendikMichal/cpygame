
# ifndef _DRAW_H
# define _DRAW_H

# include "rect.h"
# include "window.h"
# include "surface.h"


void draw_rect_window(CPG_Window *window, int color[3], CPG_Rect rect);
void draw_rect_surface(CPG_Surface *surface, int color[3], CPG_Rect rect);

void draw_rect_switch(int *type, int color[3], CPG_Rect rect);
# define draw_rect(x, color, rect) draw_rect_switch(&x.type, color, rect)
# define cpg_draw_rect(x, y, z) draw_rect(x, y, z)

typedef struct Draw {
		
} Draw;

# endif
