// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TicTacToe.h"
#include <iostream>

using namespace std;

int main()
{
    bool quit = false;

    TicTacToe game;

    while (!quit)
    {
        quit = game.Play();

        if (!quit)
        {
            char token;
            if (game.Winner(token))
            {
                if (token == 'X')
                {
                    cout << "Congratulations! Give me another chance? (Y/N): ";
                }
                else
                {
                    cout << "I win. Try again?  (Y/N): ";
                }
            }
            else
            {
                cout << "It's a tie! Play again? (Y/N): ";
            }

            cin >> token;
            if (token == 'N' || token == 'n')
            {
                quit = true;
            }

            cout << endl;
        }
    }

    return 0;
} 