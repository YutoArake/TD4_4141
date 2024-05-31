#include "Door.h"
#include <DxLib.h>

Door::Door(const char* normaltexture, const char* shinetexture, int x, int y, int sizeX, int sizeY, int phase)
{
	this->normaltexture = LoadGraph(normaltexture);
	this->shinetexture = LoadGraph(shinetexture);

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->phase = phase;

}

void Door::Update()
{
}

void Door::Draw()
{
	if (phase == 0) {
		DrawGraph(x - sizeX, y - sizeY, normaltexture, true);
	}
	if (phase == 1) {
		DrawGraph(x - sizeX, y - sizeY, shinetexture, true);
	}
}
