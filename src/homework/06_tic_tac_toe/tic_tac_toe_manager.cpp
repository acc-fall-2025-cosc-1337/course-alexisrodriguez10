//cpp
#include "tic_tac_toe_manager.h"

void TicTacToe3::save_game(TicTacToe b)
{
    games.push_back(b);
    update_winner_count(b.get_winner());
}

void TicTacToe3::get_winner_total(int& o, int& x, int& t)
{
    o = o_wins;
    x = x_wins;
    t = ties;
}

void TicTacToe3::update_winner_count(string winner)
{
    if (winner == "O")
    {
        o_wins+= 1;
    }
    else if (winner == "X")
    {
        x_wins+= 1;
    }
    else if (winner == "C")
    {
        ties+= 1;
    }
}



