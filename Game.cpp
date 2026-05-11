#include "Chess_Game_Header.h"

Player::Player() { Player_name = "None"; Player_color = ' '; }
Player::Player(string n, char col) { Player_name = n; Player_color = col; }
string Player::getName() { return Player_name; }
char Player::getColor() { return Player_color; }

Game::Game()
{
	char name1[50], name2[50];
	system("cls");
	cout << "================================" << endl;
	cout << "       CHESS GAME OOP C++       " << endl;
	cout << "================================" << endl;
	cout << endl;
	cout << "Enter name for White player: ";
	cin >> name1;
	cin.ignore();
	cout << "Enter name for Black player: ";
	cin >> name2;
	player[0] = Player(name1, 'W');
	player[1] = Player(name2, 'B');
	currentPlayer = 0;
	gameOver = false;
	cout << endl;
	cout << "White: " << player[0].getName() << endl;
	cout << "Black: " << player[1].getName() << endl;
	cout << "White moves first. Good luck!" << endl << endl;
}
void Game::switchTurn() { currentPlayer = 1 - currentPlayer; }
void Game::Parse_Input(const char* input, int& row, int& col)
{
	col = input[0] - 'a';
	row = 8 - (input[1] - '0');
}
bool Game::isValideSelectio(int fromRow, int fromCol)
{
	if (fromRow < 0 || fromRow > 7 || fromCol < 0 || fromCol > 7)
	{ cout << "Invalid input. Square is outside the board." << endl; return false; }
	Piece* p = board.getPiece(fromRow, fromCol);
	if (p == nullptr)
	{ cout << "No piece at that square. Try again." << endl; return false; }
	if (p->getColor() != player[currentPlayer].getColor())
	{ cout << "That piece does not belong to you. Try again." << endl; return false; }
	return true;
}
void Game::start()
{
	char fromInput[10], toInput[10];
	int fromRow, fromCol, toRow, toCol;
	while (!gameOver)
	{
		board.Dispaly();
		cout << endl;
		cout << "--- " << player[currentPlayer].getName();
		cout << "'s turn (";
		cout << (player[currentPlayer].getColor() == 'W' ? "White" : "Black");
		cout << ") ---" << endl;
		cout << "Enter move (e.g. e2 e4): ";
		cin >> fromInput >> toInput;
		if (fromInput[0] < 'a' || fromInput[0] > 'h' || toInput[0] < 'a' || toInput[0] > 'h')
		{ cout << "Invalid input. Columns must be a to h." << endl; continue; }
		if (fromInput[1] < '1' || fromInput[1] > '8' || toInput[1] < '1' || toInput[1] > '8')
		{ cout << "Invalid input. Rows must be 1 to 8." << endl; continue; }
		Parse_Input(fromInput, fromRow, fromCol);
		Parse_Input(toInput, toRow, toCol);
		if (!isValideSelectio(fromRow, fromCol)) continue;
		Piece* p = board.getPiece(fromRow, fromCol);
		if (!p->isValidMove(toRow + 1, toCol + 1, board.getGrid()))
		{ cout << "Invalid move for that piece. Try again." << endl; continue; }
		if (board.isKingInCheck(player[currentPlayer].getColor()))
		{
			if (board.doesMoveResolveCheck(fromRow, fromCol, toRow, toCol, player[currentPlayer].getColor()))
			{ cout << "You are in check! This move does not resolve the check." << endl; continue; }
		}
		else
		{
			if (board.isInCheckAfterMove(fromRow, fromCol, toRow, toCol, player[currentPlayer].getColor()))
			{ cout << "This move leaves your King in check!" << endl; continue; }
		}
		Piece* destination = board.getPiece(toRow, toCol);
		if (destination != nullptr)
			cout << player[currentPlayer].getName() << " captures opponent's piece at " << toInput << "!" << endl;
		board.movePiece(fromRow, fromCol, toRow, toCol);
		Piece* p2 = board.getPiece(toRow, toCol);
		if (p2 != nullptr && (p2->getSymbol() == 'P' || p2->getSymbol() == 'p'))
		{
			Pawn* pawn = (Pawn*)p2;
			pawn->setHasMoved(true);
			if (p2->getRow() == 0 || p2->getRow() == 7)
				board.PawnSpecial(p2->getColor(), toRow, toCol);
		}
		if (board.isDraw())
		{
			board.Dispaly();
			cout << "\n================================" << endl;
			cout << "             DRAW!              " << endl;
			cout << "================================" << endl;
			char choice;
			cout << "\nPlay again? (y/n): ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y') { board = Board(); currentPlayer = 0; gameOver = false; }
			else { cout << "Thanks for playing. Goodbye!" << endl; gameOver = true; }
			continue;
		}
		char opponentColor = (player[currentPlayer].getColor() == 'W') ? 'B' : 'W';
		if (board.isKingInCheck(opponentColor))
		{
			if (board.isCheckMate(opponentColor))
			{
				board.Dispaly();
				cout << "\n================================" << endl;
				cout << "           CHECKMATE!           " << endl;
				cout << "================================" << endl;
				cout << "  " << player[currentPlayer].getName() << " wins!" << endl;
				cout << "================================" << endl;
				char choice;
				cout << "\nPlay again? (y/n): ";
				cin >> choice;
				if (choice == 'y' || choice == 'Y') { board = Board(); currentPlayer = 0; gameOver = false; }
				else { cout << "Thanks for playing. Goodbye!" << endl; gameOver = true; }
				continue;
			}
			else { cout << "Check!" << endl; switchTurn(); }
		}
		else switchTurn();
	}
}
void Game::PrintWinner() {}