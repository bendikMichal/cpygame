
# include <stdio.h>

# include <SDL2/SDL_mixer.h>

# include "../cpygame.h"

void mixer_init(int frequency, Uint16 format, int channels, int chunksize) {
	if(Mix_OpenAudio(frequency, format, channels, chunksize) < 0) {
		printf("Failed to init mixer: %s\n", Mix_GetError());
	}

}


// > SOUND <

CPG_Sound mixer_Sound(char *soundPath, int channelID) {
	CPG_Sound newSound = {
		.type = TYPE_CPG_SOUND,
		.sound = Mix_LoadWAV(soundPath),
		.channelID = channelID,

		.play = &mixer_sound_play,
		.stop = &mixer_sound_stop,
		.Free = &mixer_sound_Free,
	};
	return newSound;
}

void mixer_sound_play(CPG_Sound sound, int loops) {
	Mix_PlayChannel(sound.channelID, sound.sound, loops);
}

void mixer_sound_stop(CPG_Sound sound) {
	Mix_HaltChannel(sound.channelID);
}

void mixer_sound_Free(CPG_Sound sound) {
	Mix_FreeChunk(sound.sound);
}


// > MUSIC <

CPG_Music mixer_music_load(char *musicPath) {
	CPG_Music newMusic = {
		.type = TYPE_CPG_MUSIC,
		.music = Mix_LoadMUS(musicPath),

		.play = &mixer_music_play,
		.stop = &mixer_music_stop,
		.Free = &mixer_music_Free,
	};

	return newMusic;
}

void mixer_music_play(CPG_Music music, int loops) {
	Mix_PlayMusic(music.music, loops);
}

void mixer_music_stop() {
	Mix_PauseMusic();
}

void mixer_music_Free(CPG_Music music) {
	Mix_FreeMusic(music.music);
}


void mixer_quit() {
	Mix_Quit();
	Mix_CloseAudio();
}
