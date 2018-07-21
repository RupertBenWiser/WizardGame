#include "StaticProp.h"

StaticProp::StaticProp(char* texture, float x, float y, float z): _billboard(texture, x, y, z) {}

void StaticProp::start() {

}

void StaticProp::update() {

}

void StaticProp::render() {
	_billboard.render();
}