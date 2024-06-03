#include "Stage.h"
#include "DxLib.h"
#include <fstream>
#include <cassert>
#include <random>

std::random_device rnd;		// 非決定的な乱数生成器を生成
std::mt19937 mt(rnd());	//  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
std::uniform_int_distribution<> rand5(0, 4);	// [0, 4] 範囲の一様乱数

//rand5(mt)

void Stage::Initialize()
{
	// バッファをクリア
	stageCommands_.str("");
	// 状態をクリア
	stageCommands_.clear(std::stringstream::goodbit);

	// マップをロード
	LoadStageFile(1);
	LoadStageCommands();

	// 画像読み込み
	mapGraph[0] = LoadGraph("Resource/textures/sample1.png");
	mapGraph[1] = LoadGraph("Resource/textures/sample2.png");
	mapGraph[2] = LoadGraph("Resource/textures/sample3.png");
	mapGraph[3] = LoadGraph("Resource/textures/sample4.png");
	mapGraph[4] = LoadGraph("Resource/textures/sample5.png");
	post1Graph = LoadGraph("Resource/textures/poster1.png");
	post2Graph = LoadGraph("Resource/textures/poster2.png");
	post3Graph = LoadGraph("Resource/textures/poster3.png");
	post4Graph = LoadGraph("Resource/textures/poster4.png");
	doorGraph = LoadGraph("Resource/textures/door.png");
	prantGraph = LoadGraph("Resource/textures/prant.png");
	machineGraph = LoadGraph("Resource/textures/machine.png");
	fireExtinGraph = LoadGraph("Resource/textures/fireExtin.png");

	scrollX = 0;
	stageNum = 0;
}

void Stage::Update(char keys[256], char oldkeys[256], Player* p)
{
	// プレイヤー座標からスクロール座標を計算する
	if (p->GetPosX() >= 640 && scrollX < 1960 && keys[KEY_INPUT_D]) {
		scrollX += p->GetMoveSpeed();
		p->SetPosX(640);
	}
	if (p->GetPosX() <= 640 && scrollX > 0 && keys[KEY_INPUT_A]) {
		scrollX -= p->GetMoveSpeed();
		p->SetPosX(640);
	}
	
}

void Stage::Draw()
{
	DrawExtendGraph(0 - scrollX, 0, 3239 - scrollX, 959, mapGraph[stageNum], FALSE);
	
}

void Stage::Reset(Player* p)
{
	stageNum = rand5(mt);
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