#include<Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	position.x = -30.0f;
	position.y = -30.0f;
	radius = 10.0f;
	speed = 10.0f;
	isAlive = false;
	color = 0x33a22bFF;
}

Bullet::~Bullet() {

}

void Bullet::Update() {
	if (isAlive) {
		position.y -= speed;
	}
	if (position.y < 0 - radius) {
		isAlive = false;
	}
}

void Bullet::Draw() {

	if (isAlive) {
		Novice::DrawEllipse(
			position.x, position.y, radius, radius,
			0.0f, color, kFillModeSolid
		);
	}
}