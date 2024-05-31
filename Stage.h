#pragma once
#include "Player.h"
/// <summary>
/// 
/// </summary>
class Stage
{
private:
	// �}�b�v�摜
	int mapGraph = 0;
	// ����
	int post1Graph = 0;
	int post2Graph = 0;
	int post3Graph = 0;
	int post4Graph = 0;
	int doorGraph = 0;
	int prantGraph = 0;
	int machineGraph = 0;
	int fireExtinGraph = 0;

	// �X�N���[�����W
	int scrollX = 0;

public:
	// ������
	void Initialize();

	// �X�V
	void Update(char keys[256], char oldkeys[256], Player* p);

	// �`��
	void Draw();

	// ���Z�b�g
	void Reset(Player* p);
};

