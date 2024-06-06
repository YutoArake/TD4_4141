#include "GameSelectScene.h"
#include "SceneManager.h"

/// <summary>
/// 静的メンバ変数の実体
/// </summary>

void GameSelectScene::Initialize()
{
	ruleGraph = LoadGraph("Resource/textures/intro.png");
}

void GameSelectScene::Finalize()
{
}

void GameSelectScene::Update(char keys[256] , char oldkeys[256])
{
	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// ゲームプレイシーンへ
		SceneManager::GetInstance()->ChangeScene("PLAY");
		return;
	}
}

void GameSelectScene::GameTransition()
{
}

void GameSelectScene::Draw()
{
	DrawExtendGraph(0, 0, 1280, 960, ruleGraph, true);
}