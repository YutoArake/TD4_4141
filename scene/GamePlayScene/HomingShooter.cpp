#include "HomingShooter.h"
#include "GamePlayScene/ShootingPlayer.h"


HomingShooter::HomingShooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingPlayer)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;

	this->sizeX = sizeX;
	this->sizeY = sizeY;

	this->shootingPlayer = shootingPlayer;
}

void HomingShooter::Update()
{
	shootinterval--;
	if (shootinterval == 0) {
		Shoot();
		shootinterval = intervaltime * 60;
	}
	UpdateBullet();
	SendPlayerPosition();
	DeleteBullet();
}

void HomingShooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
	DrawBullet();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", shootinterval);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", homingbullets.size());
}

void HomingShooter::Shoot()
{
	homingbullets.push_back(new HomingBullet(static_cast<float>(x), static_cast<float>(y)));
}

void HomingShooter::UpdateBullet()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end(); ++itr) {
		(*itr)->Update();
	}
}

void HomingShooter::DrawBullet()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end(); ++itr) {
		(*itr)->Draw();
	}
}

void HomingShooter::DeleteBullet()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end();) {
		int x = (*itr)->GetBulletX();
		int y = (*itr)->GetBulletY();

		if (x < -100 || x > 1200 || y < -10 || y > 750) {
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
