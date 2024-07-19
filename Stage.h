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
	int mapGraph[7] = { 0 };
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
	int shootGraph = 0;

	int stageNum = 0;
	bool isDoorOpen = false;
	int doorTimer = 0;
	
	int miniGameFlag = 0;

	// スクロール座標
	int scrollX = 0;

	int loadFloor = 0;

	//演出用タイマー
	float flameTime = 0.0f;

	float maxTime = 0.0f;

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


	int GetLoadFloor()
	{
		return loadFloor;
	}

	void SetLoadFloor(int _loadFloor)
	{
		this->loadFloor = _loadFloor;
	}

	//イージング関数
	double easeOutBack(double start, double end, double time)
	{
		double c1 = 1.70158;
		double c3 = c1 + 1.0;

		return start + c3 * (pow(time - 1, 3)) + c1 * (pow(time - 1, 2)) * (end - start);
	}

	double easeInOutBack(double start, double end, double time){
		double c1 = 1.70158;
		double c2 = c1 * 1.525;

	return time < 0.5 
	? (pow(2 * time, 2) * ((c2 + 1) * 2 * time - c2)) / 2 * (end - start)
	: (pow(2 * time - 2, 2) * ((c2 + 1) * (time * 2 - 2) + c2) + 2) / 2 * (end - start);
	}
	//イージング関数終わり

	// ステージロード
	void LoadStageFile(int stageNum);

	// コマンド読み込み
	void LoadStageCommands();

};

