#include "Chess_Game_Header.h"

Board::Board() { initilizeBoard(); }
Board::~Board() {}
void Board::initilizeBoard()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			grid[i][j] = nullptr;
	grid[0][0] = new Rook('B', 0, 0, 'r');
	grid[0][1] = new knight('B', 0, 1, 'n');
	grid[0][2] = new Bishop('B', 0, 2, 'b');
	grid[0][3] = new Queen('B', 0, 3, 'q');
	grid[0][4] = new King('B', 0, 4, 'k');
	grid[0][5] = new Bishop('B', 0, 5, 'b');
	grid[0][6] = new knight('B', 0, 6, 'n');
	grid[0][7] = new Rook('B', 0, 7, 'r');
	grid[1][0] = new Pawn('B', 1, 0, 'p');
	grid[1][1] = new Pawn('B', 1, 1, 'p');
	grid[1][2] = new Pawn('B', 1, 2, 'p');
	grid[1][3] = new Pawn('B', 1, 3, 'p');
	grid[1][4] = new Pawn('B', 1, 4, 'p');
	grid[1][5] = new Pawn('B', 1, 5, 'p');
	grid[1][6] = new Pawn('B', 1, 6, 'p');
	grid[1][7] = new Pawn('B', 1, 7, 'p');
	grid[6][0] = new Pawn('W', 6, 0, 'P');
	grid[6][1] = new Pawn('W', 6, 1, 'P');
	grid[6][2] = new Pawn('W', 6, 2, 'P');
	grid[6][3] = new Pawn('W', 6, 3, 'P');
	grid[6][4] = new Pawn('W', 6, 4, 'P');
	grid[6][5] = new Pawn('W', 6, 5, 'P');
	grid[6][6] = new Pawn('W', 6, 6, 'P');
	grid[6][7] = new Pawn('W', 6, 7, 'P');
	grid[7][0] = new Rook('W', 7, 0, 'R');
	grid[7][1] = new knight('W', 7, 1, 'N');
	grid[7][2] = new Bishop('W', 7, 2, 'B');
	grid[7][3] = new Queen('W', 7, 3, 'Q');
	grid[7][4] = new King('W', 7, 4, 'K');
	grid[7][5] = new Bishop('W', 7, 5, 'B');
	grid[7][6] = new knight('W', 7, 6, 'N');
	grid[7][7] = new Rook('W', 7, 7, 'R');
}
void Board::Dispaly()
{
	cout << "     a   b   c   d   e   f   g   h " << endl;
	cout << "   +---+---+---+---+---+---+---+---+" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << 8 - i << " |";
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == nullptr) cout << " . |";
			else cout << " " << grid[i][j]->getSymbol() << " |";
		}
		cout << endl << "   +---+---+---+---+---+---+---+---+" << endl;
	}
}
Piece* Board::getPiece(int row, int col) { return grid[row][col]; }
Piece* (*Board::getGrid())[8] { return grid; }
void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol)
{
	if (grid[toRow][toCol] != nullptr)
	{
		if (grid[toRow][toCol]->getColor() != grid[fromRow][fromCol]->getColor())
		{
			delete grid[toRow][toCol];
			grid[toRow][toCol] = nullptr;
			grid[toRow][toCol] = grid[fromRow][fromCol];
			grid[toRow][toCol]->setRow(toRow);
			grid[toRow][toCol]->setCol(toCol);
			grid[fromRow][fromCol] = nullptr;
		}
	}
	else
	{
		grid[toRow][toCol] = grid[fromRow][fromCol];
		grid[toRow][toCol]->setRow(toRow);
		grid[toRow][toCol]->setCol(toCol);
		grid[fromRow][fromCol] = nullptr;
	}
}
void Board::PawnSpecial(char Color, int row, int col)
{
	char sym;
	bool b = true;
	do {
		cout << "Wow. Your Pawn is now converting into higher piece. " << endl;
		cout << "Enter the Symbol of your piece ";
		cin >> sym;
		if (Color == 'w' || Color == 'W')
		{
			if (sym == 'R') { delete grid[row][col]; grid[row][col] = new Rook(Color, row, col, sym); b = false; }
			else if (sym == 'N') { delete grid[row][col]; grid[row][col] = new knight(Color, row, col, sym); b = false; }
			else if (sym == 'B') { delete grid[row][col]; grid[row][col] = new Bishop(Color, row, col, sym); b = false; }
			else if (sym == 'Q') { delete grid[row][col]; grid[row][col] = new Queen(Color, row, col, sym); b = false; }
			else { cout << "Invalid." << endl; b = true; }
		}
		else
		{
			if (sym == 'r') { delete grid[row][col]; grid[row][col] = new Rook(Color, row, col, sym); b = false; }
			else if (sym == 'n') { delete grid[row][col]; grid[row][col] = new knight(Color, row, col, sym); b = false; }
			else if (sym == 'b') { delete grid[row][col]; grid[row][col] = new Bishop(Color, row, col, sym); b = false; }
			else if (sym == 'q') { delete grid[row][col]; grid[row][col] = new Queen(Color, row, col, sym); b = false; }
			else { cout << "Invalid." << endl; b = true; }
		}
	} while (b);
}
bool Board::isKingInCheck(char Color)
{
	int r, c, row, col;
	bool f = false;
	for (r = 0; r < 8 && !f; r++)
		for (c = 0; c < 8 && !f; c++)
			if (grid[r][c] != nullptr)
				if (grid[r][c]->getSymbol() == 'k' || grid[r][c]->getSymbol() == 'K')
					if (grid[r][c]->getColor() == Color)
					{ row = r; col = c; f = true; }
	if (!f) return false;
	for (int r1 = 0; r1 < 8; r1++)
		for (int c1 = 0; c1 < 8; c1++)
			if (grid[r1][c1] != nullptr)
				if (grid[r1][c1]->getColor() != Color)
					if (grid[r1][c1]->isValidMove(row + 1, col + 1, getGrid()))
						return true;
	return false;
}
bool Board::doesMoveResolveCheck(int fromRow, int fromCol, int toRow, int toCol, char color)
{
	Piece* destinationPiece = grid[toRow][toCol];
	grid[toRow][toCol] = grid[fromRow][fromCol];
	grid[fromRow][fromCol] = nullptr;
	grid[toRow][toCol]->setRow(toRow);
	grid[toRow][toCol]->setCol(toCol);
	bool stillInCheck = isKingInCheck(color);
	grid[fromRow][fromCol] = grid[toRow][toCol];
	grid[toRow][toCol] = destinationPiece;
	grid[fromRow][fromCol]->setRow(fromRow);
	grid[fromRow][fromCol]->setCol(fromCol);
	return stillInCheck;
}
bool Board::isInCheckAfterMove(int fromRow, int fromCol, int toRow, int toCol, char color)
{
	Piece* destinationPiece = grid[toRow][toCol];
	grid[toRow][toCol] = grid[fromRow][fromCol];
	grid[fromRow][fromCol] = nullptr;
	grid[toRow][toCol]->setRow(toRow);
	grid[toRow][toCol]->setCol(toCol);
	bool kingExposed = isKingInCheck(color);
	grid[fromRow][fromCol] = grid[toRow][toCol];
	grid[toRow][toCol] = destinationPiece;
	grid[fromRow][fromCol]->setRow(fromRow);
	grid[fromRow][fromCol]->setCol(fromCol);
	return kingExposed;
}
bool Board::isCheckMate(char color)
{
	if (!isKingInCheck(color)) return false;
	for (int fromRow = 0; fromRow < 8; fromRow++)
		for (int fromCol = 0; fromCol < 8; fromCol++)
		{
			if (grid[fromRow][fromCol] == nullptr) continue;
			if (grid[fromRow][fromCol]->getColor() != color) continue;
			for (int toRow = 0; toRow < 8; toRow++)
				for (int toCol = 0; toCol < 8; toCol++)
				{
					if (fromRow == toRow && fromCol == toCol) continue;
					if (!grid[fromRow][fromCol]->isValidMove(toRow + 1, toCol + 1, grid)) continue;
					if (!doesMoveResolveCheck(fromRow, fromCol, toRow, toCol, color)) return false;
				}
		}
	return true;
}
bool Board::isDraw()
{
	int whitePieces = 0, blackPieces = 0;
	char whiteExtra = ' ', blackExtra = ' ';
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == nullptr) continue;
			char sym = grid[i][j]->getSymbol();
			char col = grid[i][j]->getColor();
			if (col == 'W') { whitePieces++; if (sym != 'K') whiteExtra = sym; }
			else { blackPieces++; if (sym != 'k') blackExtra = sym; }
		}
	int totalPieces = whitePieces + blackPieces;
	if (totalPieces == 2) return true;
	if (whitePieces == 2 && blackPieces == 1 && (whiteExtra == 'B' || whiteExtra == 'N')) return true;
	if (blackPieces == 2 && whitePieces == 1 && (blackExtra == 'b' || blackExtra == 'n')) return true;
	if (whitePieces == 2 && blackPieces == 2 && whiteExtra == 'B' && blackExtra == 'b') return true;
	for (int color = 0; color < 2; color++)
	{
		char currentColor = (color == 0) ? 'W' : 'B';
		if (isKingInCheck(currentColor)) continue;
		bool hasLegalMove = false;
		for (int fromRow = 0; fromRow < 8 && !hasLegalMove; fromRow++)
			for (int fromCol = 0; fromCol < 8 && !hasLegalMove; fromCol++)
			{
				if (grid[fromRow][fromCol] == nullptr) continue;
				if (grid[fromRow][fromCol]->getColor() != currentColor) continue;
				for (int toRow = 0; toRow < 8 && !hasLegalMove; toRow++)
					for (int toCol = 0; toCol < 8 && !hasLegalMove; toCol++)
					{
						if (fromRow == toRow && fromCol == toCol) continue;
						if (!grid[fromRow][fromCol]->isValidMove(toRow + 1, toCol + 1, grid)) continue;
						if (!doesMoveResolveCheck(fromRow, fromCol, toRow, toCol, currentColor)) hasLegalMove = true;
					}
			}
		if (!hasLegalMove) return true;
	}
	return false;
}