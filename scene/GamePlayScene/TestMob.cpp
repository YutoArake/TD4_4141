#include "TestMob.h"
#include <DxLib.h>

TestMob::TestMob(const char* texture, int x, int y, int sizeX, int sizeY)
{
	this->texture = LoadGraph(texture);
	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void TestMob::Update()
{

}

void TestMob::Draw()
{

}
