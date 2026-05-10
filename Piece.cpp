#include "Chess_Game_Header.h"

Piece::Piece(char color, int row, int col, char sym) : P_color(color), P_row(row), P_colun(col), P_symbol(sym) {}
char Piece::getColor() { return P_color; }
int Piece::getRow() { return P_row; }
int Piece::getCol() { return P_colun; }
char Piece::getSymbol() { return P_symbol; }
void Piece::setRow(int r) { P_row = r; }
void Piece::setCol(int c) { P_colun = c; }
bool Piece::isValidMove(int R, int C, Piece* board[8][8]) { return true; }
Piece::~Piece() {}