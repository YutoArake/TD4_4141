#include "Player.h"

void Player::initialize()
{
	x = 0;
	y = 600;
	playerGraph = LoadGraph("Resource/gorushi.png");
}

void Player::Update(char keys[256], char oldkeys[256])
{

	if (isJumpAction == true)
	{
		
		Jump(keys, oldkeys);
		JumpUpdate();
	}
	
	Move(keys, oldkeys);
}

void Player::Move(char keys[256], char oldkeys[256])
{




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

	if (keys[KEY_INPUT_LSHIFT] == true)
	{
		moveSpeed = dashSpeed;
	}
	else
	{
		moveSpeed = walkSpeed;
	}

	if (keys[KEY_INPUT_J] == true && oldkeys[KEY_INPUT_J] == false)
	{
		isJumpAction = !isJumpAction;
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


void Player::Draw()
{
	DrawBox(x, y, x + 31, y + 31, GetColor(255, 255, 255), TRUE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", isJumpAction);
	DrawRotaGraph(300, 300,
		1.0, 3.141592 /180 * x,
		playerGraph, false);
}


