#include "Wizard.h"

Wizard::Wizard(float x, float y, float z) :
	_x(x), _y(y), _z(z),
	_billboard("resources/images/wizard.png", 0, 0, 0),
	_animationController(4, 4, new std::vector<int> {
		0, 4, 0, 0
	}) {
	_animationController.setBillboard(&_billboard);
	_animationController.setAnimationSpeed(0.2f);
	_animationController.setAnimation(0);
}

void Wizard::start() {
	_vX = 0;
	_vZ = 0;
}

void Wizard::update() {
	const float MAX_SPEED = 0.5f;
	const float SPEED = 0.02f;

	if (pressed[GLFW_KEY_LEFT] && _vX > -MAX_SPEED) {
		_vX -= SPEED;
	}
	if (pressed[GLFW_KEY_RIGHT] && _vX < MAX_SPEED) {
		_vX += SPEED;
	}
	if (pressed[GLFW_KEY_UP] && _vZ > -MAX_SPEED) {
		_vZ -= SPEED;
	}
	if (pressed[GLFW_KEY_DOWN] && _vZ < MAX_SPEED) {
		_vZ += SPEED;
	}

	bool noKeyPress = !pressed[GLFW_KEY_LEFT] &&
		!pressed[GLFW_KEY_RIGHT] &&
		!pressed[GLFW_KEY_UP] &&
		!pressed[GLFW_KEY_DOWN];

	if (noKeyPress && _animationController.getAnimation() != 0) {
			_animationController.setAnimation(0);
	}
	else if (!noKeyPress && _animationController.getAnimation() != 1) {
		_animationController.setAnimation(1);
	}

	_animationController.play();

	if (_vX > 0) {
		_vX -= SPEED / 2.0f;
	}
	if (_vX < 0) {
		_vX += SPEED / 2.0f;
	}
	if (_vZ > 0) {
		_vZ -= SPEED / 2.0f;
	}
	if (_vZ < 0) {
		_vZ += SPEED / 2.0f;
	}
	if (_vX < SPEED / 2.0f && _vX > -SPEED / 2.0f) {
		_vX = 0.0f;
	}
	if (_vZ < SPEED / 2.0f && _vZ > -SPEED / 2.0f) {
		_vZ = 0.0f;
	}
	_x += _vX;
	_z += _vZ;
}

void Wizard::render() {
	glPushMatrix();
	glTranslatef(_x, _y, _z);
	_billboard.render();
	glPopMatrix();
}