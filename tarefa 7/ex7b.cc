/*
* Encryption
* ========================================
* Writen by: Eliane Dahab
*
* This program has 2 processes: encode and decode.
* The first process (encode) identifies a string and does the following steps:
* - Every letter jumps n letters in the ASCII table.
* Means that if n is 3, the letter X will become A for example.
* Does not matter whether the letter is upper or lower case.
* What is not letter, do not suffer any modification.
* - After that, the modified string suffers a mirror process.
* Means that the first letter will swap with the last letter and so on.
* For example: abcde will become edcba.
* - And then, add a random letter between the string according to n jumps.
* Means that after n characters, a random letter is added.
* - For last, add the value of n in the end of the string.
* The second process (decode) is the reverse process.
* Means that receives a string after that suffered a encode process.
* And decode the string.
* The last character of the string is the n jumps.
* - So the program identifies the n.
* - Remove the random letter added between the string according to n jumps.
* - Does the mirror process to reverse.
* - Jump back n times in the ASCII table.
* The n jumps is in between 2 to 4, means that the maximum of jumps possible is 3.
* Input: 1 (to encode process) or 2 (to decode process) and then the string.
* Output: A decode or encoded string.
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
const int N = 1000;
const int SEED = 17;

//----------------prototypes-----------------
void encode();
void decode();
void read_data(char str[N]);
int switch_letter_by_n(char str_encode[N], int n);
void reverse_str(char str_encode[N], int n);
void add_ramdon(char str_encode[N], int n);
void add_n_at_the_end(char str_encode[N], int n);
int find_n(char str_decode[N], int n);
void remove_random(char str_decode[N], int n);
void switch_to_original(char str_decode[N], int n);
void print_str(const char str_decode[N]);

//------------------ main ---------------------
int main()
{
   int command;

   cin >> command;

   if (command == 1) //encode process
       encode();
   
   else if (command == 2) //decode process
       decode();

    return EXIT_SUCCESS;
}

//------------------ functions --------------------

void encode()
{
    char str_encode[N];
    
    srand(SEED); //srand is the ramdomize numbers machine 
    int n = rand() % 3 + 2; //To get a number between 2 to 4 
 
    read_data(str_encode);
    switch_letter_by_n(str_encode, n);   
    reverse_str(str_encode, n);                                  
    add_ramdon(str_encode, n);                                    
    add_n_at_the_end(str_encode,n);
}
//-----------------------------------------

void decode()
{
    char str_decode[N];

    read_data(str_decode);

    int n = find_n(str_decode, n);

    remove_random(str_decode, n);
    reverse_str(str_decode, n);
    switch_to_original(str_decode, n);
    find_n(str_decode, n);
}
//-----------------------------------------

void read_data(char str[N]) //No const char str[N] because we edit the str[N].
{
    //In order to read the backspace after the first command (1 or 2),
    //here is to get the space. 
    char c;
    cin.get(c); //to read till enter, reads every character separately

    //Here is to read to the str_encode string
    for(int index = 0; index < N; index++) 
    {
        cin.get(c);
        if (c == '\n') //If user finished the string (means he pressed enter)
        {
            str[index] = '\n';
            break; //Finishing reading input...
        }
        str[index] = c;
    }
}
//-----------------------------------------

//No const is used to the string because we are edditing this current string.
int switch_letter_by_n(char str_encode[N], int n) 
{
    //Here is to rand a number and due to this randomize,
    //we add random(n) times for each letter.

    for (int index = 0; str_encode[index] != '\n' ; index++)
    {
        if (islower(str_encode[index]))
        {
            str_encode[index] += n; 
            if (str_encode[index] > 122)
            {
                char new_char = '`'; //a = 97
                char jump = str_encode[index] - 'z';
                new_char += jump;
                str_encode[index] = new_char;
            }
        }
        else if (isupper(str_encode[index]))
        {
            str_encode[index] += n; //n
            if (str_encode[index] > 90)
            {
                char new_char = '@'; //A = 65
                char jump = str_encode[index] - 'Z';
                new_char += jump;
                str_encode[index] = new_char;
            }
        }
    }
	print_str(str_encode);  
    return 0;
}
//-----------------------------------------

void reverse_str(char str_encode[N], int n) //mirror process
{
    //here we check the size of the array
    int size = 0;
    for (int i = 0; i < N; i++)
    {
        if (str_encode[i] != '\n')
            size++;
        
        else
           break;
    }
    
    int start = 0;
    int end = n;

    while (end <= size)
    {
        int jump = 0;
        for (int index = start; index < end; index++)
        {
            if (index == end - jump - 1) //Checking if finished swaping characters
               break;

            char a = str_encode[index];
            str_encode[index] = str_encode[end-jump-1];
            str_encode[end-jump-1] = a;
            jump++;  
        }
        start += n;
        end += n;
    }
    print_str(str_encode);  
}
//-----------------------------------------

void add_ramdon(char str_encode[N], int n)
{
	srand(SEED); //Calling the srand again.
    int i = 0;
    char c = 'a' + rand() % 26; //To get a random char.
    while (str_encode[i] != '\n')
    {
        if (i % (n+1) == n)
        {
            char saver = str_encode[i];
            str_encode[i] = c; //Insert the randomize char.
            
            //To add the current random char.
            for (int j = i + 1; j < N; j++)
            {
                //Here we move all the next right side of the array 1 cell right
                char next = str_encode[j];
                str_encode[j] = saver;

                if (saver == '\n')
                   break;

               saver = next;   
            }                            
        }
        i++;
    }
}
//-----------------------------------------

void add_n_at_the_end(char str_encode[N], int n)
{
    for (int i = 0; i < N; i++)
    {
        //Means we finished so here we add the n at the end of the array and break.
        if (str_encode[i] == '\n')
        {
            if (n == 2)
              str_encode[i] = '2';
            if (n == 3)
              str_encode[i] = '3';
            if (n == 4)
              str_encode[i] = '4';

            str_encode[i + 1] = '\n';    
            break;
        }
    } 
    print_str(str_encode);  
}
//-----------------------------------------

int find_n(char str_decode[N], int n)
{
    for (int i = 0; i < N; i++)
    {
        if (str_decode[i] == '\n') //The end of the string.
        {
            n = str_decode[i-1]; 
            str_decode[i-1] = '\n';

            if (n == '2')
                return 2;

            if (n == '3')
                return 3;

            if (n == '4')
                return 4;
        }
    }
    return 0;
}
//-----------------------------------------

void remove_random(char str_decode[N], int n)
{
    int i = 0;
    int counter = 0; //0-4 cells
  
    while (str_decode[i] != '\n')
    {
        counter++;
        if(counter == n+1)
        {
            //Means we want to delete.
            for (int j = i  ; j < N; j++)
            {
                //Here we move all the next right side of the array 1 cell left.
                str_decode[j] = str_decode[j+1];
                if (str_decode[j+1] == '\n')  
                    break;
            }
          counter =  1; //Reset the counter.
        }
        i++;
    }
    print_str(str_decode);
}
//-----------------------------------------

void switch_to_original(char str_decode[N], int n)
{
    //Runs till the end of the array.
    for (int index = 0; str_decode[index] != '\n'; index++)
    {
        if (islower(str_decode[index]))
        {
            str_decode[index] -= n; 
            
            if (str_decode[index] < 97) //a = 97
            {
                char new_char = '{'; 
                char jump = 'a' - str_decode[index];
                new_char -= jump;
                str_decode[index] = new_char;
            }
        }
        else if (isupper(str_decode[index]))
        {
            str_decode[index] -= n; 
            if (str_decode[index] < 65)
            {
                char new_char = '['; //A = 65
                char jump = 'A' - str_decode[index];
                new_char -= jump;
                str_decode[index] = new_char;
            }
        }
    }
    print_str(str_decode);
}
//-----------------------------------------

void print_str(const char str_decode[N])
{
    for (int i = 0; i < N; i++)
    {
        if (str_decode[i] != '\n')
            cout << str_decode[i];
        
        else
        {
            cout << endl;
            break;
        }
    }
}