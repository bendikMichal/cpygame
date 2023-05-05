
# ifndef _CIRCLE_H
# define _CIRCLE_H

typedef struct {
	int type;

	float x, y;
	float r;

} CPG_Circle;

CPG_Circle circle_Circle(float x, float y, float r);

# endif
