#pragma once
#include "StateImpl.h"
#include "gl.h"

class Prop {
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void renderShadow() {}
	virtual float getX() {
		return 0.0f;
	}
	virtual float getZ() {
		return 0.0f;
	}
};