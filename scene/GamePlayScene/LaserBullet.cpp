#include "LaserBullet.h"
#include "math.h"

LaserBullet::LaserBullet(double startX, double startY, double endX, double endY)
{
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;

	Extension();
}

void LaserBullet::Update()
{
}

void LaserBullet::Draw()
{
	//DrawLineAA(startX, startY, endX, endY, GetColor(255, 0, 0), true);
	DrawLineAA(startX, startY, extensionX, extensionY, GetColor(255, 0, 0), true);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "%f", extensionX);
	DrawFormatString(0, 160, GetColor(255, 255, 255), "%f", extensionY);
}

void LaserBullet::Extension()
{
	distance = sqrt((endX - startX) * (endX - startX) + (endY - startY) * (endY - startY));
	extensionX = (-1000 * startX + (distance + 1000) * endX) / distance;
	extensionY = (-1000 * startY + (distance + 1000) * endY) / distance;
}


