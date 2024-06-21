#pragma once


struct Position {
	int x;
	int y;
};

class Bullet
{
public:
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
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

	int movementX;
	int movementY;

	int sizeX;
	int sizeY;

	int texture;

};

