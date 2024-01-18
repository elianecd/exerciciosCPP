/*
 * ID numbers verification
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program verifies whether the ID is a valid number.
 * The first step is to identify the amount of digits of the ID. 
 * A valid ID has at least 6 digits up to 9 digits.
 * The second step is to multiply by 2 the digits that are in even positions.
 * The third step is to sum the digits of the multiplication, which means that if the number multiplied by 2 got the result a number of 2 digits, we sum those 2 digits.
 * After all the that we sum all the digits, the sum must be divided by 10 without any rest to be considered as a valid number.
 * Input: ID number up to 9 digits.
 * Output: 1 for a valid ID or 0 for a wrong or invalid ID number.
 */

//-------------- include section ------------
#include <iostream>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::endl;

//-----------------  main -------------------
int main()
{
	//determining the numbers type
	long long id;
	int counter = 1, sum = 0, tempID = 0, len;
        
	cin >> id; //user input

	tempID = id;

    //adding a variable to calculates the length of the id
	for (len = 0; tempID > 0; len++)
		tempID = tempID / 10;
	
	if (len >= 6 && len <= 9) //conditioning that the id has between 6 and 9 digits 
	{
		while (counter <= 9) //couting the digits
		{
			int digit = id % 10; //taking each digit separately
			id /= 10; 

			if (counter % 2 == 0) //checking if the digit is in the even position
				digit *= 2; //if the digit is in the even position so we multiply the digit by 2

			if (digit > 9) //conditioning the result of the multiplication
			{
				int temp = 0; 
				temp += digit % 10; //taking each digit result separately
				digit /= 10;
				temp += digit; //sum the 2 digits of the multiplication result
				sum += temp; //adding the sum of the 2 digits to the sum of the all digits
			}
			else
				sum += digit; //sum all the digits of the id

			counter ++; //making the step to check the next digit
		}
        //conditioning that the sum of the all digits must be a divisible number by 10 without rest
		if (sum % 10 == 0 && id == 0) 
			cout << "1" << endl; //valid id number
		else
			cout << "0" << endl; //wrong id number
	}
	else
		cout << "0" << endl; //invalid id number

	return 0;
}