#pragma once
#include "Model.h"
#include "Image.h"

class Billboard
{
private:
	float _r;
	float _g;
	float _b;
	Model _model = Model(std::vector<float> {
		-1.0f, 1.0f, -10.0f,
		-1.0f,  -1.0f, -10.0f,
		 1.0f,  -1.0f, -10.0f,
		 1.0f, 1.0f, -10.0f
	}, std::vector<float> {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	});
	Image _image;
	GLuint _tex;
public:
	Billboard(float, float, float);

	void render(void);
};

