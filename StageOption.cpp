#include "StageOption.h"

void StageOption::Initialize()
{
	srand((unsigned int)time(NULL));
	if (rand() % 2 == 0)
	{
		ExitStair = 1;
		EntranceStair = 0;
	}
	else
	{
		ExitStair = 0;
		EntranceStair = 1;
	}

}

void StageOption::Update(Player* _player)
{
	if (_player->GetInteract() == true)
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
}

void StageOption::Judge(Player* _player)
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
	_player->SetInteract(false);

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

void StageOption::Draw(Player* _player)
{
	DrawFormatString(0, 60, GetColor(255, 255, 255), "floor:%d", floor);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "Entrance:%d", EntranceStair);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Exit:%d", ExitStair);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "%d", _player->GetInteract());
}
