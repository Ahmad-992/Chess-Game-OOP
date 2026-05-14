// Chess_Game_Header.h — Updated with Exception Handling

#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <stdexcept>    // for out_of_range, bad_alloc
using namespace std;

// ── Custom Exception Class ───────────────────────────────────
class InvalidMoveException
{
private:
	string message;
public:
	InvalidMoveException(string msg) : message(msg) {}
	string getMessage() const { return message; }
};
// ─────────────────────────────────────────────────────────────

class Piece
{
protected:
	char P_color;
	int P_row;
	int P_colun;
	char P_symbol;
public:
	Piece(char color, int row, int col, char sym);
	virtual ~Piece();
	char getColor();
	int getRow();
	int getCol();
	char getSymbol();
	void setRow(int r);
	void setCol(int c);
	virtual bool isValidMove(int R, int C, Piece* board[8][8]) = 0;
};

class Pawn : public Piece
{
private:
	bool has_Moved;
public:
	Pawn(char color, int row, int col, char sym);
	bool isValidMove(int R, int C, Piece* board[8][8]);
	void setHasMoved(bool v);
	bool getHasMoved();
};

class Rook : public Piece
{
public:
	Rook(char color, int row, int col, char sym);
	bool isValidMove(int R, int C, Piece* board[8][8]);
};

class knight : public Piece
{
public:
	knight(char color, int row, int col, char sym);
	bool isValidMove(int R, int C, Piece* board[8][8]);
};

class Bishop : public Piece
{
public:
	Bishop(char color, int row, int col, char sym);
	bool isValidMove(int R, int C, Piece* board[8][8]);
};

class Queen : public Piece
{
public:
	Queen(char color, int row, int col, char sym);
	bool isValidMove(int R, int C, Piece* board[8][8]);
};

class King : public Piece
{
public:
	King(char color, int row, int col, char sym);
	bool isValidMove(int R, int C, Piece* board[8][8]);
};

class Board
{
private:
	Piece* grid[8][8];
public:
	Board();
	~Board();
	void initilizeBoard();
	void Dispaly();
	Piece* getPiece(int row, int col);
	void movePiece(int from_Row, int from_Col, int t0Row, int toCol);
	bool isKingInCheck(char Color);
	Piece* (*getGrid())[8];
	void PawnSpecial(char Color, int row, int col);
	bool doesMoveResolveCheck(int fromRow, int fromCol, int toRow, int toCol, char color);
	bool isInCheckAfterMove(int fromRow, int fromCol, int toRow, int toCol, char color);
	bool isCheckMate(char color);
	bool isDraw();
};

class Player
{
private:
	string Player_name;
	char Player_color;
public:
	Player();
	Player(string n, char col);
	string getName();
	char getColor();
};

class Game
{
private:
	Board board;
	Player player[2];
	int currentPlayer;
	bool gameOver;

	void Parse_Input(const char* input, int& row, int& col);
	bool isValideSelectio(int fromRow, int formCol);
public:
	Game();
	void start();
	void switchTurn();
	void PrintWinner();
};
