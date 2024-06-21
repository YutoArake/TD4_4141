#include "GamePlayScene.h"
#include "SceneManager.h"
#include "GamePlayScene/Collision.h"

void GamePlayScene::Initialize()
{
	player = new Player("aaaa");


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

	AllUpdate();
}

void GamePlayScene::Draw()
{
	for (auto backgrounditr = backgroundlist.begin(); backgrounditr != backgroundlist.end(); ++backgrounditr) {
		(*backgrounditr)->Draw();
	}

	for (auto objectitr = objectlist.begin(); objectitr != objectlist.end(); ++objectitr) {
		(*objectitr)->Draw();
	}

	for (auto mobitr = moblist.begin(); mobitr != moblist.end(); ++mobitr) {
		(*mobitr)->Draw();
	}

	player->Draw();
}

void GamePlayScene::AllUpdate()
{
	for (auto backgrounditr = backgroundlist.begin(); backgrounditr != backgroundlist.end(); ++backgrounditr) {
		(*backgrounditr)->Update();
	}

	for (auto objectitr = objectlist.begin(); objectitr != objectlist.end(); ++objectitr) {
		(*objectitr)->Update();
	}

	for (auto mobitr = moblist.begin(); mobitr != moblist.end(); ++mobitr) {
		(*mobitr)->Update();
	}

	player->Update();
}
