/*
* Checking valid password
* =============================================================
* Writen by: Eliane Dahab
*
* This program verifies which password is valid.
* Means, which password contains the requirement that is asked to have.
* So, first the input will be the number of password's possibilities.
* And then, following will come the possibilities of password (per line).
* After, also as input, the program receives the number of requirements.
* And then, following will come the requirements (per line).
* A password is valid if contains at least one character of each requirements.
* Input: Passwords and requirements. 
* Output: A valid password.
*
* The Runtime of the check_valid_password function is:
* Good case: size_inp_passwd runs just one time through check_one_password.
* The check_one_password function runs input*check times, means that it depends
* on the size of the arrays.
* Worst case: check_valid_password function will run 
* [size_inp_passwd*size_mandatory] * check_one_password.
* Means, the check_one_password went through all the characters of the arrays.
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

//-------------- const section --------------
const int MAX_STRS = 10;
const int MAX_STR_LEN = 100;

//----------------prototypes-----------------
int read_input(char current_passwd[MAX_STRS][MAX_STR_LEN]);
void check_valid_password(const char inp_passwdd[MAX_STRS][MAX_STR_LEN],
                          char out_passwdd[MAX_STRS][MAX_STR_LEN],
                          const char mandatory[MAX_STRS][MAX_STR_LEN],
                          int size_inp_passwd, int size_mandatory, 
                          int &size_out_passwd);
bool check_one_password(const char input[MAX_STR_LEN],
                        const char check[MAX_STR_LEN]);
void print_array(char array[][MAX_STR_LEN], int size);

//------------------ main ---------------------
int main()
{
    char inp_passwd[MAX_STRS][MAX_STR_LEN];
    char out_passwd[MAX_STRS][MAX_STR_LEN];
    char mandatory[MAX_STRS][MAX_STR_LEN];

    int size_inp_passwd = read_input(inp_passwd);
    int size_mandatory = read_input(mandatory);
    int size_out_passwd = 0;

    check_valid_password(inp_passwd, out_passwd, mandatory, 
                         size_inp_passwd, size_mandatory, size_out_passwd);

    print_array(out_passwd, size_out_passwd);

	return EXIT_SUCCESS;
}

//------------------ functions --------------------

int read_input(char current_passwd[MAX_STRS][MAX_STR_LEN])
{
    int rows ;
    cin >> rows;
    
    char c;
    cin.get(c); //to read till enter, reads every character separately

    int counter = 0;

    //If counter is smaller than rows, means it didn't finished reading the lines.
    while (counter < rows) 
    {
        cin.get(c); //for the first cell

        int col = 0;

        while (c != '\n')
        {
            current_passwd[counter][col] = c;
            col++;
            cin.get(c);
        }
        current_passwd[counter][col] = '\n'; //means finished another line 
        counter++;
    }
    return rows;
}
//-----------------------------------------

void check_valid_password(const char inp_passwd[MAX_STRS][MAX_STR_LEN],
                          char out_passwd[MAX_STRS][MAX_STR_LEN],
                          const char mandatory[MAX_STRS][MAX_STR_LEN],
                          int size_inp_passwd, int size_mandatory, 
                          int &size_out_passwd)
{
    for (int i = 0; i < size_inp_passwd; i++)
    {
        bool flag = true, temp = true;

        for (int j = 0; j < size_mandatory; j++)
        {   
            //here we send to check character by character     
            temp = check_one_password(inp_passwd[i], mandatory[j]);

            if (!temp) 
            {
                //means that the requirements were not found in the passwords
                flag = false;
                break;
            }
        }
        if (flag)
        {
            int k = 0;

            while (inp_passwd[i][k] != '\n')
            {
                out_passwd[size_out_passwd][k] = inp_passwd[i][k];
                k++;
            }
            out_passwd[size_out_passwd][k] = '\n';  
            size_out_passwd++;
        }
    }    
}
//-----------------------------------------

bool check_one_password(const char input[MAX_STR_LEN],
                        const char check[MAX_STR_LEN])
{   
    int i = 0, j = 0;

    while (input[i] != '\n')
    {
        j = 0;

        while (check[j] != '\n')
        {
            if (input[i] == check[j])
                return true;
          
            j++;
        }
        i++;       
    }
    return false; 
}
//-----------------------------------------

void print_array(char array[][MAX_STR_LEN], int size)
{
    int counter = 0;
    while (counter < size)
    {
        int col = 0 ;
        while (array[counter][col] != '\n')
        {
            cout << array[counter][col];
            col++;
        }
        cout << endl;   
        counter++;
    }
}