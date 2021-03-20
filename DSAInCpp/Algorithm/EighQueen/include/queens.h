#ifndef QUEEN_H_
#define QUEEN_H_

#include <iostream>

using namespace std;

class ChessBoard
{
public:
	ChessBoard(); //8x8
	ChessBoard(int n); //nxn
	void findSolution();
private:
	const bool available;
	const int squares;
	const int norm;
	bool *column, *leftDiagonal, *rightDiagonal;
	int *positionInRow, howMany;
	
	void putQueen(int);
	void printBoard(ostream& );
	void initializeBoard();	
};

ChessBoard::ChessBoard(): available(true), squares(8), norm(squares-1)
{
    initializeBoard();
}
ChessBoard::ChessBoard(int  n): available(true), squares(4), norm(squares-1)
{
    initializeBoard();
}

void ChessBoard::putQueen(int row)
{
    for(int col =0; col < squares; col ++)
    {
        if(column[col] == available  &&\
            leftDiagonal[row + col] == available &&\
            rightDiagonal[row-col+norm] == available
            )
        {
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row + col] = !available;
            rightDiagonal[row-col+norm] = !available;
            if( row < squares - 1)
            {
                putQueen(row+1);
            }
            else   
                printBoard(cout);
            column[col] = available;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col + norm] = available;
        }
    }
}

void ChessBoard::printBoard(ostream& os)
{
    
}

void ChessBoard::initializeBoard()
{
    register int i;
    column = new bool[squares];
    positionInRow = new int [squares];
    leftDiagonal = new bool[squares*2 - 1];
    rightDiagonal = new bool[squares*2 -  1];
    for(i = 0; i < squares; i++)
    {
        positionInRow[i] = -1;
    }
    
    for(i = 0; i < squares; i++ )
    {
        column[i] = available;
    }

    for( i = 0; i < squares*2 -1; i++) 
    {
        leftDiagonal[i] = rightDiagonal[i] = available;
    }

    howMany = 0;
}

void ChessBoard::findSolution()
{
    putQueen(0);
    cout << howMany << "solution found.\n";
}
#endif
