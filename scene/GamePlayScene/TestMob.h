#pragma once
#include "Mob.h"

class TestMob :public Mob
{
public:
	TestMob(const char* texture, int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;


private:
	int movementX;
	int movementY;

	int sizeX;
	int sizeY;

	int texture;
};

