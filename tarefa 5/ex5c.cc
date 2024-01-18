/*
* Drawing a histogram
* =============================================================
* Writen by: Eliane Dahab
*
* This program counts from an array the following topics:
* - how many numbers are primes;
* - how many numbers are divided by 2;
* - how many numbers are divided by 3;
* - how many numbers are divided by 4;
* - how many numbers are divided by 5;
* - how many numbers are divided by 6;
* Each topic compounds each column of the histogram.
* The array is filled with random values between a low and high numbers.
* This program "calls" the other program's functions to create the histogram.
* Input: A low and high numbers
* Output: Histogram
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>
#include "histogram.h"

//-------------- using section --------------
using std::cout;
using std::cin;
using std::endl;

//-------------- const section --------------
const int N = 200;
const int DIVIDE_BY = 6;

//----------------prototypes-----------------
void fillArrayRand(int array[N], int lo, int hi);
void calculateInfo (int array[N], int info[DIVIDE_BY]);
int calculatePrimes(int array[N]);
int howManyDivideBy(const int array[N], int divisor);
bool is_prime(int num);

//------------------ main ---------------------
int main()
{
	int lo, hi;
	cin >> lo >> hi; //user input

	int array[N];
	fillArrayRand(array, lo, hi);

	int info[DIVIDE_BY];
	calculateInfo(array, info);

    //"calling" the functions from other programs to create the histogram
    create_hist(30,
            DIVIDE_BY * (COL_MIN_WIDTH + COL_MIN_SPACE),
            DIVIDE_BY,
            "primes and divide-by histogram");

    for (int index = 0; index < DIVIDE_BY; index++)
    {
        char col_title[10];
        sprintf(col_title, "div-by-%d", index + 1);
        if (index == 0)
        {
            sprintf(col_title, "#primes", index + 1);
        }
        add_col(index, info[index], lo, hi, col_title, '#');
    }
    draw_hist();

	return EXIT_SUCCESS;
}

//------------------ functions --------------------

//filling the array with random values 
void fillArrayRand(int array[N], int lo, int hi)
{
    srand(101);

    //random values between the low and high numbers from the user input
    for (int index = 0; index < N ; index++)
        array[index] = rand() % (hi - lo + 1) + lo; 
}

//function to keep all the informations
void calculateInfo (int array[N], int info[DIVIDE_BY])
{
    info[0] = calculatePrimes(array);

    for (int i = 1; i < DIVIDE_BY; i++)
        info[i] = howManyDivideBy(array, i + 1);
}

//function to counts how many numbers are primes
int calculatePrimes(int array[N])
{
    int primes = 0; //start point

    for (int i = 0; i < N; i++)
        if (is_prime(array[i]))
            primes++; //counting
    
    return primes;
}

//function to calculate how many numbers are divided by 2 till DIVIDE_BY
int howManyDivideBy(const int array[N], int divisor)
{
    int counter = 0; //start point

    for (int i = 0 ; i < N; i++)
        //here we check if the current divisor divides the array[i]
        if (array[i] % divisor == 0)
            counter ++; //counting
    
    return counter;
}

//boolean to calculate the primes numbers
bool is_prime(int num)
{   
    for (int div = 2; div <= num / 2; div++)
        if (num % div == 0)
            return false;
    
	return true;
}