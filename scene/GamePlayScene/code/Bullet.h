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

	bool GetHit() {
		return hit;
	}

	void onCollision() {
		hit = true;
	}

	float GetBulletX() {
		return x;
	}
	float GetBulletY() {
		return y;
	}

	int GetSizeX() {
		return sizeX;
	}

	int GetSizeY() {
		return sizeY;
	}

private:
	float x;
	float y;

	float movementX = -10;
	float movementY = 0;

	int sizeX = 15;
	int sizeY = 15;

	bool hit = false;

	int texture;

};

