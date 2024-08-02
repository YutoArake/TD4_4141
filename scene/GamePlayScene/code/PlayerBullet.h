#pragma once
#include <DxLib.h>

class PlayerBullet
{
public:
	PlayerBullet(float x, float y);

	void Update();

	void Draw();

	bool GetHit() {
		return hit;
	}

	void onCollision() {
		hit = true;
	}

	float GetBulletX() {
		return x;
	}
	float GetBulletY() {
		return y;
	}

	int GetSizeX() {
		return sizeX;
	}

	int GetSizeY() {
		return sizeY;
	}

private:
	float x;
	float y;

	bool hit = false;

	float movementX = 10.0;
	float movementY = 0;

	int sizeX = 15;
	int sizeY = 15;

	int texture;
};

