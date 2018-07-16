#pragma once
#include "gl.h"
#include <vector>

class Model
{
private:
	std::vector<float> vertices;
	std::vector<float> texCoords;

public:
	Model(std::vector<float> v, std::vector<float> t): vertices(v), texCoords(t) {}

	void render(void);
};

