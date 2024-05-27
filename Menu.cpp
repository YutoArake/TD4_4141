#include "Menu.h"
#include "SceneManager.h"


void Menu::Menu_Update(char keys[256], char oldkeys[256])
{
    if (keys[KEY_INPUT_DOWN] == 1 && oldkeys[KEY_INPUT_DOWN] == 0) {//下キーが押されていたら
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
    }
    if (keys[KEY_INPUT_UP] == 1 && oldkeys[KEY_INPUT_UP] == 0) {//上キーが押されていたら
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
    }
    if (keys[KEY_INPUT_RETURN] == 1) {//エンターキーが押されたら
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eMenu_Game://ゲーム選択中なら
            // ゲームセレクトシーンへ
            SceneManager::GetInstance()->ChangeScene("SELECT");
            break;
        case eMenu_Exit://設定選択中なら
            DxLib_End();
            break;
        }
    }
}

void Menu::Menu_Draw()
{
    DrawString(450, 350, "メニュー画面です。", GetColor(255, 255, 255));
    DrawString(450, 370, "上下キーを押し、エンターを押して下さい。", GetColor(255, 255, 255));
    DrawString(550, GAME_Y, "ゲーム", GetColor(255, 255, 255));
    DrawString(550, EXIT_Y, "終了", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eMenu_Game://ゲーム選択中なら
        y = GAME_Y;    //ゲームの座標を格納
        break;
    case eMenu_Exit://設定選択中なら
        y = EXIT_Y;    //終了の座標を格納
        break;
    }
    DrawString(520, y, "■", GetColor(255, 255, 255));
}
