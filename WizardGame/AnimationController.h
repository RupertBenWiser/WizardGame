#pragma once
#include <vector>
#include "Billboard.h"

class AnimationController
{
private:
	std::vector<int>* _maxFrames;
	int _frames;
	int _animations;
	int _animation;
	float _speed;
	float _currentFrame;
	Billboard* _billboard = nullptr;

public:
	AnimationController(int frames, int animations, std::vector<int>* maxFrames);
	~AnimationController();

	void setAnimation(int animation);
	void setAnimationSpeed(float speed);
	void play();

	void setBillboard(Billboard* billboard);

	int getFrames();
	int getCurrentFrame();
	int getAnimation();
	int getAnimations();
};

