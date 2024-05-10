#pragma once
#include "DxLib.h"

class Player
{

public: //ƒƒ“ƒoŠÖ”

	void initialize();

	void Update(char keys[256], char oldkeys[256]);

	void Draw();

private:

	void Move(char keys[256], char oldkeys[256]);

	void Jump(char keys[256], char oldkeys[256]);

private: //ƒƒ“ƒo•Ï”
	int x = 0;
	int y = 0;
	int playerGraph;
	bool canJump = false;
	bool isAction = false;

};

