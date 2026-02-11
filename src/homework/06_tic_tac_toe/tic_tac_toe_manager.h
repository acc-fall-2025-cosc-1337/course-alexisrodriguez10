#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <vector>
#include <memory>

using namespace std;

class TicTacToeManager
{
public:
    // 2) Parameter is a reference to unique_ptr<TicTacToe>
    void save_game(unique_ptr<TicTacToe>& game);

    void get_winner_total(int& o, int& x, int& t);

    // 3) Display all games played
    void display_games() const;

private:
    // 1) Vector of unique_ptr to TicTacToe
    vector<unique_ptr<TicTacToe>> games;

    int x_win{0};
    int o_win{0};
    int ties{0};

    void update_winner_count(string winner);
};

#endif
