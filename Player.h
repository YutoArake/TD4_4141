#pragma once
#include "DxLib.h"
#include<math.h>

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

private: //メンバ関数

	//移動関数
	void Move(char keys[256], char oldkeys[256]);

	//移動禁止エリア関数
	void KeepOut();

	//アニメーション関数
	void Animation();

	//ジャンプ関数
	void Jump(char keys[256], char oldkeys[256]);
	//ジャンプ更新関数
	void JumpUpdate();

	//プレイヤーのアクション
	void MoveFloor(char keys[256], char oldkeys[256]);


private: //メンバ変数
	int x = 0;				//x座標
	int y = 0;				//y座標

	int radius = 32;

	int oldX = 0;
	int oldY = 0;
	int playerFrontGraph[11];		//プレイヤー画像
	int playerLeftGraph[11];
	int playerRightGraph[11];
	int playerBackGraph[11];
	int playerMiniGraph[2];

	int playerDirection = 2;
	bool canJump = false;	//プレイヤーが地面にいるか
	bool isAction = false;	//プレイヤーがアクションを起こしているか
	int moveSpeed = 6;		//移動スピード設定変数
	int walkSpeed = 6;		//歩きのスピード
	int dashSpeed = 10;		//走りのスピード
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

