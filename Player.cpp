#include "Player.h"

void Player::initialize()
{
	x = 100;
	y = 600;
	playerGraph = LoadGraph("Resources/gorushi.png");
}

void Player::Update(char keys[256], char oldkeys[256])
{

	if (isJumpAction == true)
	{

		Jump(keys, oldkeys);
		JumpUpdate();
	}
	Interact(keys, oldkeys);
	Move(keys, oldkeys);
}

void Player::Move(char keys[256], char oldkeys[256])
{
	oldX = x;
	oldY = y;


	if (isJumpAction == false)
	{
		if (keys[KEY_INPUT_W] == true)
		{
			y -= moveSpeed;
		}

		if (keys[KEY_INPUT_S] == true)
		{
			y += moveSpeed;
		}
	}



	if (keys[KEY_INPUT_D] == true)
	{
		x += moveSpeed;
	}

	if (keys[KEY_INPUT_A] == true)
	{
		x -= moveSpeed;
	}

	if (keys[KEY_INPUT_LSHIFT] == true && oldkeys[KEY_INPUT_LSHIFT] == true)
	{
		moveSpeed = dashSpeed;
		isDash = true;
	}
	else
	{
		moveSpeed = walkSpeed;
		isDash = false;
	}

	if (keys[KEY_INPUT_J] == true && oldkeys[KEY_INPUT_J] == false)
	{
		isJumpAction = !isJumpAction;
	}

	if (x < 50) {
		x = 50;
	}
	if (x > 1150) {
		x = 1150;
	}

	if (x < 794 && x >= 50 || x > 1050)
	{
		if (y < 265)
		{
			x = oldX;
			y = oldY;
		}
	}

	if (x < 90 || x > 340)
	{
		if (y > 665)
		{
			x = oldX;
			y = oldY;
		}
	}
}

void Player::Jump(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_SPACE] == true &&
		oldkeys[KEY_INPUT_SPACE] == false)
	{
		if (canJump == true)
		{
			canJump = false;
			vel = -20;
		}

	}
}

void Player::JumpUpdate()
{
	if (canJump == true)
	{
		return;
	}

	vel += acc;
	y += vel;

	if (y > 600)
	{
		y = 600;
		vel = 0;
		canJump = true;
	}
}

void Player::Interact(char keys[256], char oldkeys[256])
{
	if (x >= 88 && y >= 650 && x <= 340 && y <= 665)
	{
		if (keys[KEY_INPUT_F] && oldkeys[KEY_INPUT_F])
		{
			x = 214;
			y = 461;

			isInteract = true;
			isEntranceStair = true;
		}
	}
	if (x >= 770 && y >= 265 && x <= 1070 && y <= 290)
	{
		if (keys[KEY_INPUT_F] && oldkeys[KEY_INPUT_F])
		{
			x = 214;
			y = 461;

			isInteract = true;
			isExitStair = true;
		}
	}
}


void Player::Draw()
{
	DrawBox(x, y, x + 31, y + 31, GetColor(255, 255, 255), TRUE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d,%d", x, y);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "%d", GetInteract());
	/*DrawRotaGraph(300, 300,
		1.0, 3.141592 /180 * x,
		playerGraph, false);*/
}

void Player::Reset()
{
	x = 0;
	y = 600;
}


