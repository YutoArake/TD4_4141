#include "LaserBullet.h"

LaserBullet::LaserBullet(int startX,int startY,int endX,int endY)
{
}

void LaserBullet::Update()
{
}

void LaserBullet::Draw()
{
	DrawLine(startX, startY, endX, endY, GetColor(255, 0, 0), true);
}
