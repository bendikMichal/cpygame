
# ifndef _MIXER_H
# define _MIXER_H

# include <SDL2/SDL_mixer.h>

typedef struct {

} Mixer;

void mixer_init(int frequency, Uint16 format, int channels, int chunksize);
void mixer_quit();

# endif
