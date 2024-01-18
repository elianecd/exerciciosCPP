/*
 * The average and amount of positive and negative numbers
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program calculates from a serie of numbers with zero, these following aspects:
 * - The amount of numbers in the serie, not counting the zero;
 * - The average of all numbers until zero, the average is calculated by their sum divided by their amount;
 * - The amount of positive numbers until zero;
 * - The amount of negative numbers until zero.
 * The program will read all the numbers until the zero.
 * The moment that the program identifies the zero in the serie, he will stop running and will not take in consideration the numbers after him.
 * The zero won't be part of the serie for the calculation.
 * Input: a serie of numbers
 * Output: In the first line will be printed the amount of numbers and their average.
 *         In the second line will be shown the amount of positive and negative numbers from the serie.
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
	int number; 
	int amount = 0;
	double sum = 0;
	int positive = 0;
	int negative = 0;

	cin >> number; //user input

	while (number != 0) //determining to calculate all the numbers until we get zero
	{
		amount++;

		sum += number; //sum of the amount

		if (number > 0) //checking if the number is positive
			positive ++;

		else //checking if the number is not positive, so will be negative
			negative ++;

		cin >> number; //taking the next number of the serie

	}

	cout << amount << " " << sum / amount << endl; //printing the first line
	cout << positive << " " << negative << endl; //printing the second line

	return 0;
}
