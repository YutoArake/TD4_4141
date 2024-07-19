#pragma once
#include <DxLib.h>

class PlayerBullet
{
public:
	PlayerBullet(float x, float y);

	void Update();

	void Draw();

	float GetBulletX() {
		return x;
	}

private:
	float x;
	float y;

	float movementX = 10.0;
	float movementY = 0;

	int sizeX = 15;
	int sizeY = 15;

	int texture;
};

