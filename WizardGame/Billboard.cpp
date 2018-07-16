#include "Billboard.h"

Billboard::Billboard(float r, float g, float b)
{
	_r = r;
	_g = g;
	_b = b;

	glGenTextures(1, &_tex);
	glBindTexture(GL_TEXTURE_2D, _tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _image.getWidth(), _image.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, _image.getImage());

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Billboard::render(void)
{
	glBindTexture(GL_TEXTURE_2D, _tex);
	_model.render();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBindTexture(GL_TEXTURE_2D, 0);
}
