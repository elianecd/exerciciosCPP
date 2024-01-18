/*
 * Finding the loop inside of the array
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program identifies whether there is a loop inside of the array.
 * The array contains 8 cells.
 * The loop happens when the value of a cell points to the position of another cell and so on.
 * And the loop finishes until the last cell in the series indicates back the first cell of the loop. 
 * Input: An array.
 * Output: The positions of the cells that represents the loop. Not including back the start cell.     
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int N = 8;

//------------------ main ---------------------
int main()
{
    int i;
    bool found = false;
    int array[N];

    for (i = 0; i < N; i++ ) //creating a variable for the array
        cin >> array[i]; //the user input

    for (i = 0; i < N; i++) //working with the variable that was created to roam the array
    {
        int count = 0;

        //creating another variable for the next number/cell of the loop
        for (int next = array[i]; next >= 0 && next < N; next = array[next]) 
        {
            if (next == i) //checking the position with the value of the other cell
            {
                found = true; //checking concluded
                break; //getting out of the condition 
            }
            //checking whether the value of a cell is higher than the numbers of the cells
            if (count > N) 
                break; //getting out of the condition
            count++; //going to the next cell
        }   
        if (found == true) //checking the existence of a loop inside of the array
            break; //going to the next command
    }
    if (found == true) //checking again the existence of a loop inside of the array
    {
        cout << i; //printing the first position of the loop
        
        //creating a variable for the positions of the loop
        for (int next = array[i]; next != i; next = array[next])
            cout << " " << next; //printing the other positions of the loop
        cout << endl;
    }
    return EXIT_SUCCESS;
}