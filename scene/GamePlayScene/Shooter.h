#pragma once
#include "GamePlayScene/Mob.h"

class Shooter : public Mob
{
public:
	Shooter(const char* texture, int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;

private:
	int movementX;
	int movementY;

	int texture;
};