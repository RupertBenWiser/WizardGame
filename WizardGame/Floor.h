#pragma once
#include "Prop.h"
#include "Billboard.h"

class Floor: public Prop
{
private:
	Billboard _billboard;

public:
	Floor(const char* texture, float x, float z, float w, float h);

	void start() {}
	void update() {}
	void render();
};

