#include <iostream>
#include <cstdlib>
#include "histogram.h"

using std::cout;
using std::cin;
using std::endl;

const int N = 20;
const int DIVIDE_BY = 6;
void fillArrayRand(int array[N], int lo, int hi);
void calculateInfo (int array[N], int info[DIVIDE_BY]);
int calculatePrimes(int array[N]);
int howManyDivideBy(const int array[N], int divisor);
bool is_prime(int num);
void displayInfo(int info[DIVIDE_BY]);
/*void printArr(int arr[N])
{
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}*/
int main()
{
	int lo, hi;
	cin >> lo >> hi;

	int array[N];
	fillArrayRand(array, lo, hi);

	int info[DIVIDE_BY];
	calculateInfo(array, info);
 // printArr(array);
	displayInfo(info);

	return EXIT_SUCCESS;
}
void fillArrayRand(int array[N], int lo, int hi)
{
    srand(101);

    for (int index = 0; index < N ; index++)
        array[index] = rand() % (hi - lo + 1) + lo;
}
void calculateInfo (int array[N], int info[DIVIDE_BY])
{
    info[0] = calculatePrimes(array);

    for (int i = 1; i < DIVIDE_BY; i++)
        info[i] = howManyDivideBy(array, i+1);
}
int calculatePrimes(int array[N])
{
    int primes = 0;

    for (int i = 0; i < N; i++)
    
        if (is_prime(array[i]))
            primes++;
    
    return primes;
}
int howManyDivideBy(const int array[N], int divisor)
{
    int counter = 0;

    for (int i = 0 ; i < N; i++)
        //here we check if the current divisor divides the array[i]
        if (array[i] % divisor == 0)
            counter ++;
    
    return counter;
}
bool is_prime(int num)
{   
    for (int div = 2; div <= num / 2; div++)
        if (num % div == 0)
            return false;
    
	return true;
}
void displayInfo(int info[DIVIDE_BY])
{
    for (int i = 0; i < DIVIDE_BY; i++)
        cout << info[i] << endl;
}