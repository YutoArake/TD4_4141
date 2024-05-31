#include "Stage.h"
#include "DxLib.h"
#include <fstream>
#include <cassert>

void Stage::Initialize()
{
	// �o�b�t�@���N���A
	stageCommands_.str("");
	// ��Ԃ��N���A
	stageCommands_.clear(std::stringstream::goodbit);

	// �}�b�v�����[�h
	LoadStageFile(1);
	LoadStageCommands();

	// �摜�ǂݍ���
	mapGraph = LoadGraph("Resource/textures/road.png");
	post1Graph = LoadGraph("Resource/textures/poster1.png");
	post2Graph = LoadGraph("Resource/textures/poster2.png");
	post3Graph = LoadGraph("Resource/textures/poster3.png");
	post4Graph = LoadGraph("Resource/textures/poster4.png");
	doorGraph = LoadGraph("Resource/textures/door.png");
	prantGraph = LoadGraph("Resource/textures/prant.png");
	machineGraph = LoadGraph("Resource/textures/machine.png");
	fireExtinGraph = LoadGraph("Resource/textures/fireExtin.png");

	scrollX = 0;
}

void Stage::Update(char keys[256], char oldkeys[256], Player* p)
{
	// �v���C���[���W����X�N���[�����W���v�Z����
	if (p->GetPosX() >= 640 && scrollX < 1960 && keys[KEY_INPUT_D]) {
		scrollX += 5;
		p->SetPosX(640);
	}
	if (p->GetPosX() <= 640 && scrollX > 0 && keys[KEY_INPUT_A]) {
		scrollX -= 5;
		p->SetPosX(640);
	}
}

void Stage::Draw()
{
	DrawExtendGraph(0 - scrollX, 0, 3239 - scrollX, 959, mapGraph, FALSE);
}

void Stage::Reset(Player* p)
{

	scrollX = 0;
}

void Stage::LoadStageFile(int stageNum)
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

void Stage::LoadStageCommands()
{
	// 1�s���̕����������ϐ�
	std::string line;

	// �R�}���h���s���[�v
	while (getline(stageCommands_, line)) {
		// 1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
		std::istringstream line_stream(line);
		// ������
		std::string word;

		// �R���}��؂�ōs�̐擪��������擾
		while (getline(line_stream, word, ',')) {
			// 
			if (word.find("0") == 0) {
			}
			// 
			else if (word.find("1") == 0) {
			}
			// 
			else if (word.find("2") == 0) {
			}
		}
	}
}