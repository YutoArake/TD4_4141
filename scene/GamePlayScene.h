#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Stage.h"

/// <summary>
/// ゲームプレイシーン
/// </summary>
class GamePlayScene : public BaseScene
{
private: // メンバ変数
	bool isClear = false;

	float flameTime = 0.0f;

	float maxTime = 0.0f;

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
	///  シーン遷移
	/// </summary>
	void GameTransition() override;
	/// <summary>
	///  描画
	/// </summary>
	void Draw() override;

private:
	Player* player;
	Stage stage;
};