/*Due date:Feburary 15,2016*
Author:Jeremy Bicford
course number:2170-03
This progrom takes a file input of string lines and converts each line into acronym
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;
void OpenFile (ifstream& readFile);
void acronym(string line);

int main() 
{   ifstream readFile;
    string line;
    OpenFile ( readFile);
    getline(readFile, line);
    while (readFile.good())//read untill file error 
    {
        cout << line<< "--->";
       acronym(line);
            getline(readFile, line);//read next line for processing
    }
    return 0;
}  

void OpenFile (ifstream& readFile) // Function opens file and checks validity.
{
    readFile.open("../Acronym.dat");// Open file stream and assert whether it works.
    assert(readFile);
}
void acronym(string line)//function turns each line into acronyms
{
    char prev = ' ';  // to remember previous character, also forces use of fir character
        for (int i = 0; i < line.length(); i++)
        {
            // if previous was space and current is not, use it
            if(prev == ' ')
                {cout << (char) toupper(line[i]);}// make single uppercase letter
            prev = line[i]; // always remember previous 
        }
        cout << endl; // new line after string processed
}