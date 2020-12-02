#ifndef _CHARACTER_IMPLEMENTED_
#define _CHARACTER_IMPLEMENTED_

#include "Model_Parent.h"
#include "Bullet.h"

class Character : private Model{
	float modelWidth, modelHeight;
	float windowTopEdge;

	const int maxBulletCount = 5;

	Bullet** bullet;

public:
	Character(float centerX, float centerY, 
	float sizeX, float sizeY, glm::mat4x4 ortho,
	float rotationAngle, const char* path, 
	const unsigned int const* program,
	float windowWidth);

	~Character();

	void moveIt(float speed);

	void shoot();

	void drawIt();
};

#endif