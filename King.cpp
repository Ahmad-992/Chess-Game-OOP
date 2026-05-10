#include "Chess_Game_Header.h"

King::King(char color, int row, int col, char sym) :Piece(color, row, col, sym) {}
bool King::isValidMove(int R, int C, Piece* board[8][8])
{
	if (R >= 1 && R <= 8 && C >= 1 && C <= 8)
	{
		int x = P_row, y = P_colun;
		if ((R - 1 == x + 1 && C - 1 == y + 1) || (R - 1 == x - 1 && C - 1 == y - 1) ||
			(R - 1 == x - 1 && C - 1 == y + 1) || (R - 1 == x + 1 && C - 1 == y - 1) ||
			(R - 1 == x + 1 && C - 1 == y) || (R - 1 == x - 1 && C - 1 == y) ||
			(R - 1 == x && C - 1 == y - 1) || (R - 1 == x && C - 1 == y + 1))
		{
			if (board[R - 1][C - 1] != nullptr)
				if (board[R - 1][C - 1]->getColor() == P_color) return false;
			Piece* savedDest = board[R - 1][C - 1];
			Piece* savedKingSquare = board[x][y];
			board[R - 1][C - 1] = board[x][y];
			board[x][y] = nullptr;
			bool squareIsAttacked = false;
			for (int i = 0; i < 8 && !squareIsAttacked; i++)
				for (int j = 0; j < 8 && !squareIsAttacked; j++)
					if (board[i][j] != nullptr)
						if (board[i][j]->getColor() != P_color)
							if (board[i][j]->isValidMove(R, C, board))
								squareIsAttacked = true;
			board[x][y] = savedKingSquare;
			board[R - 1][C - 1] = savedDest;
			if (squareIsAttacked) return false;
			return true;
		}
	}
	return false;
}