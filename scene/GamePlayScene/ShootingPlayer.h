#pragma once
#include <DxLib.h>

struct Position {
	int x;
	int y;
};

class ShootingPlayer
{
public:
	ShootingPlayer();

	Position GetPosition() {
		Position position;

		position.x = x;
		position.y = y;

		return position;
	}

private:
	int x;
	int y;
};
