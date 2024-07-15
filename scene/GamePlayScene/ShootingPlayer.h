#pragma once
#include <DxLib.h>
#include <GamePlayScene/PlayerBullet.h>
#include <list>


class ShootingPlayer
{
public:
	ShootingPlayer();

	void Update();

	void Draw();

	void Move();

	void Shoot();

	void DeleteBullet();

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

	char key[256];
	char oldkey[256];

	std::list<PlayerBullet*> playerbullet;
};
