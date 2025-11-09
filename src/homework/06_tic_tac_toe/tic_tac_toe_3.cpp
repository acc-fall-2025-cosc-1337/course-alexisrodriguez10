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

string TicTacToe::get_winner() const
{
    return winner;
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
    if (check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if (check_board_full())
    {
        winner = "C";
        return true;
    }
    else

    {
        return false;
    }
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


bool TicTacToe::check_column_win()
{
    for (int i = 0; i < 3; ++i)
    {
        if (pegs[i] == pegs[i + 3] && pegs[i] == pegs[i + 6] && pegs[i] != " ")
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win()
{
    for (int i = 0; i < 9; i += 3)
    {
        if (pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2] && pegs[i] != " ")
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    if ((pegs[0] == pegs[4] && pegs[0] == pegs[8] && pegs[0] != " ") ||
        (pegs[2] == pegs[4] && pegs[2] == pegs[6] && pegs[2] != " "))
    {
        return true;
    }
    return false;
}

void TicTacToe::set_winner()
{
    if (player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
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
