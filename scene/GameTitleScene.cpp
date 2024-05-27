#include "GameTitleScene.h"
#include "SceneManager.h"


void GameTitleScene::Initialize()
{
	titleGraph = LoadGraph("Resource/Title.png");
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
	x = 1 * time * time * (50 - 0);
}

void GameTitleScene::Draw()
{
	DrawExtendGraph(
		x,
		0,
		x + 1279,
		0 + 799,
		titleGraph,
		FALSE
	);
	menu.Menu_Draw();
}


