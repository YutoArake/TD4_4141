#pragma once
#include <DxLib.h>


class ShootingPlayer
{
public:
	ShootingPlayer();

	void Update();

	void Draw();

	void Move();

	int GetPositionX() {
		return x;
	}

	int GetPositionY() {
		return y;
	}

private:
	int x = 300;
	int y = 300;

	int sizeX = 15;
	int sizeY = 15;

	int texture = 0;
};
