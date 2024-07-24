#include "LaserShooter.h"
#include "GamePlayScene/ShootingPlayer.h"

LaserShooter::LaserShooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingPlayer)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;

	this->sizeX = sizeX;
	this->sizeY = sizeY;

	this->shootingPlayer = shootingPlayer;
}

void LaserShooter::Update()
{
	if (intervaltime >= 0) {
		//”­ŽË‘O
		intervaltime--;
		if (intervaltime < 0) {
			//”­ŽË€”õ
			reservetime--;
			if (reservetime == 0) {
				//”­ŽË
				Shoot();
			}

			if (reservetime < 0) {
				//”­ŽË’†
				shootingtime--;
				if (shootingtime < 0) {
					//”­ŽËI—¹
					shootinginterval = intervaltime * 60;
					reservetime = reservesecond * 60;
					shootingtime = shootingsecond * 60;
				}
			}
		}
	}
	UpdateBullet();
}

void LaserShooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
	DrawBullet();
}

void LaserShooter::Shoot()
{
	laserbullets.push_back(new LaserBullet(x, y, shootingPlayer->GetPositionX(), shootingPlayer->GetPositionY()));
}

void LaserShooter::UpdateBullet()
{
	for (auto itr = laserbullets.begin(); itr != laserbullets.end(); ++itr) {
		(*itr)->Update();
	}
}

void LaserShooter::DrawBullet()
{
	for (auto itr = laserbullets.begin(); itr != laserbullets.end(); ++itr) {
		(*itr)->Draw();
	}
}

void LaserShooter::DeleteBullet()
{
}

void LaserShooter::SendPlayerPosition()
{
	for (auto itr = laserbullets.begin(); itr != laserbullets.end(); ++itr) {
		(*itr)->SetPlayerPosition(shootingPlayer->GetPositionX(), shootingPlayer->GetPositionY());
	}
}
