#include "GameClearScene.h"
#include "SceneManager.h"

void GameClearScene::Initialize()
{
	clearGraph = LoadGraph("Resource/textures/clear.png");
}

void GameClearScene::Finalize()
{
}

void GameClearScene::Update(char keys[256], char oldkeys[256])
{
	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		SceneManager::GetInstance()->ChangeScene("TITLE");
		return;
	}
}

void GameClearScene::GameTransition()
{
}

void GameClearScene::Draw()
{
	DrawExtendGraph(0, 0, 1280, 960, clearGraph, false);
}