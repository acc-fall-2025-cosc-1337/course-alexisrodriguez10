#include "tic_tac_toe_3.h"
#include <iostream>
using namespace std;


void TicTacToe::start_game(string first_player)
{
    if (first_player == "X" || first_player == "O")
    {
        player = first_player;
        clear_board();
    }
    else
    {
        cout << "Invalid first player. Please choose 'X' or 'O'." << endl;
    }

    {
        /* code */
    }
    
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();

}
string TicTacToe::get_player() const
{
    return player;
}   

void TicTacToe::display_board() const
{
    cout << pegs[0] << "|" << pegs[1] << "|" << pegs[2] << endl;
    cout << "-+-+-" << endl;
    cout << pegs[3] << "|" << pegs[4] << "|" << pegs[5] << endl;
    cout << "-+-+-" << endl;
    cout << pegs[6] << "|" << pegs[7] << "|" << pegs[8] << endl;
}

bool TicTacToe::game_over()
{
    return check_board_full();
}

void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}


bool TicTacToe::check_board_full()
{
    for (const auto &peg : pegs)
    {
        if (peg == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board()
{
    for (auto &peg : pegs)
    {
        peg = " ";
    }
}









/*
class function check_column_win
Win by column if and return true if
0,3, and 6 are equal
1, 4, and 7
2, 5, and 8
else
false
*/



/*
class function check_row_win
Win by row if
0, 1, 2 are equal
3,4,5 are equal
6,7,8 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0 1 2
3 4 5
6 7 8

*/
