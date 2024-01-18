/*
* Common value in the same line
* ========================================
* Writen by: Eliane Dahab
*
* This program identifies in each row the number that most appears.
* The program will print the common value in a line if the same number,
* does not appear a larger number of times in any other line.
* Input: An array of 4 rows and 7 columns. 
* Output: Row Value TimesAppeared
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int ROW = 4;
const int COL = 7;
const int ROW_RESULT = 4;
const int COL_RESULT = 7;
const int EMPTY = -1;

//----------------prototypes-----------------
void readInput(int array[ROW][COL]);
void times_in_row(const int array[ROW][COL], int result_array[ROW_RESULT][COL_RESULT]);
bool check_to_print(const int array[][COL], int max_digit, int max_counter, int current_row);
void print_data(const int result_array[ROW_RESULT][COL_RESULT]);

//------------------ main ---------------------
int main()
{
    int array[ROW][COL];

    readInput(array);

    int result_array[ROW_RESULT][COL_RESULT];

    times_in_row(array,result_array);
    print_data(result_array);

    return EXIT_SUCCESS;
}

//------------------ functions --------------------

//filling the array with the user input
void readInput(int array[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cin >> array[i][j]; //user input
}

void times_in_row(const int array[ROW][COL], 
    int result_array[ROW_RESULT][COL_RESULT])
{
    //here we set the results
    result_array[0][0] = EMPTY;
    result_array[1][0] = EMPTY;
    result_array[2][0] = EMPTY;
    result_array[3][0] = EMPTY;

    //here we know the index of the new line that need to be added
    int ind_res=0; 
    int max_counter = 0;
    int max_digit = 0;

    for (int i = 0; i < ROW; i++)
    {
        int counter = 0;
        max_counter = 0;

        for (int j = 0; j < COL; j++)
        {
            //now we are at one array and try to find the max_digit here
            counter = 0;

            for (int index = j; index < COL; index++) //moving forward with the row
            {
                if (array[i][j] == array[i][index])
                    counter++;
            }
            if (counter > max_counter)
            {
                max_digit = array[i][j];
                max_counter = counter;
            }
        }

        //Now we send to a bool function that tell us which row 
        //has the highest max with the same digit we have.
        if (check_to_print(array, max_digit, max_counter, i) == true)
        {
            //cout << "row index " << i << " digit " << max_digit
            // << " counter " << max_counter << endl;
            result_array[ind_res][0] = i;
            result_array[ind_res][1] = max_digit;
            result_array[ind_res][2] = max_counter; 
            ind_res++;
        }
    }  
}

bool check_to_print(const int array[][COL], int max_digit, int max_counter,
                    int current_row)
{
    //define a counter to help us counter the number of max_digit at each line
    int counter = 0;
    for (int row = 0; row < ROW; row++)
    {
        counter = 0;

        if (row == current_row)
           continue; 
        
        for (int col = 0; col < COL; col++)
            if (array[row][col] == max_digit)
                counter++;

        if (counter > max_counter)
            return false;
    }
    return true;
}

//function to print
void print_data(const int result_array[ROW_RESULT][COL_RESULT])
{
    for (int i = 0; i < ROW_RESULT; i++)
    {
        if (result_array[i][0] == EMPTY)
            continue;
        else
        {
            cout << result_array[i][0] << " " << result_array[i][1] << " "
                 << result_array[i][2] << endl;
        }        
    }
}