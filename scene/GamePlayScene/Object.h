#pragma once
#include <DxLib.h>

class Object
{
public:
	Object(const char* texture, const char* objectname, int x, int y)
	{
		this->texture = LoadGraph(texture);

		this->x = x;
		this->y = y;
		this->objectname = objectname;
	}

	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();

private:
	int texture;

	int x;
	int y;

	int movementX = 8;

	const char* objectname;
};
