#pragma once
#include "DxLib.h"

class Player
{

public: //�����o�֐�

	void initialize();

	void Update(char keys[256], char oldkeys[256]);

	void Draw();

private:

	void Move(char keys[256], char oldkeys[256]);

	void Jump(char keys[256], char oldkeys[256]);

private: //�����o�ϐ�
	int x = 0;
	int y = 0;
	int playerGraph;
	bool canJump = false;
	bool isAction = false;

};

