#pragma once
#include "GamePlayScene/Object.h"

class Dump : public Object
{
public:
	Dump(const char* texture, int x, int y, int sizeX, int sizeY, const char* objectname);

	void Update() override;

	void Draw() override;

private:
	int texture;

};

