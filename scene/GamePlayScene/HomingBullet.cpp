#include "HomingBullet.h"
#include <DxLib.h>

HomingBullet::HomingBullet(int x, int y)
{
	texture = LoadGraph("");

	this->x = x;
	this->y = y;
}

void HomingBullet::Update()
{
}

void HomingBullet::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
