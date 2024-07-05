#include "Player.h"

void Player::initialize()
{
	x = 100;
	y = 600;
	LoadDivGraph("Resource/player/playerFront.png",11,11,1,1114,1114,playerFrontGraph);
	LoadDivGraph("Resource/player/playerLeft.png", 11, 11, 1, 1114, 1114, playerLeftGraph);
	LoadDivGraph("Resource/player/playerRight.png", 11, 11, 1, 1114, 1114, playerRightGraph);
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
			playerDirection = 1;
		}
	}
	


	if (keys[KEY_INPUT_D] == true)
	{
		playerDirection = 4;
		x += moveSpeed;
		
	}

	if (keys[KEY_INPUT_A] == true)
	{
		playerDirection = 3;
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

	//�_�b�V�����Ȃ�A�j���[�V������{�̑����œ�����
	if (isDash == true)
	{
		animateTimer += 2;
	}
	else
	{
		animateTimer++;
	}
	//�A�j���^�C�}�[�����̒l�ȏ�ŃA�j���^�C�}�[�����Z�b�g�A�A�j���[�V������i�s������
	if (animateTimer >= 5)
	{
		animateTimer = 0;
		playerWalkAnime++;
	}

	//�A�j���[�V������11�ȍ~��0�Ƀ��Z�b�g
	if (playerWalkAnime == 11)
	{
		playerWalkAnime = 0;
	}
	if (keys[KEY_INPUT_J] == true && oldkeys[KEY_INPUT_J] == false)
	{
		isJumpAction = !isJumpAction;
	}

	//�i���֎~�G���A
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
		if (y > 585)
		{
			x = oldX;
			y = oldY;
		}
	}
	//�i���֎~�G���A�����܂�

	//�K�i�����Ɉړ�����Ɣ��肪�s����
	if (x >= 90 && x <= 340)
	{
		if (y >= 940)
		{
			isInteract = true;
			isEntranceStair = true;
			y = 500;
		}
	}

	//�ړ���������΃A�j���[�V�������~�߂�
	if (x - oldX == 0 &&  y - oldY == 0)
	{
		playerWalkAnime = 0;
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
	//�v���C���[�̌���(1���O�A2�����A3�����A4���E)
	switch (playerDirection)
	{
	case 1:
		DrawExtendGraph(x - 85, y - 85, x + 115, y + 115, playerFrontGraph[playerWalkAnime], TRUE);
		break;

	case 2:
		break;

	case 3:
		DrawExtendGraph(x - 85, y - 85, x + 115, y + 115, playerLeftGraph[playerWalkAnime], TRUE);
		break;

	case 4:
		DrawExtendGraph(x - 85, y - 85, x + 115, y + 115, playerRightGraph[playerWalkAnime], TRUE);
		break;

	default:
		break;

	}
	
	DrawBox(x, y, x + 31, y + 31, GetColor(255, 255, 255), TRUE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d,%d", x, y);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "animateTimer:%d",playerWalkAnime);
	/*DrawRotaGraph(300, 300,
		1.0, 3.141592 /180 * x,
		playerGraph, false);*/
}

void Player::Reset()
{
	x = 0;
	y = 600;
}


