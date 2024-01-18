/*
 * The difference between random numbers 
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program calculates the difference between random numbers:
 * - The first line result shows the difference between the first number 
 * with itself, the first with the second number and then with the last number.
 * - The second line result shows the difference between the second number
 * with the first number, thus with itself and then with the third number.
 * - The third line result shows the difference between the third number
 * with the first number, therefore with the second number and then with itself.
 * Input: three random integer numbers
 * Output: the difference between them
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
    int num1, num2, num3; //defining the type of the input

    //the options the user may input:
    cin >> num1 >> num2 >> num3;  //three random integer numbers

    //showing the resul of the difference between the first input number 
    //with itself, therefore with the second input and then with the last and third input.
    cout << num1 - num1 << " " << num1 - num2 << " " << num1 - num3 << endl;

    //showing the resul of the difference between the second input number 
    //with the first number, therefore with itself and then with the last and third input.
    cout << num2 - num1 << " " << num2 - num2 << " " << num2 - num3 << endl;

    //showing the resul of the difference between the third input number 
    //with the first number, therefore with the second number and then with itself.
    cout << num3 - num1 << " " << num3 - num2 << " " << num3 - num3 << endl;

    return 0;
}


