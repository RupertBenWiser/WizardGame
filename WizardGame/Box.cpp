#include "Box.h"

Box::Box(float r, float g, float b)
{
	_r = r;
	_g = g;
	_b = b;
}

void Box::render(void)
{
	glColor3f(_r, _g, _b);
	_model.render();
	glColor3f(1.0f, 1.0f, 1.0f);
}
