#pragma once

struct PlayerPosition
{
	int x;
	int y;
};

struct JumpSetting
{
	int jumpPower;
	int gravity;
	bool downForce;
	bool jumpdetection;
};

class Player
{
public:
	void Initialize();

	void Update();

	void Draw();

	void MoveRight();

	void MoveLeft();

	void Jump();

	void JumpProcess();

	void ToggleJumpDetection() {
		if (jumpSetting.jumpdetection == true) {
			jumpSetting.jumpdetection = false;
			jumpSetting.downForce = false;
			return;
		}
		if (jumpSetting.jumpdetection == false) {
			jumpSetting.jumpdetection = true;
			jumpSetting.downForce = true;
			return;
		}
	}

	PlayerPosition GetPlayerPosition() {
		PlayerPosition playerposition;

		playerposition.x = this->x;
		playerposition.y = this->y;

		return playerposition;
	}

private:
	JumpSetting jumpSetting;

	int Texture = 0;

	int x = 640;
	int y = 560;
	int sizeX = 45;
	int sizeY = 100;

	int movementX = 8;
	int movementY = 4;
};

