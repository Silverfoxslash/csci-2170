#include "slist.h"



// default constructor
SortedList::SortedList() 
// Post: head == NULL
{
  head = NULL;
  currPos = NULL;
  length = 0;
  lastPtr = NULL;
}

// *******************************************************
SortedList::SortedList(const SortedList& otherList) 
// Copy constructor
// Post: A deep copy of otherList is created and the external pointer now
//       points to this list
{
  SongPtr fromPtr;   // Pointer into list being copied from
  SongPtr toPtr;     // Pointer into new list being built

  if (otherList.head == NULL)  {
   	head = NULL;
	return;
  }

  // Copy the first node
  fromPtr = otherList.head;
  head = new SongType;
  head = fromPtr;

  // Copy the remaining nodes
  toPtr = head;
  fromPtr = fromPtr->next;
  while (fromPtr != NULL)  {
  // copy nodes from original to duplicate
  	toPtr->next = new SongType; // Store new node in "next" of
				    //   last node added to new list
	toPtr = toPtr->next;  // toPtr points to new node
	toPtr->rank = fromPtr->rank; // copy component to new node
    toPtr->title = fromPtr->title; // copy component to new node
    toPtr->year = fromPtr->year; // copy component to new node
    toPtr->artist = fromPtr->artist; // copy component to new node
	fromPtr = fromPtr->next;  // fromPtr points to next node of the 
	 			// original list
  }

  toPtr->next = NULL;
  lastPtr = toPtr;  // set last pointer
}


// *******************************************************
void SortedList::Insert(SongPtr item)
// Post: New node containing item is in its proper place and
//       and data members of list nodes are in ascending order
{
  SongPtr currPtr;   // Moving pointer
  SongPtr prevPtr;   // Trailing pointer
  SongPtr newNodePtr;  // Pointer to new ndoe

  newNodePtr = new SongType;  // new node is created and value stored 
  newNodePtr = item;
  newNodePtr->next = NULL;

  if (head == NULL)   {  // empty list case
	head = newNodePtr;
	lastPtr = newNodePtr;
  }
  else {
    	// Find previous insertion point
	currPtr = head;
	prevPtr = NULL;
	while (currPtr != NULL && currPtr->title < item) 
    {
	    prevPtr = currPtr;
	    currPtr = currPtr->next;
	}

	// Insert new node
	if (prevPtr == NULL)   // insert at front of the list?
	    head = newNodePtr;
	else		// NOT inserting at the front of the list
	    prevPtr->next = newNodePtr;
	newNodePtr->next = currPtr;  // do this in both case


	// update lastPtr
	if (currPtr == NULL)
	  lastPtr = newNodePtr; // the new node is the last node of the list
  }
  length++;
}

// *******************************************************
void SortedList::Delete(string item)
{
  SongPtr prevPtr = NULL;   // trailing pointer
  SongPtr currPtr = head;   // loop control pointer
  while (currPtr != NULL && currPtr ->title != item) {
     	prevPtr = currPtr;
	currPtr = currPtr->next;
  }
  if (currPtr != NULL)  {
  	if (currPtr == head)    // item is in the first node
	 	head = currPtr->next;
	else    // item in the middle or end of the list
		prevPtr = currPtr->next;
	
	if (currPtr == lastPtr)  // item is in the last node
		lastPtr = prevPtr; // update pointer to the last node

	delete currPtr;
	length --;
  }
  // if currPtr is equal to NULL, item is not in the list
}

// *******************************************************
void SortedList::Reset()
{
  currPos = head;
}

// *******************************************************
SongPtr SortedList::GetNextItem() 
{
  SongPtr item;
  item=currPos;
  currPos = currPos->next;  // advance the current position pointer
  return item; 
}


// *******************************************************
int SortedList::GetLength() const
{
  return length;
}

// *******************************************************
bool SortedList::IsEmpty() const
{
  return (head==NULL);
}

// *******************************************************
bool SortedList::HasNext() const
{
  return (currPos != NULL); 
}

// *******************************************************
bool SortedList::IsFull() const
{
  return false;
}

// *******************************************************
bool SortedList::IsThere(string item) const
{
  SongPtr currPtr = head;

  while (currPtr != NULL && currPtr->title != item)  {
  	currPtr = currPtr->next;
  }

  if (currPtr != NULL)
  	return true;
  else
  	return false;
}

// *******************************************************
SortedList::~SortedList()  
// Destructor
// Post: All linked list nodes have been deallocated
{
  SongPtr tempPtr;
  SongPtr currPtr = head;

  while (currPtr != NULL) {
  	tempPtr = currPtr;
	currPtr = currPtr->next;
	delete tempPtr;
  }
}
bool SortedList::operator==(const SongPtr&p)
{
   bool IsSameSong = ((rank == p->rank) &&
                   (artist== p->artist) &&
                   (title == p->title) &&
                   (year == p->year));
   return IsSamesong;
}
void SortedList& operator=(const SongPtr& rhs)
{
    rank=rhs->rank
    p->title=rhs->title
    p->artist=rhs->artist
    p->year=rhs->year
}