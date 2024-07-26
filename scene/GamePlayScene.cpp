#include "GamePlayScene.h"
#include "SceneManager.h"
#include "GamePlayScene/Collision.h"

void GamePlayScene::Initialize()
{
	shootingplayer = new ShootingPlayer();

	moblist.push_back(new Shooter(800, 100, 15, 15, shootingplayer));

	moblist.push_back(new HomingShooter(800, 200, 15, 15, shootingplayer));

	moblist.push_back(new LaserShooter(800, 300, 15, 15, shootingplayer));

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

	AllUpdate();
}

void GamePlayScene::Draw()
{
	for (auto mobitr = moblist.begin(); mobitr != moblist.end(); ++mobitr) {
		(*mobitr)->Draw();
	}

	shootingplayer->Draw();
}

void GamePlayScene::AllUpdate()
{
	for (auto mobitr = moblist.begin(); mobitr != moblist.end(); ++mobitr) {
		(*mobitr)->Update();
	}
	shootingplayer->Update();
}


