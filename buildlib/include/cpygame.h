
# ifndef _CPYGAME_H
# define _CPYGAME_H

/*<------------ FUNCTION DEFINITIONS ------------>*/
# ifndef main
# define CPG_main(argc, argv) main(argc, argv)
# endif

# ifndef CPG_main
# define CPG_main(argc, argv) SDL_main(argc, argv)
# endif

# define dist(x, y) (sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2)))
# define arrlen(x) (int)(sizeof(x)/sizeof(x[0]))

/*<------------ CONSTANTS DEFINITIONS ------------>*/
# define MILISECOND 1000
# define DEFAULT_FPS 60
# define pi 3.14159265358

# define TOPLEFT (int[2]){0, 0}


/*
 *	How the including works:
 *		all *.h files are included in main cpygame.h file which is then included in all *.c files
 *		Kinda like inheritance in c#
 *
 */
# include "libs/Type.h"
# include "libs/window.h"
# include "libs/display.h"
# include "libs/mouse.h"
# include "libs/image.h"
# include "libs/surface.h"
# include "libs/font.h"
# include "libs/rect.h"
# include "libs/circle.h"
# include "libs/key.h"
# include "libs/clock.h"
# include "libs/draw.h"
# include "libs/transform.h"

typedef struct cpygame {
	void (*init)();
	void (*quit)();

	SDL_Event event;

	CPG_Window window;
	Mouse mouse;
	Display display;
	Image image;
	Font font;
	Key key;
	Clock clock;
	Draw draw;
	Transform transform;

	CPG_Surface (*Surface) (int [2]);
	CPG_Rect (*Rect) (float, float, float, float);
	CPG_Circle (*Circle) (float, float, float);

	// keys
	int K_0;
	int K_1;
	int K_2;
	int K_3;
	int K_4;
	int K_5;
	int K_6;
	int K_7;
	int K_8;
	int K_9;

	int K_a;
	int K_b;
	int K_c;
	int K_d;
	int K_e;
	int K_f;
	int K_g;
	int K_h;
	int K_i;
	int K_j;
	int K_k;
	int K_l;
	int K_m;
	int K_n;
	int K_o;
	int K_p;
	int K_q;
	int K_r;
	int K_s;
	int K_t;
	int K_u;
	int K_v;
	int K_w;
	int K_x;
	int K_y;
	int K_z;


	int K_F1;
	int K_F2;
	int K_F3;
	int K_F4;
	int K_F5;
	int K_F6;
	int K_F7;
	int K_F8;
	int K_F9;
	int K_F10;
	int K_F11;
	int K_F12;
	

	int K_UP;
	int K_DOWN;
	int K_LEFT;
	int K_RIGHT;

	int K_SPACE;
	//
} cpygame;

extern cpygame *cpgP;
# define cpg (* cpgP)

void init ();
void quit ();

# endif

