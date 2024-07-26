#pragma once
#include <DxLib.h>

class LaserBullet
{
public:
	LaserBullet(double startX, double startY, double endX, double endY);

	void Update();

	void Draw();

	void Extension();

	bool GetHit() {
		return hit;
	}

	void onCollision() {
		hit = true;
	}

	void SetPlayerPosition(int x, int y) {
		this->playerPositionX = x;
		this->playerPositionY = y;
	};

private:
	double startX = 0;
	double startY = 0;

	double endX = 0;
	double endY = 0;

	double extensionX = 0;
	double extensionY = 0;

	bool hit = false;

	int distance = 0;

	int playerPositionX = 0;
	int playerPositionY = 0;
};

