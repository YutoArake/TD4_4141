#pragma once
#include "GamePlayScene/Object.h"

class Poster :public Object
{
public:
	Poster(const char* normaltexture, const char* bigtexture, const char* scratchtexture, const char* eyetexture, int x, int y, int sizeX, int sizeY, int phase, const char* objectname);

	void Update() override;

	void Draw() override;


private:
	int normaltexture;

	int bigtexture;

	int scratchtexture;

	int eyetexture;

	int phase; //0:normal 1:big 2:scratch 3:eye

};

