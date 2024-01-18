/*
 * The greater value between 3 numbers
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program calculates the maximum result that is possible to obtain between 3 numbers through sum and multiplication operations.
 * Is necessary to identify the possibilities of how to work with the 3 numbers. 
 * Then compare the results of the operations and print the highest result.
 * Input: Three random integer numbers
 * Output: The highest result between the 3 numbers through sum and multiplication
*/

//-------------- include section ------------
#include <iostream>

//-------------- using section --------------
using std::cin;
using std::cout;

//-----------------  main -------------------
int main()
{
    //------------- enum section ------------
    int num1, num2, num3, maxR1 = 0, maxR2 = 0, maxR3 = 0, maxR4 = 0, maxR5 = 0, maxR6 = 0, maxTotal = 0, maxTotal12 = 0, maxTotal34 = 0, maxTotal56 = 0;

    cin >> num1 >> num2 >> num3; //the user input

    //the possibilities using sum and multiplication with 3 numbers to obtain the maximum result between them
    maxR1 = num1 + num2 * num3;
    maxR2 = num1 * num2 + num3;
    maxR3 = num1 + num3 * num2;
    maxR4 = (num1 + num2) * num3;
    maxR5 = num1 * (num2 + num3);
    maxR6 = (num1 + num3) * num2;

    //comparing the results
    if (maxR1 > maxR2)
    {
        maxTotal12 = maxR1;
    }
    else
    {
        maxTotal12 = maxR2;
    }

    if (maxR3 > maxR4)
    {
        maxTotal34 = maxR3;
    }
    else
    {
        maxTotal34 = maxR4;
    }

    if (maxR5 > maxR6)
    {
        maxTotal56 = maxR5;
    }
    else
    {
        maxTotal56 = maxR6;
    }

    //comparing again the results with other results
    if (maxTotal12 > maxTotal34)
    {
        maxTotal = maxTotal12;
    }
    else
    {
        if (maxTotal34 > maxTotal56)
        {
            maxTotal = maxTotal34;
        }
        else
        {
            maxTotal = maxTotal56;
        }
    }

   //printing with the characters
   if (maxTotal == maxR1)
    {
        cout << num1 << " + " << num2 << " *  " << num3 << " = " << maxTotal;
    }
    else if (maxTotal == maxR2)
    {
        cout << num1 << " * " << num2 << " + " << num3 << " = " << maxTotal;
    }
    else if (maxTotal == maxR3)
    {
        cout << num1 << " + " << num3 << " * " << num2 << " = " << maxTotal;
    }

    else if (maxTotal == maxR4)
    {
        cout << "(" << num1 << " + " << num2 << ")" << " * " << num3 << " = " << maxTotal;
    }

    else if (maxTotal == maxR5)
    {
        cout << num1 << " * " << "(" << num2 << " + " << num3 << ")" << " = " << maxTotal;
    }

    else 
    {
        cout << "(" << num1 << " + " << num3 << ")" << " * " << num2 << " = " << maxTotal;
    }

 return 0;
}
