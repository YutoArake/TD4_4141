#pragma once
#include <DxLib.h>

class Object
{
public:

	virtual void Update();

	virtual void Draw();

	void MoveRight();

	void MoveLeft();

private:


	int movementX = 8;
protected:
	int x;
	int y;

	int sizeX;
	int sizeY;
};
