#include "Player.h"
#include "DxLib.h"



Player::Player()
{

}

void Player::Initialize()
{
	//Texture = LoadGraph("Resource/ ");


}

void Player::Update()
{
	if (injump == true) {
		JumpProcess();
	}
	Fall();
}

void Player::Draw()
{
	DrawBox(x - sizeX, y - sizeY, x + sizeX, y + sizeY, GetColor(255, 255, 255), true);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", gravity);
}

void Player::MoveRight()
{
	x += movementX;
}

void Player::MoveLeft()
{
	x -= movementX;
}



void Player::Fall()
{
	int fallresult;
	fallresult = movementY * gravity;
	y += fallresult;
	gravity += 1;
}

void Player::ResetGravity()
{
	gravity = 5;
}

void Player::JumpProcess()
{
	int jumpresultPower = 0;
	if (onground == false) {
		jumpresultPower = movementY * jumpPower * gravity;
		if (downForce == false) {
			y -= jumpresultPower;
			gravity -= 1;
		}
		if (downForce == true) {
			y += jumpresultPower;
			gravity += 2;
		}


		if (gravity <= 1) {
			downForce = true;
		}
	}

	if (onground == true) {
		gravity = 3/*atode*/;
		injump = false;
	}
}
