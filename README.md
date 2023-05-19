
# Cpygame
- A pygame-like c framework
- you can read more about [pygame](https://www.pygame.org/news), (! This is not an official port of pygame for c !)

Hopefuly me or someone makes documentation, though the usage should not be that much different from pygame

example code can be found in `test.c`, though it will periodically be changed based on the stuff I'm working on.

There are also build scripts (for windows only, arch script has the same names but ends with .sh) `build.bat` to build and run `test.c`.
There is also `lib.bat` used to build the library, which will be then located in `./buildlib/`.

## Basic code exaple 

```c
# include <stdio.h>

# include <cpygame.h>

# define FPS 60


int CPG_main (int argc, char *argv[]) {
	cpg.init();

	int BLACK[] = {0, 0, 0};

	int size[] = {640, 480};
	CPG_Window Window = cpg.display.set_mode(size, 0);
	cpg.display.set_caption("Some name");

	// loading music
	CPG_Music music = cpg.mixer.music.load("someMusic.wav");
	music.play(music, -1);

	bool main = true;
	while (main) {
		// handling events
		while( cpg.event.get() ){
			if( cpg.event.event.type == SDL_QUIT ){
					main = false;
			}

			bool *mouse_buttons = cpg.mouse.get_pressed();
			if (mouse_buttons[1]) printf("Hello world\n");
		}

		Window.fill(BLACK);

		cpg.display.update();
		cpg.clock.tick(FPS);

	}
	
    // free created music
	music.Free(music);
	cpg.quit();
	return 0;
}

```

### Disclaimer: 
* This is *NOT* official port of pygame for c!
* This library/framework depends on *SDL2* to work properly.
