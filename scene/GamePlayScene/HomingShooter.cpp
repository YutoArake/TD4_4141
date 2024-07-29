#include "HomingShooter.h"
#include "GamePlayScene/ShootingPlayer.h"
#include "GamePlayScene/Collision.h"


HomingShooter::HomingShooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingPlayer)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;

	this->sizeX = sizeX;
	this->sizeY = sizeY;

	this->shootingplayer = shootingPlayer;
}

void HomingShooter::Update()
{
	shootinterval--;
	if (shootinterval == 0) {
		Shoot();
		shootinterval = intervaltime * 60;
	}
	Collision();
	UpdateBullet();
	SendPlayerPosition();
	DeleteBullet();
	HitDeleteBullet();
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

void HomingShooter::HitDeleteBullet()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end();) {
		if ((*itr)->GetHit() == true) {
			itr = homingbullets.erase(itr); // イテレーターを更新して次の要素に進む
		}
		else {
			++itr; // 次の要素に進む
		}
	}
}

void HomingShooter::Collision()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end(); ++itr) {
		if (Collision::SquareToSquare((*itr)->GetBulletX() - (*itr)->GetSizeX(), (*itr)->GetBulletY() - (*itr)->GetSizeY(),
			(*itr)->GetBulletX() + (*itr)->GetSizeX(), (*itr)->GetBulletY() + (*itr)->GetSizeY(),
			shootingplayer->GetPositionX() - shootingplayer->GetSizeX(), shootingplayer->GetPositionY() - shootingplayer->GetSizeY(),
			shootingplayer->GetPositionX() + shootingplayer->GetSizeX(), shootingplayer->GetPositionY() + shootingplayer->GetSizeY())) {
			(*itr)->onCollision();
			shootingplayer->Damage();
		}
	}
}

void HomingShooter::SendPlayerPosition()
{
	for (auto itr = homingbullets.begin(); itr != homingbullets.end(); ++itr) {
		(*itr)->SetPlayerPosition(shootingplayer->GetPositionX(), shootingplayer->GetPositionY());
	}
}
