#pragma once
#include <string>
#include <iostream>
#include "FileLoader.h"
#include "gl.h"

class Shader
{
private:
	GLuint _program;
	GLuint createShader(std::string source, GLenum type);

public:
	Shader(std::string shader);
	Shader(std::string vertexShader, std::string fragmentShader);
	~Shader();
	void bind();
	void unbind();
};

