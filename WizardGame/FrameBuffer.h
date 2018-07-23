#pragma once
#include "gl.h"

class FrameBuffer
{
private:
	GLuint _framebuffer;
	GLuint _texture;
public:
	FrameBuffer();
	void bind();
	void unbind();

	void bindTexture();
	void unbindTexture();
};

