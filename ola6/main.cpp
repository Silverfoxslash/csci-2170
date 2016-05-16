//PROGRAMMER: Jeremy Bickford
//Assignment: OLA 6
//Class: CSCI 2170 Section 1
//Course Instructor: Dr. Li
//Due Date: April 11,2016 midnight, monday
//Description:This program is a list of songs that you can add or remove and search for songs
//This program takes a input of a file with a list of song info like rank, artist,title and year
//This program outputs the song formented and able to search for secific data

#include <iostream>
#include <fstream>
#include <cassert>
#include "slist.h"
using namespace std;
void AddSond(SortedList& TopSongs);
void searchArtist(SortedList TopSongs);
void Delete(SortedList& songs);
void printYear(SortedList TopSongs);
void menu(SortedList Topsongs);
int main()
{   SortedList Topsongs;//initialise the song list
    ifstream myIn;//open file stream
    myIn.open("../topsongs.dat");
    assert(myIn);//check file opened
    
    songPtr aSong;//use for holding the info before adding to list
    //while lines are left in file and list is less that 500
    while (myIn>>aSong->rank && Topsongs.getLength() < 500) 
    {//read into songtype  var then send to list
        myIn.ignore(50,'\n');
		getline(myIn, aSong->artist);
        getline(myIn, aSong->title);
		myIn >> aSong->year;
        myIn.ignore(50,'\n');
		// addline below to add the book into the list
        Topsongs.Add(aSong);
    }
    menu(Topsongs);
 return 0;
}



void menu(songList Topsongs)
{   //menu interface
    int userInput;//intiate input var for search
    while(userInput!=5)
    {
        cout <<"\tBillboard Top Song (2012-2015) Management\n\n";
        cout <<"Please select from the following menu choices:\n\n";
        cout << "\t1. Look up an artist\n";
        cout <<"\t2. Add a song\n";
        cout <<"\t3. Delete a song\n";
        cout << "\t4. Print\n";
        cout << "\t5. Exit\n";
        cin >> userInput;
        switch(userInput)
        {    case 1:
            {
                searchArtist(Topsongs);
                break;
            }
            case 2:
            {
                AddSond(Topsongs);  
                break; 
            }
            case 3:
            {
                Delete(Topsongs);  
                break;
            }
            case 4:
            {
                printYear(Topsongs);
                break;
            }
        }
    }
}
//prints title, author, ect

void searchArtist(songList TopSongs)
{
    string userArtist;
   int count=0;
    cout << "1. Look up Artist\n";
    cout << "Enter name of Artist: ";
    cin.ignore(1000, '\n');
    getline(cin, userArtist);
    TopSongs.reset();
    songPtr holder;
    for(int x=0;x<TopSongs.getLength();x++)
        {holder=TopSongs.GetNextItem();
        //only prints if book matches input
            if(holder->artist ==userArtist)
              {  if (count==0)
                    {   cout << "Here are song(s) by "<<userArtist<< endl;
                        cout <<left<<setw(20) <<"\nTitle "<<setw(10)<<"Rank"<<"Year\n";
                        count++;
                    }
                 cout <<setw(20)<< holder->title<<setw(10)<<holder->rank << holder->year<<endl;
              }
        }
        if(count==0)
            cout << "Artist not in list\n";
        
}
        
//adds song to end of list
void AddSond(songList& TopSongs)
{
    songPtr aSong;
    cout <<"2.  Add a song\n";
    cout << "Enter song title to add: ";
        cin.ignore(1000, '\n');
        getline(cin, aSong->title);
        cout << "Enter the artist name: ";
		getline(cin, aSong->artist);
        cout << "Enter the song rank: ";
        cin >> aSong->rank;
        cout << "Enter the year of song release:";
		cin >> aSong->year;
		// addline below to add the book into the list
        TopSongs.Add(aSong);
        return;
    
}
//removes song by searching for title
void Delete(songList& songs)
{
    string userSong;
    cout << "Enter song title to delete: ";
    cin.ignore(1000, '\n');
    getline(cin, userSong);
    songs.Delete(userSong);
    return;
    }
//prints all songs in inputed year
void printYear(songList TopSongs)
{
    int userInput;
    int count=0;
    cout <<right<< setw(7)<< "4. Print\n"; 
    cout << "Year of songs: ";
    cin >> userInput;
    TopSongs.reset();
    songType holder;
    for(int x=0;x<TopSongs.getLength();x++)
        {holder=TopSongs.GetNextItem();
        //only prints if book matches input
            if(holder.year == userInput)
              {  if (count==0)
                    {   cout << "\nHere are songs for "<<userInput<< endl;
                        cout <<left<<setw(40) <<"Artist "<<setw(25)<<"Title"<<"rank\n";
                        count++;
                    }
              
              cout <<left<<setw(40)<< holder.artist<<setw(25)<<holder.title << holder.rank<<endl;
              }
        }
        cout << endl;
        if(count==0)
            cout << "Year not valid, enter year between 2012-2015\n\n";
            return;
}