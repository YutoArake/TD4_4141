#pragma once
#include "BaseScene.h"

// ���j���[��ʐ��̗񋓌^
typedef enum {
	eMenu_Game,        //�Q�[��
	eMenu_Exit,    //�ݒ�

	eMenu_Num,        //�{���ڂ̐�
} eMenu;

// �ÓI�O���[�o���ϐ�
static int NowSelect = eMenu_Game;    //���݂̑I�����(�����̓Q�[���I��)

/// <summary>
/// �^�C�g�����j���[
/// </summary>
class Menu
{
public: // �����o�֐�

	void Menu_Update(char keys[256], char oldkeys[256]);

	void Menu_Draw();

private: // �����o�ϐ�

	const int GAME_Y = 440;	//�u�Q�[���v������y�ʒu
	const int EXIT_Y = 470;		//�u�ݒ�v������y�ʒu

};

