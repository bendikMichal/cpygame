
# ifndef _TYPE_H
# define _TYPE_H

# include "window.h"
# include "surface.h"
# include "rect.h"

# define TYPE_CPG_WINDOW  0
# define TYPE_CPG_SURFACE 1
# define TYPE_CPG_RECT 2
# define TYPE_CPG_CIRCLE 3
# define TYPE_CPG_SOUND 4
# define TYPE_CPG_MUSIC 5

typedef struct {
    int type;
} CPG_Obj;

# define ToCPG_Obj(x) ((CPG_Obj *)&x)

// these require a pointer
# define ToCPG_Window(x) ((CPG_Window *)x)
# define ToCPG_Surface(x) ((CPG_Surface *)x)
# define ToCPG_Rect(x) ((CPG_Rect *)x)
# define ToCPG_Circle(x) ((CPG_Circle *)x)
# define ToCPG_Sound(x) ((CPG_Sound *)x)
# define ToCPG_Mixer(x) ((CPG_Mixer *)x)

# endif
