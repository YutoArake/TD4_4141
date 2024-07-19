#pragma once
#include "Player.h"
#include <sstream>

class MiniGame
{
private:
	const int MapX = 20;
	const int MapY = 15;
	const int Size = 64;

	// �t�@�C���R�}���h
	std::stringstream stageCommands_;

	int miniGame[15][20] = { 0 };

	int blocks[5] = { 0 };
public:
	// ������
	void Initialize();

	// �X�V
	void Update(char keys[256], char oldkeys[256], Player* p, bool& isClear);

	// �`��
	void Draw();

	// ���Z�b�g
	void Reset(int stageNum);

	// �X�e�[�W���[�h
	void LoadStageFile(int stageNum);

	// �R�}���h�ǂݍ���
	void LoadStageCommands();
};

