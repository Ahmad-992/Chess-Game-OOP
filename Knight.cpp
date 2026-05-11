#include "Chess_Game_Header.h"

knight::knight(char color, int row, int col, char sym) : Piece(color, row, col, sym) {}
bool knight::isValidMove(int R, int C, Piece* board[8][8])
{
	if (R >= 1 && R <= 8 && C >= 1 && C <= 8)
	{
		int x = P_row, y = P_colun;
		if ((R - 1 == x + 2 && C - 1 == y + 1) || (R - 1 == x + 2 && C - 1 == y - 1) ||
			(R - 1 == x - 2 && C - 1 == y + 1) || (R - 1 == x - 2 && C - 1 == y - 1) ||
			(R - 1 == x + 1 && C - 1 == y + 2) || (R - 1 == x - 1 && C - 1 == y + 2) ||
			(R - 1 == x + 1 && C - 1 == y - 2) || (R - 1 == x - 1 && C - 1 == y - 2))
		{
			if (board[R - 1][C - 1] == nullptr) return true;
			else if (board[R - 1][C - 1]->getColor() != P_color) return true;
		}
	}
	return false;
}