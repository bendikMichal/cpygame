
typedef struct Mouse {
	int* (*get_pos)();

} Mouse;

int* mouse_get_pos ();
