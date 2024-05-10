#pragma once
#include "DxLib.h"

class Player
{

public: //メンバ関数

	void initialize();

	void Update(char keys[256], char oldkeys[256]);

	void Draw();

private:

	void Move(char keys[256], char oldkeys[256]);

	void Jump(char keys[256], char oldkeys[256]);

private: //メンバ変数
	int x = 0;
	int y = 0;
	int playerGraph;
	bool canJump = false;
	bool isAction = false;

};

