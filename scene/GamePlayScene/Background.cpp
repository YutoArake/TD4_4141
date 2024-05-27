#include "Background.h"
#include "DxLib.h"

Background::Background(const char* texture, int x, int y)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
}

void Background::Update()
{

}

void Background::Draw()
{
	DrawGraph(x, y, texture, true);
}

void Background::MoveRight()
{
	x += movementX;
}

void Background::MoveLeft()
{
	x -= movementX;
}
