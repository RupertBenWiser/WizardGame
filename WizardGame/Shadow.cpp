#include "Shadow.h"

extern FrameBuffer* shadowFramebuffer;
extern Prop* focusedProp;

Shadow::Shadow()
{
	_width = 5.0f;
	_height = 5.0f;
	_y = -0.9f;
}

void Shadow::start() {

}

void Shadow::update() {

}

void Shadow::render() {
	glPushMatrix();
	glTranslatef(focusedProp->getX(), 0.0f, focusedProp->getZ());
	shadowFramebuffer->bindTexture();
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-_width, _y, -_height);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(_width, _y, -_height);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(_width, _y, _height);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-_width, _y, _height);
	glEnd();
	shadowFramebuffer->unbindTexture();
	glPopMatrix();
}
