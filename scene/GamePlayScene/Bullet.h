#pragma once




class Bullet
{
public:
	/// <summary>
	/// ê∂ê¨
	/// </summary>
	/// <param name="x">xç¿ïW</param>
	/// <param name="y">yç¿ïW</param>
	Bullet(float x, float y);

	void Update();

	void Draw();

	float GetBulletX() {
		return x;
	}
	float GetBulletY() {
		return y;
	}

private:
	float x;
	float y;

	float movementX = -10;
	float movementY = 0;

	int sizeX = 15;
	int sizeY = 15;

	int texture;

};

