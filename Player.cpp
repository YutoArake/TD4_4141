#include "Player.h"


void Player::initialize()
{
	x = 100;
	y = 600;
	LoadDivGraph("Resource/player/playerFront.png",11,11,1,1114,1114,playerFrontGraph);
	LoadDivGraph("Resource/player/playerLeft.png", 11, 11, 1, 1114, 1114, playerLeftGraph);
	LoadDivGraph("Resource/player/playerRight.png", 11, 11, 1, 1114, 1114, playerRightGraph);
	LoadDivGraph("Resource/player/playerBack.png", 11, 11, 1, 1114, 1114, playerBackGraph);
	playerMiniGraph[0] = LoadGraph("Resource/player/miniGameRight.png", true);
	playerMiniGraph[1] = LoadGraph("Resource/player/miniGameLeft.png", true);
}

void Player::Update(char keys[256], char oldkeys[256])
{
	// ミニゲームなら
	if (isMiniGame == true) {
		// ジャンプ中なら
		if (isJumpAction == true)
		{
			Jump(keys, oldkeys);
			JumpUpdate();
		}

		// プレイヤーの移動
		Move(keys, oldkeys);

		// ミニゲームの更新が終わったら抜ける
		return;
	}

	// 階層移動の判定
	MoveFloor(keys, oldkeys);

	// プレイヤーの移動
	Move(keys, oldkeys);
	// 移動範囲指定
	KeepOut();
	// アニメーション
	Animation();
}

void Player::Move(char keys[256], char oldkeys[256])
{
	// 前フレームの座標保持
	oldX = x;
	oldY = y;
	
	// ジャンプ中じゃないかつ、ミニゲーム中でもないなら
	if (isMiniGame == false)
	{
		if (keys[KEY_INPUT_W] == true)
		{
			y -= moveSpeed;
			playerDirection = 2;
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

	if (keys[KEY_INPUT_J] == true && oldkeys[KEY_INPUT_J] == false)
	{
		isJumpAction = !isJumpAction;
	}
}

void Player::KeepOut()
{
	if (isMiniGame == false)
	{
		//進入禁止エリア
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
		//進入禁止エリアここまで
	}
}

void Player::Animation()
{
	//ダッシュ時ならアニメーションを倍の速さで動かす
	if (isDash == true)
	{
		animateTimer += 2;
	}
	else
	{
		animateTimer++;
	}
	//アニメタイマーが一定の値以上でアニメタイマーをリセット、アニメーションを進行させる
	if (animateTimer >= 5)
	{
		animateTimer = 0;
		playerWalkAnime++;
	}

	//アニメーションが11以降で0にリセット
	if (playerWalkAnime == 11)
	{
		playerWalkAnime = 0;
	}

	//移動が無ければアニメーションを止める
	if (x - oldX == 0 && y - oldY == 0)
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

	if (y > BLOCK_SIZE * 14 - radius)
	{
		y = BLOCK_SIZE *14 - radius;
		vel = 0;
		canJump = true;
	}
}

void Player::MoveFloor(char keys[256], char oldkeys[256])
{

	if (x >= 795 && x <= 1050)
	{
		if (y <= 0)
		{
			x = 214;
			y = 500;

			isMoveFloor = true;
			isExitStair = true;
		}
	}

	//階段入口に移動すると判定が行われる
	if (x >= 90 && x <= 340)
	{
		if (y >= 940)
		{
			isMoveFloor = true;
			isEntranceStair = true;
			y = 500;
		}
	}
}



void Player::Draw()
{
	if (isMiniGame == true) {
		switch (playerDirection)
		{
		case 3:
			DrawExtendGraph(x - 31, y - 31, x + 31, y + 31, playerMiniGraph[1], true);
			break;
		case 4:
			DrawExtendGraph(x - 31, y - 31, x + 31, y + 31, playerMiniGraph[0], true);
			break;
		}
		return;
	}


	//プレイヤーの向き(1＝前、2＝後ろ、3＝左、4＝右)
	switch (playerDirection)
	{
	case 1:
		DrawExtendGraph(x - 85, y - 85, x + 115, y + 115, playerFrontGraph[playerWalkAnime], TRUE);
		break;

	case 2:
		DrawExtendGraph(x - 85, y - 85, x + 115, y + 115, playerBackGraph[playerWalkAnime], TRUE);
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
}

void Player::Reset()
{
	x = 0;
	y = 600;
}


