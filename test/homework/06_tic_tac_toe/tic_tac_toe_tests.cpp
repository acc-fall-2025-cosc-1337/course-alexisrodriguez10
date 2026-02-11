#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

#include <memory>
using std::unique_ptr;
using std::make_unique;

TEST_CASE("Verify Test Configuration") {
    REQUIRE(true == true);
}



TEST_CASE("TEST game over if 9 positions are filled") {
    TicTacToe3 game;
    game.start_game("X");

    
    for (int i = 1; i <= 9; ++i) {
        game.mark_board(i);
    }

    REQUIRE(game.game_over() == true);
}

TEST_CASE("TicTacToe get_player returns correct current player") {
    TicTacToe3 game;
    game.start_game("X");

    REQUIRE(game.get_player() == "X");

    game.mark_board(1); // X
    REQUIRE(game.get_player() == "O");

    game.mark_board(2); // O
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("game_over returns false for non-full board") {
    TicTacToe3 game;
    game.start_game("X");

   
    game.mark_board(1); 
    game.mark_board(2); 
    game.mark_board(3); 

    REQUIRE(game.game_over() == false);
}

TEST_CASE("game over returns true for full board") {
    TicTacToe3 game;
    game.start_game("O");

    
    for (int i = 1; i <= 9; ++i) {
        game.mark_board(i);
    }

    REQUIRE(game.game_over() == true);
}

TEST_CASE("Test first player to set to X") {
    TicTacToe3 game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player to set to O") {
    TicTacToe3 game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}



TEST_CASE("TEST FIRST COLUMN WIN") {
    TicTacToe3 game;
    game.start_game("X");

    game.mark_board(1); 
    game.mark_board(2); 
    game.mark_board(4); 
    game.mark_board(5); 
    game.mark_board(7); 

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST SECOND COLUMN WIN") {
    TicTacToe3 game;
    game.start_game("O");

    game.mark_board(2); // O
    game.mark_board(1); // X
    game.mark_board(5); // O
    game.mark_board(3); // X
    game.mark_board(8); // O

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("TEST THIRD COLUMN WIN") {
    TicTacToe3 game;
    game.start_game("X");

    game.mark_board(3); 
    game.mark_board(1); 
    game.mark_board(6); 
    game.mark_board(2); 
    game.mark_board(9); 

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST FIRST ROW WIN") {
    TicTacToe3 game;
    game.start_game("O");

    game.mark_board(1); 
    game.mark_board(4); 
    game.mark_board(2); 
    game.mark_board(5); 
    game.mark_board(3); 

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("TEST SECOND ROW WIN") {
    TicTacToe3 game;
    game.start_game("X");

    game.mark_board(4); 
    game.mark_board(1); 
    game.mark_board(5); 
    game.mark_board(2); 
    game.mark_board(6); 

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST THIRD ROW WIN") {
    TicTacToe3 game;
    game.start_game("O");

    game.mark_board(7); 
    game.mark_board(1); 
    game.mark_board(8); 
    game.mark_board(2); 
    game.mark_board(9); 

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}

TEST_CASE("TEST DIAGONAL WIN FROM LEFT TO RIGHT") {
    TicTacToe3 game;
    game.start_game("X");

    game.mark_board(1); 
    game.mark_board(2); 
    game.mark_board(5); 
    game.mark_board(3); 
    game.mark_board(9); 

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST DIAGONAL WIN FROM RIGHT TO LEFT") {
    TicTacToe3 game;
    game.start_game("O");

    game.mark_board(3); 
    game.mark_board(1); 
    game.mark_board(5); 
    game.mark_board(2); 
    game.mark_board(7); 

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "O");
}



TEST_CASE("TEST Counting amount of X Wins Correctly")
{
    TicTacToeManager manager;
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

    
    game->start_game("X");
    game->mark_board(1); 
    game->mark_board(4); 
    game->mark_board(2); 
    game->mark_board(5); 
    game->mark_board(3); 

    REQUIRE(game->game_over() == true);

    manager.save_game(game); 

    int o_wins = 0;
    int x_wins = 0;
    int ties   = 0;

    manager.get_winner_total(o_wins, x_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 0);
    REQUIRE(ties   == 0);
}

TEST_CASE("TEST Counting amount of O Wins Correctly")
{
    TicTacToeManager manager;
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

    
    game->start_game("O");
    game->mark_board(1); 
    game->mark_board(2); 
    game->mark_board(4); 
    game->mark_board(3); 
    game->mark_board(7); 

    REQUIRE(game->game_over() == true); 

    manager.save_game(game);

    int o_wins = 0;
    int x_wins = 0;
    int ties   = 0;

    manager.get_winner_total(o_wins, x_wins, ties);

    REQUIRE(o_wins == 1);
    REQUIRE(x_wins == 0);
    REQUIRE(ties   == 0);
}

TEST_CASE("TEST Counting amount of Ties Correctly")
{
    TicTacToeManager manager;
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

    
    game->start_game("X");
    game->mark_board(1); 
    game->mark_board(2); 
    game->mark_board(3); 
    game->mark_board(5); 
    game->mark_board(4); 
    game->mark_board(6); 
    game->mark_board(8); 
    game->mark_board(7); 
    game->mark_board(9); 

    REQUIRE(game->game_over() == true); 
    REQUIRE(game->get_winner() == "C");

    manager.save_game(game);

    int o_wins = 0;
    int x_wins = 0;
    int ties   = 0;

    manager.get_winner_total(o_wins, x_wins, ties);

    REQUIRE(ties   == 1);
    REQUIRE(o_wins == 0);
    REQUIRE(x_wins == 0);
}



TEST_CASE("SHOW WHO IS THE WINNER OF THE GAME") {
    TicTacToe3 game;
    game.start_game("X");

    game.mark_board(1); 
    game.mark_board(4); 
    game.mark_board(2); 
    game.mark_board(5); 
    game.mark_board(3); 

    REQUIRE(game.game_over() == true); 
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TicTacToeManager counts X wins for TicTacToe4") {
	TicTacToeManager manager;
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();

	game->start_game("X");
	// same sequence as FIRST ROW WIN above
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(7);
	game->mark_board(4);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

	manager.save_game(game);

	int o_wins = 0, x_wins = 0, ties = 0;
	manager.get_winner_total(o_wins, x_wins, ties);

	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 0);
	REQUIRE(ties == 0);
}

TEST_CASE("TicTacToe4 DIAGONAL RIGHT TO LEFT WIN") {
	TicTacToe4 game;
	game.start_game("O");

	game.mark_board(4);  // O
	game.mark_board(1);  // X
	game.mark_board(7);  // O
	game.mark_board(2);  // X
	game.mark_board(10); // O
	game.mark_board(3);  // X
	game.mark_board(13); // O -> completes diagonal (4,7,10,13)

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}



