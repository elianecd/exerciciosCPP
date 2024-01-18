#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

const int N = 6;

void displayResults(int array[N]);

int main()
{
    int array[N];

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    displayResults(array);

    return EXIT_SUCCESS;
}
void displayResults( int array[N])
{
    int min = array[0];

    for (int i = 0; i < N; i++)
    {
        if (array[i] <= min)
        {
            min = array[i];
        }
    }

    int max = array[0];

    for (int i = 0; i < N; i++)
    {
        if (array[i] >= max)
        {
            max = array[i];
        }
    }

    //here we sum the values of the array
    int sum = 0;

    for (int j = 0; j < N; j++)
    {
        sum += array[j];
    }
    
    int avg = sum / N;

    //here we calculate the variances
    sum = 0;

    for (int k = 0; k < N; k++)
    {
        //sum += (array[k] - avg) * 2;
        int num = (array[k] - avg);
        //sum += ((num) ^ 2);
        sum += pow(num, 2);
    }
    int var = sum / N;

    //here we define negative, positive and zero's numbers
    int negative = 0, positive = 0, zero = 0;

    for (int index = 0; index < N; index++)
    {
        if (array[index] < 0)
        {
            negative++;
        }
        else if (array[index] > 0)
        {
            positive++;
        }
        else
        {
            zero++;
        }    
    }
    cout << min << " " << max << " " << avg << " " << var << " " << negative << " " << zero << " " << positive;
}