#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
}

void GameTitleScene::Finalize()
{
}

void GameTitleScene::Update(char keys[256], char oldkeys[256])
{
	// �V�[���؂�ւ�
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// �Q�[���Z���N�g�V�[����
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}
}

void GameTitleScene::GameTransition()
{

}

void GameTitleScene::Draw()
{

}


