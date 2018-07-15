#pragma once
#include "Model.h"

class Box
{
private:
	float _r;
	float _g;
	float _b;
	Model _model = Model(std::vector<float> {
		-1.0f, -1.0f, -10.0f,
		-1.0f,  0.0f, -10.0f,
		 0.0f, -1.0f, -10.0f
	});
public:
	Box(float, float, float);

	void render(void);
};

