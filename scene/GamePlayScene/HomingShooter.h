#pragma once
#include "GamePlayScene/Mob.h"
#include <DxLib.h>
#include "GamePlayScene/HomingBullet.h"
#include <list>

class ShootingPlayer;

class HomingShooter : public Mob
{
public:
	HomingShooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingPlayer);

	void Update() override;

	void Draw() override;

	void Shoot();

	void UpdateBullet();

	void DrawBullet();

	void DeleteBullet();

	void SendPlayerPosition();

private:
	int movementX;
	int movementY;

	int texture;

	int hp;

	int shootinterval = intervaltime * 60;

	int intervaltime = 0;

	std::list<HomingBullet*> homingbullets;

	ShootingPlayer* shootingPlayer;
};

