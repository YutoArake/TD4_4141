#pragma once
#include <DxLib.h>

class Object
{
public:
	Object(const char* texture, int x, int y);

	virtual void Update();

	virtual void Draw();

	void MoveRight();

	void MoveLeft();

private:
	int texture;

	int x;
	int y;

	int movementX = 8;

};
