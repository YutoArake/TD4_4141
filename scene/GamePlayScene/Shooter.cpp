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
		//���݂̃C�e���[�^�[�̍��W���擾
		int x = (*itr)->GetBulletPosition().x;
		int y = (*itr)->GetBulletPosition().y;

		//�e�폜�̔���
		if (x > 0) {
			//�폜
			itr = bullets.erase(itr);
		}
		else
		{
			//�폜�������̃C�e���[�^�[��
			++itr;
		}
	}
}
