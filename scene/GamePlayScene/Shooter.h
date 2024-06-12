#pragma once
#include "GamePlayScene/Mob.h"
#include "GamePlayScene/Bullet.h"
#include <list>

class Shooter : public Mob
{
public:
	Shooter(const char* texture, int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;

	void Shoot();

private:
	int movementX;
	int movementY;

	int texture;

	std::list<Bullet*> bullets;
};