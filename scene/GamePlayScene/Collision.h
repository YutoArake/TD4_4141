#pragma once



class Collision
{
public:
	/// <summary>
	/// �l�p�`���m�̓����蔻��
	/// </summary>
	/// <param name="mx1">�l�p�`1�̍���x���W</param>
	/// <param name="my1">�l�p�`1�̍���y���W</param>
	/// <param name="mx2">�l�p�`1�̉E��x���W</param>
	/// <param name="my2">�l�p�`1�̉E��y���W</param>
	/// <param name="ex1">�l�p�`2�̍���x���W</param>
	/// <param name="ey1">�l�p�`2�̍���y���W</param>
	/// <param name="ex2">�l�p�`2�̉E��x���W</param>
	/// <param name="ey2">�l�p�`2�̉E��y���W</param>
	/// <returns>�������Ă邩�̐���</returns>
	bool SquareToSquare(int mx1, int my1, int mx2, int my2, int ex1, int ey1, int ex2, int ey2);

	bool LineToSquare();
};



