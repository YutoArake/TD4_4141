#include "Shooter.h"
#include <DxLib.h>

Shooter::Shooter(int x, int y, int sizeX, int sizeY)
{
	texture = LoadGraph("Resources/test.png");

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

}

void Shooter::Update()
{
	shootinterval--;
	if (shootinterval == 0) {
		Shoot();
		shootinterval = intervaltime * 60;
	}
	UpdateBullet();
	DeleteBullet();
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
