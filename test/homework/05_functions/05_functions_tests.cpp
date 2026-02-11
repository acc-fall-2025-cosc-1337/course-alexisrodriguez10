#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("GC content of DNA is calculated correctly") {
	REQUIRE(get_gc_content("AGCTATAG") == Approx(37.5));
	REQUIRE(get_gc_content("CGCTATAG") == Approx(50.0));
	REQUIRE(get_gc_content("CGCTATAGCGCTA") == Approx(53.84615338462));
}

TEST_CASE("Reverse string of DNA is calculated correctly") {
	REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
	REQUIRE(get_reverse_string("CGCTATAG") == "GATATCGC");
	REQUIRE(get_reverse_string("CGCTATAGCGCTA") == "ATCGCGATATCGC");
}

 

TEST_CASE("DNA complement is calculated correctly") {
	string dna1 = "AAAACCCGGT";
	REQUIRE(get_dna_complement(dna1) == "ACCGGGTTTT");
	string dna2 = "CCCGGAAAAT";
	REQUIRE(get_dna_complement(dna2) == "ATTTTCCGGG");
	string dna3 = "ACCGGGTTTT";
	REQUIRE(get_dna_complement(dna3) == "AAAACCCGGT");
}
    