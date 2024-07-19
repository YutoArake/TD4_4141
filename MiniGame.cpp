#include "MiniGame.h"
#include <fstream>
#include <cassert>

void MiniGame::Initialize()
{
	// �o�b�t�@���N���A
	stageCommands_.str("");
	// ��Ԃ��N���A
	stageCommands_.clear(std::stringstream::goodbit);

	// �}�b�v�����[�h
	LoadStageFile(1);
	LoadStageCommands();

	blocks[0] = LoadGraph("Resource/blocks/block.png");
	blocks[1] = LoadGraph("Resource/blocks/brick.png");
	blocks[2] = LoadGraph("Resource/blocks/broken.png");
	blocks[3] = LoadGraph("Resource/blocks/ice.png");
	blocks[4] = LoadGraph("Resource/blocks/fall.png");
}

void MiniGame::Update(char keys[256], char oldkeys[256], Player* p, bool& isClear)
{

}

void MiniGame::Draw()
{
	for (int y = 0; y < MapY; y++) {
		for (int x = 0; x < MapX; x++) {
			if (miniGame[y][x] == 1) {
				DrawGraph(x * Size, y * Size, blocks[0], false);
			}
		}
	}
}

void MiniGame::Reset(int stageNum)
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
			// ����I�u�W�F�N�g�i���i�j
			else if (word.find("2") == 0) {
				miniGame[y][x] = 2;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
