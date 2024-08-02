#pragma once
#include "DxLib.h"
#include<math.h>

class Player
{

public: //�����o�֐�

	//�v���C���[������
	void initialize();

	//�v���C���[�X�V
	void Update(char keys[256], char oldkeys[256]);

	//�v���C���[�`��
	void Draw();

	// �v���C���[���Z�b�g
	void Reset();

	int GetPosX() { return x; }
	void SetPosX(int _posX) { x = _posX; }

	int GetPosY() { return y; }
	void SetPosY(int _posY) { y = _posY; }

	int GetMoveSpeed() { return moveSpeed; }

	bool GetMoveFloor() { return isMoveFloor; }
	void SetMoveFloor(bool _MoveFloor) { this->isMoveFloor = _MoveFloor; }

	bool GetisEntranceStair() { return isEntranceStair; }
	void SetisEntranceStair(bool _isEntranceStair) { this->isEntranceStair = _isEntranceStair; }

	bool GetisExitStair() { return isExitStair; }
	void SetisExitStair(bool _isExitStair) { this->isExitStair = _isExitStair; }

	void SetIsMiniGame(bool _isMiniGame) {
		this->isMiniGame = _isMiniGame;
	}

	void SetMoveSpeed(int _moveSpeed) {
		this->moveSpeed = _moveSpeed;
	}

private: //�����o�֐�

	//�ړ��֐�
	void Move(char keys[256], char oldkeys[256]);

	//�ړ��֎~�G���A�֐�
	void KeepOut();

	//�A�j���[�V�����֐�
	void Animation();

	//�W�����v�֐�
	void Jump(char keys[256], char oldkeys[256]);
	//�W�����v�X�V�֐�
	void JumpUpdate();

	//�v���C���[�̃A�N�V����
	void MoveFloor(char keys[256], char oldkeys[256]);


private: //�����o�ϐ�
	int x = 0;				//x���W
	int y = 0;				//y���W

	int radius = 32;

	int oldX = 0;
	int oldY = 0;
	int playerFrontGraph[11];		//�v���C���[�摜
	int playerLeftGraph[11];
	int playerRightGraph[11];
	int playerBackGraph[11];
	int playerMiniGraph[2];

	int playerDirection = 2;
	bool canJump = false;	//�v���C���[���n�ʂɂ��邩
	bool isAction = false;	//�v���C���[���A�N�V�������N�����Ă��邩
	int moveSpeed = 6;		//�ړ��X�s�[�h�ݒ�ϐ�
	int walkSpeed = 6;		//�����̃X�s�[�h
	int dashSpeed = 10;		//����̃X�s�[�h
	int vel = 0;
	int acc = 1;
	int animateTimer = 0;
	int playerWalkAnime = 0;

	bool isJumpAction = false;

	bool isDash = false;

	bool isMoveFloor = false;

	bool isEntranceStair = false;

	bool isExitStair = false;

	bool isMiniGame = false;

	const int BLOCK_SIZE = 64;
};

