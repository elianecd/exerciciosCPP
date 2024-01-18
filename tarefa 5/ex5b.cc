/*
* Identifying in an array the cell that is divided by and divides
* =============================================================
* Writen by: Eliane Dahab
*
* This program identifies from an array which cell follows the conditions:
* - is divided by the values of the cells before him, without remainder;
* - divides the values of the cells after him, without remainder.
* Input: An array 
* Output: Index of the cell
*         Or -1 if the cell with those conditions does not exist.
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
void readInput(int array[N]);
int findFirstDivisorDivider(int array[N]);
bool checkLeft(int array[N], int index);
bool checkRight(int array[N], int index);

//------------------ main ---------------------
int main()
{
    int array[N];

    readInput(array);

    cout << findFirstDivisorDivider(array) << endl; //prints the index of the cell

    return EXIT_SUCCESS;
}

//------------------ functions --------------------

//filling the array with the user input
void readInput(int array[N])
{
    for (int i = 0; i < N; i++)
        cin >> array[i]; //user input
}

//function to find the cell that follows the conditions
int findFirstDivisorDivider(int array[N])
{
    for (int i = 0; i < N; i++)
        if (checkLeft(array, i) && checkRight(array, i))
            return i;

    return -1; //print this if the cell is not found
}

//function to check whether the value of the cell is divided by 
//the values of the cells before him, must to have no remainder.
bool checkLeft(int array[N], int index)
{
    for (int left = 0; left < index; left++)
        if (array[left] == 0 || array[index] % array[left] != 0)
            return false;

    return true;
}

//function to check whether the value of the cell divides 
//the values of the cells after him, must to have no remainder.
bool checkRight(int array[N], int index) 
{
    for (int right = index + 1; right < N; right++)
        if (array[index] == 0 || array[right] % array[index] != 0)
            return false;

    return true;
}