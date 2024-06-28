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

	// プレイヤーリセット
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


private: //メンバ関数

	//移動関数
	void Move(char keys[256], char oldkeys[256]);

	//ジャンプ関数
	void Jump(char keys[256], char oldkeys[256]);
	//ジャンプ更新関数
	void JumpUpdate();

	//プレイヤーのアクション
	void Interact(char keys[256], char oldkeys[256]);

private: //メンバ変数
	int x = 0;				//x座標
	int y = 0;				//y座標
	int oldX = 0;
	int oldY = 0;
	int playerGraph;		//プレイヤー画像
	bool canJump = false;	//プレイヤーが地面にいるか
	bool isAction = false;	//プレイヤーがアクションを起こしているか
	int moveSpeed = 6;		//移動スピード設定変数
	int walkSpeed = 6;		//歩きのスピード
	int dashSpeed = 10;		//走りのスピード
	int vel = 0;
	int acc = 1;

	bool isJumpAction = false;

	bool isDash = false;

	bool isInteract = false;

	bool isEntranceStair = false;

	bool isExitStair = false;
};

