#pragma once
#include "Prop.h"
#include "StateImpl.h"
#include "FrameBuffer.h"

class Shadow: public Prop
{
private:
	float _width, _height;
	float _y;
public:
	Shadow();
	void start();
	void update();
	void render();
};

