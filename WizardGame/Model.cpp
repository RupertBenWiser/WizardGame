#include "Model.h"
#include <iostream>

void Model::render(void) {
	glBegin(GL_TRIANGLES);
	int i = 0;
	while (i < this->vertices.size()) {
		float x = this->vertices[i++];
		float y = this->vertices[i++];
		float z = this->vertices[i++];
		glVertex3f(x, y, z);
	}
	glEnd();
}