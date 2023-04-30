
# ifndef _TYPE_H
# define _TYPE_H

# include "window.h"
# include "surface.h"
# include "rect.h"

# define TYPE_CPG_WINDOW  0
# define TYPE_CPG_SURFACE 1
# define TYPE_CPG_RECT 2

typedef struct {
    int type;
} CPG_Obj;

# define ToCPG_Obj(x) ((CPG_Obj *)&x)

// these require a pointer
# define ToCPG_Window(x) ((CPG_Window *)x)
# define ToCPG_Surface(x) ((CPG_Surface *)x)
# define ToCPG_Rect(x) ((CPG_Rect *)x)

# endif
