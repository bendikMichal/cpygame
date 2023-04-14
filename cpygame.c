
// to see clangd output -> :CocCommand workspace.showOutput

# include <stdio.h>
# include <stdbool.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_keycode.h>

# include "cpygame.h"
// gcc cpygame.c -o cpygame -ID:\Home\Programming\C\SDL2\include -LD:\Home\Programming\C\SDL2\lib -lSDL2 -lSDL2_image


cpygame cpg = {
	.mouse.get_pos = &mouse_get_pos,

	.init = &init,
	.quit = &quit,

	.display.set_mode = &display_set_mode,
	.display.set_caption = &display_set_caption,
	.display.update = &display_update,

	.image.load = &image_load,

	.font.SysFont = &font_SysFont,
	.font.render = &font_render,

	.Surface = &surface_Surface,
	.Rect = &rect_Rect,

	.key.get_pressed = &key_get_pressed,

	// keys
	.K_0 = SDL_SCANCODE_0,
	.K_1 = SDL_SCANCODE_1,
	.K_2 = SDL_SCANCODE_2,
	.K_3 = SDL_SCANCODE_3,
	.K_4 = SDL_SCANCODE_4,
	.K_5 = SDL_SCANCODE_5,
	.K_6 = SDL_SCANCODE_6,
	.K_7 = SDL_SCANCODE_7,
	.K_8 = SDL_SCANCODE_8,
	.K_9 = SDL_SCANCODE_9,

	.K_a = SDL_SCANCODE_A,
	.K_b = SDL_SCANCODE_B,
	.K_c = SDL_SCANCODE_C,
	.K_d = SDL_SCANCODE_D,
	.K_e = SDL_SCANCODE_E,
	.K_f = SDL_SCANCODE_F,
	.K_g = SDL_SCANCODE_G,
	.K_h = SDL_SCANCODE_H,
	.K_i = SDL_SCANCODE_I,
	.K_j = SDL_SCANCODE_J,
	.K_k = SDL_SCANCODE_K,
	.K_l = SDL_SCANCODE_L,
	.K_m = SDL_SCANCODE_M,
	.K_n = SDL_SCANCODE_N,
	.K_o = SDL_SCANCODE_O,
	.K_p = SDL_SCANCODE_P,
	.K_q = SDL_SCANCODE_Q,
	.K_r = SDL_SCANCODE_R,
	.K_s = SDL_SCANCODE_S,
	.K_t = SDL_SCANCODE_T,
	.K_u = SDL_SCANCODE_U,
	.K_v = SDL_SCANCODE_V,
	.K_w = SDL_SCANCODE_W,
	.K_x = SDL_SCANCODE_X,
	.K_y = SDL_SCANCODE_Y,
	.K_z = SDL_SCANCODE_Z,

	.K_F1 = SDL_SCANCODE_F1,
	.K_F2 = SDL_SCANCODE_F2,
	.K_F3 = SDL_SCANCODE_F3,
	.K_F4 = SDL_SCANCODE_F4,
	.K_F5 = SDL_SCANCODE_F5,
	.K_F6 = SDL_SCANCODE_F6,
	.K_F7 = SDL_SCANCODE_F7,
	.K_F8 = SDL_SCANCODE_F8,
	.K_F9 = SDL_SCANCODE_F9,
	.K_F10 = SDL_SCANCODE_F10,
	.K_F11 = SDL_SCANCODE_F11,
	.K_F12 = SDL_SCANCODE_F12,

	.K_UP = SDL_SCANCODE_UP,
	.K_DOWN = SDL_SCANCODE_DOWN,
	.K_LEFT = SDL_SCANCODE_LEFT,
	.K_RIGHT = SDL_SCANCODE_RIGHT,

	.K_SPACE = SDL_SCANCODE_SPACE,

	//
};

void init() {
	printf("\n Welcome to cpygame a pygame inspired library for c\n");
	printf("\tVisit www.pygame.org for more info about pygame\n");

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
}


