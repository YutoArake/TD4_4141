#pragma once
#include "DxLib.h"

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

	bool GetInteract() { return isInteract; }
	void SetInteract(bool _interAct) { this->isInteract = _interAct; }

	bool GetisEntranceStair() { return isEntranceStair; }
	void SetisEntranceStair(bool _isEntranceStair) { this->isEntranceStair = _isEntranceStair; }

	bool GetisExitStair() { return isExitStair; }
	void SetisExitStair(bool _isExitStair) { this->isExitStair = _isExitStair; }


private: //�����o�֐�

	//�ړ��֐�
	void Move(char keys[256], char oldkeys[256]);

	//�W�����v�֐�
	void Jump(char keys[256], char oldkeys[256]);
	//�W�����v�X�V�֐�
	void JumpUpdate();

	//�v���C���[�̃A�N�V����
	void Interact(char keys[256], char oldkeys[256]);

private: //�����o�ϐ�
	int x = 0;				//x���W
	int y = 0;				//y���W
	int oldX = 0;
	int oldY = 0;
	int playerGraph;		//�v���C���[�摜
	bool canJump = false;	//�v���C���[���n�ʂɂ��邩
	bool isAction = false;	//�v���C���[���A�N�V�������N�����Ă��邩
	int moveSpeed = 6;		//�ړ��X�s�[�h�ݒ�ϐ�
	int walkSpeed = 6;		//�����̃X�s�[�h
	int dashSpeed = 10;		//����̃X�s�[�h
	int vel = 0;
	int acc = 1;

	bool isJumpAction = false;

	bool isDash = false;

	bool isInteract = false;

	bool isEntranceStair = false;

	bool isExitStair = false;
};

