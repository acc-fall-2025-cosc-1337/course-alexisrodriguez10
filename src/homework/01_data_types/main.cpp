//write include statements
#include <iostream>
#include "data_types.h"


//write namespace using statement for cout
using std::cout;

int main()
{
	int result;
	result = multiply_numbers(7, 7);
	cout << "7 * 7 = " << result << "\n";

	result = multiply_numbers(5, 5);
	cout << "5 * 5 = " << result << "\n";
	

	return 0;
}
