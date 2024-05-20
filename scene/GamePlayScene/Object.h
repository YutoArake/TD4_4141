#pragma once


class Object
{
public:
	Object(const char* texture, int x, int y);

	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();

private:
	int texture;

	int x;
	int y;

};
