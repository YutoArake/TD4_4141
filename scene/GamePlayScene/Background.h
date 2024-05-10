#pragma once

struct Position
{
	int x;
	int y;
};

class Background
{
public:
	Background(const char* texture, int x, int y);

	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();

	Position GetPosion() {
		Position position;

		position.x = this->x;
		position.y = this->y;

		return position;
	}

private:
	int texture;

	int x;
	int y;

	int movementX = 8;
	int movementY = 8;
};

