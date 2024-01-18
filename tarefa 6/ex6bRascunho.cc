#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

//----------
const int ROW = 5;
const int COL = 5;
const int UP =1;
const int DOWN = 2;

//-------------------
void readInput(int mat[ROW][COL]);
void check_left_right_beginning(int mat[][COL]);
//void check_is_real_triangle(int mat[][COL], int, int);
int check_is_real_triangle(int mat[][COL], int row, int col, int cheak);
int cheack_down(int mat[][COL], int row, int col);
int cheack_up(int mat[][COL], int row, int col);
bool cheack_base(int mat[][COL], int row, int colstart, int colend);
void reset_res_matrix(int mat[][5]);

//------------------------------------------------
int main()
{
    int mat[ROW][COL];
    int result_matrix[ROW][5];
    readInput(mat);
    reset_res_matrix(result_matrix);
    check_left_right_beginning(mat,result_matrix);

	return EXIT_SUCCESS;
}

//----------------------------
void reset_res_matrix(int mat[][5])
{
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < 5; j++)
             mat[i][j] = -1;
}
void readInput(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            cin >> mat[i][j];
}
//-------------------------------------------------------------------------------
void check_left_right_beginning(int mat[][COL], int result_matrix[][5])
{
    int res=0; //he will save us the size of the cutt triangle if it is a real triangle 
        //it will be equle to =>3 , else it is not trinagle acorging to the exc so it will be = -1

    ind_row_res = 0;
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 2; col < COL - 2; col++)
        {
            res=-1;
            if (row == 0 || row == 1)  //HERE WE NEED TO CHEAK ONLY IF THERE A TRIANGLE AT BOTTOM
            {
               if (mat[row][col] == mat[row + 1][col - 1] && mat[row + 1][col + 1])
               {
                    res= check_is_real_triangle(mat, row, col,UP); 
                    if(res != -1)//MEANS WE FOUND AND THEN PRINT
                    {
                        result_matrix[ind_row_res][0]=row;
                        result_matrix[ind_row_res][1]=col;
                        result_matrix[ind_row_res][2]=res;
                        result_matrix[ind_row_res][3]=(mat[row][col];
                        result_matrix[ind_row_res][4]=UP;
                        ind_row_res++;

                       cout << row <<" " << col <<": "<< res<< "standing. Value: " << mat[row][col] << endl;
                    } 
               }
                    
            }
            else if (row == ROW - 1 || row == ROW - 2)//HERE WE CHEAK IF THERE TRING AT UPPER
            {
                if (mat[row][col] == mat[row - 1][col - 1] && mat[row - 1][col + 1])
                {
                    res=    check_is_real_triangle(mat, row, col,2); 
                    if(res != -1)
                    {
                       cout << row <<" " << col <<": "<< res<< "inverted. Value: " << mat[row][col] << endl;
                    } 
                }
                   
                 
            }
            else if (mat[row][col] == mat[row - 1][col - 1] && mat[row - 1][col + 1] //HERE WE NEED TO CHEAK UP AND DOWN
                || mat[row][col] == mat[row + 1][col - 1] && mat[row + 1][col + 1])
            {
                res=  check_is_real_triangle(mat, row, col,1); 
                if(res != -1)//MEANS WE FOUND AND THEN PRINT
                {
                    cout << row <<" " << col <<": "<< res<< "standing. Value: " << mat[row][col] << endl;
                } 
                res=  check_is_real_triangle(mat, row, col,2); 
                if(res != -1)//MEANS WE FOUND AND THEN PRINT
                {
                     cout << row <<" " << col <<": "<< res<< "inverted. Value: " << mat[row][col] << endl;
                } 
            }
        }
    }
}
//-------------------------------------------------------------------------------------------
int check_is_real_triangle(int mat[][COL], int row, int col, int cheak)
{   
     int resu=-1;
    if(cheak == 1)//const int DOWN = 1
    {
       // cout << "DOWN" <<row << " "<< col<<" "<<endl;
      
       resu= cheack_down(mat, row, col);//row and col are the starting triangle
         //   cout << "DOWN " <<row << " "<< col<< "SIZEOFTRIANGLE: "<< resu<<endl;
       return resu;
    //cheak_dowm(,,,)
    //RETUTN RESULT

    }
    if(cheak == 2)//const int UP = 2
    {
       // cout << "UP" <<row << " "<< col<<" "<<endl;
        resu= cheack_up(mat, row, col);
         //    cout << "UP  " <<row << " "<< col<< "SIZEOFTRIANGLE: "<< resu<<endl;
        return resu;
    //cheak_up(,,,)
    }

    return 0;
}
//---------------------cheack_down---------------------------------------------
int cheack_down(int mat[][COL], int row, int col)
{
    int counter = 1;
    int current_r=row+1;
    int current_c_left=col-1;
    int current_c_right=col+1;
    int max_counter = -1;

    while (current_r< ROW && current_c_left>=0 && current_c_right< COL)//HERE WE CHEAK THAT WE DONT OVERFOLW FROM MAT
    {
        counter++;
        if (mat[row][col] == mat[current_r][current_c_left]  &&
             mat[row][col] == mat[current_r][current_c_right]) //HERE WE CHEAK THAT THE NEXT LINE IF IT STILL A TRIANGLE :)
        {
            //CHEAK BASIC =
            //IF BASCIK RETURN TRUE IT MEANS IT IS A GOOD TRUANGLE
            if(cheack_base(mat, current_r,current_c_left, current_c_right ))
            {
                max_counter= counter;//SAVE THE TRAINGLE
                //MAX TRIANGLE = COUNTER;
            }
        } 
        current_r++;
        current_c_left--;
        current_c_right++;
    }
    
    if(max_counter >= 3)//MEANS WE HAVE A REAL TRINAGLE! MIN = 3 :)
    {
        return  max_counter;
    } 
    return -1;
}

//---------------------------------------------------------------
//
//here we chak thAT IF THE BASIC OF THE CURR TIRANGLE IS OK
//I MEAN THAT ALL OF HIS VALUSES ARE EQULE 
bool cheack_base(int mat[][COL], int row, int colstart, int colend)
{
    for (int i = colstart; i < colend; i++)
    {
        /* code */
        if(mat[row][colstart] != mat[row][i])
        {
            return false;
        }
    }
    
    return true;
}
//---------------------------------------------------------------
int cheack_up(int mat[][COL], int row, int col)
{
    int counter = 1;
    int current_r=row-1;
    int current_c_left=col-1;
    int current_c_right=col+1;
    int max_counter = -1;

    while (current_r < ROW && current_c_left >= 0 && current_c_right < COL)//HERE WE CHEAK THAT WE DONT OVERFOLW FROM MAT
    {
        counter++;
        if (mat[row][col] == mat[current_r][current_c_left]  &&
             mat[row][col] == mat[current_r][current_c_right]) //HERE WE CHEAK THAT THE NEXT LINE IF IT STILL A TRIANGLE :)
        {
            //CHEAK BASIC =
            //IF BASCIK RETURN TRUE IT MEANS IT IS A GOOD TRUANGLE
            if(cheack_base(mat, current_r,current_c_left, current_c_right ))
            {
                max_counter = counter;//SAVE THE TRAINGLE
                //MAX TRIANGLE = COUNTER;
            }
        } 
        current_r--;
        current_c_left--;
        current_c_right++;
    }
    
    if(max_counter >= 3)//MEANS WE HAVE A REAL TRINAGLE! MIN = 3 :)
    {
        return  max_counter;
    } 
    return -1;
}

