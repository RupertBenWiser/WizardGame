#include "KinematicProp.h"

KinematicProp::KinematicProp(float speed, float maxSpeed, float x, float y, float z):
	_speed(speed), _maxSpeed(maxSpeed), _x(x), _y(y), _z(z)
{
	_vX = 0;
	_vZ = 0;
}

void KinematicProp::update() {
	if (_vX > 0) {
		_vX -= _speed / 2.0f;
	}
	if (_vX < 0) {
		_vX += _speed / 2.0f;
	}
	if (_vZ > 0) {
		_vZ -= _speed / 2.0f;
	}
	if (_vZ < 0) {
		_vZ += _speed / 2.0f;
	}
	if (_vX < _speed / 2.0f && _vX > -_speed / 2.0f) {
		_vX = 0.0f;
	}
	if (_vZ < _speed / 2.0f && _vZ > -_speed / 2.0f) {
		_vZ = 0.0f;
	}
	_x += _vX;
	_z += _vZ;
}
