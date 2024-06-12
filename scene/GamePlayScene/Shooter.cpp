#include "Shooter.h"
#include <DxLib.h>

Shooter::Shooter(const char* texture, int x, int y, int sizeX, int sizeY)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

}

void Shooter::Update()
{

}

void Shooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}

void Shooter::Shoot()
{
	bullets.push_back(new Bullet(0, 0));
}
