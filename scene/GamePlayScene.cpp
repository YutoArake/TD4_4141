#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	player = new Player();
	player->initialize();
	stage.Initialize();
}

void GamePlayScene::Finalize()
{
	delete player;
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{

	if (keys[KEY_INPUT_ESCAPE] == true && oldkeys[KEY_INPUT_ESCAPE] == false) {
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}

	player->Update(keys,oldkeys);
	stage.Update(keys, oldkeys, player);

	if (isClear) {
		// ゲームクリアシーンへ
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}
}

void GamePlayScene::GameTransition()
{
}

void GamePlayScene::Draw()
{
	stage.Draw();
	player->Draw();
}

