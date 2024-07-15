#include "ShootingPlayer.h"

ShootingPlayer::ShootingPlayer()
{
	texture = LoadGraph("Resources/test.png");

}

void ShootingPlayer::Update()
{
	GetHitKeyStateAll(key);
	Move();

	for (int i = 0; i < 256; i++) {
		oldkey[i] = key[i];
	}
}

void ShootingPlayer::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);

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
		playerbullet.push_back(new PlayerBullet(static_cast<float>(x), static_cast<float>(y)));
	}
}

void ShootingPlayer::DeleteBullet()
{
	for (auto itr = playerbullet.begin(); itr != playerbullet.end();) {
		if ((*itr)->GetBulletX() > 720) {
			itr = playerbullet.erase(itr);
		}
		else
		{
			++itr;
		}
	}
}
