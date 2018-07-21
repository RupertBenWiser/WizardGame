#include "AnimationController.h"

AnimationController::AnimationController(int frames, int animations, std::vector<int>* maxFrames) {
	_frames = frames;
	_animations = animations;
	_maxFrames = maxFrames;
}

void AnimationController::setAnimation(int animation) {
	_currentFrame = 0.0f;
	_animation = animation;

	if (_billboard != nullptr) {
		_billboard->setAnimation(
			this->getAnimation(),
			this->getAnimations()
		);
	}
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
	if (_billboard != nullptr) {
		_billboard->setFrame(
			this->getCurrentFrame(),
			this->getFrames()
		);
	}
}

void AnimationController::setBillboard(Billboard* billboard) {
	_billboard = billboard;
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

