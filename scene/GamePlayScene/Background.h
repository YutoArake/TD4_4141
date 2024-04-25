#pragma once

class Background
{
public:
	Background(const char* texture, int x, int y);

	void Initialize();

	void Update();

	void Draw();

private:
	int texture;

	int x;
	int y;
};

