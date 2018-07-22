#include <string>
#include "gl.h"
#include "State.h"
#include "Scene.h"
#include "PuzzleOne.h"
#include "Math.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateCamera();

Scene* currentScene = nullptr;
Prop* focusedProp = nullptr;

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
		double startTime = glfwGetTime();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		currentScene->update();
		updateCamera();

		glPushMatrix();
		glRotatef(cameraRotation, 1, 0, 0);
		glTranslatef(-cameraX, cameraY, -cameraZ - cameraOffset);
		currentScene->render();
		glPopMatrix();

		glfwSwapBuffers(window);

		double finishTime = glfwGetTime();

		// TODO: need to add delta variable
		Sleep((1000.0f / 120.0f) - (finishTime - startTime));
	}

	glfwTerminate();

	return 0;
}

void updateCamera() {
	if (focusedProp != nullptr) {
		cameraX += (focusedProp->getX() - cameraX) / 5.0f;
		cameraZ += (focusedProp->getZ() - cameraZ) / 5.0f;
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	pressed[key] = action;
}