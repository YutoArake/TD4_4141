#pragma once
#include "Player.h"
#include <sstream>

class MiniGame
{
private:
	const int MapX = 20;
	const int MapY = 15;
	const int Size = 64;

	// ファイルコマンド
	std::stringstream stageCommands_;

	int miniGame[15][20] = { 0 };

	int blocks[5] = { 0 };
public:
	// 初期化
	void Initialize();

	// 更新
	void Update(char keys[256], char oldkeys[256], Player* p, bool& isClear);

	// 描画
	void Draw();

	// リセット
	void Reset(int stageNum);

	// ステージロード
	void LoadStageFile(int stageNum);

	// コマンド読み込み
	void LoadStageCommands();
};

