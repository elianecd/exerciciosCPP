/*
* Dividing gold bars
* =============================================================
* Writen by: Eliane Dahab
*
* This program divides the gold bars equally between 2 persons.
* The input is an array of 5 numbers that represents the weigh 
* of the rocks. 
* Means, the program divides the rocks in a manner that the 2 persons
* get the same weigh of gold bars.
* If the division won't be equal between the 2 persons, the program 
* will print: "Cannot divide".
* If the division can be equal, will be printed in separated lines what
* each person will get of the total of the gold bars.
* Input: The array of 5 numbers (the weigh of the 5 gold bars)
* Output: The division
*/

//-------------- include section ------------
#include <iostream>
#include <cstdlib>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-------------- const section --------------
const int N = 5;

//----------------prototypes-----------------
void read_data(int rocks[N]);
bool divide_rocks(const int rocks[N], int person1[N],
                  int person2[N], int index);
bool check_divison(const int person1[N], const int person2[N]);
void print_division(const int person1[N], const int person2[N]);

//------------------ main ---------------------
int main()
{
    int person1[N] = {0};
    int person2[N] = {0};
    int rocks[N];
    int index = 0; //to run over the rocks

    read_data(rocks);
    divide_rocks(rocks, person1, person2, index);

    return EXIT_SUCCESS;
}
//-----------------------------------------------

void read_data(int rocks[N])
{
    //To fill the array with the input
    for (int i = 0; i < N; i++)
        cin >> rocks[i];
}
//-----------------------------------------------

bool divide_rocks(const int rocks[N], int person1[N],
                  int person2[N], int index)
{
    bool flag = false, temp = false;

    if (index == 5)
    {
        //If the division is equall
        if (check_divison(person1, person2) == true)
        {
            //send to print
            print_division(person1, person2);
            return true;
        }
    }
    else
    {
        //Filling the array of person1 with the rocks
        person1[index] = rocks[index];
        temp = divide_rocks(rocks, person1, person2, index+1);
        if (temp)
            flag = true;
        person1[index] = 0;

        //Filling the array of person2 with the rocks
        person2[index] = rocks[index];
        temp = divide_rocks(rocks, person1, person2, index+1);
        if (temp)
            flag = true;
        person2[index] = 0;
    }
    if (index == 0 && !flag)
        cout << "Cannot divide";

    return flag;
}
//-------------------------------------------------

bool check_divison(const int person1[N], const int person2[N])
{
    int sum_person1 = 0;
    int sum_person2 = 0;

    //to sum for each person
    for (int i = 0; i < N; i++)
    {
        sum_person1 += person1[i];
        sum_person2 += person2[i];
    }
    
    //checks if the sum of one is equal to the other
    //means, if the division is equal
    if (sum_person1 == sum_person2)
        return true;

    return false;
}
//-----------------------------------------------

void print_division(const int person1[N], const int person2[N])
{
    static bool print_only_one = true;

    if (print_only_one == true)
    {
        for (int i = 0; i < N; i++)
            if (person1[i] != 0)
                cout << person1[i] << " ";

        cout << endl;

        for (int i = 0; i < N; i++)
            if (person2[i] != 0)
                cout << person2[i] << " ";
            
        cout << endl;

        //This way it will print only once at the program
        print_only_one = false; 
    }
}