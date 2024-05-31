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
	void SetPosX(int posX) { x = posX; }

	int GetMoveSpeed() { return moveSpeed; }

private: //�����o�֐�

	//�ړ��֐�
	void Move(char keys[256], char oldkeys[256]);

	//�W�����v�֐�
	void Jump(char keys[256], char oldkeys[256]);

	void JumpUpdate();

private: //�����o�ϐ�
	int x = 0;				//x���W
	int y = 0;				//y���W
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
};

