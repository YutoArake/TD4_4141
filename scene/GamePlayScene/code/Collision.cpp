#include "Collision.h"






float Collision::Cross(float vector1X, float vector1Y, float vector2X, float vector2Y)
{
	float result;

	result = vector1X * vector2Y - vector1Y * vector2X;

	return result;
}

Vector2 Collision::VectorCalc(float startX, float startY, float endX, float endY)
{
	Vector2 result;

	result.x = endX - startX;
	result.y = endY - startY;

	return result;
}

bool Collision::SquareToSquare(int mx1, int my1, int mx2, int my2, int ex1, int ey1, int ex2, int ey2)
{
	if (mx1 <= ex2 && ex1 <= mx2 && my1 <= ey2 && ey1 <= my2) {
		return true;
	}

	return false;
}

bool Collision::LineToSquare(float squareX1, float squareY1, float squareX2, float squareY2, float squareX3, float squareY3, float squareX4, float squareY4, float lineSX, float lineSY, float lineEX, float lineEY)
{
	bool collision1;
	bool collision2;
	bool collision3;
	bool collision4;

	Vector2 vectorLine;

	vectorLine.x = VectorCalc(lineSX, lineSY, lineEX, lineEY).x;
	vectorLine.y = VectorCalc(lineSX, lineSY, lineEX, lineEY).y;

	Vector2 vectorLineToSquare;

	//1
	vectorLineToSquare.x = VectorCalc(lineSX, lineSY, squareX1, squareY1).x;
	vectorLineToSquare.y = VectorCalc(lineSX, lineSY, squareX1, squareY1).y;

	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) >= 0) {
		collision1 = true;
	}
	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) < 0) {
		collision1 = false;
	}

	//2
	vectorLineToSquare.x = VectorCalc(lineSX, lineSY, squareX2, squareY2).x;
	vectorLineToSquare.y = VectorCalc(lineSX, lineSY, squareX2, squareY2).y;

	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) >= 0) {
		collision2 = true;
	}
	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) < 0) {
		collision2 = false;
	}

	//3
	vectorLineToSquare.x = VectorCalc(lineSX, lineSY, squareX3, squareY3).x;
	vectorLineToSquare.y = VectorCalc(lineSX, lineSY, squareX3, squareY3).y;

	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) >= 0) {
		collision3 = true;
	}
	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) < 0) {
		collision3 = false;
	}

	//4
	vectorLineToSquare.x = VectorCalc(lineSX, lineSY, squareX4, squareY4).x;
	vectorLineToSquare.y = VectorCalc(lineSX, lineSY, squareX4, squareY4).y;

	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) >= 0) {
		collision4 = true;
	}
	if (Cross(vectorLine.x, vectorLine.y, vectorLineToSquare.x, vectorLineToSquare.y) < 0) {
		collision4 = false;
	}

	if ((collision1 == collision2) && (collision2 == collision3) && (collision3 == collision4)) {
		// ���ׂē����l�̏ꍇ
		return false;
	}
	else {
		// �قȂ�l���܂܂�Ă���ꍇ
		return true;
	}


}


