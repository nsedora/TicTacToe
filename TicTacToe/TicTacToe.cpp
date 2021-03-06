// TicTacToe.cpp : This file contains the main game class
//

#include "pch.h"
#include "TicTacToe.h"
#include <iostream>

using namespace std;
 

// Public:

TicTacToe::TicTacToe()
{
    ResetBoard();
}

bool
TicTacToe::AddToken(char t, unsigned x, unsigned y)
{
    bool ok = false;
    if (x < 3 && y < 3 && board[x][y] == '-')
    {
        board[x][y] = t;
        ok = true;
    }
    return ok;
}

void TicTacToe::PrintBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// TODO: Smart/AI version of MakeMyMove
bool 
TicTacToe::MakeMyMove()
{
    char *p = board[0];
    for (int i = 0; i < 9; ++i)
    {
        if (*p == '-')
        {
            *p = 'O';
            return true;
        }
        p++;
    }
    abort();
}

bool 
TicTacToe::Play()
{
    bool quit = false;

    ResetBoard();
    PrintBoard();

    while (1)
    {
        if (!MakeYourMove())
        {
            quit = true;
            break;
        }
        
        if (CheckForWinner('X') || IsFull())
        {
            PrintBoard();
            break;
        }

        MakeMyMove();
        PrintBoard();

        if (CheckForWinner('O') || IsFull())
        {
            break;
        }
    }

    return quit;
}

bool
TicTacToe::Winner(char &c)
{
    if (!IsFull())
    {
        if (winner != 'N')
        {
            c = winner;
            return true;
        }
    }
    return false;
}

// Private:

void TicTacToe::ResetBoard()
{
    winner = 'N';
    char *p = board[0];
    for (int i = 0; i < 9; i++)
    {
        *p++ = '-';
    }
}

bool 
TicTacToe::IsFull()
{
    char *p = board[0];
    for (int i = 0; i < 9; ++i)
    {
        if (*p++ == '-')
        { 
            return false;
        }
    }
    return true;
}

bool 
TicTacToe::IsLegal(unsigned x, unsigned y)
{
    if (x < 3 && y < 3 && board[x][y] == '-')
    {
        return true;
    }
    return false;
}

bool 
TicTacToe::MakeYourMove()
{
    unsigned x = (unsigned)-1;
    unsigned y = (unsigned)-1;

    while (1)
    {
        cout << endl << "Enter your move: <row col> (ex: 0 0) or -1 to Forfeit: ";
        cin >> x;
        if (x == (unsigned)-1)
        {
            return false;
        }
        cin >> y;
        cout << endl;

        if (IsLegal(x, y))
        {
            break;
        }

        cout << "Illegal move, try again..." << endl;
    } 

    return AddToken('X', x, y);
}

bool 
TicTacToe::CheckForWinner(char t)
{
    char *p = board[0];

    if ( (*p == t && *(p + 1) == t && *(p + 2) == t) ||
         (*(p + 3) == t && *(p + 4) == t && *(p + 5) == t) ||
         (*(p + 6) == t && *(p + 7) == t && *(p + 8) == t) ||
         // three rows
         (*p == t && *(p + 3) == t && *(p + 6) == t) ||
         (*(p + 1) == t && *(p + 4) == t && *(p + 7) == t) ||
         (*(p + 2) == t && *(p + 5) == t && *(p + 8) == t) ||
         // three columns
         (*p == t && *(p + 4) == t && *(p + 8) == t) ||
         (*(p + 2) == t && *(p + 4) == t && *(p + 6) == t) )
         // two diagonals
    {
        winner = t;
        return true;
    }

    return false;
}


