//write include statements
#include <iostream>
#include "repetition.h"
//write using statements
using std::cout;
using std::cin;
using std::endl;
int main() 
{
	int number;

	do {
		cout << "Homework 4 Menu" << endl;
		cout << "1. Factorial" << endl;
		cout << "2. Sum of Odd Numbers" << endl;
		cout << "3. EXIT" << endl;
		cin >> number;

		if (number == 1) {
			int num;
			cout << "Enter a non-negative number: ";
			cin >> num;
			if (num >= 0 and num <= 10) { // Limiting to 10 
				int factorial = get_factorial(num);
				cout << "Factorial of " << num << " is " << factorial << endl;
			} else {
				cout << "Please enter a non-negative number between 0 and 10." << endl;
			}
		} else if (number == 2) {
			int limit;
			cout << "Enter a positive number: ";
			cin >> limit;
			if (limit >= 0 and limit <= 100) { // Limiting to 100 to prevent large sums
				int sum = sum_odd_numbers(limit);
				cout << "Sum of odd numbers up to " << limit << " is " << sum << endl;
			} else {
				cout << "Please enter a positive number between 0 and 100." << endl;
			}
		} else if (number == 3) {
			cout << "Exiting program." << endl;
			break;
		} else if (number != 0) {
			cout << "Invalid choice. Please select 1, 2, or 3 to exit." << endl;
		}
	} while (number != 0);







	return 0;
}
