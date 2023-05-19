
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>

# include <cpygame.h>
# include <SDL2/SDL_mixer.h>
/* # include "cpygame.h" */


int CPG_main(int argc, char *argv[]) {
/* int SDL_main(int argc, char *argv[]) { */
	cpg.init();
	cpg.mixer.init(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// others
	int red[3] = {255, 0, 0};
	int blue[3] = {0, 0, 255};
	int yellow[3] = {255, 255, 0};
	SDL_Color white = {255, 255, 255};
	int corner[2] = {0, 0};

	// window & surface
	int size[2] = {640, 420};
	CPG_Window window = cpg.display.set_mode(size, 0);
	CPG_Surface surf = cpg.Surface(size);

	char Window_title[64] = "";
	char Window_name[] = "Test captions";
	char fps_string[16] = "0";
	cpg.display.set_caption(Window_title);

	CPG_Rect testrect = cpg.Rect(0, 0, 100, 200);
	CPG_Rect testrect2 = cpg.Rect(100, 0, 100, 200);

	CPG_Circle testcircle = cpg.Circle(50, 150, 40);

	// loading images
	SDL_Texture *image = cpg.image.load("mountains_1.png");
	SDL_Texture *image_rot = cpg.transform.rotate(image, 45);

	// loading fonts
	cpg.font.SysFont("minecraft_font.ttf", 12);
	SDL_Texture *text = cpg.font.render("hello world", false, white);

	// loading music
	CPG_Music music = cpg.mixer.music.load("main_theme.wav");

	// loading sounds
	CPG_Sound sound = cpg.mixer.Sound("main_theme.wav", 0);
	sound.play(sound, -1);
	sound.stop(sound);

	const Uint8 *keys = cpg.key.get_pressed();

	const int fps = 60;

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

		if (keys[cpg.K_a]) {
			printf("works uwu\n");
		}
	
		// drawing 
		window.fill(red);

		cpg.draw.rect(ToCPG_Obj(surf), yellow, testrect);
		cpg.draw.rect(ToCPG_Obj(window), blue, testrect2);
		cpg.draw.circle(ToCPG_Obj(window), blue, testcircle, 0);
		cpg.draw.circle(ToCPG_Obj(window), yellow, testcircle, 1);

		/* window.blit(surf.surface, corner); */
		window.blit(text, corner);
		/* window.blit_rot(image, corner, 90); */
		window.blit(image_rot, corner);

		cpg.display.update();
		cpg.clock.tick(fps);

		/* itoa(cpg.clock.get_fps(), fps_string, 10); */
		sprintf(Window_title, "%s - %f", Window_name, cpg.clock.get_fps());
		cpg.display.set_caption(Window_title);
	}

	SDL_DestroyWindow(window.window);
	// do you need to free textures or does destroy renderer do it for you ?
	SDL_DestroyTexture(image);
	SDL_DestroyTexture(text);
	/* SDL_DestroyTexture(surf.surface); */

	music.Free(music);
	sound.Free(sound);
	cpg.quit();
	return 0;
}
