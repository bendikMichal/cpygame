

# ifndef _CLOCK_H
# define _CLOCK_H

# include <SDL2/SDL.h>

typedef struct Clock{

	Uint32 frameDELAY;
	Uint32 frameSTART;
	Uint32 frameTIME;
	int a;

	void (*tick) (int);
	float (*get_fps) ();

} Clock;

void clock_tick(int fps);

float clock_get_fps ();

#endif
