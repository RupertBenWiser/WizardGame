#include <string>
#include "gl.h"
#include "State.h"
#include "Scene.h"
#include "PuzzleOne.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

const int WIDTH = 800;
const int HEIGHT = 600;

Scene* currentScene = nullptr;

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

	glfwSetKeyCallback(window, key_callback);

	PuzzleOne puzzleOne;

	currentScene = &puzzleOne;
	currentScene->start();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		keyEvents.clear();

		glfwPollEvents();

		currentScene->update();
		currentScene->render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	KeyEvent event(action, key);
	keyEvents.push_back(event);
}