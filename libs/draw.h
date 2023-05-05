
# ifndef _DRAW_H
# define _DRAW_H

# include "rect.h"
# include "circle.h"
# include "window.h"
# include "surface.h"
# include "Type.h"


void draw_rect_window(CPG_Window *window, int color[3], CPG_Rect rect);
void draw_rect_surface(CPG_Surface *surface, int color[3], CPG_Rect rect);
void draw_rect(CPG_Obj *obj, int color[3], CPG_Rect rect);

void draw_circle_window(CPG_Window *window, int color[3], CPG_Circle c, int border);
void draw_circle_surface(CPG_Surface *surface, int color[3], CPG_Circle c, int border);
void draw_circle(CPG_Obj *obj, int color[3], CPG_Circle circle, int border);

typedef struct Draw {
	void (*rect)(CPG_Obj *, int [3], CPG_Rect);
	void (*circle)(CPG_Obj *, int [3], CPG_Circle, int);
		
} Draw;

# endif
