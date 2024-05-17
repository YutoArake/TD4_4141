#include "Player.h"
#include "DxLib.h"



void Player::Initialize()
{
	Texture = LoadGraph("Resource/ ");

	jumpSetting.jumpPower = 0;
	jumpSetting.gravity = 0;
	jumpSetting.downForce = true;
	jumpSetting.jumpdetection = false;
}

void Player::Update()
{
	JumpProcess();
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
	x -= movementX;
}

void Player::Jump()
{
	ToggleJumpDetection();
}

void Player::JumpProcess()
{
	int jumpresultPower = 0;
	if (jumpSetting.jumpdetection == true) {
		jumpresultPower = movementY * jumpSetting.jumpPower * jumpSetting.gravity;
		y -= jumpresultPower;
		jumpSetting.gravity /= 2;
	}
}
