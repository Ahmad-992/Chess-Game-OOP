# Chess Game — OOP C++

A fully functional two-player Chess Game built in C++ using Object-Oriented Programming concepts.

## Group Members
| Member | GitHub | Role |
|--------|--------|------|
| Ahmad Ijaz | Ahmad-992 | Piece movement logic (Pawn, Rook, Knight) |
| Ghulam Hussain Ansari | Ghulam-Hussain-Ansari | Board logic, Check, Checkmate, Game loop |

## Features
- Two player turn-based chess
- Valid move detection for all pieces
- Check and Checkmate detection
- Draw detection
- Pawn promotion
- Console based display

## How to Run
1. Open project in Visual Studio
2. Add all 3 files to the project
3. Build and Run

## Files
| File | Description |
|------|-------------|
| `Chess_Game_Header.h` | All class declarations |
| `Chess_Game_implement.cpp` | All class implementations |
| `Chess_Game_Main.cpp` | Main entry point |

## OOP Concepts Used
- Inheritance — Pawn, Rook, Knight, Bishop, Queen, King inherit from Piece
- Polymorphism — isValidMove() overridden in each piece
- Encapsulation — private data members with getters/setters
- Abstraction — Piece base class with pure virtual function
