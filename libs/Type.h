
# ifndef _TYPE_H
# define _TYPE_H


# define TYPE_CPG_WINDOW  0
# define TYPE_CPG_SURFACE 1
# define TYPE_CPG_RECT 2
# define TYPE_CPG_CIRCLE 3

typedef struct {
    int type;
} CPG_Obj;

# define ToCPG_Obj(x) ((CPG_Obj *)&x)

# endif
