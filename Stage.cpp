#include "Stage.h"
#include "DxLib.h"
#include <fstream>
#include <cassert>

void Stage::Initialize()
{
	// バッファをクリア
	stageCommands_.str("");
	// 状態をクリア
	stageCommands_.clear(std::stringstream::goodbit);

	stageNum = stageOp.InitializeFloor();

	// マップをロード
	LoadStageFile(1);
	LoadStageCommands();

	// 画像読み込み
	mapGraph[0] = LoadGraph("Resource/textures/sample1.png");
	mapGraph[1] = LoadGraph("Resource/textures/sample2.png");
	mapGraph[2] = LoadGraph("Resource/textures/sample3.png");
	mapGraph[3] = LoadGraph("Resource/textures/sample4.png");
	mapGraph[4] = LoadGraph("Resource/textures/sample5.png");
	mapGraph[5] = LoadGraph("Resource/textures/sample1.png");
	mapGraph[6] = LoadGraph("Resource/textures/gameSample.png");
	post1Graph = LoadGraph("Resource/textures/poster.png");
	post2Graph = LoadGraph("Resource/textures/poster2.png");
	post3Graph = LoadGraph("Resource/textures/poster3.png");
	post4Graph = LoadGraph("Resource/textures/poster4.png");
	doorGraph = LoadGraph("Resource/textures/doorOpen.png");
	prantGraph = LoadGraph("Resource/textures/prant.png");
	machineGraph = LoadGraph("Resource/textures/machine.png");
	fireExtinGraph = LoadGraph("Resource/textures/fireExtin.png");
	womanGraph = LoadGraph("Resource/textures/woman.png");
	womanAnomalyGraph = LoadGraph("Resource/textures/womanAnomaly.png");
	shootGraph = LoadGraph("Resource/textures/show.png");
	for (int i = 1; i < 11; i++)
	{
		sprintf_s(filename, "Resource/Floor/%i.png", i);
		floorGraph[i] = LoadGraph(filename);
	}
	scrollX = 0;
	stageNum = 0;
	maxTime = 300;
}

void Stage::Update(char keys[256], char oldkeys[256], Player* p, bool &isClear)
{
	if(miniGameFlag == 0)
	{
		if (loadFloor == 1)
		{
			flameTime += 4.0f;
		}

		if (flameTime >= maxTime)
		{
			flameTime = 0;
			loadFloor = 0;
		}

		// プレイヤー座標からスクロール座標を計算する
		if (p->GetPosX() >= 640 && scrollX < 1960 && keys[KEY_INPUT_D]) {
			scrollX += p->GetMoveSpeed();
			p->SetPosX(640);
		}
		if (p->GetPosX() <= 640 && scrollX > 0 && keys[KEY_INPUT_A]) {
			scrollX -= p->GetMoveSpeed();
			p->SetPosX(640);
		}

		//ドアを開けたかの判定
		if (scrollX >= 320 && scrollX <= 450)
		{
			if (p->GetPosY() <= 277 &&
				keys[KEY_INPUT_F] == 1 && oldkeys[KEY_INPUT_F] == 0)
			{
				isDoorOpen = true;

				if (stageNum == 6)
				{
					miniGameFlag = 1;
					stageOp.SetMiniGameFlag(miniGameFlag);

				}

			}
		}

		//ドアを開けたらドアタイマーを進める
		if (isDoorOpen == true)
		{
			doorTimer++;
		}

		//ドアタイマーが一定の値に達したらドアのフラグを戻し、タイマーの値も戻す
		if (doorTimer >= 120)
		{
			isDoorOpen = false;
			doorTimer = 0;
		}

		stageOp.Update(p);

		if (p->GetMoveFloor() == true)
		{
			scrollX = 0;
			Reset(p);
			p->SetMoveFloor(false);
			loadFloor = 1;
		}
	}
	isClear = stageOp.IsClear();
}

void Stage::Draw()
{
	if (miniGameFlag == 0)
	{
		DrawExtendGraph(0 - scrollX, 0, 3239 - scrollX, 959, mapGraph[stageNum], FALSE);
		DrawExtendGraph(2590 - scrollX, 100, 2654 - scrollX, 218, floorGraph[stageOp.GetFloor() + 1], true);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", stageNum);
		DrawFormatString(0, 140, GetColor(255, 255, 255), "scrollX: %d", scrollX, false);

		if (isDoorOpen == true)
		{
			DrawExtendGraph(988 - scrollX, 67, 1115 - scrollX, 271, doorGraph, true);

			if (stageNum != 5)
			{
				DrawExtendGraph(978 - scrollX, 110, 1145 - scrollX, 271, womanGraph, true);
			}

			else
			{
				DrawExtendGraph(978 - scrollX, 110, 1145 - scrollX, 271, womanAnomalyGraph, true);
			}
		}
		stageOp.Draw();
	}
	else if (miniGameFlag == 1)
	{

		DrawExtendGraph(0, 0, 800, 800, post2Graph, false);
		DrawExtendGraph(0, 0, 800, 800, shootGraph, false);

		
	}


	
}

void Stage::Reset(Player* p)
{
	stageNum = stageOp.InitializeFloor();
	scrollX = 0;
}

void Stage::LoadStageFile(int stageNum)
{
	// ファイル
	std::ifstream file;
	// パスを取得
	std::string mapNum;
	mapNum = std::to_string(stageNum);
	const std::string mapFolder = "stages/";
	const std::string filename = "stage" + mapNum + ".txt";
	const std::string directoryPath = "Resource/" + mapFolder + filename;
	// ファイルを開く
	file.open(directoryPath);
	assert(file.is_open());
	// ファイルの内容を文字列ストリームにコピー
	stageCommands_ << file.rdbuf();
	// ファイルを閉じる
	file.close();
}

void Stage::LoadStageCommands()
{
	// 1行分の文字列を入れる変数
	std::string line;

	// コマンド実行ループ
	while (getline(stageCommands_, line)) {
		// 1行分の文字列をストリームに変換して解析しやすくする
		std::istringstream line_stream(line);
		// 文字列
		std::string word;

		// コンマ区切りで行の先頭文字列を取得
		while (getline(line_stream, word, ',')) {
			// 
			if (word.find("0") == 0) {
			}
			// 
			else if (word.find("1") == 0) {
			}
			// 
			else if (word.find("2") == 0) {
			}
		}
	}
}