#pragma once
#include "GamePlayScene/Object.h"

class Missile : public Object
{
public:
	Missile(const char* texture, int x, int y, int sizeX, int sizeY, const char* objectname);

	void Update() override;

	void Draw() override;

private:
	int texture;

};


