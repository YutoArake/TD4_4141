#pragma once




class Bullet
{
public:
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
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

