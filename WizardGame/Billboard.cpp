#include "Billboard.h"

Billboard::Billboard(char* texture, float x, float y, float z) : _image(texture)
{
	_x = x;
	_y = y;
	_z = z;
}

void Billboard::render(void)
{
	_image.bind();
	_model.render(_x, _y, _z);
	_image.unbind();
}
