#pragma once



class Collision
{
public:
	/// <summary>
	/// 四角形同士の当たり判定
	/// </summary>
	/// <param name="mx1">四角形1の左上x座標</param>
	/// <param name="my1">四角形1の左上y座標</param>
	/// <param name="mx2">四角形1の右下x座標</param>
	/// <param name="my2">四角形1の右下y座標</param>
	/// <param name="ex1">四角形2の左上x座標</param>
	/// <param name="ey1">四角形2の左上y座標</param>
	/// <param name="ex2">四角形2の右下x座標</param>
	/// <param name="ey2">四角形2の右下y座標</param>
	/// <returns>当たってるかの成否</returns>
	bool SquareToSquare(int mx1, int my1, int mx2, int my2, int ex1, int ey1, int ex2, int ey2);

	bool LineToSquare();
};



