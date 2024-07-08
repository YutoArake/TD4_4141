#include "HomingBullet.h"
#include <DxLib.h>
#include <math.h>


HomingBullet::HomingBullet(float x, float y)
{
	texture = LoadGraph("");

	this->x = x;
	this->y = y;
}

void HomingBullet::Update()
{
	x += movementX;
	y += movementY;
}

void HomingBullet::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}

void HomingBullet::BallisticUpdate()
{

	float Xlength = playerPositionX - x;
	float Ylength = playerPositionY - y;

	float reference = sqrt(static_cast<double>(Xlength * Xlength + Ylength * Ylength));

	movementX = reference * speedX;
	movementY = reference * speedY;
}


