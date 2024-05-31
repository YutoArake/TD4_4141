#include "Stage.h"
#include "DxLib.h"

void Stage::Initialize()
{
	// 画像読み込み
	mapGraph = LoadGraph("Resource/textures/通路.png");
	scrollX = 0;
}

void Stage::Update(char keys[256], char oldkeys[256], Player* p)
{
	// プレイヤー座標からスクロール座標を計算する
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

void Stage::Reset()
{

}
