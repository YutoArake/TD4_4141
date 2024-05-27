#pragma once
#include "BaseScene.h"

/// <summary>
///	 ゲームタイトルシーン
/// </summary>
class GameTitleScene : public BaseScene
{
private: // メンバ変数

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

	/// <summary>
	/// シーン遷移
	/// </summary>
	void GameTransition() override;

	int titleGraph = 0;
	int time = 0;

	int x = 0;
};