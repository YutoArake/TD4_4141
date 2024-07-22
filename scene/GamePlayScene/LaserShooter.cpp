#include "LaserShooter.h"

LaserShooter::LaserShooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingPlayer)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;

	this->sizeX = sizeX;
	this->sizeY = sizeY;

	this->shootingPlayer = shootingPlayer;
}
