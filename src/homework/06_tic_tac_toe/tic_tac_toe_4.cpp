#include "tic_tac_toe_4.h"

bool TicTacToe4::check_row_win()
{
    // rows: (r*4 + 0..3)
    for (int r = 0; r < 4; ++r)
    {
        int i = r * 4;
        if (pegs[i] != " " &&
            pegs[i] == pegs[i+1] &&
            pegs[i] == pegs[i+2] &&
            pegs[i] == pegs[i+3]) return true;
    }
    return false;
}

bool TicTacToe4::check_column_win()
{
    
    for (int c = 0; c < 4; ++c)
    {
        if (pegs[c] != " " &&
            pegs[c] == pegs[c+4] &&
            pegs[c] == pegs[c+8] &&
            pegs[c] == pegs[c+12]) return true;
    }
    return false;
}

bool TicTacToe4::check_diagonal_win()
{
    if (pegs[0] != " " && pegs[0] == pegs[5] && pegs[0] == pegs[10] && pegs[0] == pegs[15])
        return true;
    if (pegs[3] != " " && pegs[3] == pegs[6] && pegs[3] == pegs[9]  && pegs[3] == pegs[12])
        return true;
    return false;
}

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/




/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
