#include "MiniGame.h"
#include <fstream>
#include <cassert>

void MiniGame::Initialize()
{
	// バッファをクリア
	stageCommands_.str("");
	// 状態をクリア
	stageCommands_.clear(std::stringstream::goodbit);

	// マップをロード
	LoadStageFile(1);
	LoadStageCommands();

	blocks[0] = LoadGraph("Resource/blocks/block.png");
	blocks[1] = LoadGraph("Resource/blocks/brick.png");
	blocks[2] = LoadGraph("Resource/blocks/broken.png");
	blocks[3] = LoadGraph("Resource/blocks/ice.png");
	blocks[4] = LoadGraph("Resource/blocks/fall.png");
}

void MiniGame::Update(char keys[256], char oldkeys[256], Player* p, bool& isClear)
{

}

void MiniGame::Draw()
{
	for (int y = 0; y < MapY; y++) {
		for (int x = 0; x < MapX; x++) {
			if (miniGame[y][x] == 1) {
				DrawGraph(x * Size, y * Size, blocks[0], false);
			}
		}
	}
}

void MiniGame::Reset(int stageNum)
{
	// バッファをクリア
	stageCommands_.str("");
	// 状態をクリア
	stageCommands_.clear(std::stringstream::goodbit);

	// マップをロード
	LoadStageFile(stageNum);
	LoadStageCommands();
}

void MiniGame::LoadStageFile(int stageNum)
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

void MiniGame::LoadStageCommands()
{
	// 1行分の文字列を入れる変数
	std::string line;
	int x = 0, y = 0;

	// コマンド実行ループ
	while (getline(stageCommands_, line)) {
		// 1行分の文字列をストリームに変換して解析しやすくする
		std::istringstream line_stream(line);
		// 文字列
		std::string word;

		// コンマ区切りで行の先頭文字列を取得
		while (getline(line_stream, word, ',')) {
			// 空
			if (word.find("0") == 0) {
				miniGame[y][x] = 0;
			}
			// ブロック
			else if (word.find("1") == 0) {
				miniGame[y][x] = 1;
			}
			// 回収オブジェクト（寿司）
			else if (word.find("2") == 0) {
				miniGame[y][x] = 2;
			}
			x++;
		}
		y++;
		x = 0;
	}
}
