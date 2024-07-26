#pragma once
#include "GamePlayScene/Mob.h"
#include "GamePlayScene/Bullet.h"
#include <list>

class ShootingPlayer;

class Shooter : public Mob
{
public:
	Shooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingplayer);

	void Update() override;

	void Draw() override;

	void Shoot();

	void UpdateBullet();

	void DrawBullet();

	void DeleteBullet();

	void HitDeleteBullet();

	void Collision();

private:
	int movementX;
	int movementY;

	int texture;

	int hp;

	int intervaltime = 2;

	int shootinterval = intervaltime * 60;



	std::list<Bullet*> bullets;
	ShootingPlayer* shootingplayer;
};