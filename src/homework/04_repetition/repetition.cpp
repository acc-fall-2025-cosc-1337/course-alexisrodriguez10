//add include statements
#include <stdio.h>
#include "repetition.h"

int get_factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i;
    }
    return result;
}


int sum_odd_numbers(int num) {
    int sum = 0;
    int i = 1;
    while (i <= num) {
        sum += i;
        i += 2;
    }
    return sum;
}


//add function(s) code here
