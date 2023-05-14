
# ifndef _MOUSE_H
# define _MOUSE_H


typedef struct Mouse {
	int* (*get_pos)();
	bool* (*get_pressed)();

} Mouse;

int* mouse_get_pos ();
bool* mouse_get_pressed ();

# endif
