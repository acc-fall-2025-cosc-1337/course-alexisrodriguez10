//cpp
#include "tic_tac_toe_manager.h"
#include <iostream>

using namespace std;

void TicTacToeManager::save_game(unique_ptr<TicTacToe>& game)
{
    // 2a) First: update winner count, using -> for get_winner
    update_winner_count(game->get_winner());

    // 2b) Move the unique_ptr into the vector
    games.push_back(move(game));
}

void TicTacToeManager::get_winner_total(int& o, int& x, int& t)
{
    o = o_win;
    x = x_win;
    t = ties;
}

void TicTacToeManager::update_winner_count(string winner)
{
    if (winner == "X")
    {
        x_win++;
    }
    else if (winner == "O")
    {
        o_win++;
    }
    else
    {
        // Assume anything else is a tie (usually "C")
        ties++;
    }
}

// 3) Display all games played
void TicTacToeManager::display_games() const
{
    int game_number = 1;

    // 3a) auto& game (reference to unique_ptr)
    for (const auto& game : games)
    {
        cout << "Game " << game_number++ << ":\n";

        // 3b) Dereference pointer in the block: *game
        // If you have operator<< overloaded for TicTacToe, you can do:
        // cout << *game << "\n";
        // Otherwise, use the member display_board:
        game->display_board();

        string w = game->get_winner();
        cout << "\nResult: ";
        if (w == "C")
        {
            cout << "Tie";
        }
        else
        {
            cout << "Winner " << w;
        }
        cout << "\n\n";
    }

    cout << "Totals — X wins: " << x_win
         << " | O wins: " << o_win
         << " | Ties: "   << ties << "\n";
}
