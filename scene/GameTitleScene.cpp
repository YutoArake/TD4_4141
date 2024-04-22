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
		// ゲームセレクトシーンへ
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}
}

void GameTitleScene::GameTransition()
{

}

void GameTitleScene::Draw()
{
	DrawGraph(0, 0, titleGraph, FALSE);
}


