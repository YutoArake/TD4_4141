#pragma once
#include "GamePlayScene/Mob.h"
#include <DxLib.h>
#include "GamePlayScene/HomingBullet.h"
#include <list>

class HomingShooter : public Mob
{
public:
	HomingShooter(int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;

	void Shoot();

	void DeleteBallet();

private:
	int movementX;
	int movementY;

	int texture;

	int hp;

	int shootinterval = intervaltime * 60;

	int intervaltime = 0;

	std::list<HomingBullet*> homingbullets;
};

