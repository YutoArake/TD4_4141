#include "Stage.h"
#include "DxLib.h"
#include <fstream>
#include <cassert>
#include <random>

std::random_device rnd;		// �񌈒�I�ȗ���������𐶐�
std::mt19937 mt(rnd());	//  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
std::uniform_int_distribution<> rand5(0, 4);	// [0, 4] �͈͂̈�l����

//rand5(mt)

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
	mapGraph[0] = LoadGraph("Resource/textures/sample1.png");
	mapGraph[1] = LoadGraph("Resource/textures/sample2.png");
	mapGraph[2] = LoadGraph("Resource/textures/sample3.png");
	mapGraph[3] = LoadGraph("Resource/textures/sample4.png");
	mapGraph[4] = LoadGraph("Resource/textures/sample5.png");
	post1Graph = LoadGraph("Resource/textures/poster1.png");
	post2Graph = LoadGraph("Resource/textures/poster2.png");
	post3Graph = LoadGraph("Resource/textures/poster3.png");
	post4Graph = LoadGraph("Resource/textures/poster4.png");
	doorGraph = LoadGraph("Resource/textures/door.png");
	prantGraph = LoadGraph("Resource/textures/prant.png");
	machineGraph = LoadGraph("Resource/textures/machine.png");
	fireExtinGraph = LoadGraph("Resource/textures/fireExtin.png");

	scrollX = 0;
	stageNum = 0;
}

void Stage::Update(char keys[256], char oldkeys[256], Player* p)
{
	// �v���C���[���W����X�N���[�����W���v�Z����
	if (p->GetPosX() >= 640 && scrollX < 1960 && keys[KEY_INPUT_D]) {
		scrollX += p->GetMoveSpeed();
		p->SetPosX(640);
	}
	if (p->GetPosX() <= 640 && scrollX > 0 && keys[KEY_INPUT_A]) {
		scrollX -= p->GetMoveSpeed();
		p->SetPosX(640);
	}
	
}

void Stage::Draw()
{
	DrawExtendGraph(0 - scrollX, 0, 3239 - scrollX, 959, mapGraph[stageNum], FALSE);
	
}

void Stage::Reset(Player* p)
{
	stageNum = rand5(mt);
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