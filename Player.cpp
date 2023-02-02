#include<Novice.h>
#include "Player.h"

Player::Player() {
	pos_.x = 200.0f;
	pos_.y = 500.0f;
	speed_ = 10.0f;
	radius_ = 20.0f;
	color_ = RED;
	isAlive_ = true;
	isShot = false;
}

Player::~Player() {

}

void Player::Update(char* keys) {
	if (keys[DIK_SPACE]&&!bullet.isAlive) {
		bullet.position = pos_;
		bullet.isAlive = true;
		
	}
	bullet.Update();

	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	else if (keys[DIK_S]) {
		pos_.y += speed_;
	}

	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	else if (keys[DIK_D]) {
		pos_.x += speed_;
	}

}

void Player::Draw() {
	bullet.Draw();
	Novice::DrawEllipse(
		pos_.x, pos_.y, radius_, radius_,
		0.0f, color_, kFillModeSolid
	);
}

float Player::GetPositionX() {
	return bullet.position.x;
}

float Player::GetPositionY() {
	return bullet.position.y;
}

float Player::GetRadius() {
	return bullet.radius;
}