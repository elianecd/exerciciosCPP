/*
 * Even, odd, positive, zero and negative numbers
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program classifies the numbers as even, odd, positive, zero and negativo and then shows how many of each classification there is.
 * - The first classification is even numbers, including zero. 
 * - The second classification is odd numbers.
 * - The third classification is positive numbers.
 * - The fourth classification is zero numbers.
 * - The fifth classification is negative numbers.
 * Input: Four random integer numbers
 * Output: The quantity of number in each classification
*/

//-------------- include section ------------
#include <iostream>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-----------------  main -------------------
int main()
{ 
    //------------- enum section ------------
    int number, sumEven = 0, sumOdd = 0, sumPositive = 0, sumNegative = 0, sumZeros = 0;
    
    //adding a variable
    for (int i = 0; i < 4; i++)
    {
        //the options the user may input: a sequence of numbers up to 4 numbers
        cin >> number;

        //condition to identify an even and odd number
        if (number % 2 == 0)
        {
            sumEven++;
        }
        else
        {
            sumOdd++;
        }
        //condition to identify a positive and negative number
        if (number > 0)
        {
            sumPositive++;
        }
        else if (number < 0)
        {
            sumNegative++;
        }
        //condition to identify the zeros
        else
        {
            sumZeros ++;
        }
        
    }
    //printing in the first line how many even and odd numbers there are in the sequence numbers that the user putted as input
    cout << sumEven << " " << sumOdd << endl;

    //printing in the second line how many positive, zeros and negative numbers there are in the sequence numbers that the user putted as input
    cout << sumPositive << " " << sumZeros << " " << sumNegative;

    return 0;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------

