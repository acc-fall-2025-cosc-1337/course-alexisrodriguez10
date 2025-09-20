#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "if.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("AND TRUTH TABLE") {
	REQUIRE((true && true) == true);
	REQUIRE((true && false) == false);
	REQUIRE((false && true) == false);
	REQUIRE((false && false) == false);
}


TEST_CASE("OR TRUTH TABLE") {
	REQUIRE((true || true) == true);
	REQUIRE((true || false) == true);
	REQUIRE((false || true) == true);
	REQUIRE((false || false) == false);
}

TEST_CASE("NOT TRUTH TABLE", "[not]") {
	REQUIRE((!true) == false);
	REQUIRE((!false) == true);
}

