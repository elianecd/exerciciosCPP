#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

const int ROW = 10;
const int COL = 15;
const int UP = 1;
const int DOWN = 2;

void readInput(int mat[ROW][COL]);
void check_triangle_top(int mat[][COL]);
int check_is_real_triangle(int mat[][COL], int row, int col, int check);
int check_down(int mat[][COL], int row, int col);
int check_up(int mat[][COL], int row, int col);
bool check_base(int mat[][COL], int row, int col_start, int col_end);

int main()
{
    int mat[ROW][COL];
    
    readInput(mat);
    check_triangle_top(mat);

	return EXIT_SUCCESS;
}
void readInput(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cin >> mat[i][j];
}
void check_triangle_top(int mat[][COL])
{
    int size = 0; 

    for (int row = 0; row < ROW; row++)
    {
        for (int col = 2; col < COL - 2; col++)
        {
            size = -1;
            if (row == 0 || row == 1)  //HERE WE NEED TO CHEAK ONLY IF THERE A TRIANGLE AT BOTTOM
            {
               if (mat[row][col] == mat[row + 1][col - 1] && mat[row + 1][col + 1])
               {
                    size = check_is_real_triangle(mat, row, col, UP); 

                    if (size != -1)
                       cout << row << " " << col <<": " << size << " standing. Value: " << mat[row][col] << endl;
               }
            }
            else if (row == ROW - 1 || row == ROW - 2)//HERE WE CHEAK IF THERE TRING AT UPPER
            {
                if (mat[row][col] == mat[row - 1][col - 1] && mat[row - 1][col + 1])
                {
                    size = check_is_real_triangle(mat, row, col, DOWN); 

                    if(size != -1)
                       cout << row << " " << col << ": "<< size << " inverted. Value: " << mat[row][col] << endl;
                } 
            }
            else if (mat[row][col] == mat[row - 1][col - 1] && mat[row - 1][col + 1] //HERE WE NEED TO CHEAK UP AND DOWN
                    || mat[row][col] == mat[row + 1][col - 1] && mat[row + 1][col + 1])
            {
                size = check_is_real_triangle(mat, row, col, UP); 

                if(size != -1)//MEANS WE FOUND AND THEN PRINT
                    cout << row << " " << col << ": " << size << " standing. Value: " << mat[row][col] << endl;

                size = check_is_real_triangle(mat, row, col, DOWN);

                if(size != -1)//MEANS WE FOUND AND THEN PRINT
                    cout << row << " " << col << ": "<< size << " inverted. Value: " << mat[row][col] << endl;
            }
        }
    }
}
int check_is_real_triangle(int mat[][COL], int row, int col, int check)
{   
     int result = -1;
    if (check == UP)//const int DOWN = 1
    {
       result = check_down(mat, row, col);

       return result;
    }
    if (check == DOWN)//const int UP = 2
    {
        result = check_up(mat, row, col);

        return result;
    }
    return 0;
}
int check_down(int mat[][COL], int row, int col)
{
    int counter = 1;
    int current_row = row + 1;
    int current_col_left = col - 1;
    int current_col_right = col + 1;
    int max_counter = -1; 

    while (current_row < ROW && current_col_left >= 0 && current_col_right < COL)//HERE WE CHEAK THAT WE DONT OVERFOLW FROM MAT
    {
        counter++;
        if (mat[row][col] == mat[current_row][current_col_left]  &&
            mat[row][col] == mat[current_row][current_col_right]) //HERE WE CHEAK THAT THE NEXT LINE IF IT STILL A TRIANGLE :)
        {
            if(check_base(mat, current_row, current_col_left, current_col_right))
                max_counter= counter;
        } 
        current_row++;
        current_col_left--;
        current_col_right++;
    }
    if(max_counter >= 3)//MEANS WE HAVE A REAL TRINAGLE! MIN = 3 :)
        return max_counter;
    
    return -1;
}
int check_up(int mat[][COL], int row, int col)
{
    int counter = 1;
    int current_row = row - 1;
    int current_col_left = col - 1;
    int current_col_right = col + 1;
    int max_counter = -1;

    while (current_row < ROW && current_col_left >= 0 && current_col_right < COL)//HERE WE CHEAK THAT WE DONT OVERFOLW FROM MAT
    {
        counter++;
        if (mat[row][col] == mat[current_row][current_col_left]  &&
            mat[row][col] == mat[current_row][current_col_right]) //HERE WE CHEAK THAT THE NEXT LINE IF IT STILL A TRIANGLE :)
        {
            if(check_base(mat, current_row, current_col_left, current_col_right))
                max_counter = counter;
        } 
        current_row--;
        current_col_left--;
        current_col_right++;
    }
    if(max_counter >= 3)//MEANS WE HAVE A REAL TRINAGLE! MIN = 3 :)
        return max_counter;

    return -1;
}
bool check_base(int mat[][COL], int row, int col_start, int col_end)
{
    for (int i = col_start; i < col_end; i++)
    {
        if(mat[row][col_start] != mat[row][i])
            return false;
    }
    return true;
}

