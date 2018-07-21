#pragma once
#include "Prop.h"
#include "Billboard.h"

class StaticProp: public Prop
{
private:
	Billboard _billboard;

public:
	StaticProp(char*, float, float, float);

	void start();

	void update();

	void render();
};

