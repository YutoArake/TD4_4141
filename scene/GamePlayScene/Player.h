#pragma once

class Player
{
public:
	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();

private:
	int Texture;

	int x = 640;
	int y = 560;
	int sizeX = 45;
	int sizeY = 100;

	int movementX = 8;
	int movementY = 8;
};

