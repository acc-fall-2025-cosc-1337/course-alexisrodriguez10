//h
#include "tic_tac_toe_3.h"
#include <vector>
#include <string>
using namespace std;

class TicTacToe3  
{
public:

    void save_game(TicTacToe b);

    void get_winner_total(int& o, int& x, int& t);

    private:
    vector<TicTacToe> games;
    int o_wins = 0;
    int x_wins = 0;
    int ties = 0;

    void update_winner_count(string winner);
};