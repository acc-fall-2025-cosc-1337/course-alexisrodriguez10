#include "hwexpressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}



double get_sales_tax_amount(double meal_amount)
{
	return meal_amount * tax_rate;
}

double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * tip_rate;
}
double get_total(double meal_amount, double tip_rate)
{
	double sales_tax = get_sales_tax_amount(meal_amount);
	double tip_amount = get_tip_amount(meal_amount, tip_rate);
	return meal_amount + sales_tax + tip_amount;
}


//write function code here




