//h
#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

#include <string>
#include <vector>

using namespace std;


class TicTacToe
{
public:

    void start_game(string first_player);

    void mark_board(int position);

    string get_player() const;

    void display_board() const;

    bool game_over();

    string get_winner() const;

private:

    string player;
    vector<string> pegs = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    string winner;

    void set_next_player();

    bool check_board_full();

    void clear_board();

    bool check_column_win();

    bool check_row_win();

    bool check_diagonal_win();

    void set_winner();

    

};

#endif 
