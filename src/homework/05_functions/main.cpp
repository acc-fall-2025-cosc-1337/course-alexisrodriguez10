#include <iostream>
#include <string>
#include "func.h"
using namespace std;


int main() 
{
	int number = 0;
	do
	{
		std::cout << "Homework 5 Menu" << std::endl;
		std::cout << "1. GC Content" << std::endl;
		std::cout << "2. Reverse String" << std::endl;
		std::cout << "3. DNA Complement" << std::endl;
		std::cout << "4. EXIT" << std::endl;
		std::cin >> number;

		if (number == 1) {
			std::string dna;
			std::cout << "Enter a DNA string: ";
			std::cin >> dna;
			double gc_content = get_gc_content(dna);
			std::cout << "GC Content: " << gc_content << "%" << std::endl;
		} else if (number == 2) {
			std::string dna;
			std::cout << "Enter a DNA string: ";
			std::cin >> dna;
			std::string reverse_string = get_reverse_string(dna);
			std::cout << "Reverse String: " << reverse_string << std::endl;
		} else if (number == 3) {
			std::string dna;
			std::cout << "Enter a DNA string: ";
			std::cin >> dna;
			std::string dna_complement = get_dna_complement(dna);
			std::cout << "DNA Complement: " << dna_complement << std::endl;
		} else if (number == 4) {
			std::cout << "Exiting program." << std::endl;
			break;
		} else if (number != 0) {
			std::cout << "Invalid choice. Please select 1, 2, or 3 to exit." << std::endl;
		}
	} while (number != 0);






	



	return 0;
}
