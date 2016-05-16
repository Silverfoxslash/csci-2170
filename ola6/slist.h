// header file for sorted list class

#ifndef LIST_H
#define LIST_H
#include <string>   
#include <iostream>
#include <cstddef> // for NULL

using namespace std;
struct SongType;            // forward declaration
typedef SongType * SongPtr;

struct SongType
{
  int rank;
  string artist;
  string title;
  int year;
  SongPtr  next;
};

class SortedList
{
public:
  SortedList();
  // Post: List is the empty list.

  SortedList(const SortedList& otherList);
  // Copy-constructor for ItemList.

  void Insert(SongPtr  item);
  // Pre:  item is not already in the list.
  // Post: item is in the list.

  void Delete(string  item);
  // Pre:  item is in the list.
  // Post: item is no longer in the list.

  void Reset();
  // Post: The current position is reset to the first item in the list

  SongPtr GetNextItem();
  // Assumptions: No transformers are called during the iteration.
  //        There is an item to be returned; that is HasNext is true when
  //        this method is involed.
  // Pre: ResetList has been called if this is not the first iteration
  // Post: Returns item at the current position

  int GetLength() const;
  // Post: Length is equal to the number of items in the list.

  bool IsEmpty() const;
  // Post: Returns true if listis empty: false otherwise

  bool IsFull() const;
  // Post:  Returns true if list is full; false otherwise

  bool IsThere(string item) const;
  // Post: Returns true if item is in the list and false otherwise

  bool HasNext() const;
  // Post: Returns true if there is another item to be returned
  //       false otherwise
  bool operator==(const SongPtr&p);
  void operator=(const SongPtr& rhs),

  ~SortedList();   // destructor
  // Post: List has been destroyed.

private:
  SongPtr    head;     // pointer to the first node in the list
  int  	     length;   
  SongPtr    lastPtr;  // pointer to the last node in the list
  SongPtr    currPos;  // pointer to the current position in a traversal
};

#endif