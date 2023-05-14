

# ifndef _EVENT_H
# define _EVENT_H

# include <SDL2/SDL_events.h>

typedef struct {

	SDL_Event event;
	int (* get) ();

} Event;

int event_get();

# endif
