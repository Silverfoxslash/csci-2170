#include <iostream>
using namespace std;

void DisplayTitle();
void GetDate(int month,int day, int year);
int CalcDayofWeek(int month, int day,  int year);  
void isALeapYear(int year);
void DisplayDay(int weekday);

int main() 
{ 

    int month, day, year;
    int weekday;      
    DisplayTitle();
    GetDate(int month, int day, int year);
    
    //use the input to calculate the number of the day and store it into a variable
    weekday = CalcDayofWeek(month, day, year);
    //use the calculated number of the weekday to print the name of the day.
    cout << "You were born on a ";
    DisplayDay(weekday);
    cout <<endl;
    isALeapYear( year );
    return 0;
}

 

void DisplayTitle()
{
   cout << "\n       Zeller's Algorithim     ";
   cout << endl;
}


void GetDate(int& month, int& day, int& year)// calling the function by reference
{
    cout << endl;
    cout << " Enter the Month: ";
    cin >> month;
    cout << endl;
    cout << " Enter the Day:  ";
    cin >> day;
    cout << endl;
    cout << " Enter the year: ";
    cin >> year;
    cout << endl;
}
//int weekday;
int CalcDayofWeek (int month, int day, int year) //change return type of this function
{   
    int modifiedMonth;
   
    switch(month)
    {
        case 1: modifiedMonth = 11; break;
        case 2: modifiedMonth = 12; break;
        case 3: modifiedMonth = 1; break;
        case 4: modifiedMonth = 2; break;
        case 5: modifiedMonth = 3; break;
        case 6: modifiedMonth = 4; break;
        case 7: modifiedMonth = 5; break;
        case 8: modifiedMonth = 6; break;
        case 9: modifiedMonth = 7; break;
        case 10: modifiedMonth = 8; break;
        case 11: modifiedMonth = 9; break;
        case 12: modifiedMonth =  10; break;
    } 
    
    int weekday = day+ (13 * modifiedMonth - 1)/ 5 + (year % 100) + (year/ 100)/ 4 - 2*(year/100);
    return weekday;  // return the number of the day
   //weekday = 2.6*m - .2 + k + d +(d/4)+(c/4)- 2 * c %7; 
}

void DisplayDay(int weekday) 
{
     switch (weekday) 
     {
        case 0: cout << "Sunday" << endl; break;
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        case 3: cout << "Wednesday" << endl; break;
        case 4: cout << "Thursday" << endl; break;
        case 5: cout << "Friday" << endl; break;
        case 6: cout << "Saturday" << endl; break;
        default:
        cout << "Enter a valid date." << endl;
     }     
}

void isALeapYear( int year )
{
/* Check if the year is divisible by 4 or 
is divisible by 400 */
    if ( (year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
        cout<< "The year "<< year<< " is a leap year.";
    else
         cout << "The year "<< year<< " is a leap year.";
}