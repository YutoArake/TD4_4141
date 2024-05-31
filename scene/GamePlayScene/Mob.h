#pragma once

class Mob
{
public:
	Mob();

	virtual void Update();

	virtual void Draw();

private:

protected:
	int x;
	int y;

	int sizeX;
	int sizeY;
};

