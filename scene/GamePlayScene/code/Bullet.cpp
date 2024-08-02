#include "Bullet.h"
#include <DxLib.h>

Bullet::Bullet(float x, float y)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;
}

void Bullet::Update()
{
	x += movementX;
	y += movementY;
}

void Bullet::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
