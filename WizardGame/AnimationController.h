#pragma once
#include <vector>

class AnimationController
{
private:
	std::vector<int>* _maxFrames;
	int _frames;
	int _animations;
	int _animation;
	float _speed;
	float _currentFrame;

public:
	AnimationController(int frames, int animations, std::vector<int>* maxFrames);
	~AnimationController();

	void setAnimation(int animation);
	void setAnimationSpeed(float speed);
	void play();

	int getFrames();
	int getCurrentFrame();
	int getAnimation();
	int getAnimations();
};

