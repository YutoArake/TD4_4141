#pragma once
#include "DxLib.h"

class Player
{

public: //メンバ関数

	//プレイヤー初期化
	void initialize();

	//プレイヤー更新
	void Update(char keys[256], char oldkeys[256]);

	//プレイヤー描画
	void Draw();

	int GetPosX() { return x; }
	void SetPosX(int posX) { x = posX; }

private: //メンバ関数

	//移動関数
	void Move(char keys[256], char oldkeys[256]);

	//ジャンプ関数
	void Jump(char keys[256], char oldkeys[256]);

	void JumpUpdate();

private: //メンバ変数
	int x = 0;				//x座標
	int y = 0;				//y座標
	int playerGraph;		//プレイヤー画像
	bool canJump = false;	//プレイヤーが地面にいるか
	bool isAction = false;	//プレイヤーがアクションを起こしているか
	int moveSpeed = 5;		//移動スピード設定変数
	int walkSpeed = 5;		//歩きのスピード
	int dashSpeed = 10;		//走りのスピード
	int vel = 0;
	int acc = 1;

	bool isJumpAction = false;
};

