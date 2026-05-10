#include "Chess_Game_Header.h"

Rook::Rook(char color, int row, int col, char sym) :Piece(color, row, col, sym) {}
bool Rook::isValidMove(int R, int C, Piece* board[8][8])
{
	if (R >= 1 && R <= 8 && C >= 1 && C <= 8)
	{
		if (R - 1 == P_row)
		{
			if (C - 1 < P_colun)
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < (P_colun - (C - 1)); i++)
							if (board[R - 1][C - 1 + i] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 0; i < (P_colun - (C - 1)); i++)
						if (board[R - 1][C - 1 + i] != nullptr) return false;
					return true;
				}
			}
			if (C - 1 > P_colun)
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < ((C - 1) - P_colun); i++)
							if (board[R - 1][C - 1 - i] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 0; i < ((C - 1) - P_colun); i++)
						if (board[R - 1][C - 1 - i] != nullptr) return false;
					return true;
				}
			}
		}
		if (C - 1 == P_colun)
		{
			if (R - 1 < P_row)
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < (P_row - (R - 1)); i++)
							if (board[R - 1 + i][C - 1] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 0; i < (P_row - (R - 1)); i++)
						if (board[R - 1 + i][C - 1] != nullptr) return false;
					return true;
				}
			}
			if (R - 1 > P_row)
			{
				if (board[R - 1][C - 1] != nullptr)
				{
					if (board[R - 1][C - 1]->getColor() != P_color)
					{
						for (int i = 1; i < (R - 1 - P_row); i++)
							if (board[R - 1 - i][C - 1] != nullptr) return false;
						return true;
					}
				}
				else
				{
					for (int i = 1; i < (R - 1 - P_row); i++)
						if (board[R - 1 - i][C - 1] != nullptr) return false;
					return true;
				}
			}
		}
	}
	return false;
}