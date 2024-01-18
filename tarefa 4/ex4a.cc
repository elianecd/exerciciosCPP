/*
 * Counting how many cells from an array is divisible by the cell before him
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program calculates whether the value of a cell from an array is:
 * - Divisible by the value of the cell before him;
 * - And also divides the value of the cell after him;
 * The divisions must to have no remainder.
 * The array contains 6 cells.
 * The program will count how many cells that follow those conditions. 
 * Input: An array.
 * Output: The quantity of the cells that follow the conditions.
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int N = 6; 

//------------------ main ---------------------
int main()
{
	int array[N];
	int count = 0;

    //creating a variable for the array
	for (int i = 0; i < N; i++)
		cin >> array[i]; //the user input

	for (int i = 1; i < N-1; i++) //working with the same variable
	{
		//checking if the values of the cells follow the conditions
		if (array[i] % array[i-1] == 0 && array[i+1] % array[i] == 0)
			count++; //counting the cells that follow the conditions
	}
	cout << count << endl; //printing the quantity of the cells from the conditioning

	return EXIT_SUCCESS;
}
