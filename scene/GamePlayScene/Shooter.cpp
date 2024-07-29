#include "Shooter.h"
#include "GamePlayScene/ShootingPlayer.h"
#include "GamePlayScene/Collision.h"
#include <DxLib.h>

Shooter::Shooter(int x, int y, int sizeX, int sizeY, ShootingPlayer* shootingplayer)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	this->shootingplayer = shootingplayer;
}

void Shooter::Update()
{
	shootinterval--;
	if (shootinterval == 0) {
		Shoot();
		shootinterval = intervaltime * 60;
	}
	Collision();
	UpdateBullet();
	DeleteBullet();
	HitDeleteBullet();
}

void Shooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
	DrawBullet();
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", shootinterval);
	//DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", bullets.size());
}

void Shooter::Shoot()
{
	bullets.push_back(new Bullet(static_cast<float>(x), static_cast<float>(y)));
}

void Shooter::UpdateBullet()
{
	for (auto itr = bullets.begin(); itr != bullets.end(); ++itr) {
		(*itr)->Update();
	}
}

void Shooter::DrawBullet()
{
	for (auto itr = bullets.begin(); itr != bullets.end(); ++itr) {
		(*itr)->Draw();
	}
}

void Shooter::DeleteBullet()
{
	for (auto itr = bullets.begin(); itr != bullets.end();) {

		//弾削除の判定
		if ((*itr)->GetBulletX() < -100.0) {
			//削除
			itr = bullets.erase(itr);
		}
		else
		{
			//削除せず次のイテレーターへ
			++itr;
		}
	}
}

void Shooter::HitDeleteBullet()
{
	for (auto itr = bullets.begin(); itr != bullets.end();) {
		if ((*itr)->GetHit() == true) {
			itr = bullets.erase(itr); // イテレーターを更新して次の要素に進む
		}
		else {
			++itr; // 次の要素に進む
		}
	}
}

void Shooter::Collision()
{
	for (auto itr = bullets.begin(); itr != bullets.end(); ++itr) {
		if (Collision::SquareToSquare((*itr)->GetBulletX() - (*itr)->GetSizeX(), (*itr)->GetBulletY() - (*itr)->GetSizeY(),
			(*itr)->GetBulletX() + (*itr)->GetSizeX(), (*itr)->GetBulletY() + (*itr)->GetSizeY(),
			shootingplayer->GetPositionX() - shootingplayer->GetSizeX(), shootingplayer->GetPositionY() - shootingplayer->GetSizeY(),
			shootingplayer->GetPositionX() + shootingplayer->GetSizeX(), shootingplayer->GetPositionY() + shootingplayer->GetSizeY())) {
			(*itr)->onCollision();
			shootingplayer->Damage();
		}
	}
}
