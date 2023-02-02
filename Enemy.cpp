#include<Novice.h>
#include "Enemy.h"

Enemy::Enemy() {
	
	pos_.x = 200.0f;
	pos_.y = 200.0f;
	speed_ = 10.0f;
	radius_ = 20.0f;
	color_ = 0x38b48bFF;
	isAlive_ = true;
}

Enemy::~Enemy() {
	
}

void Enemy::Update() {
	if (isAlive) {
		pos_.x += speed_;

		if (pos_.x >= 1280 - radius_ || pos_.x <= 0 + radius_) {
			speed_ *= -1;
		}
	}
}

void Enemy::Draw() {
	if (isAlive) {
		Novice::DrawEllipse(
			pos_.x, pos_.y, radius_, radius_,
			0.0f, color_, kFillModeSolid
		);
	}
}

float Enemy::GetPositionY() {
	return pos_.y;
}

void Enemy::SetPositionY(float y, int i) {
	this->pos_.y = y + i * 80;
}

void Enemy::SetPositionX(float x, int i) {
	this->pos_.x = x + i * 80;
}

float Enemy::GetPositionX() {
	return pos_.x;
}

float Enemy::GetRadius() {
	return radius_;
}