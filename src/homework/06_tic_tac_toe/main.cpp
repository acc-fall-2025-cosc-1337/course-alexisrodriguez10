#include <iostream>
#include "tic_tac_toe_3.h"
using namespace std;


int main()
{
    TicTacToe game;
    string first_player;
    char choice = 'Y';

    cout << "Welcome to Tic Tac Toe!\n";


    while (choice == 'y' || choice == 'Y')
    {
        do
        {
        cout << "Enter first player (X or O): ";
        cin >> first_player;

        if (first_player != "X" && first_player != "O")
        {
            cout << "Invalid input! Please enter 'X' or 'O'.\n";
        }

        } while (first_player != "X" && first_player != "O");

        
        game.start_game(first_player);

        int position;

        
        while (!game.game_over())
        {
            game.display_board();
            cout << "Player " << game.get_player()
                 << ", enter a position (1-9): ";
            cin >> position;

            
            if (position < 1 || position > 9)
            {
                cout << "Invalid position! Please enter a number 1-9.\n";
                continue;
            }

            game.mark_board(position);
        }

        cout << "\nFinal Board:\n";
        game.display_board();

        string winner = game.get_winner();

        if (winner == "C")
        {
            cout << "It's a tie! (Cat’s Game)\n";
        }
        else
        {
            cout << "🎉 Player " << winner << " wins! 🎉\n";
        }


        cout << "Would you like to play another game? (Y/N): ";
        cin >> choice;
        cout << "\n";
        
    }

    return 0;
}