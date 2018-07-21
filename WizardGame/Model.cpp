#include "Model.h"
#include <iostream>

void Model::render(float offsetX, float offsetY, float offsetZ) {
	glBegin(GL_QUADS);
	int i = 0;
	int t = 0;
	while (i < this->vertices.size()) {
		float x = this->vertices[i++];
		float y = this->vertices[i++];
		float z = this->vertices[i++];

		float u = (*this->texCoords)[t++];
		float v = (*this->texCoords)[t++];

		glTexCoord2f(u, v);
		glVertex3f(x + offsetX, y + offsetY, z + offsetZ);
	}
	glEnd();
}