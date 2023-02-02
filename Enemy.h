#pragma once
#include"Object.h"

class Enemy:public Object
{
public:
	static const int enemyCount;
	static int isAlive;
	Enemy();
	~Enemy();
	
	void SetPositionY(float y,int i);
	void SetPositionX(float x, int i);
	float GetPositionY();
	float GetPositionX();
	float GetRadius();
	void Update()override;
	void Draw()override;
};

