#pragma once

class Mob
{
public:
	Mob();

	void Initialize();

	void Update();

	virtual void Draw();

private:

protected:
	int x;
	int y;
};

