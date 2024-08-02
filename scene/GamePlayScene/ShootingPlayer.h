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

	void UpdateBullet();

	void DrawBullet();

	void DeleteBullet();

	void HitDeleteBullet();

	void Damage() {
		if (condition == 0) {
			hp--;
			condition = 1;
			invitime = invisecond * 60;
		}
	}

	int GetPositionX() {
		return x;
	}

	int GetPositionY() {
		return y;
	}

	int GetSizeX() {
		return sizeX;
	}

	int GetSizeY() {
		return sizeY;
	}

	int GetHp() {
		return hp;
	}

	std::list<PlayerBullet*> GetPlayerBullet() {
		return playerbullets;
	}

private:
	int x = 0;
	int y = 0;

	int invisecond = 3;
	int invitime = invisecond * 60;

	int condition = 0;
	int hp = 10;

	int sizeX = 15;
	int sizeY = 15;

	int texture = 0;

	char key[256];
	char oldkey[256];

	std::list<PlayerBullet*> playerbullets;


};
