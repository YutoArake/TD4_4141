#include "Missile.h"
#include <DxLib.h>

Missile::Missile(const char* texture, int x, int y, int sizeX, int sizeY)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Missile::Update()
{
}

void Missile::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
