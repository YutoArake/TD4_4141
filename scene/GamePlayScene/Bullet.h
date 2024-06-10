#pragma once


class Bullet
{
public:
	Bullet(int x, int y);

	void Update();

	void Draw();

private:
	int x;
	int y;

	int sizeX;
	int sizeY;

	int texture;

};

