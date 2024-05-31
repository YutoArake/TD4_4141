#pragma once
#include "GamePlayScene/Object.h"

class Missile : public Object
{
public:
	Missile(const char* texture, int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;

private:
	int texture;

};


