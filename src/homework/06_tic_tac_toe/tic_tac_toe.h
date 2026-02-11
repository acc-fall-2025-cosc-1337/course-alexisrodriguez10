#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>
#include <iosfwd>

using namespace std;


class TicTacToe
{
public:

    explicit TicTacToe(int size) : pegs(size * size, " ") {}

    void start_game(string first_player);

    void mark_board(int position);

    string get_player() const;

    void display_board() const;

    bool game_over();

    string get_winner() const;

protected:

    string player;
    std::vector<std::string> pegs;
    string winner;

    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();

private:

    void set_next_player();

    bool check_board_full();

    void clear_board();

    void set_winner();

};

#endif 
