#pragma once
#include "gl.h"
#include <vector>

class Model
{
private:
	std::vector<float> vertices;

public:
	Model(std::vector<float> v): vertices(v) {}

	void render(void);
};

