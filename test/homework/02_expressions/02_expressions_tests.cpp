#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

TEST_CASE("Verify get_sales_tax_amount function")
{
	REQUIRE(get_sales_tax_amount(100.00) == 6.75);
	REQUIRE(get_sales_tax_amount(50.00) == 3.375);
}

TEST_CASE("Verify get_tip_amount function")
{
	REQUIRE(get_tip_amount(100.00, 0.15) == 15.00);
	REQUIRE(get_tip_amount(50.00, 0.20) == 10.00);
}
