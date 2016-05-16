/*Due date:Feburary 15,2016*
Author:Jeremy Bicford
course number:2170-03
This progrom takes a user input of of positive number and returns if that number is a perffect number
 */
#include <iostream>
using namespace std;

int getUserInput();
int isPerfect(int inputNum);

int main()
{
    int inputNum=getUserInput();
    isPerfect(inputNum);
    
   return 0; 
}

int getUserInput()//takes user input and returns it to main function
{
        int userInput;
        cout << "Please enter a positive number: ";
        cin >> userInput;
        if (userInput < 0)
        {
            getUserInput();//if not positio=ve number use recursion to loop
        }
        else
        {
        return userInput;
        }
}
int isPerfect(int inputNum)
{
    int perfectTotal = 0;
    int i;
    for(i=1 ; i < inputNum/2+1; i++ )//loops to half of the input number
        {if (inputNum % i == 0)
            {
                perfectTotal += i;//if number is multiple of input add to total
            }
        };
    if (perfectTotal == inputNum)//if total of multiples is equal to input its a perfect number
        {
            cout << endl << inputNum << " is a perfect number.";
        }
    else
        {
            cout << endl << inputNum << " is not a perfect number.";
        }
    return 0;
}