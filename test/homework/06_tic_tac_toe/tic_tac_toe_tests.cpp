#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe_3.h"

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





