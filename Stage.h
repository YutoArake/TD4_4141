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
	void Reset();
};

