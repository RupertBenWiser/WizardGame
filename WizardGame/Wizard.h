#pragma once
#include <vector>
#include "KinematicProp.h"
#include "Billboard.h"
#include "AnimationController.h"

class Wizard: public KinematicProp
{
private:
	Billboard _billboard;
	AnimationController _animationController;

public:
	Wizard(float, float, float);

	void start();
	void update();
	void render();
	void renderShadow();
	float getX();
	float getZ();
};

