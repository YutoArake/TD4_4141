#include "Stage.h"
#include "DxLib.h"

void Stage::Initialize()
{
	// �摜�ǂݍ���
	mapGraph = LoadGraph("Resource/textures/road.png");
	scrollX = 0;
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
	DrawExtendGraph(0 - scrollX, 0, 3239 - scrollX, 959, mapGraph, FALSE);
	
}

void Stage::Reset(Player* p)
{
	scrollX = 0;
}
