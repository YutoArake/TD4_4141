#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(float x, float y)
{
	texture = LoadGraph("Resources/test.png");
	this->x = x;
	this->y = y;
}

void PlayerBullet::Update()
{
	x += movementX;
	y += movementY;
}

void PlayerBullet::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
