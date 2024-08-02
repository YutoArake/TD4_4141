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

	void HitDeleteBullet();

	void Collision();

	void SendPlayerPosition();

private:
	int movementX;
	int movementY;

	int texture;



	int intervaltime = 2;
	int shootinterval = intervaltime * 60;



	std::list<HomingBullet*> homingbullets;


	ShootingPlayer* shootingplayer;
};

