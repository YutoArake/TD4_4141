#include "StageOption.h"
#include <random>

std::random_device rnd;		// 非決定的な乱数生成器を生成
std::mt19937 mt(rnd());	//  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
std::uniform_int_distribution<> rand7(0, 6);	// [0, 6] 範囲の一様乱数

int StageOption::InitializeFloor()
{
	// 乱数保持
	int stageNum = rand7(mt);

	// 通常か異変か(0が通常)
	if (stageNum == 0)
	{
		ExitStair = 1;
		EntranceStair = 0;
	}
	else if (isFirstFloor == true)
	{
		stageNum = 0;
		ExitStair = 1;
		EntranceStair = 0;
		isFirstFloor = false;
	}
	else
	{
		ExitStair = 0;
		EntranceStair = 1;
	}

	// ステージ番号を返す
	return stageNum;
}

void StageOption::Update(Player* _player)
{
	if (_player->GetMoveFloor() == true)
	{

		Judge(_player);
		
	}
	if (isInCorrect == true)
	{
		FloorReset();
	}

	if (isCorrect == true)
	{
		ClimbTheStairs();
	}
	if (miniGameFlag == 1)
	{
		_player->SetIsMiniGame(miniGameFlag);
	}
}

void StageOption::Judge(Player* _player)
{
	if (_player->GetIsResetOnce() == 1)
	{
		if (_player->GetisEntranceStair() == true && EntranceStair == 1 ||
			_player->GetisExitStair() == true && ExitStair == 1)
		{
			isCorrect = true;
			
		}
		else
		{
			isInCorrect = true;
		}
		_player->SetisEntranceStair(false);
		_player->SetisExitStair(false);
		_player->SetIsResetOnce(2);
	}

}

void StageOption::FloorReset()
{
	floor = 0;
	isInCorrect = false;
}

void StageOption::ClimbTheStairs()
{
	floor++;
	isCorrect = false;
}

void StageOption::Draw()
{
	DrawFormatString(0, 60, GetColor(255, 255, 255), "floor:%d", floor);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "Entrance:%d", EntranceStair);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Exit:%d", ExitStair);
}

bool StageOption::IsClear()
{
	if (floor == 8)
	{
		return true;
	}
	return false;
}
