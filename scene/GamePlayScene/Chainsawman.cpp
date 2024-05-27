#include "Chainsawman.h"
#include <DxLib.h>

Chainsawman::Chainsawman(const char* texture, int x, int y, int sizeX, int sizeY)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Chainsawman::Update()
{

}

void Chainsawman::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
