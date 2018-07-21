#include "AnimationController.h"

AnimationController::AnimationController(int frames, int animations, std::vector<int>* maxFrames) {
	_frames = frames;
	_animations = animations;
	_maxFrames = maxFrames;
}

void AnimationController::setAnimation(int animation) {
	_currentFrame = 0.0f;
	_animation = animation;
}

void AnimationController::setAnimationSpeed(float speed) {
	_speed = speed;
}

void AnimationController::play() {
	_currentFrame += _speed;
	int maxFrame = (*_maxFrames)[_animation];
	if (_currentFrame > maxFrame) {
		_currentFrame = 0.0f;
	}
}

int AnimationController::getCurrentFrame() {
	return (int) _currentFrame;
}

int AnimationController::getFrames() {
	return _frames;
}

int AnimationController::getAnimation() {
	return _animation;
}

int AnimationController::getAnimations() {
	return _animations;
}

AnimationController::~AnimationController() {
	delete _maxFrames;
}

