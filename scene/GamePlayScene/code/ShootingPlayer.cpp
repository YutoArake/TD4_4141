#include "ShootingPlayer.h"



ShootingPlayer::ShootingPlayer()
{
	texture = LoadGraph("Resources/test.png");

}

void ShootingPlayer::Update()
{
	GetHitKeyStateAll(key);
	if (condition == 1) {
		invitime--;
		if (invitime < 0) {
			condition = 0;
		}
	}

	Move();
	UpdateBullet();
	Shoot();
	DeleteBullet();
	HitDeleteBullet();

	for (int i = 0; i < 256; i++) {
		oldkey[i] = key[i];
	}
}

void ShootingPlayer::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
	DrawBullet();
	//DrawFormatString(0, 200, GetColor(255, 255, 255), "%d", hp);
}

void ShootingPlayer::Move()
{

	if (key[KEY_INPUT_W] == 1) {
		y -= 5;
	}
	if (key[KEY_INPUT_S] == 1) {
		y += 5;
	}
	if (key[KEY_INPUT_A] == 1) {
		x -= 5;
	}
	if (key[KEY_INPUT_D] == 1) {
		x += 5;
	}
}

void ShootingPlayer::Shoot()
{
	if (key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0) {
		playerbullets.push_back(new PlayerBullet(static_cast<float>(x), static_cast<float>(y)));
	}
}

void ShootingPlayer::UpdateBullet()
{
	for (auto itr = playerbullets.begin(); itr != playerbullets.end(); ++itr) {
		(*itr)->Update();
	}
}

void ShootingPlayer::DrawBullet()
{
	for (auto itr = playerbullets.begin(); itr != playerbullets.end(); ++itr) {
		(*itr)->Draw();
	}
}

void ShootingPlayer::DeleteBullet()
{
	for (auto itr = playerbullets.begin(); itr != playerbullets.end();) {
		if ((*itr)->GetBulletX() > 1200) {
			itr = playerbullets.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}

void ShootingPlayer::HitDeleteBullet()
{
	for (auto itr = playerbullets.begin(); itr != playerbullets.end();) {
		if ((*itr)->GetHit() == true) {
			itr = playerbullets.erase(itr); // イテレーターを更新して次の要素に進む
		}
		else {
			++itr; // 次の要素に進む
		}
	}
}
