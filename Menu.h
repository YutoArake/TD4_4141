#pragma once
#include "BaseScene.h"


typedef enum {
	eMenu_Game,        //�Q�[��
	eMenu_Exit,    //�ݒ�

	eMenu_Num,        //�{���ڂ̐�
} eMenu;

static int NowSelect = eMenu_Game;    //���݂̑I�����(�����̓Q�[���I��)

class Menu
{
public:

	void Menu_Update(char keys[256], char oldkeys[256]);

	void Menu_Draw();

private:

	const int GAME_Y = 440;    //�u�Q�[���v������y�ʒu
	const int EXIT_Y = 470;    //�u�ݒ�v������y�ʒu

};

