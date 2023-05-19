
# include <stdio.h>

# include <SDL2/SDL_mixer.h>

# include "../cpygame.h"

void mixer_init(int frequency, Uint16 format, int channels, int chunksize) {
	if(Mix_OpenAudio(frequency, format, channels, chunksize) < 0) {
		printf("Failed to init mixer: %s\n", Mix_GetError());
	}
}

void mixer_quit() {
	Mix_Quit();
	Mix_CloseAudio();
}
