#pragma once
#include "Model.h"
#include "Image.h"

class Billboard
{
private:
	float _x;
	float _y;
	float _z;
	float _r;

	std::vector<float> texCoords{
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};

	Model _model;

	Image _image;

	int _animation = 0;
	int _animations = 1;
	int _frames;

public:
	Billboard(const char*, float, float, float);

	Billboard(const char*, float, float, float, float, float);

	void setFrame(int frame, int frames);

	void setAnimation(int animation, int animations);

	void render(void);

	void renderShadow(void);

	void setRotation(float r);
};

