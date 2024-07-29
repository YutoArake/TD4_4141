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

		//�e�폜�̔���
		if ((*itr)->GetBulletX() < -100.0) {
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

void Shooter::HitDeleteBullet()
{
	for (auto itr = bullets.begin(); itr != bullets.end();) {
		if ((*itr)->GetHit() == true) {
			itr = bullets.erase(itr); // �C�e���[�^�[���X�V���Ď��̗v�f�ɐi��
		}
		else {
			++itr; // ���̗v�f�ɐi��
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
