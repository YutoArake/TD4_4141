#include "HomingShooter.h"
#include "GamePlayScene/ShootingPlayer.h"


HomingShooter::HomingShooter(int x, int y, int sizeX, int sizeY)
{
	texture = LoadGraph("");

	this->x = x;
	this->y = y;

	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void HomingShooter::Update()
{
}

void HomingShooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}

void HomingShooter::Shoot()
{
	homingbullets.push_back(new HomingBullet(x, y));
}

void HomingShooter::DeleteBallet()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end();) {
		int x = (*itr)->GetBulletPosition().x;
		int y = (*itr)->GetBulletPosition().y;

		if (x > 0) {
			itr = homingbullets.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}

void HomingShooter::SendPlayerPosition()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end(); ++itr) {
		(*itr)->SetPlayerPosition(shootingPlayer->GetPositionX(), shootingPlayer->GetPositionY());
	}
}
