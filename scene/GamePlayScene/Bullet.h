#pragma once




class Bullet
{
public:
	/// <summary>
	/// 生成
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	Bullet(float x, float y);

	void Update();

	void Draw();

	float GetBulletX() {
		return x;
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

