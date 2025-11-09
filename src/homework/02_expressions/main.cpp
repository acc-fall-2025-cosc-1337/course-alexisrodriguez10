//write include statements
#include <iostream>
#include "hwexpressions.h"
#include "catch.hpp"



//write namespace using statement for cout
using std::cout; using std::cin; using std::endl;

int main()
{

	double meal_amount, tip_rate;

	cout << "Enter the meal amount: ";
	cin >> meal_amount;

	cout << "The meal amount is: " << meal_amount << endl;
	

	cout << "The sales tax is: " << get_sales_tax_amount(meal_amount) << endl;

	cout << "Enter the tip rate (as a decimal): ";
	cin >> tip_rate;

	cout << "The tip amount is: " << get_tip_amount(meal_amount, tip_rate) << endl;

	cout << "The total meal cost is: " << get_total(meal_amount, tip_rate) << endl;

	return 0;
	

}



	

