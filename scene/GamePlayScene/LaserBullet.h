#pragma once
#include <DxLib.h>

class LaserBullet
{
public:
	LaserBullet(int startX, int startY, int endX, int endY);

	void Update();

	void Draw();

	void SetPlayerPosition(int x, int y) {
		this->playerPositionX = x;
		this->playerPositionY = y;
	};

private:
	int startX;
	int startY;

	int endX;
	int endY;

	int playerPositionX;
	int playerPositionY;
};

