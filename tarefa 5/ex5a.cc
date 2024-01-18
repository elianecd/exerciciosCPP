/*
* Statistical informations about an array
* =============================================================
* Writen by: Eliane Dahab
*
* This program identifies from an array which value is the lowest and highest.
* Also calculates the average and the variance of the array.
* For last the program calculates how many values of the array are:
* - negative, zero and positive numbers.
* The average is calculated by the sum of all values of the array
* and divided by the quantity of numbers of the array.
* The variance is calculated by ((x1-AVG)2+ (x2-AVG)2+…+(xN-AVG)2)/N.
* Input: An array 
* Output: Lowest, highest, average, variance, negative, zero and positive.
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>
#include <cmath>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int N = 6;

//----------------prototypes-----------------
void readInput (int array[N]);

void min_max (int array[N], int& min, int& max);

int findAvg (int array[N]);

void findNegativeZeroPositive (int array[N], 
                               int& negative, 
                               int& zero, 
                               int& positive);

double findVariance (int array[N], int avg);

void displayResults (int min, 
                     int max, 
                     int avg, 
                     double var,
                     int negative,
                     int zero, 
                     int positive);

//------------------ main ---------------------
int main()
{
    int array[N];
    int min, max;
    int negative, zero, positive;
    readInput (array);
    min_max (array, min, max);
    int avg = findAvg (array);
    double var = findVariance (array, avg);
    findNegativeZeroPositive (array, negative, zero, positive);
    displayResults (min, max, avg, var, negative, zero, positive);

    return EXIT_SUCCESS;
}

//------------------ functions --------------------

//filling the array with the user input
void readInput (int array[N]) 
{   
    for (int i = 0; i < N; i++)
        cin >> array[i]; //user input
}

//function to find the lowest and the highest value between the array
void min_max (int array[N], int& min, int& max)
{ 
    //start point
    min = array[0];
    max = array[0];

    for (int i = 0; i < N; i++)
    {
        if (array[i] < min)
            min = array[i]; //identifying the lowest value
        
        if (array[i] > max)
            max = array[i]; //identifying the highest value
    }
}

//function to calculate the average of the array
int findAvg (int array[N])
{
    int sum = 0; //start point

    for (int j = 0; j < N; j++)
        sum += array[j]; //here we sum the values of the array

    return sum / N; //this is the way to calculate the average
}

//function to calculate the variance of the array
double findVariance (int array[N], int avg)
{
    double sum = 0; //start point

    //here we calculate the variance
    for (int k = 0; k < N; k++)
    {
        int num = (array[k] - avg);
        sum += pow(num, 2);
    }
    return sum / N;
}

//function to count the negative, zero and posituve numbers of the array
void findNegativeZeroPositive (int array[N], int& negative, 
                               int& zero, int& positive)
{
    negative = 0, zero = 0, positive = 0; //start point

    //here we counts the negative, zero and positive numbers
    for (int index = 0; index < N; index++)
    {
        if (array[index] < 0)
            negative++; //counting the negatives
        else if (array[index] > 0)
            positive++; //counting the positives
        else
            zero++; //counting the zeros 
    }
}

//function to print the requested informations about the array
void displayResults(int min, int max, int avg, double var,
                    int negative, int zero, int positive)
{
    cout << min << " " << max << " " << avg << " " << var; 
    cout << " " << negative << " " << zero << " " << positive << endl;
}