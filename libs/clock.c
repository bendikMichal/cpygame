
# include <stdio.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_stdinc.h>

# include "../cpygame.h"


void clock_tick(int fps) {

	cpg.clock.frameDELAY = (Uint32)(MILISECOND / fps);

	// caluclate time it took to do a frame
	cpg.clock.frameTIME = SDL_GetTicks() - cpg.clock.frameSTART;
	if (cpg.clock.frameTIME < cpg.clock.frameDELAY){
		SDL_Delay(cpg.clock.frameDELAY - cpg.clock.frameTIME);
	}
	cpg.clock.a = SDL_GetTicks() - cpg.clock.frameSTART;

	// reset frame timer
	cpg.clock.frameSTART = SDL_GetTicks();
}

float clock_get_fps () {

	return MILISECOND * ( 1.0f / (cpg.clock.a > 0 ? cpg.clock.a : 1));
	/* return 1.0f * MILISECOND / cpg.clock.frameDELAY; */
}
