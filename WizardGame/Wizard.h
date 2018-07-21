#pragma once
#include "Prop.h"
#include "Billboard.h"

class Wizard: public Prop
{
private:
	float _x, _y, _z;
	float _vX, _vZ;
	Billboard _billboard;

public:
	Wizard(float, float, float);

	void start();
	void update();
	void render();
};

