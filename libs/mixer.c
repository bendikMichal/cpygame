
# include <stdio.h>

# include <SDL2/SDL_mixer.h>

# include "../cpygame.h"

void mixer_init(int frequency, Uint16 format, int channels, int chunksize) {
	if(Mix_OpenAudio(frequency, format, channels, chunksize) < 0) {
		printf("Failed to init mixer: %s\n", Mix_GetError());
	}

}


// > SOUND <

CPG_Sound mixer_Sound(char *soundPath) {
	CPG_Sound newSound = {
		.type = TYPE_CPG_SOUND,
		.sound = Mix_LoadWAV(soundPath),

		.play = &mixer_Sound_play,
		.Free = &mixer_Sound_Free,
	};
	return newSound;
}

void mixer_Sound_play(CPG_Sound sound) {
	Mix_PlayChannel(-1, sound.sound, 0);
}

void mixer_Sound_Free(Mix_Chunk *sound) {
	Mix_FreeChunk(sound);
}


// > MUSIC <

CPG_Music mixer_music_load(char *musicPath) {
	CPG_Music newMusic = {
		.type = TYPE_CPG_MUSIC,
		.music = Mix_LoadMUS(musicPath),

		.play = &mixer_music_play,
		.Free = &mixer_music_Free,
	};

	return newMusic;
}

void mixer_music_play(CPG_Music music, int loops) {
	Mix_PlayMusic(music.music, loops);
}

void mixer_music_Free(Mix_Music *music) {
	Mix_FreeMusic(music);
}


void mixer_quit() {
	Mix_Quit();
	Mix_CloseAudio();
}
