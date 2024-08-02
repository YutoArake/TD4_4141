#include "MiniGame.h"
#include <fstream>
#include <cassert>

void MiniGame::Initialize()
{
	blocks[0] = LoadGraph("Resource/blocks/block.png");
	blocks[1] = LoadGraph("Resource/blocks/brick.png");
	blocks[2] = LoadGraph("Resource/blocks/broken.png");
	blocks[3] = LoadGraph("Resource/blocks/fall.png");
	blocks[4] = LoadGraph("Resource/blocks/ice.png");
	blocks[5] = LoadGraph("Resource/blocks/sushi1.png");
	blocks[6] = LoadGraph("Resource/blocks/sushi2.png");
	blocks[7] = LoadGraph("Resource/blocks/sushi3.png");
	blocks[8] = LoadGraph("Resource/blocks/sushi4.png");
}

void MiniGame::Update(char keys[256], char oldkeys[256], Player* p, int& isMiniGame)
{
	int x = p->GetPosX(), y = p->GetPosY();

	mapNumX = x / Size;
	mapNumY = y / Size;

	if (miniGame[mapNumY][mapNumX] == 6 ||
		miniGame[mapNumY][mapNumX] == 7 ||
		miniGame[mapNumY][mapNumX] == 8 ||
		miniGame[mapNumY][mapNumX] == 9) {
		miniGame[mapNumY][mapNumX] = 0;
	}

	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 20; x++) {
			if (miniGame[y][x] == 6 ||
				miniGame[y][x] == 7 ||
				miniGame[y][x] == 8 ||
				miniGame[y][x] == 9) {
				return;
			}
		}
	}

	p->SetPosX(Size * 10);
	p->SetPosY(Size * 7);
	isMiniGame = 0;
}

void MiniGame::Draw()
{
	for (int y = 0; y < MapY; y++) {
		for (int x = 0; x < MapX; x++) {
			if (miniGame[y][x] == 0) {
				continue;
			}
			else if (miniGame[y][x] == 1) {
				DrawGraph(x * Size, y * Size, blocks[0], false);
			}
			else if (miniGame[y][x] == 2) {
				DrawGraph(x * Size, y * Size, blocks[1], false);
			}
			else if (miniGame[y][x] == 3) {
				DrawGraph(x * Size, y * Size, blocks[2], false);
			}
			else if (miniGame[y][x] == 4) {
				DrawGraph(x * Size, y * Size, blocks[3], false);
			}
			else if (miniGame[y][x] == 5) {
				DrawGraph(x * Size, y * Size, blocks[4], false);
			}
			else if (miniGame[y][x] == 6) {
				DrawGraph(x * Size, y * Size, blocks[5], false);
			}
			else if (miniGame[y][x] == 7) {
				DrawGraph(x * Size, y * Size, blocks[6], false);
			}
			else if (miniGame[y][x] == 8) {
				DrawGraph(x * Size, y * Size, blocks[7], false);
			}
			else if (miniGame[y][x] == 9) {
				DrawGraph(x * Size, y * Size, blocks[8], false);
			}
		}
	}
}

void MiniGame::LoadGameMap(int stageNum, Player* p)
{
	// �o�b�t�@���N���A
	stageCommands_.str("");
	// ��Ԃ��N���A
	stageCommands_.clear(std::stringstream::goodbit);

	// �}�b�v�����[�h
	LoadStageFile(stageNum);
	LoadStageCommands();
}

void MiniGame::LoadStageFile(int stageNum)
{
	// �t�@�C��
	std::ifstream file;
	// �p�X���擾
	std::string mapNum;
	mapNum = std::to_string(stageNum);
	const std::string mapFolder = "stages/";
	const std::string filename = "stage" + mapNum + ".txt";
	const std::string directoryPath = "Resource/" + mapFolder + filename;
	// �t�@�C�����J��
	file.open(directoryPath);
	assert(file.is_open());
	// �t�@�C���̓��e�𕶎���X�g���[���ɃR�s�[
	stageCommands_ << file.rdbuf();
	// �t�@�C�������
	file.close();
}

void MiniGame::LoadStageCommands()
{
	// 1�s���̕����������ϐ�
	std::string line;
	int x = 0, y = 0;

	// �R�}���h���s���[�v
	while (getline(stageCommands_, line)) {
		// 1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
		std::istringstream line_stream(line);
		// ������
		std::string word;

		// �R���}��؂�ōs�̐擪��������擾
		while (getline(line_stream, word, ',')) {
			// ��
			if (word.find("0") == 0) {
				miniGame[y][x] = 0;
			}
			// �u���b�N
			else if (word.find("1") == 0) {
				miniGame[y][x] = 1;
			}
			// �����K�u���b�N
			else if (word.find("2") == 0) {
				miniGame[y][x] = 2;
			}
			// �Ђъ��ꃌ���K
			else if (word.find("3") == 0) {
				miniGame[y][x] = 3;
			}
			// ������u���b�N
			else if (word.find("4") == 0) {
				miniGame[y][x] = 4;
			}
			// ���ׂ�u���b�N
			else if (word.find("5") == 0) {
				miniGame[y][x] = 5;
			}
			// ����I�u�W�F�N�g�i���i�F�}�O���j
			else if (word.find("6") == 0) {
				miniGame[y][x] = 6;
			}
			// ����I�u�W�F�N�g�i���i�F�C�J�H�j
			else if (word.find("7") == 0) {
				miniGame[y][x] = 7;
			}
			// ����I�u�W�F�N�g�i���i�F�T�[�����j
			else if (word.find("8") == 0) {
				miniGame[y][x] = 8;
			}
			// ����I�u�W�F�N�g�i���i�F���܂��H�j
			else if (word.find("9") == 0) {
				miniGame[y][x] = 9;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
