#pragma once

struct PlayerPosition
{
	int x;
	int y;
};

class Player
{
public:
	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();

	PlayerPosition GetPlayerPosition() {
		PlayerPosition playerposition;

		playerposition.x = this->x;
		playerposition.y = this->y;

		return playerposition;
	}

private:
	int Texture = 0;

	int x = 640;
	int y = 560;
	int sizeX = 45;
	int sizeY = 100;

	int movementX = 8;
	int movementY = 8;
};

