#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
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
		// �Q�[���N���A�V�[����
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}
}

void GamePlayScene::GameTransition()
{
}

void GamePlayScene::Draw()
{
}
