#pragma once


class Object
{
public:
	Object(const char* texture, int x, int y, char objecname);

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

	char objectname;
};
