//add include statements
#include <iostream>
#include <string>
#include "func.h"
using namespace std;

string get_reverse_string( string dna)
{
    string reverse_string = "";
    for (int i = dna.length() - 1; i >= 0; i--)
    {
        reverse_string += dna[i];
    }
    return reverse_string;
}

double get_gc_content(const string& dna)
{
    double gc_count = 0;
    for (char nucleotide : dna)
    {
        if (nucleotide == 'G' || nucleotide == 'C')
        {
            gc_count++;
        }
    }
    return (gc_count / dna.length()) * 100;
}

string get_dna_complement( string& dna)
{
    string complement = "";
    for (char nucleotide : dna)
    {
        switch (nucleotide)
        {
            case 'A':
                complement += 'T';
                break;
            case 'T':
                complement += 'A';
                break;
            case 'C':
                complement += 'G';
                break;
            case 'G':
                complement += 'C';
                break;
            default:
                complement += nucleotide; // In case of invalid character, just append it
        }
    }
    return get_reverse_string(complement);
}





//add function code here