#pragma once
#include "StateImpl.h"

class Scene {
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};