#include "Object.h"
#include <DxLib.h>

Object::Object(const char* texture, int x, int y, char objectname)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
	this->objectname = objectname;
}

void Object::Initialize()
{
}

void Object::Update()
{

}

void Object::Draw()
{
	DrawGraph(x, y, texture, true);
}

void Object::MoveRight()
{
	x += movementX;
}

void Object::MoveLeft()
{
	x -= movementX;
}
