#include "Mob.h"
#include "DxLib.h"

Mob::Mob()
{

}

void Mob::Initialize()
{
}

void Mob::Update()
{
}

void Mob::Draw()
{
	DrawBox(x - 50, y - 50, x + 50, y + 50, GetColor(255, 255, 255), true);
}


