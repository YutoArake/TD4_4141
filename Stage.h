#pragma once
#include "StageOption.h"
#include <sstream>

struct Vec2 {
	int x;
	int y;
};

/// <summary>
/// 
/// </summary>
class Stage
{
private:
	// ファイルコマンド
	std::stringstream stageCommands_;

	StageOption stageOp;

	// マップ画像
	int mapGraph[6] = { 0 };
	int floorGraph[10] = { 0 };
	char filename[50];
	// 小物
	int post1Graph = 0;
	int post2Graph = 0;
	int post3Graph = 0;
	int post4Graph = 0;
	int doorGraph = 0;
	int prantGraph = 0;
	int machineGraph = 0;
	int fireExtinGraph = 0;
	int womanGraph = 0;
	int womanAnomalyGraph = 0;

	int stageNum = 0;
	bool isDoorOpen = false;
	int doorTimer = 0;


	// スクロール座標
	int scrollX = 0;

public:
	// 初期化
	void Initialize();

	// 更新
	void Update(char keys[256], char oldkeys[256], Player* p, bool &isClear);

	// 描画
	void Draw();

	// リセット
	void Reset(Player* p);

	int GetScrollX() {
		return scrollX;
	}
	int SetScrollX(int _scrollX)
	{this->scrollX = _scrollX;}

	// ステージロード
	void LoadStageFile(int stageNum);

	// コマンド読み込み
	void LoadStageCommands();

};

