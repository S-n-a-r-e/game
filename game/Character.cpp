#include "Character.h"
#include <iostream>
#include <glfw3.h>

Character::Character(float centerX, float centerY,
float sizeX, float sizeY,
glm::mat4x4 ortho, float rotationAngle,
const char* path, const unsigned int const* program,
float windowWidth)
: Model(centerX, centerY, sizeX, sizeY, ortho, rotationAngle, path, program) {
	windowTopEdge = centerY * 2;

	modelWidth = sizeX;
	modelHeight = sizeY;

	bullet = new Bullet* [maxBulletCount];

	for (int i = 0; i < maxBulletCount; ++i) {
		bullet[i] = new Bullet(centerX, centerY, sizeX / 3.0f, sizeY / 5.0f, ortho, rotationAngle, path, program, windowWidth);
	}

}

Character::~Character() {
	delete bullet;
}

void Character::moveIt(float speed) {
	if ((move[3][1] - (modelHeight / 2) + speed > 5.0f) && (move[3][1] + (modelHeight / 2) + speed < windowTopEdge - 5.0f)) {
		move[3][1] += speed;
	}
}

void Character::shoot() {
	for (int i = 0; i < maxBulletCount; ++i) {
		if (bullet[i]->create(move[3][0] + modelWidth / 2.0f, move[3][1]) == true) { break; }
	}
}

void Character::drawIt() {
	for (int i = 0; i < maxBulletCount; ++i) {
		if (bullet[i]->bulletExist() == true) {
			bullet[i]->moveIt(4.0f);
			bullet[i]->checkCollision();
			bullet[i]->drawIt();
		}
	}
	


	Model::drawIt();
}