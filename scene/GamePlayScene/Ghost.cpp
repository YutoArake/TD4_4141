#include "Ghost.h"
#include <DxLib.h>

Ghost::Ghost(const char* texture, int x, int y, int sizeX, int sizeY)
{
	this->texture = LoadGraph(texture);
	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Ghost::Update()
{

}

void Ghost::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
