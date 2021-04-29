#ifndef HASH_MAP
#define HASH_MAP
#include <iostream>
#include "LinkedHashEntry.h"

/*
 * ETK - April 2021
 * HashMap class
 * implements hashing with chaining
 * where the nodes in the tables are 
 * LinkedHashEntry nodes, which 
 * contain a pointer to an Entry and a pointer
 * to the next entry in the list.
 */

//constants used in generating a hash code
const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;

class HashMap{

public:
	// constructor specifies size of table
	HashMap(int sz);
	~HashMap();

	// standard dictionary operations 	
	Entry* findItem(string key);
	bool insertItem(Entry *e);
	bool insertItem(string term, string part, string def);
	void deleteItem(string key);
	int size();

	// display method for use in debugging
	void display();

private:
	// utility function
	int myHashCode(const string & str);
		
	// data members
	// a table of pointers to lists of LinkedHashEntry elements
	LinkedHashEntry **table;	
	int table_size;			// size of table; specified in constructor
	int counter;			   // number of current entries
};

#endif

