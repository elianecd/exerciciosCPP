/*
 * Finding the small array inside of the big array
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program checks whether the small array is found inside of the big array.
 * The small array must be found in his original order inside of the big array.
 * The small array contains 3 cells.
 * The big array contains 9 cells. 
 * Input: Small array first followed by the big array
 * Output: The position of the cell that is found the beginning of the small array.
 *         Or -1 if the small array is not found or is not in the correct order.
*/

//-------------- include section ------------
#include <iostream> 
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int N = 3;
const int M = 9;

//------------------ main ---------------------
int main()
{
    int small[N];
    int big[M];
    bool found;
    int i;

    for (i = 0; i < N; i++) //creating a variable for the small array
        cin >> small[i]; //the user input

    for (i = 0; i < M; i++) //creating a variable for the big array
        cin >> big[i]; //also user input
    
    for (i = 0; i <= M-N; i++) //working with the same variable to roam the big array
    {
        found = true;

        for (int j = 0; j < N; j++) //creating a variable to roam the small array
        {
            //checking if any number of the small array is not found inside of the big
            if (small[j] != big[i+j]) 
            {
                //any number of the small is not found inside of the big array
                found = false; 
                //to get out of the condition and go to the loop to check the next number
                break; 
            }
        }
        //checking that any number of the small array is found inside of the big
        if (found == true) 
            //to get out to go to the loop again to check the next number in the big array
            break; 
    }
    //checking that all the numbers of the small array is found inside of the big array
    if (found == true) 
        cout << i << endl; //printing the first cell that is found the small array

    else 
        cout << "-1" << endl; //print this if the small array is not found

    return EXIT_SUCCESS;
}