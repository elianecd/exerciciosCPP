//-------------- include section ------------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iomanip>

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
    
    srand(SEED); //SRAND IS THE THE RANDOMIZE NUMBERS MACHINE - LIKE WHEN WE USE THIS COMMAND
                 //MEANS WE OPEN THE RANDOMIZE NUMBER DUE TO SEED = 17
    int n = rand() % 3 + 2; //NOW WE GET A NUMBER BETWEEN 2 TO 4 :) 
    //cout << n << endl;
 
    read_data(str_encode);
    switch_letter_by_n(str_encode, n);   
    reverse_str(str_encode, n);                                  
    add_ramdon(str_encode, n);                                    
    add_n_at_the_end(str_encode,n);
}
//---------------------------------------
void decode()
{
    char str_decode[N];

    read_data(str_decode);

    int n = find_n(str_decode, n);
    cout << n << endl;

    remove_random(str_decode, n);
    reverse_str(str_decode, n);
    switch_to_original(str_decode, n);

    int a = 99;
    //find_n(str_decode, n);

}

//-----------------------------------------------------
void read_data(char str[N]) //no const char str [N] because we edit the str [N]
{
    //in order to read the backspace after the first command (1 or 2) here we now get the space 
    char c;
    cin.get(c);

    for(int index = 0; index < N; index++) //now here we are going to read to the str_encode string
    {
        cin.get(c);
        if (c == '\n') //if user finished the string (means he pressed enter)
        {
            str[index] = '\n';
            break; //finishing reading input...
        }
        str[index] = c;
    }
}

//---------------------------------------------
int switch_letter_by_n(char str_encode[N], int n) //WE DO NOT USE CONST TO THE ARRAY DUE TO THE FACT WE ARE EDITING THIS CURRENT ARRAY
{
     //according to the request at the exercise - now here we are going to rand a number and
     //due to this randome num we are going to add random(n) times for each letter 

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
            //cout << "upper" <<endl; //like ASDFGHJDCMO
        }
    }
    cout << str_encode << endl;

    return 0;
}

//--------------------------------------------------------
void reverse_str(char str_encode[N], int n)
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
    cout << size << endl;
    
    int start = 0;
    int end = n;

    while (end <= size)
    {
        int jump = 0;
        for (int index = start; index < end; index++)
        {
            if (index == end - jump - 1) //here we check if we finished swap characters
               break;

            char a = str_encode[index];
            str_encode[index] = str_encode[end - jump - 1];
            str_encode[end - jump - 1] = a;
            jump++;  
        }
        start += n;
        end += n;
    }
    cout << str_encode;
    cout << endl;
}

//----------------------------------------------------------------
void add_ramdon(char str_encode[N], int n)
{
    int i = 0;
    char c = 'a' + rand() % 26;//this way we get a random char
    while (str_encode[i] != '\n')
    {
        if (i % (n + 1) == n)
        {
            char saver = str_encode[i];
            str_encode[i] = c; //insert the randomize char
            //here we add the curr random char 
            for (int j = i + 1; j < N; j++)//here we move all the next right side of the array 1 cell right
            {
                char next = str_encode[j];
                str_encode[j] = saver;

                if (saver == '\n')
                   break;

               saver = next;   
            }                            
        }
        i++;
    }
   // cout << str_encode << endl;
}

//------------------------------------
void add_n_at_the_end(char str_encode[N], int n)
 {
     for (int i = 0; i < N; i++)
     {
        if (str_encode[i] == '\n')//means we finished so here we add the n at the end of the array and break
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
    cout << str_encode << endl;   
}

//------------------------------------------------
int find_n(char str_decode[N], int n)
{
    for (int i = 0; i < N; i++)
    {
        if (str_decode[i] == '\n') //the end of the string
        {
            n = str_decode[i - 1]; 
            str_decode[i - 1] = '\n';

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

//-------------------------------------------
void remove_random(char str_decode[N], int n)
{
    int i = 0;
    int counter = 0; //0-4 cells
  
    while (str_decode[i] != '\n')
    {
        counter++;
        if(counter == n + 1)
        {
          //means we want to delete
            for (int j = i  ; j < N; j++)//here we move all the next right side of the array 1 cell left
            {
                str_decode[j] = str_decode[j + 1];
                if (str_decode[j + 1] == '\n')  
                    break;
                
            }
          counter =  1;//reset the counter
        }
        i++;
    }
    cout << str_decode << endl;
}
//------------------------------------------------
void switch_to_original(char str_decode[N], int n)
{
    for (int index = 0; str_decode[index] != '\n'; index++)//here wee run till the end of the array
    {
        if (islower(str_decode[index]))
        {
           str_decode[index] -= n; 
           if (str_decode[index] < 97)//a = 97
           {
               char new_char = '{'; 
               char jump = 'a' - str_decode[index]  ;
               new_char -= jump;
               str_decode[index] = new_char;
           }
        }
        else if (isupper(str_decode[index]))
        {
            str_decode[index] -= n; //n
            if (str_decode[index] < 65)
            {
                char new_char = '['; //A = 65
                char jump = 'A' - str_decode[index];
                new_char -= jump;
                str_decode[index] = new_char;
            }
            //cout << "upper" <<endl; //like ASDFGHJDCMO
        }
    }
    cout << str_decode << endl;
}

