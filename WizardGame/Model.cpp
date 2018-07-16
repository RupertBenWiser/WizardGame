#include "Model.h"
#include <iostream>

void Model::render(void) {
	glBegin(GL_QUADS);
	int i = 0;
	int t = 0;
	while (i < this->vertices.size()) {
		float x = this->vertices[i++];
		float y = this->vertices[i++];
		float z = this->vertices[i++];

		float u = this->texCoords[t++];
		float v = this->texCoords[t++];

		glTexCoord2f(u, v);
		glVertex3f(x, y, z);
	}
	glEnd();
}