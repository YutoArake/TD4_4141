#pragma once
#include "GamePlayScene/Mob.h"

#include <DxLib.h>
#include <list>
class ShootingPlayer;

class LaserShooter : public Mob
{
public:
	LaserShooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingPlayer);

	void Update() override;

	void Draw() override;

	void Shoot();

	void UpdateBullet();

	void DrawBullet();

private:
	int movementX;
	int movementY;

	int texture;

	int hp;

	int intervaltime = 2;
	int shootinginterval = intervaltime * 60;

	int Reservesecond = 1;
	int Reservetime = Reservesecond * 60;

	int shootingsecond = 2;
	int shootingtime = shootingsecond * 60;


	ShootingPlayer* shootingPlayer;
};

