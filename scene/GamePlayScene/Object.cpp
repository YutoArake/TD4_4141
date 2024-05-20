#include "Object.h"
#include <DxLib.h>

Object::Object(const char* texture, int x, int y)
{
	this->texture = LoadGraph(texture);

	this->x = x;
	this->y = y;
}

void Object::Initialize()
{
}

void Object::Update()
{
}

void Object::Draw()
{
}

void Object::MoveRight()
{
}

void Object::MoveLeft()
{
}
