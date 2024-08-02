#pragma once
#include "Player.h"
#include <sstream>

class MiniGame
{
private:
	const int MapX = 20;
	const int MapY = 15;
	const int Size = 64;

	int mapNumX, mapNumY;

	int radius = 32;

	// �t�@�C���R�}���h
	std::stringstream stageCommands_;

	int miniGame[15][20] = { 0 };

	int blocks[9] = { 0 };
public:
	// ������
	void Initialize();

	// �X�V
	void Update(char keys[256], char oldkeys[256], Player* p, int& isMiniGame);

	// �`��
	void Draw();

	// ���Z�b�g
	void LoadGameMap(int stageNum, Player* p);

	// �X�e�[�W���[�h
	void LoadStageFile(int stageNum);

	// �R�}���h�ǂݍ���
	void LoadStageCommands();
};
