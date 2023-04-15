
// to see clangd output -> :CocCommand workspace.showOutput

# include <stdio.h>
# include <stdbool.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_keycode.h>
#include <stdlib.h>

# include "cpygame.h"

cpygame cpg_only_init = {
	.init = &init
};
cpygame *cpgP = &cpg_only_init;

void init() {
	printf("\n Welcome to cpygame a pygame inspired library for c\n");
	printf("\tVisit www.pygame.org for more info about pygame\n");

	cpgP = (cpygame *) calloc(1, sizeof(cpygame));

	cpg.mouse.get_pos = &mouse_get_pos,

	cpg.init = &init,
	cpg.quit = &quit,

	cpg.display.set_mode = &display_set_mode,
	cpg.display.set_caption = &display_set_caption,
	cpg.display.update = &display_update,

	cpg.image.load = &image_load,

	cpg.font.SysFont = &font_SysFont,
	cpg.font.render = &font_render,

	cpg.Surface = &surface_Surface,
	cpg.Rect = &rect_Rect,

	cpg.key.get_pressed = &key_get_pressed,

	// keys
	cpg.K_0 = SDL_SCANCODE_0,
	cpg.K_1 = SDL_SCANCODE_1,
	cpg.K_2 = SDL_SCANCODE_2,
	cpg.K_3 = SDL_SCANCODE_3,
	cpg.K_4 = SDL_SCANCODE_4,
	cpg.K_5 = SDL_SCANCODE_5,
	cpg.K_6 = SDL_SCANCODE_6,
	cpg.K_7 = SDL_SCANCODE_7,
	cpg.K_8 = SDL_SCANCODE_8,
	cpg.K_9 = SDL_SCANCODE_9,

	cpg.K_a = SDL_SCANCODE_A,
	cpg.K_b = SDL_SCANCODE_B,
	cpg.K_c = SDL_SCANCODE_C,
	cpg.K_d = SDL_SCANCODE_D,
	cpg.K_e = SDL_SCANCODE_E,
	cpg.K_f = SDL_SCANCODE_F,
	cpg.K_g = SDL_SCANCODE_G,
	cpg.K_h = SDL_SCANCODE_H,
	cpg.K_i = SDL_SCANCODE_I,
	cpg.K_j = SDL_SCANCODE_J,
	cpg.K_k = SDL_SCANCODE_K,
	cpg.K_l = SDL_SCANCODE_L,
	cpg.K_m = SDL_SCANCODE_M,
	cpg.K_n = SDL_SCANCODE_N,
	cpg.K_o = SDL_SCANCODE_O,
	cpg.K_p = SDL_SCANCODE_P,
	cpg.K_q = SDL_SCANCODE_Q,
	cpg.K_r = SDL_SCANCODE_R,
	cpg.K_s = SDL_SCANCODE_S,
	cpg.K_t = SDL_SCANCODE_T,
	cpg.K_u = SDL_SCANCODE_U,
	cpg.K_v = SDL_SCANCODE_V,
	cpg.K_w = SDL_SCANCODE_W,
	cpg.K_x = SDL_SCANCODE_X,
	cpg.K_y = SDL_SCANCODE_Y,
	cpg.K_z = SDL_SCANCODE_Z,

	cpg.K_F1 = SDL_SCANCODE_F1,
	cpg.K_F2 = SDL_SCANCODE_F2,
	cpg.K_F3 = SDL_SCANCODE_F3,
	cpg.K_F4 = SDL_SCANCODE_F4,
	cpg.K_F5 = SDL_SCANCODE_F5,
	cpg.K_F6 = SDL_SCANCODE_F6,
	cpg.K_F7 = SDL_SCANCODE_F7,
	cpg.K_F8 = SDL_SCANCODE_F8,
	cpg.K_F9 = SDL_SCANCODE_F9,
	cpg.K_F10 = SDL_SCANCODE_F10,
	cpg.K_F11 = SDL_SCANCODE_F11,
	cpg.K_F12 = SDL_SCANCODE_F12,

	cpg.K_UP = SDL_SCANCODE_UP,
	cpg.K_DOWN = SDL_SCANCODE_DOWN,
	cpg.K_LEFT = SDL_SCANCODE_LEFT,
	cpg.K_RIGHT = SDL_SCANCODE_RIGHT,

	cpg.K_SPACE = SDL_SCANCODE_SPACE,


	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG); 
	TTF_Init();

	SDL_Event event;

	cpg.event = event;
};


void quit() {
	SDL_DestroyRenderer(cpg.window.renderer);
	SDL_DestroyWindow(cpg.window.window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
	free(cpgP);
}


