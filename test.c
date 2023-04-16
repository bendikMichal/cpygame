# include <stdio.h>

# include <stdbool.h>
# include <string.h>
# include <math.h>

# include <cpygame.h>
/* # include "cpygame.h" */


int CPGmain(int argc, char *argv[]) {
/* int SDL_main(int argc, char *argv[]) { */
	cpg.init();
	/* init(); */

	// others
	int red[3] = {255, 0, 0};
	SDL_Color white = {255, 255, 255};
	int corner[2] = {0, 0};

	// window & surface
	int size[2] = {640, 420};
	Window window = cpg.display.set_mode(size, 0);
	CPG_Surface surf = cpg.Surface(size);

	char Window_title[64] = "";
	char Window_name[] = "Test captions";
	char fps_string[16] = "0";
	cpg.display.set_caption(Window_title);

	// loading images
	SDL_Texture *image = cpg.image.load("mountains_1.png");

	// loading fonts
	cpg.font.SysFont("minecraft_font.ttf", 12);
	SDL_Texture *text = cpg.font.render("hello world", false, white);

	const Uint8 *keys = cpg.key.get_pressed();

	const int fps = 60;

	bool main = true;
	while (main) {
		// handling events
		while( SDL_PollEvent( &cpg.event ) ){
			if( cpg.event.type == SDL_QUIT ){
					main = false;
			}
		}

		if (keys[cpg.K_a]) {
			printf("works uwu\n");
		}
	
		// drawing 
		window.fill(red);

		window.blit(text, corner);

		cpg.display.update();
		cpg.clock.tick(fps);

		itoa(cpg.clock.get_fps(), fps_string, 10);
		sprintf(Window_title, "%s - %s", Window_name, fps_string);
		cpg.display.set_caption(Window_title);
	}

	SDL_DestroyWindow(window.window);
	// do you need to free textures or does destroy renderer do it for you ?
	SDL_DestroyTexture(image);
	SDL_DestroyTexture(text);
	SDL_DestroyTexture(surf.surface);

	cpg.quit();
	return 0;
}
