#include "LaserShooter.h"
#include "GamePlayScene/ShootingPlayer.h"
#include "GamePlayScene/Collision.h"

LaserShooter::LaserShooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingPlayer)
{
	texture = LoadGraph("Resources/LaserShooter.png");

	this->x = x;
	this->y = y;

	this->sizeX = sizeX;
	this->sizeY = sizeY;

	this->hp = 4;
	this->hit = false;

	this->shootingplayer = shootingPlayer;
}

void LaserShooter::Update()
{
	if (phase == 0) {
		shootinginterval--;
		if (shootinginterval < 0) {
			targetX = shootingplayer->GetPositionX();
			targetY = shootingplayer->GetPositionY();
			phase = 1;
		}
	}
	if (phase == 1) {
		reservetime--;
		if (reservetime < 0) {
			Shoot();
			phase = 2;
		}
	}
	if (phase == 2) {
		shootingtime--;
		if (shootingtime < 0) {
			DeleteBullet();
			phase = 3;
		}
	}
	if (phase == 3) {
		shootinginterval = intervaltime * 60;
		reservetime = reservesecond * 60;
		shootingtime = shootingsecond * 60;
		phase = 0;
	}

	UpdateBullet();
	Collision();
	HitDeleteBullet();
}

void LaserShooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
	//DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", phase);
	DrawBullet();
}

void LaserShooter::Shoot()
{
	laserbullets.push_back(new LaserBullet(x, y, targetX, targetY));
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
	laserbullets.clear();
}

void LaserShooter::HitDeleteBullet()
{
	for (auto itr = laserbullets.begin(); itr != laserbullets.end();) {
		if ((*itr)->GetHit() == true) {
			itr = laserbullets.erase(itr); // イテレーターを更新して次の要素に進む
		}
		else {
			++itr; // 次の要素に進む
		}
	}
}

void LaserShooter::Collision()
{
	for (auto itr = laserbullets.begin(); itr != laserbullets.end(); ++itr) {
		if (Collision::LineToSquare(shootingplayer->GetPositionX() - shootingplayer->GetSizeX(), shootingplayer->GetPositionY() - shootingplayer->GetSizeY(),
			shootingplayer->GetPositionX() - shootingplayer->GetSizeX(), shootingplayer->GetPositionY() + shootingplayer->GetSizeY(),
			shootingplayer->GetPositionX() + shootingplayer->GetSizeX(), shootingplayer->GetPositionY() - shootingplayer->GetSizeY(),
			shootingplayer->GetPositionX() + shootingplayer->GetSizeX(), shootingplayer->GetPositionY() + shootingplayer->GetSizeY(),
			(*itr)->GetstartX(), (*itr)->GetstartY(), (*itr)->GetextensionX(), (*itr)->GetextensionY())) {
			(*itr)->onCollision();
			shootingplayer->Damage();

		}
	}
}

void LaserShooter::SendPlayerPosition()
{
	for (auto itr = laserbullets.begin(); itr != laserbullets.end(); ++itr) {
		(*itr)->SetPlayerPosition(shootingplayer->GetPositionX(), shootingplayer->GetPositionY());
	}
}
