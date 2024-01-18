/*
* Row and column with the highest sum of values
* =============================================================
* Writen by: Eliane Dahab
*
* This program identifies which row and column has the highest sum of values.
* The program sums all the values of each row and each column.
* It compares the results (the sums) of each row with other rows.
* And compare the sums of each column with other columns.
* Display as result the row and the column with the highest sum.
* All the values of the matrix are positive.
* Input: A matrix 
* Output: Row Column
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
const int COL = 5;

//----------------prototypes-----------------
void readInput(int array[ROW][COL]);
int index_max_row(int array[ROW][COL]);
int index_max_col(int array[ROW][COL]);

//------------------ main ---------------------
int main()
{
    int array[ROW][COL];

    readInput(array);

    cout << index_max_row(array) << " " << index_max_col(array) << endl;
  
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

//function to sum all the values of each row
//and then to find the row with the highest sum
int index_max_row(int array[ROW][COL])
{
    int max_row = 0, index1 = 0;

    for (int i = 0; i < ROW; i++)
    {
        int sum_row = 0;

        for (int j = 0; j < COL; j++)
            sum_row += array[i][j]; //adding the rows values

        if (sum_row > max_row)
        {
            max_row = sum_row;
            index1 = i; //defining which row has the highest value
        }
    }
    return index1;
}

//function to sum all the values of each column
//and then to find the column with the highest sum
int index_max_col(int array[ROW][COL])
{
    int max_col = 0, index2 = 0;

    for (int j = 0; j < COL; j++)
    {
        int sum_col = 0;
        
        for (int i = 0; i < ROW; i++)
            sum_col += array[i][j]; //adding the columns values

        if (sum_col > max_col)
        {
            max_col = sum_col;
            index2 = j; //defining which column has the highest value
        }
    }
    return index2;
}
