#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "int.h"
#include "int.cpp"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Test echo_variable returns input value", "[echo_variable]") {
    REQUIRE(echo_variable(5) == 5);
    REQUIRE(echo_variable(-3) == -3);
}

TEST_CASE("Test add_numbers returns correct sum", "[add_numbers]") {
	REQUIRE(add_numbers(2, 3) == 5);
	REQUIRE(add_numbers(-5, -7) == -12);
	REQUIRE(add_numbers(100, 200) == 300);
}

TEST_CASE("Test add_to_double_1 with 0 as parameter", "[add_to_double_1]") {
	REQUIRE(add_to_double_1(0.0, 0.0) == 0.0);
	REQUIRE(add_to_double_1(-5.5, 5.5) == 0.0);
	REQUIRE(add_to_double_1(100.1, -100.1) == 0.0);
}

TEST_CASE("Gross pay calculation", "[gross_pay]") {
	REQUIRE(gross_pay(40, 15.0) == 600.0);
	REQUIRE(gross_pay(0, 20.0) == 0.0);
	REQUIRE(gross_pay(10, 12.5) == 125.0);
}

/*test case echo_variable */



/*test case add_to_double_1 with 1 as parameter*/

/*test case add_to_double_2 with 0 as parameter*/


/*test case add_to_double_2 with 1 as parameter*/


/*test case char test ASCII values */


/*test case string test ASCII values Joe characters are equal to 74, 111, and 101*/


