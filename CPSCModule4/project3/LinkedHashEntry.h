#ifndef LINKED_HASH_ENTRY 
#define LINKED_HASH_ENTRY
#include <string>
#include "Entry.h"

/*
 * ETK - April 2021
 * LinkedHashEntry class
 * provides a node suitable for the linked list
 * in a hash table with chaining
 * Nodes contain a pointer to an Entry and pointer
 * to the next entry in the list.
 */



using namespace std;

class LinkedHashEntry{

public:
	// constructors 
	LinkedHashEntry(Entry *en);
	LinkedHashEntry(string term, string part, string def);

	// destructor
	~LinkedHashEntry();

	// mutators
	void setEntry(Entry *e);
	void setNext(LinkedHashEntry *next);

	// accessors 	
	string getKey();
	Entry * getEntry();	
	LinkedHashEntry * getNext();
	
private:
	Entry * entry;
	LinkedHashEntry *next;
};

#endif
