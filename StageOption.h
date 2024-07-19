#pragma once
#include "Player.h"

class StageOption
{
public:
	// 階層初期化
	int InitializeFloor();

	// 更新
	void Update(Player* _player);

	// 更新
	void Judge(Player* _player);

	void FloorReset();

	void ClimbTheStairs();

	// 描画
	void Draw();

	bool IsClear();

	int GetFloor() {
		return floor;
	}

	int GetMiniGameFlag() {
		return miniGameFlag;
	}

	void SetMiniGameFlag(int _miniGameFlag)
	{
		this->miniGameFlag = _miniGameFlag;
	}


private:
	// 階層
	int floor = 0;
	// 正しい
	bool isCorrect = 0;
	// 正しくない
	bool isInCorrect = 0;

	// 入口（手前階段）
	int EntranceStair = 0;
	// 出口（奥側階段）
	int ExitStair = 0;

	bool isFirstFloor = true;

	int miniGameFlag = 0;
};

