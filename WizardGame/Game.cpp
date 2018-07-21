#include <string>
#include "gl.h"
#include "State.h"
#include "Scene.h"
#include "PuzzleOne.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

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
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glfwSetKeyCallback(window, key_callback);

	PuzzleOne puzzleOne;

	currentScene = &puzzleOne;
	currentScene->start();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		currentScene->update();

		glPushMatrix();
		glTranslatef(cameraX, cameraY, cameraZ);
		glRotatef(cameraRotation, 1, 0, 0);
		currentScene->render();
		glPopMatrix();

		Sleep(1000.0f / 60.0f);

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	pressed[key] = action;
}