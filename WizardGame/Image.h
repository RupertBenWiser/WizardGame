#pragma once
#include "gl.h"

class Image
{
private:
	GLuint _tex;
public:
	Image(char* texture);

	void bind();

	void unbind();
};

