#include "Object.h"
#include <DxLib.h>




void Object::Update()
{

}

void Object::Draw()
{
	//DrawGraph(x, y, texture, true);
}

void Object::MoveRight()
{
	x += movementX;
}

void Object::MoveLeft()
{
	x -= movementX;
}
