#pragma once
#include <vector>
#include "Prop.h"
#include "Scene.h"
#include "StaticProp.h"

class PuzzleOne: public Scene
{
private:
	std::vector<Prop*> props;

public:
	void start();
	void update();
	void render();
};

