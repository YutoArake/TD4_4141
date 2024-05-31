#pragma once
#include "Player.h"
#include "Stage.h"
#include <stdlib.h>
#include <time.h>

class StageOption
{
public:
	// 初期化
	void Initialize();

	// 更新
	void Update(Player* _player);

	// 更新
	void Judge(Player* _player);

	void FloorReset();

	void ClimbTheStairs();
	// 描画
	void Draw(Player* _player);

private:

	int floor = 0;
	bool isCorrect = 0;
	bool isInCorrect = 0;

	int EntranceStair = 0;
	int ExitStair = 0;
};

