#pragma once
#include "BaseScene.h"
#include "GamePlayScene/Background.h"
#include "GamePlayScene/Object.h"
#include "GamePlayScene/Mob.h"
#include "GamePlayScene/TestMob.h"
#include "GamePlayScene/ShootingPlayer.h"
#include "GamePlayScene/Shooter.h";
#include "GamePlayScene/HomingShooter.h"

#include "GamePlayScene/LaserShooter.h"
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

	void Collision();


private:
	int phase = 0; //��ԁ@0:�ҋ@ 1:�o����

	int turn = 2; //0:�ʏ� 1:�z�[�~���O 2:���[�U�[

	std::list <Mob*> moblist;

	ShootingPlayer* shootingplayer;

};