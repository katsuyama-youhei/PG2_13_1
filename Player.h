#pragma once
#include"Object.h"
#include"Bullet.h"

class Player:public Object
{
public:
	Player();
	~Player();
	void Update(char* keys);
	void Draw()override;

	bool isShot;
	Bullet bullet;

	float GetPositionX();
	float GetPositionY();
	float GetRadius();

};

