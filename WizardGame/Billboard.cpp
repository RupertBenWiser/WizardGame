#include "Billboard.h"

Billboard::Billboard(const char* texture, float x, float y, float z) : _image(texture)
{
	_x = x;
	_y = y;
	_z = z;
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

void Billboard::render(void)
{
	_image.bind();
	_model.render(_x, _y, _z);
	_image.unbind();
}
