#include "Chess_Game_Header.h"

Queen::Queen(char color, int row, int col, char sym) :Piece(color, row, col, sym) {}
bool Queen::isValidMove(int R, int C, Piece* board[8][8])
{
	Rook tempRook(P_color, P_row, P_colun, 'R');
	Bishop tempBishop(P_color, P_row, P_colun, 'B');
	return tempRook.isValidMove(R, C, board) || tempBishop.isValidMove(R, C, board);
}