#pragma once
#include "BaseScene.h"

// メニュー画面数の列挙型
typedef enum {
	eMenu_Game,        //ゲーム
	eMenu_Exit,    //設定

	eMenu_Num,        //本項目の数
} eMenu;

// 静的グローバル変数
static int NowSelect = eMenu_Game;    //現在の選択状態(初期はゲーム選択中)

/// <summary>
/// タイトルメニュー
/// </summary>
class Menu
{
public: // メンバ関数

	void Menu_Update(char keys[256], char oldkeys[256]);

	void Menu_Draw();

private: // メンバ変数

	const int GAME_Y = 440;	//「ゲーム」文字のy位置
	const int EXIT_Y = 470;		//「設定」文字のy位置

};

