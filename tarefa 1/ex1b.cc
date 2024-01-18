/*
 * The area and the perimeter of a triangle
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program calculates the area and the perimeter of a triangle by the following steps:
 * The first step is to calculate the side of the triangle in order to calculte the Heron's formula.
 * The second step is to calculate the square root of the Heron's formula to find the area.
 * The third step is to calculate perimeter which is half of the side.
 * Input: three sides of the triangle
 * Output: the area and the perimeter of the triangle
*/


//-------------- include section ------------
#include <iostream> 
#include <cmath>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-----------------  main -------------------
int main()
{
    //------------- enum section ------------
    double side1, side2, side3, side, area, perimeter; //defining the type of the numbers such as input and output

    //the options the user may input:
    cin >> side1 >> side2 >> side3; //the sides of the triangle

    //calculating the side(used in Heron's formula)
    side = (side1 + side2 + side3) / 2; //using the input of the user

    //calculating the area of the triangle through Heron's formula
    area = sqrt (side * (side - side1) * (side - side2) * (side - side3));

    //calculating the perimeter of the triangle
    perimeter = side * 2; //is the same side used in the Heron's formula

    //must show the calculated area and the perimeter of the triangle in this respective order
    cout << area << " " << perimeter << endl;

    return 0;

}
