#pragma once
#include "GamePlayScene/Mob.h"

class Chainsawman :public Mob
{
public:
	Chainsawman(const char* texture, int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;

private:
	int movementX;
	int movementY;

	int sizeX;
	int sizeY;

	int texture;
};