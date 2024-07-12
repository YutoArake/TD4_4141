#include "Shooter.h"
#include <DxLib.h>

Shooter::Shooter(int x, int y, int sizeX, int sizeY)
{
	texture = LoadGraph("");

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

}

void Shooter::Update()
{

}

void Shooter::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}

void Shooter::Shoot()
{
	bullets.push_back(new Bullet(x, y));
}

void Shooter::DeleteBullet()
{
	for (auto itr = bullets.begin(); itr != bullets.end();) {
		//現在のイテレーターの座標を取得
		int x = (*itr)->GetBulletPosition().x;
		int y = (*itr)->GetBulletPosition().y;

		//弾削除の判定
		if (x > 0) {
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
