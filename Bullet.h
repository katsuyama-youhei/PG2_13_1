#pragma once
#include"Vector.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Initialize();
	void Update();
	void Draw();

	Vector2 position;
	float speed;
	float radius;
	unsigned int color;
	bool isAlive;
};

