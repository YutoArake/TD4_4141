#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	player = new Player();
	player->Initialize();

	backgroundlist.push_back(new Background("a", 0, 0));

}

void GamePlayScene::Finalize()
{
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_ESCAPE] == true && oldkeys[KEY_INPUT_ESCAPE] == false) {
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}

	if (isClear) {
		// ゲームクリアシーンへ
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}

	if (keys[KEY_INPUT_D] == 1) {
		player->MoveRight();
	}

	if (keys[KEY_INPUT_A] == 1) {
		player->MoveLeft();
	}

	player->Update();

}

void GamePlayScene::Draw()
{
	player->Draw();
}
