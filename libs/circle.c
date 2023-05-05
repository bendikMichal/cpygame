
# include "../cpygame.h"

CPG_Circle circle_Circle(float x, float y, float r) {
	CPG_Circle new_circle = {
		.type = TYPE_CPG_CIRCLE,

		.x = x,
		.y = y,
		.r = r
	};

	return new_circle;
}

