
# include "../cpygame.h"

# include <SDL2/SDL_events.h>

int event_get() {
	int res = SDL_PollEvent(&cpg.event.event);

	return res;
}
