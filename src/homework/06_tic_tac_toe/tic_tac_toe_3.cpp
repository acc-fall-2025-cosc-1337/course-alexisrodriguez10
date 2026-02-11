#include "tic_tac_toe_3.h"

bool TicTacToe3::check_row_win()
{
    // rows: 0-1-2, 3-4-5, 6-7-8
    for (int r = 0; r < 3; ++r)
    {
        int i = r * 3;
        if (pegs[i] != " " && pegs[i] == pegs[i+1] && pegs[i] == pegs[i+2])
            return true;
    }
    return false;
}

bool TicTacToe3::check_column_win()
{
    // cols: 0-3-6, 1-4-7, 2-5-8
    for (int c = 0; c < 3; ++c)
    {
        if (pegs[c] != " " && pegs[c] == pegs[c+3] && pegs[c] == pegs[c+6])
            return true;
    }
    return false;
}

bool TicTacToe3::check_diagonal_win()
{
    // diags: 0-4-8, 2-4-6
    if (pegs[4] != " ")
    {
        if (pegs[0] == pegs[4] && pegs[0] == pegs[8]) return true;
        if (pegs[2] == pegs[4] && pegs[2] == pegs[6]) return true;
    }
    return false;
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
