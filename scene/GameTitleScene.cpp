#include "GameTitleScene.h"
#include "SceneManager.h"


void GameTitleScene::Initialize()
{
	titleGraph = LoadGraph("Resource/titles/Title.png");
	titleBackGraph = LoadGraph("Resource/titles/TitleBack.png");
}

void GameTitleScene::Finalize()
{
}

void GameTitleScene::Update(char keys[256], char oldkeys[256])
{
	//// シーン切り替え
	//if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	//{
	//	time++;
	//	GameTransition();

	//	// ゲームセレクトシーンへ
	//	SceneManager::GetInstance()->ChangeScene("SELECT");

	//	
	//	return;
	//}

	menu.Menu_Update(keys,oldkeys);

}

void GameTitleScene::GameTransition()
{
	
}

void GameTitleScene::Draw()
{
	DrawExtendGraph(
		0,
		0,
		1280,
		960,
		titleBackGraph,
		false
	);
	DrawExtendGraph(
		320,
		0,
		960,
		640,
		titleGraph,
		true
	);
	menu.Menu_Draw();
}


