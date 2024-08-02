#pragma once


class HomingBullet
{
public:
	HomingBullet(float x, float y);

	void Update();

	void Draw();

	float GetBulletX() {
		return x;
	}

	float GetBulletY() {
		return y;
	}

	void BallisticUpdate();

	void SetPlayerPosition(int x, int y) {
		this->playerPositionX = x;
		this->playerPositionY = y;
	};

	bool GetHit() {
		return hit;
	}

	void onCollision() {
		hit = true;
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

	float movementX = 0;
	float movementY = 0;

	float speedX = 10;
	float speedY = 10;

	int homingsecond = 1;
	int homingtime = homingsecond * 45;

	int sizeX = 15;
	int sizeY = 15;

	bool hit = false;

	int texture;

	float playerPositionX;
	float playerPositionY;
};

