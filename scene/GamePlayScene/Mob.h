#pragma once

class Mob
{
public:
	Mob();

	virtual void Update();

	virtual void Draw();

	int GetULeftX() {
		return x - sizeX;
	}

	int GetULeftY() {
		return y - sizeY;
	}

	int GetDLeftX() {
		return x - sizeX;
	}

	int GetDLeftY() {
		return y + sizeY;
	}

	int GetURightX() {
		return x + sizeX;
	}

	int GetURightY() {
		return y - sizeY;
	}

	int GetDRightX() {
		return x + sizeX;
	}

	int GetDRightY() {
		return y + sizeY;
	}

private:

protected:
	int x;
	int y;

	int sizeX;
	int sizeY;
};

