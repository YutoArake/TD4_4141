#pragma once
#include <DxLib.h>

class PlayerBullet
{
public:
	PlayerBullet(float x, float y);

	void Update();

	void Draw();

	float GetBulletX() {
		return y;
	}

private:
	float x;
	float y;

	float movementX;
	float movementY;

	int sizeX;
	int sizeY;

	int texture;
};

