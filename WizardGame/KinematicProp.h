#pragma once
#include "Prop.h"

class KinematicProp: public Prop
{
protected:
	float _x, _y, _z;
	float _vX, _vZ;
	float _speed;
	float _maxSpeed;

public:
	KinematicProp(float speed, float maxSpeed, float x, float y, float z);

	virtual void start() = 0;
	void update();
	virtual void render() = 0;
};

