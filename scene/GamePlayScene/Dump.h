#pragma once
#include "GamePlayScene/Object.h"

class Dump : public Object
{
public:
	Dump(const char* texture, int x, int y, int sizeX, int sizeY);

	void Update() override;

	void Draw() override;

private:
	int texture;

};

