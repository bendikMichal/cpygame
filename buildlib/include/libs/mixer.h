
# ifndef _MIXER_H
# define _MIXER_H

# include <SDL2/SDL_mixer.h>

typedef struct CPG_Sound {
	int type;
	Mix_Chunk *sound;
	int channelID;

	void (* play) (struct CPG_Sound, int);
	void (* stop) (struct CPG_Sound);
	void (* Free) (struct CPG_Sound);

} CPG_Sound;

typedef struct CPG_Music {
	int type;
	Mix_Music *music;

	void (* play) (struct CPG_Music, int);
	void (* stop) ();
	void (* Free) (struct CPG_Music);

} CPG_Music;

typedef struct {
	CPG_Music (* load) (char *);

} Music;

typedef struct {
	Music music;

	void (* init) (int, Uint16, int, int);
	CPG_Sound (* Sound) (char*, int);
	void (* quit) ();

} Mixer;

void mixer_init(int frequency, Uint16 format, int channels, int chunksize);
void mixer_quit();

CPG_Sound mixer_Sound(char *soundPath, int);
void mixer_sound_play(CPG_Sound sound, int loops);
void mixer_sound_stop(CPG_Sound sound);
void mixer_sound_Free(CPG_Sound sound);

CPG_Music mixer_music_load(char *musicPath);
void mixer_music_play(CPG_Music music, int loops);
void mixer_music_stop();
void mixer_music_Free(CPG_Music music);

# endif
