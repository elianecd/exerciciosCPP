/*
Checking valid password
 =============================================================
 Writen by: Eliane Dahab

This program does simple recursion operations from a simple array:
1. Enters values from the user into the array;
2. Sums all the values of the array and shows the result of the sum;
3. Bubble sort the array to put all the values in a crescent order;
4. Searches inside the array for the wanted number that the user enters,
    but first the array must be bubbled sorted, if it not, will print "Error",
    and then will "1" if the number is found or "0" if it is not;
5. Checks whether the array is an arithmetic progression;
6. Shows the values of the array from beginning to the end;
7. Shows the values of the array from end to the beginning;
8. Starting from the third cell, the program checks if the current cell 
    represents the sum of the values of the 2 cells before him.
    The program will print "1" if the cell is the sum of the 2 cells before him,
    or will print "0" if the cell is not the sum; 
9. Checks if the array is palindrome;
10. Counts how many series are in the array, crescent and decrescent order;
11. Finds the maximum value of the sub-array.
    The user enters the number of the first and last cell of the sub-array.
12. Shows the prime numbers found in the array according to the order of the array;
13. Closes the program.
Input: Array of 10 cells
Output: the answers of the operations
*/ 
 
//-------------- include section ------------
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
 
//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;
using std::cerr; 
using std::swap;

//-------------- const and enum section --------------
enum commands
{
	READ_DATA = 1,
    SUM,
    BUBBLE_SORT,
    BINARY_SEARCH,
    ARITHMETIC_PROGRESSION,
    ARRAY_FROM_BEGINNING,
    ARRAY_FROM_END,
    SUM_OF_2_BEFORE,
    PALINDROM,
    NUMBER_OF_PROGRESSION,
    MAX_VALUE,
    PRIME_NUMBERS,
	end_program,
};

const int N = 10;


//----------------prototypes-----------------
void get_command(int array[N], int command, bool sorted);
void fill_array(int array[N], int cell);
void sum_array(const int array[N], int sum, int i);
void bubble_sort(int array[N], int i);
void find_place(int array[N], int i);
void binary_search(const int array[N], bool sorted, int i);
bool inside_binary_search(const int array[N], int center, int hi, int lo, int wanted);
void arithmetic_progression(const int array[N], int i,int d, bool &is_ap);
void array_from_beginning(int array[N], int i);
void array_from_end(int array[N], int i);
void curr_cell_equal_sum_of_2_cells_before(const int array[N], int i, bool &equal);
void isPalindrom(int array[N], int size);
void sum_sub_progression(int array[N], int size, int counter);
void print_max_value(int array[N]);
int max_value(int array[N], int begin, int end);
void prime_numbers(int array[N], int i);
bool check_prime(int array[N], int div, int i);

//------------------ main ---------------------
int main()
{   
    int array[N] = {0};
    bool sorted = false;
    int command;

    cin >> command;
    get_command(array, command, sorted);

	return EXIT_SUCCESS;
}

//------------------ functions --------------------

void get_command(int array[N], int command, bool sorted)
{
    switch (command)
    {
    case READ_DATA: fill_array(array, 0);
        sorted = false;
        break;
    
    case SUM: sum_array(array, 0, 0);
        break;

    case BUBBLE_SORT: bubble_sort(array, 0);
        //sorted = true;
        break;

    case BINARY_SEARCH: binary_search(array, sorted, 0);
        break;
    
    case ARITHMETIC_PROGRESSION:
    {
        int d = array[1] - array[0];    
        bool is_ap = true;              
        arithmetic_progression(array, 2, d, is_ap);
        cout << is_ap <<endl;
    }
    break;
       
    case ARRAY_FROM_BEGINNING: array_from_beginning(array, 0);
        break;

    case ARRAY_FROM_END: array_from_end(array, N-1);
        break;

    case SUM_OF_2_BEFORE : 
    {
        bool equal = true;
        curr_cell_equal_sum_of_2_cells_before(array, 2, equal);
        cout << equal << endl;
    }
    break;

    case PALINDROM:
    {
        //int size = sizeof(array);
        isPalindrom(array, N);
    } 
    break;

    case NUMBER_OF_PROGRESSION: sum_sub_progression(array, N, 0);
        break;

    case MAX_VALUE: print_max_value(array);
    break;

    case PRIME_NUMBERS: prime_numbers(array, 0);
        break;

    case end_program: 
        return;

    default:
        break;
    }
    
    //now after finishing one command, reads the next one now
    cin >> command;
    get_command(array, command, sorted);
}
//----------------------------------------

void fill_array(int array[N], int i)
{
    if (i == N) //finish condition
        return;
    
    cin >> array[i];
    i += 1; // now in the next recursion we get inside to the next cell! like for!
    fill_array(array, i);
}
//------------------------------------

void sum_array(const int array[N], int sum, int i)
{
    if (i == N) //finish condition
    {
        cout << sum;
        return;
    }
    
    sum += array[i];
    i++;
    sum_array(array, sum, i);
}
//------------------------------------

void bubble_sort(int array[N], int i)
{
    if (i < N)
    {
        find_place(array, 0);
        bubble_sort(array, i+1);
        cout << array[i] << " ";
    }
}
//------------------------------------

void find_place(int array[N], int i)
{
    if (i < N-1)
    {
        if (array[i] < array[i+1])
            swap(array[i], array[i+1]);
    
        find_place(array, i+1);
    }
}
//--------------------------------

void binary_search(const int array[N], bool sorted, int i)
{
    if (sorted == false)
    {
        cerr << "Error\n";
        return;
    }
    else
    {
        int wanted; 
        int center;
        int hi;
        int lo;
        bool found = false;

        cin >> wanted;

        center = ((N-1)/2);
        lo = 0;
        hi = N-1;
        found = inside_binary_search(array, center, hi, lo, wanted);

        if (found == true)
            cout << "1" << endl;
        
        else
            cout << "0" << endl;
    }
}

//-------------------------------

bool inside_binary_search(const int array[N], int center, int hi, int lo, int wanted)
{
    bool found = false;

    if (center == lo)
        return false;
    
    if (wanted == array[hi] || wanted == array[lo] || wanted == array[center])
        return true;

    if ((wanted >= array[center]) && (wanted < array[hi]))
        found = inside_binary_search(array, (center+ hi)/2, hi, center, wanted);
    
    if ((wanted < array[center]) && (wanted > array[lo]))
        found = inside_binary_search(array, (lo+center)/2, center, lo, wanted);

    return found;
}
//----------------------------------------------------------------------------------------------
void arithmetic_progression(const int array[N], int i, int d, bool &is_ap)
{   
    if (i < N)
    {
        if (array[i] - array[i - 1] != d)
        {
            is_ap = false;
            return;
        }
        else
        {
            i += 1;
            arithmetic_progression(array, i, d, is_ap);
            return;
        }       
    }                   

    if (i >= N) // stop condition for thr 10'th child (the last one)
    {
        if (is_ap)
            return;

        else
            return;        
    }   
}
//------------------------------------------------------

void array_from_beginning(int array[N], int i)
{
    if (i >= N)
    {
        cout << endl;
        return;
    }

    cout << array[i] << " ";
    i += 1;
    array_from_beginning(array, i);
}
//--------------------------------

void array_from_end(int array[N], int i)
{
    if (i < 0) //i<0  ||  i == -1 
    {
        cout << endl;
        return;
    }

    cout << array[i] << " ";
    i-=1; //i--
    array_from_end(array, i); 
}
//-----------------------------------

void curr_cell_equal_sum_of_2_cells_before(const int array[N], int i, bool &equal)
{
    if (i >= N)
        return;

    if (array[i] != array[i-1] + array[i-2])
    {
        equal = false;
        return;
    }
    i += 1;
    curr_cell_equal_sum_of_2_cells_before(array, i, equal);          
}
//-----------------------------

void isPalindrom(int array[N], int size)
{
    if (size == 0 || size == 1)
    {
        cout << "1" <<endl;
        return;
    }
    if (array[0] != array[size-1])
    {
        cout << "0" << endl;
        return;
    }
    isPalindrom(array + 1, size - 2);
}
//----------------------------------------------

void sum_sub_progression(int array[N], int size, int counter)
{
    if (size == 0)
    {
        cout << counter << endl;
        return;
    }
    if (size == 1)
    {
        cout << counter+1 << endl;
        return;
    }
    if (array[0] < array[1])
    {
        int i = 1;
        size -= 2; 
        while(size >= 1 && array[i] <= array[i+1])
        {
            i++;
            size--;
        }
        counter++;
        sum_sub_progression(array + i + 1, size, counter);
    }
    if (array[0] > array[1])
    {
        int i = 1;
        size -= 2;
        while (size >= 1 && array[i] >= array[i+1])
        {
            i++;
            size--;
        }
        counter++;
        sum_sub_progression(array + i + 1, size, counter);
    }
    if (array[0] == array[1])
        sum_sub_progression(array + 1, size--, counter);
}
//----------------------------------------

void print_max_value(int array[N])
{
    int begin, end;
    cin >> begin >> end;

    if (end < begin || end > N)
    {
        begin = 0;
        end = 9;
    }
    cout << max_value(array, begin, end);
}
int max_value(int array[N], int begin, int end)
{
    int max = array[begin];
    if (end == begin)
        return array[begin];
    
    int temp =  max_value(array, begin + 1, end);
    if (max < temp)
        max = temp;
    
    return max;
}
//---------------------------------------------------

void prime_numbers(int array[N], int i) 
{
    bool is_prime = false;
    int div = 2;

    if (i < N)
    {
        is_prime = check_prime(array, i, div);
    
        if ((array[i] > 1) && (is_prime = false) || array[i] == 2)
        {
            cout << array[i] << " ";
        }
        prime_numbers(array, i + 1);
    }
    else 
        cout << endl;
}

bool check_prime(int array[N], int i, int div)
{
    bool is_prime;
    if (div <= (array[i] / 2))
    {
        if (array[i] % div == 0)
            return true;
        
        else
            is_prime = check_prime(array, i, div + 1);
    }
    return is_prime;
}