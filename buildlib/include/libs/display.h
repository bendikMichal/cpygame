
# ifndef _DISPLAY_H
# define _DISPLAY_H

typedef struct Display{
	CPG_Window (*set_mode)(int[2], int);
	void (*set_caption)(char*);
	void (*update)();

} Display;


CPG_Window display_set_mode(int size[2], int falgs);
void display_set_caption(char *title);
void display_update();

# endif
