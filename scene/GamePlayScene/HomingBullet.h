#pragma once

struct Position
{
	int x;
	int y;
};

class HomingBullet
{
public:
	HomingBullet(float x, float y);

	void Update();

	void Draw();

	Position GetBulletPosition() {
		Position position;

		position.x = x;
		position.y = y;

		return position;
	}

	void BallisticUpdate();

	void SetPlayerPosition(int x, int y) {
		this->playerPositionX = x;
		this->playerPositionY = y;
	};

private:
	float x;
	float y;

	int movementX;
	int movementY;

	int sizeX;
	int sizeY;

	int texture;

	int playerPositionX;
	int playerPositionY;
};

