#include "gl.h"
#include "Billboard.h"
#include <string>

const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
	GLFWwindow* window;

	if (!glfwInit()) {
		return 1;
	}

	window = glfwCreateWindow(WIDTH, HEIGHT, "Wizard Game", NULL, NULL);

	glfwMakeContextCurrent(window);

	glViewport(0, 0, WIDTH, HEIGHT);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45, WIDTH / HEIGHT, 0.01f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	std::string filename = "test.png";
	Billboard test(&filename[0], 0, 0, -10);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		test.render();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}