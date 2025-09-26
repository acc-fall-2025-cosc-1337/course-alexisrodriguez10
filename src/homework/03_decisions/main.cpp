//write include statements
#include <iostream>
#include "decisions.h"

using std::cout;
using std::cin;
using std::endl;
int main() 
{
	int choice;

	cout<< "1 Letter Grade using if statement" << endl;
	cout<< "2 Letter Grade using switch statement" << endl;
	cout<< "3 Exit" << endl;

	cin >> choice;

	if (choice == 1) {	
		int score;
		cout << "Enter score: ";
		cin >> score;
		if (score >= 0 && score <= 100) {
			char grade_if = get_letter_grade_using_if(score);
			cout << "Letter grade using if: " << grade_if << endl;
		} else {
			cout << "Invalid score." << endl;
		}
	} else if (choice == 2) {
		int score;
		cout << "Enter score: ";
		cin >> score;
		if (score >= 0 && score <= 100) {
			char grade_switch = get_letter_grade_using_switch(score);
			cout << "Letter grade using switch: " << grade_switch << endl;
		} else {
			cout << "Invalid score." << endl;
		}
	} else if (choice == 3) {
		cout << "Exiting program." << endl;
	} else {
		cout << "Invalid choice. Please select 1, 2, or 3." << endl;
	}

	
	return 0;
}