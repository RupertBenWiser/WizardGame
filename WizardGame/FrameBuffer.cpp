#include "FrameBuffer.h"


FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &_framebuffer);

	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 800, 600, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texture, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::bind() {
	glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);
}

void FrameBuffer::unbind() {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBuffer::bindTexture() {
	glBindTexture(GL_TEXTURE_2D, _texture);
}

void FrameBuffer::unbindTexture() {
	glBindTexture(GL_TEXTURE_2D, 0);
}