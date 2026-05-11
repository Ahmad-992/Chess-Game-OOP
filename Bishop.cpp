#include "Chess_Game_Header.h"

Bishop::Bishop(char color, int row, int col, char sym) :Piece(color, row, col, sym) {}
bool Bishop::isValidMove(int R, int C, Piece* board[8][8])
{
	if (R >= 1 && R <= 8 && C >= 1 && C <= 8)
	{
		if (R - 1 > P_row && C - 1 > P_colun)
			if ((R - 1) - P_row == (C - 1) - P_colun)
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < (R - 1) - P_row; i++)
							if (board[P_row + i][P_colun + i] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 1; i < (R - 1) - P_row; i++)
						if (board[P_row + i][P_colun + i] != nullptr) return false;
					return true;
				}
			}
		if (R - 1 < P_row && C - 1 > P_colun)
			if (P_row - (R - 1) == (C - 1) - P_colun)
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < P_row - (R - 1); i++)
							if (board[P_row - i][P_colun + i] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 1; i < P_row - (R - 1); i++)
						if (board[P_row - i][P_colun + i] != nullptr) return false;
					return true;
				}
			}
		if (R - 1 > P_row && C - 1 < P_colun)
			if ((R - 1) - P_row == P_colun - (C - 1))
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < (R - 1) - P_row; i++)
							if (board[P_row + i][P_colun - i] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 1; i < (R - 1) - P_row; i++)
						if (board[P_row + i][P_colun - i] != nullptr) return false;
					return true;
				}
			}
		if (R - 1 < P_row && C - 1 < P_colun)
			if (P_row - (R - 1) == P_colun - (C - 1))
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < P_row - (R - 1); i++)
							if (board[P_row - i][P_colun - i] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 1; i < P_row - (R - 1); i++)
						if (board[P_row - i][P_colun - i] != nullptr) return false;
					return true;
				}
			}
	}
	return false;
}