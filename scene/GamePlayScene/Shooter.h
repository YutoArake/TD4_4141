#pragma once
#include "GamePlayScene/Mob.h"
#include "GamePlayScene/Bullet.h"
#include "GamePlayScene/PlayerBullet.h"
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

	void GotPlayerShot();

	/*void Damage() {
		hp--;
	}

	bool Gethit() {
		return hit;
	}*/

private:
	int movementX;
	int movementY;

	int texture;

	//int hp = 4;

	int intervaltime = 2;

	int shootinterval = intervaltime * 60;

	//bool hit = false;

	std::list<Bullet*> bullets;
	ShootingPlayer* shootingplayer;


};