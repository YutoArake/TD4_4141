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
/// ゲームプレイシーン
/// </summary>

class GamePlayScene : public BaseScene
{
private: // メンバ変数
	bool isClear = false;

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update(char keys[256], char oldkeys[256]) override;

	/// <summary>
	///  描画
	/// </summary>
	void Draw() override;

	void AllUpdate();

	void Collision();


private:
	int phase = 0; //状態　0:待機 1:出現中

	int turn = 2; //0:通常 1:ホーミング 2:レーザー

	std::list <Mob*> moblist;

	ShootingPlayer* shootingplayer;

};