#pragma once

// TicTacToe.h : Main game class

#include "pch.h"
 
class TicTacToe
{
public:
    TicTacToe();

    bool AddToken(char t, unsigned x, unsigned y);
    void PrintBoard();
    bool MakeMyMove();
    bool Play();
    bool Winner(char &c);

private:
    char board[3][3];
    char winner;

    void ResetBoard();
    bool IsFull();
    bool IsLegal(unsigned x, unsigned y);
    bool MakeYourMove();
    bool CheckForWinner(char t);
};
