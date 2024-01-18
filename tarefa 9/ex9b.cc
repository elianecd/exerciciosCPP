/*
* Pattern matching
* =============================================================
* Writen by: Eliane Dahab
*
* This program receives 2 strings from the user.
* Every string is up to 50 characters each.
* The first string is called string and the second string is called pattern.
* The program checks whether the string matches with the pattern.
* The conditions to check the match are:
* - For every normal character that is not "*" or "?" in the pattern
* fits only if the character is the same in the string;
* - For each "?" character in the pattern, matches for each individual 
* character in the string;
* - For the "*" character in the pattern, may matches zero or more characters
* in the string.
* In the end, will print 1 if the 2 strings match or 0 for no match.
* Input: The 2 strings
* Output: 1 or 0
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int N = 50;

//----------------prototypes-----------------
void read_input(char str[N]);
int check_format(char array[N], char format[N], 
                 int array_index, int format_index);

//------------------ main ---------------------
int main()
{
   char array[N];
   char format[N];

   read_input(array);
   read_input(format);
   cout << check_format(array, format, 0, 0);

   return EXIT_SUCCESS;
}
//---------------------------------------------

void read_input(char str[N])
{  
    char c;

    //To read to the string
    for (int i = 0; i < N; i++) 
    {
        cin.get(c);

        //If user finished the string (means he pressed enter)
        if (c == '\n') 
        {
            str[i] = '\n';
            break; //Finishing reading input
        }
        str[i] = c;
    }
}
//---------------------------------------------------

int check_format(char array[N], char format[N], 
                 int array_index, int format_index)
{
    //If the 2 arrays finish together, so return true
    //means if they finish at the same time
    if (array[array_index] == '\n' && format[format_index] == '\n')
        return 1; 
    
    //If one of the array is bigger than the other
    if (array[array_index] == '\n' || format[format_index] == '\n')
        return 0;
    
    //If there the characters are the same in both arrays
    //or if there is "?", so send to check the next character in both arrays
    if (array[array_index] == format[format_index]
        || format[format_index] == '?')
    {
        int result = check_format(array, format, 
                     ++array_index, ++format_index);  
        return result;   
    }

    if (format[format_index] == '*')
    {
        //If there is "*", and till here the arrays were equal,
        //so send to check the next character in the format, after the 
        //"*" to check what the "*" includes
        if (check_format(array, format, array_index, ++format_index))
            return 1;

        else
        {
            //May occur that the "*" come at the first cell of the format, 
            //so we progress counting the characters in the array to
            //verify what the "* includes"
            while (array[array_index] != '\n')
            {
                array_index++;
                //If till here the arrays were similar after or/and before the "*"
                //so return true
                if (check_format(array, format, array_index, format_index))
                    return 1;
            }
            return 0;            
        }        
    }
    return 0;
}