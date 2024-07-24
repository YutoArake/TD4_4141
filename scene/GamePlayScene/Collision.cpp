#include "Collision.h"




bool Collision::SquareToSquare(int mx1, int my1, int mx2, int my2, int ex1, int ey1, int ex2, int ey2)
{
	if (mx1 <= ex2 && ex1 <= mx2 && my1 <= ey2 && ey1 <= my2) {
		return true;
	}

	return false;
}

bool Collision::LineToSquare()
{
	return false;
}
