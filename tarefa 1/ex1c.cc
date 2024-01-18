/*
 * The final grade of the course
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program calculates the final grade of the course by calculating the 
 * percentage of his compounds by steps:
 * - The first step is to calculate the grade of the assignment 1 (targil 1) 
 * which represents 10% of the final grade.
 * - The second step is to calculate the grade of the assignment 2 (targil 2)
 *  which represents 20% of the final grade.
 * - The third step is to calculate grade of the exam which represents 70% of the final grade.
 * - After calculating all the percentage of the final grade compounds, just need to sum all of them.
 * Input: the grade of the first assignment, the grade of the second assignment and the grade of the exam
 * Output: the final grade of the course
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
    double num1, num2, num3, targil1, targil2, exam, finalgrade; //defining the numbers as double

    //the options the user may input:
    cin >> num1 >> num2 >> num3; //the grades os the assignments and the exam

    //calculating the grade of the assignment 1 to represents 10% of the final grade
    targil1 = (num1 * 0.1);

    //calculating the grade of the assignment 2 to represents 20% of the final grade
    targil2 = (num2 * 0.2);

    //calculating the grade of the exam to represents 70% of the final grade
    exam = (num3 * 0.7);

    //calculating the final grade by the sum of all the other grades after the percentage was calculated
    finalgrade = targil1 + targil2 + exam;

    //must show the final grade
    cout << finalgrade << endl;

    return 0;

}

