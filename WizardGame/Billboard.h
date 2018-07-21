#pragma once
#include "Model.h"
#include "Image.h"

class Billboard
{
private:
	float _x;
	float _y;
	float _z;

	Model _model = Model(std::vector<float> {
		-1.0f, 1.0f, 0.0f,
		-1.0f,  -1.0f, 0.0f,
		 1.0f,  -1.0f, 0.0f,
		 1.0f, 1.0f, 0.0f
	}, std::vector<float> {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	});
	Image _image;
public:
	Billboard(const char*, float, float, float);

	void render(void);
};

