#include "Shader.h"
#include <vector>
#include <iostream>

Shader::Shader(std::string vertexShaderFile, std::string fragmentShaderFile)
{
	auto vertexShaderSource = loadFile(vertexShaderFile);
	auto fragmentShaderSource = loadFile(fragmentShaderFile);

	_program = glCreateProgram();
	GLuint vertexShader = this->createShader(vertexShaderSource, GL_VERTEX_SHADER);
	GLuint fragmentShader = this->createShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
	glAttachShader(_program, vertexShader);
	glAttachShader(_program, fragmentShader);
	glLinkProgram(_program);
}

Shader::Shader(std::string shader): Shader(shader + ".vert", shader + ".frag")
{

}

GLuint Shader::createShader(std::string source, GLenum type)
{
	GLuint shader = glCreateShader(type);
	const char * sourcePointer = source.c_str();
	glShaderSource(shader, 1, &sourcePointer, 0);
	glCompileShader(shader);

	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

		for (GLchar c : infoLog) {
			std::cout << c;
		}
	}
	return shader;
}

void Shader::bind() {
	glUseProgram(_program);
}

void Shader::unbind() {
	glUseProgram(0);
}

Shader::~Shader()
{
	glDeleteProgram(_program);
}
