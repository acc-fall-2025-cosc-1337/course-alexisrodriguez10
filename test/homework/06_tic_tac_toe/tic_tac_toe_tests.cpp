#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("TEST game over if 9 positions are filled") {
	TicTacToe game;
	game.start_game("X");

	// Fill all positions
	for (int i = 1; i <= 9; ++i) {
		game.mark_board(i);
	}

	REQUIRE(game.game_over() == true);
}

TEST_CASE("TicTacToe get_player returns correct current player") {
	TicTacToe game;
	game.start_game("X");

	REQUIRE(game.get_player() == "X");

	game.mark_board(1); // X
	REQUIRE(game.get_player() == "O");

	game.mark_board(2); // O
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("game_over returns false for non-full board") {
	TicTacToe game;
	game.start_game("X");

	// Mark a few positions without filling the board
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(3);

	REQUIRE(game.game_over() == false);
}

TEST_CASE("game over returns true for full board") {
	TicTacToe game;
	game.start_game("O");

	// Fill the board completely
	for (int i = 1; i <= 9; ++i) {
		game.mark_board(i);
	}

	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test first player to set to X") {
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player to set to O") {
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("TEST FIRST COLUMN WIN") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X
	game.mark_board(2); // O
	game.mark_board(4); // X
	game.mark_board(5); // O
	game.mark_board(7); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST SECOND COLUMN WIN") {
	TicTacToe game;
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
	TicTacToe game;
	game.start_game("X");

	game.mark_board(3); // X
	game.mark_board(1); // O
	game.mark_board(6); // X
	game.mark_board(2); // O
	game.mark_board(9); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST FIRST ROW WIN") {
	TicTacToe game;
	game.start_game("O");

	game.mark_board(1); // O
	game.mark_board(4); // X
	game.mark_board(2); // O
	game.mark_board(5); // X
	game.mark_board(3); // O

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}

TEST_CASE("TEST SECOND ROW WIN") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(4); // X
	game.mark_board(1); // O
	game.mark_board(5); // X
	game.mark_board(2); // O
	game.mark_board(6); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST THIRD ROW WIN") {
	TicTacToe game;
	game.start_game("O");

	game.mark_board(7); // O
	game.mark_board(1); // X
	game.mark_board(8); // O
	game.mark_board(2); // X
	game.mark_board(9); // O

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}

TEST_CASE("TEST DIAGONAL WIN FROM LEFT TO RIGHT") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X
	game.mark_board(2); // O
	game.mark_board(5); // X
	game.mark_board(3); // O
	game.mark_board(9); // X

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("TEST DIAGONAL WIN FROM RIGHT TO LEFT") {
	TicTacToe game;
	game.start_game("O");

	game.mark_board(3); // O
	game.mark_board(1); // X
	game.mark_board(5); // O
	game.mark_board(2); // X
	game.mark_board(7); // O

	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "O");
}

TEST_CASE("TEST Counting amount of X Wins Correctly")
{
    TicTacToe game1;
    TicTacToe3 manager;

    // Simulate a game where X wins by the top row (1, 2, 3)
    game1.start_game("X");
    game1.mark_board(1); // X
    game1.mark_board(4); // O
    game1.mark_board(2); // X
    game1.mark_board(5); // O
    game1.mark_board(3); // X (X wins here)

    REQUIRE(game1.game_over() == true); // Ensure win condition triggered

    manager.save_game(game1);

    int o_wins = 0;
    int x_wins = 0;
    int ties = 0;

    manager.get_winner_total(o_wins, x_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 0);
    REQUIRE(ties == 0);
}

TEST_CASE("TEST Counting amount of O Wins Correctly")
{
	TicTacToe game2;
	TicTacToe3 manager;

	// Simulate a game where O wins by the first column (1, 4, 7)
	game2.start_game("O");
	game2.mark_board(1); // O
	game2.mark_board(2); // X
	game2.mark_board(4); // O
	game2.mark_board(3); // X
	game2.mark_board(7); // O (O wins here)

	REQUIRE(game2.game_over() == true); // Ensure win condition triggered

	manager.save_game(game2);

	int o_wins = 0;
	int x_wins = 0;
	int ties = 0;

	manager.get_winner_total(o_wins, x_wins, ties);

	REQUIRE(o_wins == 1);
	REQUIRE(x_wins == 0);
	REQUIRE(ties == 0);
}

TEST_CASE("TEST Counting amount of Ties Correctly")
{
	TicTacToe game3;
	TicTacToe3 manager;

	// Simulate a game that ends in a tie
	game3.start_game("X");
	game3.mark_board(1); // X
	game3.mark_board(2); // O
	game3.mark_board(3); // X
	game3.mark_board(5); // O
	game3.mark_board(4); // X
	game3.mark_board(6); // O
	game3.mark_board(8); // X
	game3.mark_board(7); // O
	game3.mark_board(9); // X (Board is full, tie)

	REQUIRE(game3.game_over() == true); // Ensure game over condition triggered

	manager.save_game(game3);

	int o_wins = 0;
	int x_wins = 0;
	int ties = 0;

	manager.get_winner_total(o_wins, x_wins, ties);

	REQUIRE(ties == 1);
	REQUIRE(o_wins == 0);
	REQUIRE(x_wins == 0);
}

TEST_CASE("SHOW WHO IS THE WINNER OF THE GAME") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1); // X
	game.mark_board(4); // O
	game.mark_board(2); // X
	game.mark_board(5); // O
	game.mark_board(3); // X (X wins here)

	REQUIRE(game.game_over() == true); // Ensure win condition triggered
	REQUIRE(game.get_winner() == "X");
}
