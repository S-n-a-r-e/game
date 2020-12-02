#ifndef _SHADER_PARSER_INITIALIZED_
#define _SHADER_PARSER_INITIALIZED_

#include <glew.h>
#include <glfw3.h>
#include <mat4x4.hpp>

#include <iostream>
#include <fstream>

class Shader {
	std::ifstream sh;
	int length = 0;

	char* vSourceCode;
	char* fSourceCode;

	unsigned int vShader, fShader;

	bool vCompileSuccessful;
	bool fCompileSuccessful;
	bool linkSuccessful;

	unsigned int program;

	void debug();

	void createShaderProgram();
public:
	Shader(const char* vPath, const char* fPath);

	~Shader();

	void initMatrix(glm::mat4x4 matrix, const char* name);

	inline unsigned int* getProgram() {
		return &program;
	}
};

#endif