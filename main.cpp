#include "DxLib.h"
#include "SceneFactory.h"
#include "SceneManager.h"
#include <stdlib.h>
#include <time.h>


// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

#pragma region Dxlib初期化処理
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウのタイトルに表示する文字列
	const char TITLE[] = "4141";

	// ウィンドウ横幅
	const int WIN_WIDTH = 1280;

	// ウィンドウ縦幅
	const int WIN_HEIGHT = 960;

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);
#pragma endregion//Dxlib初期化処理

	// 画像などのリソースデータの変数宣言と読み込み

	// ゲームループで使う変数の宣言
	// シーンマネージャー
	SceneManager* sceneManager_ = nullptr;
	// シーンファクトリー
	AbstractSceneFactory* sceneFactory_ = nullptr;

	// シーンマネージャーのインスタンス取得
	sceneManager_ = SceneManager::GetInstance();
	// シーンファクトリーを生成し、マネージャーに最初にセット
	sceneFactory_ = new SceneFactory();
	sceneManager_->SetSceneFactory(sceneFactory_);

	// シーンマネージャーに最初のシーンをセット
	SceneManager::GetInstance()->ChangeScene("TITLE");

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i) {
			oldkeys[i] = keys[i];
		}

		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		sceneManager_->Update(keys, oldkeys);

		// 描画処理
		sceneManager_->Draw();

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		if (sceneManager_->GetIsGameEnd()) {
			break;
		}
	}

	// シーンマネージャーの解放
	sceneManager_->Finalize();

	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}