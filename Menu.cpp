#include "Menu.h"
#include "SceneManager.h"


void Menu::Menu_Update(char keys[256], char oldkeys[256])
{
    if (keys[KEY_INPUT_DOWN] == 1 && oldkeys[KEY_INPUT_DOWN] == 0) {//���L�[��������Ă�����
        NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
    }
    if (keys[KEY_INPUT_UP] == 1 && oldkeys[KEY_INPUT_UP] == 0) {//��L�[��������Ă�����
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
    }
    if (keys[KEY_INPUT_RETURN] == 1) {//�G���^�[�L�[�������ꂽ��
        switch (NowSelect) {//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
        case eMenu_Game://�Q�[���I�𒆂Ȃ�
            // �Q�[���Z���N�g�V�[����
            SceneManager::GetInstance()->ChangeScene("SELECT");
            break;
        case eMenu_Exit://�ݒ�I�𒆂Ȃ�
            DxLib_End();
            break;
        }
    }
}

void Menu::Menu_Draw()
{
    DrawString(450, 350, "���j���[��ʂł��B", GetColor(255, 255, 255));
    DrawString(450, 370, "�㉺�L�[�������A�G���^�[�������ĉ������B", GetColor(255, 255, 255));
    DrawString(550, GAME_Y, "�Q�[��", GetColor(255, 255, 255));
    DrawString(550, EXIT_Y, "�I��", GetColor(255, 255, 255));
    int y = 0;
    switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
    case eMenu_Game://�Q�[���I�𒆂Ȃ�
        y = GAME_Y;    //�Q�[���̍��W���i�[
        break;
    case eMenu_Exit://�ݒ�I�𒆂Ȃ�
        y = EXIT_Y;    //�I���̍��W���i�[
        break;
    }
    DrawString(520, y, "��", GetColor(255, 255, 255));
}
