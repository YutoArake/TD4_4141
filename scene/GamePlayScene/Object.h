#pragma once


class Object
{
public:
	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();

private:
	int texture;

	int x;
	int y;

	int sizeX;
	int sizeY;
};
