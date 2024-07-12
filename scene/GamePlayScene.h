#pragma once
#include "BaseScene.h"
#include "GamePlayScene/Background.h"
#include "GamePlayScene/Object.h"
#include "GamePlayScene/Mob.h"
#include "GamePlayScene/TestMob.h"
#include "GamePlayScene/ShootingPlayer.h"
#include <list>

/// <summary>
/// �Q�[���v���C�V�[��
/// </summary>

class GamePlayScene : public BaseScene
{
private: // �����o�ϐ�
	bool isClear = false;

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
	///  �`��
	/// </summary>
	void Draw() override;

	void AllUpdate();

private:


	std::list <Mob*> moblist;

	ShootingPlayer* shootingplayer;

};