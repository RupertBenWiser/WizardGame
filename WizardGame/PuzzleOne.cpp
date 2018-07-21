#include "PuzzleOne.h"
#include <iostream>

void PuzzleOne::start() {
	std::string filename = "test.png";
	StaticProp* test = new StaticProp(&filename[0], 0, 0, -10);

	this->props.push_back(test);
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