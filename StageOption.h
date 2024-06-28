#pragma once
#include "Player.h"

class StageOption
{
public:
	// �K�w������
	int InitializeFloor();

	// �X�V
	void Update(Player* _player);

	// �X�V
	void Judge(Player* _player);

	void FloorReset();

	void ClimbTheStairs();

	// �`��
	void Draw();

	bool IsClear();

	int GetFloor() {
		return floor;
	}

private:
	// �K�w
	int floor = 0;
	// ������
	bool isCorrect = 0;
	// �������Ȃ�
	bool isInCorrect = 0;

	// �����i��O�K�i�j
	int EntranceStair = 0;
	// �o���i�����K�i�j
	int ExitStair = 0;
};

