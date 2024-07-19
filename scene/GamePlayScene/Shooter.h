#pragma once
#include "GamePlayScene/Mob.h"
#include "GamePlayScene/Bullet.h"
#include <list>

class Shooter : public Mob
{
public:
	Shooter(int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;

	void Shoot();

	void UpdateBullet();

	void DrawBullet();

	void DeleteBullet();

private:
	int movementX;
	int movementY;

	int texture;

	int hp;

	int intervaltime = 2;

	int shootinterval = intervaltime * 60;



	std::list<Bullet*> bullets;
};