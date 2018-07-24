#pragma once
#include <vector>
#include "Prop.h"
#include "StateImpl.h"

class Scene {
protected:
	std::vector<Prop*> props;
public:
	virtual void start() = 0;
	virtual void update() = 0;
	virtual void render() {
		for (int i = 0; i < this->props.size(); i++) {
			this->props[i]->render();
		}
	}
	virtual void renderShadow() {
		for (int i = 0; i < this->props.size(); i++) {
			this->props[i]->renderShadow();
		}
	}
};