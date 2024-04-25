#include "Player.h"
#include "DxLib.h"

void Player::Initialize()
{
	Texture = LoadGraph("Resource / ");
}

void Player::Update()
{
	MoveRight();
	MoveLeft();
}

void Player::Draw()
{
	DrawBox(x - sizeX, y - sizeY, x + sizeX, y + sizeY, GetColor(255, 255, 255), true);

}

void Player::MoveRight()
{
	x += movementX;
}

void Player::MoveLeft()
{
	x -= movementY;
}
