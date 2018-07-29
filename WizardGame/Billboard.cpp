#include "Billboard.h"

Billboard::Billboard(const char* texture, float x, float y, float z, float w, float h) : _image(texture), _model(std::vector<float> {
	-w, h, 0.0f,
	-w, -h, 0.0f,
	w, -h, 0.0f,
	w, h, 0.0f
}, &texCoords)
{
	_x = x;
	_y = y;
	_z = z;
	_r = -45.0f;
}

Billboard::Billboard(const char* texture, float x, float y, float z) : Billboard(texture, x, y, z, 1.0f, 1.0f)
{
}

void Billboard::setFrame(int frame, int frames) {
	texCoords[0] = frame / (float)frames;
	texCoords[1] = _animation / (float) _animations;
	texCoords[2] = frame / (float)frames;
	texCoords[3] = (_animation + 1.0f) / (float)_animations;
	texCoords[4] = (frame + 1.0f) / (float)frames;
	texCoords[5] = (_animation + 1.0f) / (float)_animations;
	texCoords[6] = (frame + 1.0f) / (float)frames;
	texCoords[7] = _animation / (float)_animations;
	_frames = frames;
}

void Billboard::setAnimation(int animation, int animations) {
	_animation = animation;
	_animations = animations;
	this->setFrame(0, _frames);
}

void Billboard::render(void) {
	glPushMatrix();
	glTranslatef(_x, _y, _z);
	glRotatef(_r, 1.0f, 0.0f, 0.0f);
	_image.bind();
	_model.render(0.0f, 0.0f, 0.0f);
	_image.unbind();
	glPopMatrix();
}

void Billboard::renderShadow(void) {
	glColor3f(0.0f, 0.0f, 0.0f);
	this->render();
	glColor3f(1.0f, 1.0f, 1.0f);
}

void Billboard::setRotation(float r) {
	_r = r;
}