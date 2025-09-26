//write include statement for decisions header
#include "decisions.h"

//Write code for function(s) code here

int get_letter_grade_using_if(int score){
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }

}


int get_letter_grade_using_switch(int score){
    switch (score / 10) {
        case 10:
        case 9:
            return 'A';
            break;
        case 8:
            return 'B';
            break;
        case 7:
            return 'C';
            break;
        case 6:
            return 'D';
            break;
        default:
            return 'F';
            break;
    }
}
