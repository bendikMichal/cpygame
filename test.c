# include <stdio.h>

# include <stdbool.h>
# include <math.h>

# include <cpygame.h>
/* # include "cpygame.h" */

int SDL_main(int argc, char *argv[]) {
/* int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) { */
	cpg.init();

	// others
	int red[3] = {255, 0, 0};
	SDL_Color white = {255, 255, 255};
	int corner[2] = {0, 0};

	// window & surface
	int size[2] = {640, 420};
	Window window = cpg.display.set_mode(size, 0);
	CPG_Surface surf = cpg.Surface(size);

	cpg.display.set_caption("Test captions");

	// loading images
	SDL_Texture *image = cpg.image.load("mountains_1.png");

	// loading fonts
	cpg.font.SysFont("minecraft_font.ttf", 12);
	SDL_Texture *text = cpg.font.render("hello world", false, white);

	const Uint8 *keys = cpg.key.get_pressed();

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
	}

	SDL_DestroyWindow(window.window);
	// do you need to free textures or does destroy renderer do it for you ?
	SDL_DestroyTexture(image);
	SDL_DestroyTexture(text);
	SDL_DestroyTexture(surf.surface);

	cpg.quit();
	return 0;
}
