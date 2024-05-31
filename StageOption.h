#pragma once
#include "Player.h"
#include "Stage.h"
#include <stdlib.h>
#include <time.h>

class StageOption
{
public:
	// ������
	void Initialize();

	// �X�V
	void Update(Player* _player);

	// �X�V
	void Judge(Player* _player);

	void FloorReset();

	void ClimbTheStairs();
	// �`��
	void Draw(Player* _player);

private:

	int floor = 0;
	bool isCorrect = 0;
	bool isInCorrect = 0;

	int EntranceStair = 0;
	int ExitStair = 0;
};

