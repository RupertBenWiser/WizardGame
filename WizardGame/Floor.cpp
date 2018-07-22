#include "Floor.h"



Floor::Floor(const char* texture, float x, float z, float w, float h): _billboard(texture, x, -1.0f, z, w, h)
{
	_billboard.setRotation(90.0f);
}

void Floor::render() {
	_billboard.render();
}