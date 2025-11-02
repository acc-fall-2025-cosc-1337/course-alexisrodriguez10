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
        
        cout << "Enter first player (X or O): ";
        cin >> first_player;

        
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

        
        cout << "\nGame Over!\n";
        game.display_board();
        cout << "It's a tie! (No winner )\n";

        // 5) Clear the board for a new game
        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
        cout << "\n";
    }

    return 0;
}