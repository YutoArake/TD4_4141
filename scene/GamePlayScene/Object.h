#pragma once
#include <DxLib.h>

struct Translate
{
	int x;
	int y;
};

struct Coners
{
	Translate LeftUp;
	Translate LeftDown;
	Translate RightUp;
	Translate RightDown;
};

class Object
{
public:

	virtual void Update();

	virtual void Draw();

	void MoveRight();

	void MoveLeft();

	const char* GetName() {
		return objectname;
	}

	Coners GetConers() {
		Coners coners;

		coners.LeftUp.x = x - sizeX;
		coners.LeftUp.y = y - sizeY;

		coners.LeftDown.x = x - sizeX;
		coners.LeftDown.y = y + sizeY;

		coners.RightUp.x = x + sizeX;
		coners.RightUp.y = y - sizeY;

		coners.RightDown.x = x + sizeX;
		coners.RightDown.y = y + sizeY;

		return coners;
	}

private:


	int movementX = 8;
protected:
	int x = 0;
	int y = 0;

	int sizeX = 0;
	int sizeY = 0;

	const char* objectname;
};
