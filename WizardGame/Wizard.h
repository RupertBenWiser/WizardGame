#pragma once
#include <vector>
#include "Prop.h"
#include "Billboard.h"
#include "AnimationController.h"

class Wizard: public Prop
{
private:
	float _x, _y, _z;
	float _vX, _vZ;
	Billboard _billboard;
	AnimationController _animationController;

public:
	Wizard(float, float, float);

	void start();
	void update();
	void render();
};

