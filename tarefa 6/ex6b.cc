/*
* Statistical informations about an array
* =============================================================
* Writen by: Eliane Dahab
*
* This program identifies triangles inside a matrix.
* First, identifies whether the sides are equals to the top.
* Then, checks whether there is a base for the sides.
* The checking happens through values, comparing the cells. 
* The minimal size of any side of the triangle must be 3.
* The base of the triangle is always horizontal.
* Is possible to find triangles in standing and inverted positions.
* So triangles can share the same base.
* The size of the triangle is counted by the cells of his side.
* Lastly, the program identifies which triangle is the biggest and what his size.
* Input: A matrix of 10 rows and 15 columns 
* Output: Row Column: Size standing or inverted. Value:
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int ROW = 10;
const int COL = 15;
const int UP = 1;
const int DOWN = 2;
const int MIN_SIZE = 3;

//----------------prototypes-----------------
void readInput(int mat[ROW][COL]);
void check_triangle_beginning(int mat[][COL]);
int check_is_real_triangle(int mat[][COL], int row, int col, int check);
int check_down(int mat[][COL], int row, int col);
int check_up(int mat[][COL], int row, int col);
bool check_base(int mat[][COL], int row, int col_start, int col_end);
void check_max_triangle(int size, int &max_size, int &sum_max);

//------------------ main ---------------------
int main()
{
    int mat[ROW][COL];

    readInput(mat);
    check_triangle_beginning(mat);

    return EXIT_SUCCESS;
}

//------------------ functions --------------------

//filling the array with the user input
void readInput(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cin >> mat[i][j]; //user input
}

void check_triangle_beginning(int mat[][COL])
{
    int size = 0; 
    int max_size = 0;
    int sum_max = 0;

    for (int row = 0; row < ROW; row++)
    {
        for (int col = 2; col < COL - 2; col++) 
        {
            size = 0;

            if (row == 0 || row == 1) //check if there is a triangle at the bottom
            {
                if (mat[row][col] == mat[row + 1][col - 1] && mat[row][col] == mat[row + 1][col + 1])
                {
                    size = check_is_real_triangle(mat, row, col, UP);

                    if (size != 0)
                    {
                        cout << row << " " << col << ": " << size << " standing. Value: " << mat[row][col] << endl;
                        check_max_triangle(size, max_size, sum_max);
                    }   
                }       
            }
            else if (row == ROW - 1 || row == ROW - 2) //check if there is a triangle at the top
            {
                if (mat[row][col] == mat[row - 1][col - 1] && mat[row][col] == mat[row - 1][col + 1])
                {
                    size = check_is_real_triangle(mat, row, col, DOWN);

                    if (size != 0)
                    {
                        cout << row << " " << col << ": " << size << " inverted. Value: " << mat[row][col] << endl;
                        check_max_triangle(size, max_size, sum_max);
                    }
                }
            }
            else if (mat[row][col] == mat[row - 1][col - 1] && mat[row][col] == mat[row - 1][col + 1] 
                    || mat[row][col] == mat[row + 1][col - 1] && mat[row][col] == mat[row + 1][col + 1])      
            {
                
                size = check_is_real_triangle(mat, row, col, UP);

                if (size != 0)
                {
                    cout << row << " " << col << ": " << size << " standing. Value: " << mat[row][col] << endl;
                    check_max_triangle(size, max_size, sum_max);
                }

                size = check_is_real_triangle(mat, row, col, DOWN);

                if (size != 0)
                {
                    cout << row << " " << col << ": " << size << " inverted. Value: " << mat[row][col] << endl;
                    check_max_triangle(size, max_size, sum_max);
                }
            }
        }
    }
    cout << sum_max << " " << max_size << endl;
}

int check_is_real_triangle(int mat[][COL], int row, int col, int check)
{
    int result = 0;

    if (check == UP)
    {
        result = check_down(mat, row, col);
        return result;
    } 
    if (check == DOWN)
    {
        result = check_up(mat, row, col);
        return result;
    }
    return 0;
}

//function to check only standing triangles
int check_down(int mat[][COL], int row, int col)
{
    int counter = 1;
    int current_row = row + 1;
    int current_col_left = col - 1;
    int current_col_right = col + 1;
    int max_counter = 0;

    //check that we do not overflow the matrix
    while (current_row < ROW && current_col_left >= 0 && current_col_right < COL)
    {
        counter++;

        if (mat[row][col] == mat[current_row][current_col_left] &&
            mat[row][col] == mat[current_row][current_col_right]) 
        {
            if (check_base(mat, current_row, current_col_left, current_col_right))
                max_counter = counter; //save the triangle
        } 
        else //here we finished finding equal sides
        {
            if (max_counter >= MIN_SIZE)
                  return max_counter;
            return 0;
        }
          
        current_row++;
        current_col_left--;
        current_col_right++;
    }
    if (max_counter >= MIN_SIZE)
        return max_counter;

  return 0;
}

//function to check only inverted triangles
int check_up(int mat[][COL], int row, int col)
{
    int counter = 1;
    int current_row = row - 1;
    int current_col_left = col - 1;
    int current_col_right = col + 1;
    int max_counter = 0;

    while (current_row >= 0 && current_col_left >= 0 && current_col_right < COL)
    {
        counter++;

        if (mat[row][col] == mat[current_row][current_col_left] &&
            mat[row][col] == mat[current_row][current_col_right]) 
        {
            if (check_base(mat, current_row, current_col_left, current_col_right))
                max_counter = counter;
        }
        else 
        {
            if (max_counter >= MIN_SIZE)
                  return max_counter;
            return 0;
        }

        current_row--;
        current_col_left--;
        current_col_right++;
    }

    if (max_counter >= MIN_SIZE)
        return max_counter;

  return 0;
}

//function to check whether there is triangle base
//if all the sides of the triangle are equals
bool check_base(int mat[][COL], int row, int col_start, int col_end)
{
    for (int i = col_start + 1; i < col_end; i++)
    {
        if (mat[row][col_start] != mat[row][i])
            return false;
    }
    return true;
}

//function to count the biggest triangles and their sizes
void check_max_triangle(int size, int &max_size, int &sum_max)
{
    if (size > max_size)
    {
        max_size = size;
        sum_max = 1;
    }
    else if (size == max_size)
        sum_max++;
}