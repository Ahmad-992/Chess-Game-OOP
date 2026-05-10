#include "Chess_Game_Header.h"

Pawn::Pawn(char color, int row, int col, char sym) :Piece(color, row, col, sym)
{
	has_Moved = false;
}
void Pawn::setHasMoved(bool v) { has_Moved = v; }
bool Pawn::getHasMoved() { return has_Moved; }
bool Pawn::isValidMove(int R, int C, Piece* board[8][8])
{
	if (R >= 1 && R <= 8 && C >= 1 && C <= 8)
	{
		if (P_color == 'B' || P_color == 'b')
		{
			if (R - 1 > P_row)
			{
				if (R - 1 - P_row == 1)
				{
					if (C - 1 == P_colun)
						if (board[R - 1][C - 1] == nullptr)
							return true;
					if (C - 1 - P_colun == 1 || C - 1 - P_colun == -1)
						if (board[R - 1][C - 1] != nullptr)
							if (board[R - 1][C - 1]->getColor() != P_color)
								return true;
				}
				if (R - 1 - P_row == 2)
					if (!has_Moved)
						if (C - 1 == P_colun)
							if (board[R - 1][C - 1] == nullptr)
								if (board[R - 2][C - 1] == nullptr)
									return true;
			}
		}
		if (P_color == 'w' || P_color == 'W')
		{
			if (R - 1 < P_row)
			{
				if (R - 1 - P_row == -1)
				{
					if (C - 1 == P_colun)
						if (board[R - 1][C - 1] == nullptr)
							return true;
					if (C - 1 - P_colun == 1 || C - 1 - P_colun == -1)
						if (board[R - 1][C - 1] != nullptr)
							if (board[R - 1][C - 1]->getColor() != P_color)
								return true;
				}
				if (R - 1 - P_row == -2)
					if (!has_Moved)
						if (C - 1 == P_colun)
							if (board[R - 1][C - 1] == nullptr)
								if (board[R][C - 1] == nullptr)
									return true;
			}
		}
		return false;
	}
	return false;
}