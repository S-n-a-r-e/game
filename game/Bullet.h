#ifndef _BULLET_IMPLEMENTED_
#define _BULLET_IMPLEMENTED_

#include "Model_Parent.h"

class Bullet : private Model{
	bool exists = false;

	float windowWidth;
public:
	Bullet(float centerX, float centerY,
		float sizeX, float sizeY, glm::mat4x4 ortho,
		float rotationAngle, const char* path,
		const unsigned int const* program,
		float windowWidth);

	bool bulletExist();

	bool create(float x, float y);

	void checkCollision();

	void moveIt(float speed);

	void drawIt();
};

#endif