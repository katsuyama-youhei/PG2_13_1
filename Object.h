#pragma once
#include"Vector.h"

class Object
{
protected:
	Vector2 pos_;
	float speed_;
	float radius_;
	bool isAlive_;
	unsigned int color_;
public:
	//virtual ~Object();
	virtual void Update();
	virtual void Draw();
};