#pragma once
#include "GamePlayScene/Object.h"

class Door :public Object
{
public:
	Door(const char* normaltexture, const char* shinetexture, int x, int y, int sizeX, int sizeY, int phase, const char* objectname);

	void Update() override;

	void Draw() override;

private:
	int normaltexture;

	int shinetexture;

	int phase; //0:normal 1:shine
};

