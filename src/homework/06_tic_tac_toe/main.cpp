#include <iostream>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_manager.h"
using namespace std;


int main()
{
    TicTacToe3 manager;
    TicTacToe game;
    string first_player;
    char choice = 'y';
    int o_wins, x_wins, ties;

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
            cout << "It's a tie! \n";
        }
        else
        {
            cout << "🎉 Player " << winner << " wins! 🎉\n";
        }

        manager.save_game(game);
        manager.get_winner_total(o_wins, x_wins, ties);
        cout<< "Scoreboard:\n";
        cout << "Player X Wins: " << x_wins << "\n";
        cout << "Player O Wins: " << o_wins << "\n";
        cout << "Ties: " << ties << "\n";


        cout << "Would you like to play another game? (Y/N): ";
        cin >> choice;
        cout << "\n";




        
    }

    cout << "The Winner Is \n";
    manager.get_winner_total(o_wins, x_wins, ties);
    if (o_wins > x_wins)
    {
        cout << "Player O with " << o_wins << " wins!\n";
    }
    else if (x_wins > o_wins)
    {
        cout << "Player X with " << x_wins << " wins!\n";
    }
    else
    {
        cout << "It's a tie overall with both players having "
             << x_wins << " wins!\n";
    }



    return 0;
}