#pragma once
#include "Player.h"

/// <summary>
/// 
/// </summary>
class Stage
{
private:
	int mapGraph = 0;
	int scrollX = 0;

public:
	void Initialize();
	void Update(char keys[256], char oldkeys[256], Player* p);
	void Draw();
	void Reset();
};

