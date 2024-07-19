#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	player = new Player();
	player->initialize();
	stage.Initialize();

	maxTime = 300;
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
	stage.Update(keys, oldkeys, player, isClear);

	if (stage.GetLoadFloor() == 1)
	{
		flameTime += 4.0f;
	}

	if (flameTime >= maxTime)
	{
		flameTime = 0;
		stage.SetLoadFloor(0);
	}

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
	if (stage.GetLoadFloor() == 1)
	{
		DrawCircle(640, 480, stage.easeInOutBack(200,1000,flameTime / maxTime), GetColor(255, 255, 255), true);
	}
}

