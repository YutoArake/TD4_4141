#include "HomingBullet.h"
#include <DxLib.h>
#include <math.h>


HomingBullet::HomingBullet(float x, float y)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;
}

void HomingBullet::Update()
{
	x += movementX;
	y += movementY;

	if (homingtime > 0) {
		BallisticUpdate();
		homingtime--;
	}

}

void HomingBullet::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", homingtime);
}

void HomingBullet::BallisticUpdate()
{

	float Xlength = playerPositionX - x;
	float Ylength = playerPositionY - y;

	float reference = sqrt(static_cast<double>(Xlength * Xlength + Ylength * Ylength));

	float referenceX = Xlength / reference;
	float referenceY = Ylength / reference;

	movementX = referenceX * speedX;
	movementY = referenceY * speedY;
}


