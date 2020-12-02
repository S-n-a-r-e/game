#include "Model_Parent.h"
#include <gtx\transform.hpp>
#include <iostream>
#include <glew.h>

void Model::initBuffer(unsigned int attribNumber, unsigned int* buffer, unsigned int arraySize, unsigned int verticesCount, float* data) {
	glEnableVertexAttribArray(attribNumber);
	glGenBuffers(1, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * arraySize + 1, data, GL_STATIC_DRAW);
	glVertexAttribPointer(attribNumber, verticesCount, GL_FLOAT, GL_FALSE, sizeof(float) * (arraySize / verticesCount), 0);
}

Model::Model(float centerX, float centerY, 
float sizeX, float sizeY, 
glm::mat4x4 ortho, float rotationAngle, 
const char* path, const unsigned int const* program) {

	//vertex array
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	//data for buffers (coordinates and texture coordinates)
	/*float coords[8] = {
		centerX,		centerY - sizeY,
		centerX + sizeX, centerY - sizeY,
		centerX + sizeX, centerY + sizeY,
		centerX,		centerY + sizeY
	};*/
	float coords[8] = {
		0.0f,		0.0f - sizeY / 2,
		0.0f + sizeX, 0.0f - sizeY / 2,
		0.0f + sizeX, 0.0f + sizeY / 2,
		0.0f,		0.0f + sizeY / 2
	};
	float texCoords[8] = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	//buffers
	initBuffer(0, &coordBuffer, 8, 4, coords);
	initBuffer(1, &texCoordBuffer, 8, 4, texCoords);

	//matrices
	this->ortho = ortho;
	rotate = glm::rotate(rotationAngle, glm::vec3(0.0f, 0.0f, 1.0f));
	/*move = glm::mat4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);*/
	move = glm::mat4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		centerX, centerY, 0.0f, 1.0f
	);

	//matrix location
	matrixLocation = glGetUniformLocation(*program, "mtx");

	//texture
	texture = new Texture(path, program, "inpTexture");
}

Model::~Model() {
	glDeleteBuffers(1, &coordBuffer);
	glDeleteBuffers(1, &texCoordBuffer);
	glDeleteVertexArrays(1, &vertexArray);
	delete texture;
}

void Model::drawIt() {
	texture->setTexture();

	glm::mat4x4 mtx = ortho * move * rotate;

	glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, &mtx[0][0]);
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_QUADS, 0, 4);
}
