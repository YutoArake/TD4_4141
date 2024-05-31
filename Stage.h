#pragma once
#include "Player.h"

/// <summary>
/// 
/// </summary>
class Stage
{
private:
	// マップ画像
	int mapGraph = 0;

	// スクロール座標
	int scrollX = 0;

public:
	// 初期化
	void Initialize();

	// 更新
	void Update(char keys[256], char oldkeys[256], Player* p);

	// 描画
	void Draw();

	// リセット
	void Reset();
};

