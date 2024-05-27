#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
	titleGraph = LoadGraph("Resource/gorushi.png");
}

void GameTitleScene::Finalize()
{
}

void GameTitleScene::Update(char keys[256], char oldkeys[256])
{
	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		time++;
		GameTransition();

		// ゲームセレクトシーンへ
		SceneManager::GetInstance()->ChangeScene("SELECT");

		
		return;
	}
}

void GameTitleScene::GameTransition()
{
	x = 1 * time * time * (50 - 0);
}

void GameTitleScene::Draw()
{
	DrawGraph(x, 0, titleGraph, FALSE);
}


