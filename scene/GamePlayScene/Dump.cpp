#include "Dump.h"
#include <DxLib.h>

Dump::Dump(const char* texture, int x, int y, int sizeX, int sizeY)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Dump::Update()
{
}

void Dump::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
