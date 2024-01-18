/*
* Checking valid password
* =============================================================
* Writen by: Eliane Dahab
*
* This program receives 2 strings for the following operations:
* First identifies whether the first string contains:
* - Letter in lower case, so it converts to upper case;
* - Character that are not letters, it removes them.
* After that, the program compare the 2 strings.
* The comparison is to check similar characters between them.
* If both strings contain the same characters,
* the program will print the characters that are not in common between them.
* Input: Two strings
* Output: The first string all in upper case and only letter,
          String that prints the characters that are not in common in both strings.
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;
using std::getline;

//-------------- const section --------------
const int MAX_STR_LEN = 100;

//----------------prototypes-----------------
void read_input(char str[MAX_STR_LEN]);
void remove(char str[MAX_STR_LEN]);
void not_in_common(char str1[MAX_STR_LEN], char str2[MAX_STR_LEN]);

//------------------ main ---------------------
int main()
{   
    char str1[MAX_STR_LEN];
    char str2[MAX_STR_LEN];

    read_input(str1);
    read_input(str2);

    remove(str1);
    not_in_common(str1, str2);

	return EXIT_SUCCESS;
}

//------------------ functions --------------------

void read_input(char str[MAX_STR_LEN])
{  
    char c;

    for (int i = 0; i < MAX_STR_LEN; i++) //now here we are going to read to the str_encode string
    {
        cin.get(c);

        if (c == '\n') //if user finished the string (means he pressed enter)
        {
            str[i] = '\n';
            break; //finishing reading input...
        }
        str[i] = c;
    }
    //cout << str;
}
//-----------------------------------------

//remove what is not letter and convert lower case letters in upper case 
void remove(char str[MAX_STR_LEN])
{
    for (int i = 0; str[i] != '\n'; i++)
    {
        if (isalpha(str[i])) //checking if is letter
        {
            if (islower(str[i])) //checking if the lower is in lower case
                cout << char(toupper(str[i])); //converting lower case to upper case

            else
                cout << char(str[i]); //keeps if the letter is already in upper case
        } 
    } 
    cout << endl;   
}
//-----------------------------------------

//print what is not in common between the 2 strings
void not_in_common(char str1[MAX_STR_LEN], char str2[MAX_STR_LEN])
{
    int i = 0, j = 0;
    bool flag = true;

    while (str1[i] != '\n')   
    {
        j = 0; flag = true;

        while (str2[j] != '\n')
        {
            if (str1[i] == str2[j])
            {
                //means that was found character in common
                flag = false;
                break;
            }           
            j++;
        }
        if (flag)
            cout << str1[i];
        i++;
    }
    cout << endl;
}