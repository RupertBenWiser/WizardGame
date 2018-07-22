#include "Wizard.h"

Wizard::Wizard(float x, float y, float z) :
	KinematicProp(0.02f, 0.5f, x, y, z),
	_billboard("resources/images/wizard.png", 0, 0, 0),
	_animationController(4, 4, new std::vector<int> {
		0, 4, 0, 0
	}) {
	_animationController.setBillboard(&_billboard);
	_animationController.setAnimationSpeed(0.2f);
	_animationController.setAnimation(0);
}

void Wizard::start() {
}

void Wizard::update() {
	KinematicProp::update();

	if (pressed[GLFW_KEY_LEFT] && _vX > -_maxSpeed) {
		_vX -= _speed;
	}
	if (pressed[GLFW_KEY_RIGHT] && _vX < _maxSpeed) {
		_vX += _speed;
	}
	if (pressed[GLFW_KEY_UP] && _vZ > -_maxSpeed) {
		_vZ -= _speed;
	}
	if (pressed[GLFW_KEY_DOWN] && _vZ < _maxSpeed) {
		_vZ += _speed;
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
}

void Wizard::render() {
	glPushMatrix();
	glTranslatef(_x, _y, _z);
	_billboard.render();
	glPopMatrix();
}

float Wizard::getX() {
	return _x;
}

float Wizard::getZ() {
	return _z;
}