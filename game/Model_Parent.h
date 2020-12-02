#ifndef _MODEL_PARENT_IMPLEMENTED_
#define _MODEL_PARENT_IMPLEMENTED_

#include <mat4x4.hpp>

#include "Texture.h"

class Model {
	unsigned int vertexArray, coordBuffer, texCoordBuffer;

	glm::mat4x4 ortho, rotate;
	int matrixLocation;

	Texture* texture;
	
	void initBuffer(unsigned int attribNumber, unsigned int* buffer, unsigned int arraySize, unsigned int verteciesCount, float* data);
public:
	glm::mat4x4 move;

	Model(float centerX, float centerY, float sizeX, float sizeY,
		glm::mat4x4 ortho, float rotationAngle,
		const char* path, const unsigned int const* program);

	~Model();

	void drawIt();
};

#endif