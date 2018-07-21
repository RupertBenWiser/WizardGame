#pragma once
#include "gl.h"

class Image
{
private:
	GLuint _tex;
public:
	Image(const char* texture);

	void bind();

	void unbind();
};

