#pragma once
#include "StateImpl.h"
#include "gl.h"

class Prop {
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};