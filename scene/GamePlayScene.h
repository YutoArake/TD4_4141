#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Stage.h"

/// <summary>
/// �Q�[���v���C�V�[��
/// </summary>
class GamePlayScene : public BaseScene
{
private: // �����o�ϐ�
	bool isClear = false;

	float flameTime = 0.0f;

	float maxTime = 0.0f;

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// �I������
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// ���t���[���X�V
	/// </summary>
	void Update(char keys[256], char oldkeys[256]) override;

	/// <summary>
	///  �V�[���J��
	/// </summary>
	void GameTransition() override;
	/// <summary>
	///  �`��
	/// </summary>
	void Draw() override;

private:
	Player* player;
	Stage stage;
};