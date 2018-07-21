#include "PuzzleOne.h"

void PuzzleOne::start() {
	//this->props.push_back(new StaticProp("test.png", 0, 0, -10));
	this->props.push_back(new Wizard(0, 0, -5));
}

void PuzzleOne::update()  {
	for (int i = 0; i < this->props.size(); i++) {
		this->props[i]->update();
	}
}

void PuzzleOne::render() {
	for (int i = 0; i < this->props.size(); i++) {
		this->props[i]->render();
	}
}