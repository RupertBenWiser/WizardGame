#include "PuzzleOne.h"

extern Prop* focusedProp;

void PuzzleOne::start() {
	this->props.push_back(new Floor("resources/images/floor.png", 0, 0, 20.0f, 20.0f));
	Wizard* wizard = new Wizard(0, 0, -5);
	this->props.push_back(wizard);
	focusedProp = wizard;
}

void PuzzleOne::update()  {
	for (int i = 0; i < this->props.size(); i++) {
		this->props[i]->update();
	}
}