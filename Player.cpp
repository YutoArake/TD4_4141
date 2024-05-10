#include "Player.h"

void Player::initialize()
{
	x = 0;
	y = 600;

}

void Player::Update(char keys[256], char oldkeys[256])
{
	Move(keys, oldkeys);
}

void Player::Move(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_A] == true)
	{
		x -= 5;
	}

	if (keys[KEY_INPUT_D] == true)
	{
		x += 5;
	}
}

void Player::Jump(char keys[256], char oldkeys[256])
{

}


void Player::Draw()
{
	DrawBox(x, y, x +31, y + 31, GetColor(255, 255, 255), TRUE);
}


