#pragma once


struct Position {
	int x;
	int y;
};

class Bullet
{
public:
	Bullet(int x, int y);

	void Update();

	void Draw();

	Position GetBulletPosition() {
		Position position;

		position.x = this->x;
		position.y = this->y;

		return position;
	}

private:
	int x = 0;
	int y = 0;

	int sizeX;
	int sizeY;

	int texture;

};

