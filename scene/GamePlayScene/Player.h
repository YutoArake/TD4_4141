#pragma once

struct PlayerPosition
{
	int x;
	int y;
};



class Player
{
public:
	Player();

	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();



	void Fall();

	void ToggleJump() {
		if (injump == false) {
			injump = true;
		}
	}
	void TrueOnGround() {
		onground = true;
	}


	PlayerPosition GetPlayerPosition() {
		PlayerPosition playerposition;

		playerposition.x = this->x;
		playerposition.y = this->y;

		return playerposition;
	}



private:
	void JumpProcess();

private:
	int jumpPower = 2;
	int gravity = 5;
	bool downForce = true;
	bool onground = true;
	bool injump = false;

	int Texture = 0;

	int x = 640;
	int y = 560;
	int sizeX = 45;
	int sizeY = 100;

	int movementX = 8;
	int movementY = 2;
};

