#include <iostream>
#include <cstdlib>
#include "histogram.h"

const int N = 20;
const int DIVIDE_BY = 6;
int getNumDividedByDivisor (const int array[N], int divisor);

int main()
{
    int lo, hi;

    cin >> lo >> hi;
    
    int randominteger;
    srand(101);
    int array[N];
    int index = 0;
    //on this while we will randomize N valueses into the arrat!
    while (index < N)
    {
        randominteger = rand() % (hi - lo + 1) + lo; 
        array[index] = randominteger;
        index++;
    }
    //here we define the divisors and send to the function data return the number of dividedinterger the array
    int result[DIVIDE_BY];
    int anotherindex = 0;
    for (int divisor = 2; divisor <= DIVIDE_BY; divisor ++)
    {
        //cout << getNumDividedByDivisor(array, divisor) << " " << endl;
        //by this way we will save the number of division of each divisor in our array
        result[anotherindex] = getNumDividedByDivisor(array, divisor);
    }
    /*for(int i = 0 ; i < N; i++)
    {
        cout << array[i] << " ";
    }*/

    return EXIT_SUCCESS;
}
//----------------------------------------------------------------------
int getNumDividedByDivisor (const int array[N], int divisor)
{
    int counter =0;
    if(divisor == 0)
    {
        return 0; //there is no sense to divide by zero!
    }

    for (int i = 0 ; i < N; i++)
    {
        //here we check if the current divisor divides the array[i]
        if (array[i] % divisor == 0)
        {
            counter ++;
        }
    }
    return counter; 
}
