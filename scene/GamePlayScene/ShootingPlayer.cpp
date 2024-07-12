#include "ShootingPlayer.h"

ShootingPlayer::ShootingPlayer()
{
	texture = LoadGraph("Resources/test.png");
}

void ShootingPlayer::Update()
{
	Move();
}

void ShootingPlayer::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);

}

void ShootingPlayer::Move()
{
	char key[256];

	GetHitKeyStateAll(key);

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
