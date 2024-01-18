/*
* The highest of 9 digits that is divided by 11
* =============================================================
* Writen by: Eliane Dahab
*
* This program prints the highest value of 9 digits that is divided by 11.
* All the digits must be different from each other.
* The division leaves no remainder.
* Input: none
* Output: the highest value
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int SIZE = 9;

//----------------prototypes-----------------
long long find_max(long long num);

//------------------ main ---------------------
int main()
{   
    long long num = 987654321;

    cout << find_max(num);

    return EXIT_SUCCESS;
}
//---------------------------------------------

long long find_max(long long num)
{
    int current = num;
    bool even = false;
    int digit = 0;
    int sum_even = 0;
    int sum_odd = 0;
    int digits[SIZE] = {0};

    for (int i = 0; i < SIZE ; i++)
    {
        //To take every digit separately 
        digit = current % 10;
        digits[i] = digit;

        if (even == false)
        {
            //To sum the values that are in the even position
            sum_even += digit;    
            even = true;
        }
        else
        {
            //To sum the values that are in the odd position
            sum_odd += digit;  
            even = false;
        }
        current /= 10; //To subtract the last digit, one by one
    }

    bool ok = true;

    //If the difference of the sums are divided by 11 without
    //remainder
    if ((sum_odd - sum_even) % 11 == 0)
    {
        //now check each digit not equal to other digit
        for (int i = 0; i < SIZE; i++)
        {
            for (int k = i+1; k < SIZE; k++)
            {
                if (digits[i] == digits[k])
                {
                    ok = false;
                    break;
                }
            }
            if (ok == false)
                break;
        }
    }
    else
        ok = false;

    if (ok == true)//this is ok according to the condition
        return num;
    else
        return find_max(num-1); 
        //To subtract 1 from num every time to check value
        //by value till we get the number that we need
}