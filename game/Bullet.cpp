#include "Bullet.h"
#include <iostream>

Bullet::Bullet(float centerX, float centerY,
	float sizeX, float sizeY, glm::mat4x4 ortho,
	float rotationAngle, const char* path,
	const unsigned int const* program,
	float windowWidth)
	: Model(centerX, centerY, sizeX, sizeY, ortho, rotationAngle, path, program) 
{
	this->windowWidth = windowWidth;
}

bool Bullet::bulletExist() { 
	return exists; 
}

bool Bullet::create(float x, float y) {
	if (exists == false) {
		move[3][0] = x; move[3][1] = y;
		exists = true;
		return true;
	}
	else {
		return false;
	}
}

void Bullet::checkCollision() {
	if (exists == true) {
		if (move[3][0] > windowWidth) {
			exists = false;
		}
	}
}

void Bullet::moveIt(float speed) {
	if (exists == true) {
		move[3][0] += speed;
	}
}

void Bullet::drawIt() {
	if (exists == true) {
		Model::drawIt();
	}
}