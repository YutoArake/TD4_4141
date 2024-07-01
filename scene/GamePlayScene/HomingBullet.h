#pragma once

struct Position
{
	int x;
	int y;
};

class HomingBullet
{
public:
	HomingBullet(int x, int y);

	void Update();

	void Draw();

	Position GetBulletPosition() {
		Position position;

		position.x = x;
		position.y = y;

		return position;
	}

	void Shoot();

	void DeleteBullet();


private:
	int x;
	int y;

	int movementX;
	int movementY;

	int sizeX;
	int sizeY;

	int texture;
};

