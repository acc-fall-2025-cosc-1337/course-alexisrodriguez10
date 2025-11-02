#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_3.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("TicTacToe game over detects a full board") {
	TicTacToe game;
	game.start_game("X");

	// Fill the board without any winning condition
	for (int i = 1; i <= 9; ++i) {
		game.mark_board(i);
		if (i < 9) {
			game.mark_board(i + 1); // Alternate moves
		}
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
