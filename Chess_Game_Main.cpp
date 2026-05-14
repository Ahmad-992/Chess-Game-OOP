// Chess_Game_Main.cpp — Updated with Exception Handling

#include "Chess_Game_Header.h"

int main()
{
	try
	{
		Game game;
		game.start();
	}
	catch (bad_alloc& e)
	{
		// Catches memory allocation failure (e.g. new fails)
		cout << "Fatal Error: Not enough memory to run the game." << endl;
		cout << "Details: " << e.what() << endl;
	}
	catch (out_of_range& e)
	{
		// Catches any board coordinate that goes out of bounds
		cout << "Fatal Error: Board access out of range." << endl;
		cout << "Details: " << e.what() << endl;
	}
	catch (InvalidMoveException& e)
	{
		// Catches any unhandled invalid move that bubbles up
		cout << "Fatal Error: Unhandled invalid move." << endl;
		cout << "Details: " << e.getMessage() << endl;
	}
	catch (exception& e)
	{
		// Catches any other standard C++ exception
		cout << "Unexpected Error: " << e.what() << endl;
	}

	return 0;
}
