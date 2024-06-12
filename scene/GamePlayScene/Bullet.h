#pragma once


class Bullet
{
public:
	Bullet(int x, int y);

	void Update();

	void Draw();

private:
	int x = 0;
	int y = 0;

	int sizeX;
	int sizeY;

	int texture;

};

