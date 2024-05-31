#include "Extinguisher.h"
#include <DxLib.h>

Extinguisher::Extinguisher(const char* texture, int x, int y, int sizeX, int sizeY)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Extinguisher::Update()
{
}

void Extinguisher::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
