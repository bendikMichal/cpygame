
#ifndef _MOUSE_H
#define _MOUSE_H

typedef struct Mouse {
	int* (*get_pos)();

} Mouse;

int* mouse_get_pos ();

#endif
