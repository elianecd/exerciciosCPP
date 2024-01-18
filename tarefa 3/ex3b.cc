/*
 * A pair of numbers
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program verifies which pair of numbers from 1 to 1000 fits the following conditions:
 * - The sum of two squared numbers is equal to a third power of any number;
 * - And the sum of those two numbers in the third power each, is equal to a square of any number.
 * Input: none
 * Output: pairs of numbers
 */

//-------------- include section ------------
#include <iostream>

//-------------- using section --------------
using std::cout;
using std::endl;
using std::cin;

//-----------------  main -------------------
int main()
{
    //conditioning the first number from the pair to be from 1 to 1000
    for (int num1 = 1; num1 <= 1000; num1++) 
    {
        //conditioning the second number from the pair to be from 1 to 1000
        for (int num2 = num1; num2 <= 1000; num2++) 
        {
            bool found1 = false; //creating a boolean condition 

            int sum1 = num1 * num1 + num2 * num2; //determining one of the sums

            for (int i = 1; i * i * i <= sum1; i++) //creating a variable for one of the results
            {
                if (i * i * i == sum1) //checking the first sum with the first result
                {
                    found1 = true; //successful comparison
                    break;
                } 
            }
            //determining that the second condition exists only if the first condition exists as well
            if (found1) 
            {
                int sum2 = num1 * num1 * num1 + num2 * num2 * num2; //determining the second sum

                bool found2 = false; //creating another boolean condition

                for (int i = 1; i * i <= sum2; i++) //creating a variable for the second condition
                {
                    if (i * i == sum2) //checking the second sum with the second result
                    {
                        found2 = true; //successful comparison
                        break;
                    } 
                }
                if (found2)
                    cout << num1 << " " << num2 << endl; 
            }
        }
    }

 return 0;
}