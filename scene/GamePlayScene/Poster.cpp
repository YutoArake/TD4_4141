#include "Poster.h"
#include <DxLib.h>





Poster::Poster(const char* normaltexture, const char* bigtexture, const char* scratchtexture, const char* eyetexture, int x, int y, int sizeX, int sizeY, int phase)
{
	this->normaltexture = LoadGraph(normaltexture);
	this->bigtexture = LoadGraph(bigtexture);
	this->scratchtexture = LoadGraph(scratchtexture);
	this->eyetexture = LoadGraph(eyetexture);

	this->x = x;
	this->y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->phase = phase;
}

void Poster::Update()
{
}

void Poster::Draw()
{
	if (phase == 0) {
		DrawGraph(x - sizeY, y - sizeY, normaltexture, true);
	}
	if (phase == 1) {
		DrawGraph(x - sizeY, y - sizeY, bigtexture, true);
	}
	if (phase == 2) {
		DrawGraph(x - sizeY, y - sizeY, scratchtexture, true);
	}
	if (phase == 3) {
		DrawGraph(x - sizeY, y - sizeY, eyetexture, true);
	}
}
