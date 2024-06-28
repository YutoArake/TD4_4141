#include "HomingShooter.h"


HomingShooter::HomingShooter(int x, int y, int sizeX, int sizeY)
{
	texture = LoadGraph("");

	this->x = x;
	this->y = y;

	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void HomingShooter::Update()
{
}

void HomingShooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}

void HomingShooter::Shoot()
{

}

void HomingShooter::DeleteBallet()
{

}
