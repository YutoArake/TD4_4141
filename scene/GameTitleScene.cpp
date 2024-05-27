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
	// �V�[���؂�ւ�
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		time++;
		GameTransition();

		// �Q�[���Z���N�g�V�[����
		SceneManager::GetInstance()->ChangeScene("SELECT");

		
		return;
	}
}

void GameTitleScene::GameTransition()
{
	x = 1 * time * time * (50 - 0);
}

void GameTitleScene::Draw()
{
	DrawGraph(x, 0, titleGraph, FALSE);
}


