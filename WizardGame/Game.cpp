#include <string>
#include "gl.h"
#include "State.h"
#include "Scene.h"
#include "PuzzleOne.h"
#include "Math.h"
#include "FrameBuffer.h"
#include <iostream>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateCamera();

Scene* currentScene = nullptr;
Prop* focusedProp = nullptr;

int main() {
	GLFWwindow* window;
	
	if (!glfwInit()) {
		return 1;
	}

	glewExperimental = GL_TRUE;

	window = glfwCreateWindow(WIDTH, HEIGHT, "Wizard Game", NULL, NULL);

	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cout << glewGetErrorString(err) << std::endl;
		int a;
		std::cin >> a;
		return 2;
	}

	glViewport(0, 0, WIDTH, HEIGHT);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45, WIDTH / HEIGHT, 0.01f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_FRAMEBUFFER);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glfwSetKeyCallback(window, key_callback);

	PuzzleOne puzzleOne;

	currentScene = &puzzleOne;
	currentScene->start();

	FrameBuffer framebuffer;

	while (!glfwWindowShouldClose(window)) {
		double startTime = glfwGetTime();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();

		currentScene->update();
		updateCamera();

		framebuffer.bind();
		glPushMatrix();
		glRotatef(cameraRotation, 1, 0, 0);
		glTranslatef(-cameraX, cameraY, -cameraZ - cameraOffset);
		currentScene->render();
		glPopMatrix();
		framebuffer.unbind();

		framebuffer.bindTexture();
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -5.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -5.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -5.0f);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -5.0f);

		glEnd();
		framebuffer.unbindTexture();

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