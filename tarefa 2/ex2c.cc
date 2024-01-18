/*
 * Date in words
 * =============================================================
 * Writen by: Eliane Dahab
 *
 * This program prints any date in numbers to words. 
 * The first step is to condition the days according to the days of a month and print it in words. 
 * The second step is to condition the months according to their names.
 * The third step is to condition the days according to the months.
 * The last step is to condition the year.
 * Input: Any date such as 22 6 1992
 * Output: Printing the date in words like 22nd June 1992
*/

//-------------- include section ------------
#include <iostream>
#include <string>

//-------------- using section --------------
using std::cin;
using std::cout;
using std::string;
using std::to_string;

//-----------------  main -------------------
int main()
{
  //------------- enum section ------------
  int day, month, year;
  bool isValid = false;
  string dayString = "", monthString = "";

  cin >> day >> month >> year; //the user input
  
  //conditioning the days with their respectives sufix
  if (day == 1 || day == 21 || day == 31)
  {
    dayString = to_string(day) + "st";
  }
  else if (day == 2 || day == 22)
  {
    dayString = to_string(day) + "nd";
  }
  else if (day == 3 || day == 23)
  {
    dayString = to_string(day) + "rd";
  }
  else
  {
    dayString = to_string(day) + "th";
  }
 
  //conditioning the months with their respective names
  switch (month)
  {
    case 1:
      monthString = "January";
      break;
    case 2:
      monthString = "February";
      break;    
    case 3:
      monthString = "March";
      break;
    case 4:
      monthString = "April";
      break; 
    case 5:
      monthString = "May";
      break;
    case 6:
      monthString = "June";
      break;    
    case 7:
      monthString = "July";
      break;
    case 8:
      monthString = "August";
      break;  
    case 9:
      monthString = "September";
      break;
    case 10:
      monthString = "October";
      break;   
    case 11:
      monthString = "Movember";
      break;
    case 12:
      monthString = "December";
      break;                      
    
    default:
      monthString = " ";
      break;
  }
  //conditioning the number of the days in a month
  if (day > 0 && day < 32)
  {
    isValid = true;
  }
  
  //conditioning which months have 31 days
  if(day == 31)
  {
    if(month == 4 || month == 6 || month == 9 || month == 11 || month == 2)
    {
      isValid = false;
    }
  }
  
  //conditioning the month of February which has 28 days
  if (month == 2 && day > 29)
  {
    isValid = false;
  }
  
  //conditioning the numbers of the months in a year
  if (month > 12 || month < 0)
  {
    isValid = false;
  }

  //conditioning the leap year with February which has 29 days
  if (day == 29 && month == 2)
  {
    if(year % 4 != 0 && year % 100 != 0)
    {
      isValid = false;
    }
  }
  
  //conditioning the year
  if (year < 0 || year > 3000)
  {
    isValid = false;
  }

  //printing the result after all the conditions
  if (isValid == true)
  {
    cout << dayString << " " << month << " " << year;
  }
  return 0;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------