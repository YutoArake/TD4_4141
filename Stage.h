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
	// 小物
	int post1Graph = 0;
	int post2Graph = 0;
	int post3Graph = 0;
	int post4Graph = 0;
	int doorGraph = 0;
	int prantGraph = 0;
	int machineGraph = 0;
	int fireExtinGraph = 0;

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
	void Reset(Player* p);
};

