#include "HashMap.h"
using namespace std;


/*
 * ETK - April 2021
 * HashMap class
 * implements hashing with chaining
 * where the nodes in the tables are 
 * LinkedHashEntry nodes, which 
 * contain a pointer to an Entry and a pointer
 * to the next entry in the list.
 */

// constructor initialize table size and counter
// then creates table of nullptr entries
HashMap::HashMap(int sz):table_size(sz),counter(0){
	table = new LinkedHashEntry*[table_size];
	for (int i=0; i < table_size; i++){
		table[i] = nullptr;
	}
}

// destructor iterates through the table
// and traverses each list, deleting the nodes in the list 
HashMap::~HashMap(){
	for (int i=0; i<table_size; i++){
		if (table[i] != nullptr){
			LinkedHashEntry *trailingCursor = nullptr;
			LinkedHashEntry *leadingCursor = table[i];
			while (leadingCursor != nullptr){
				trailingCursor = leadingCursor;
				leadingCursor = leadingCursor->getNext();
				delete trailingCursor;
			}
		}
	}
	delete[] table;
}

// returns number of entries in the hash table
int HashMap::size(){
	return counter;
}

// a reasonabe hash code function
int HashMap::myHashCode(const string &str)
{
	unsigned hash = HASH_SEED;
	int nchars = str.length();
	for (int i=0; i < nchars; i++)
	{
		hash = HASH_MULTIPLIER * hash + str[i];
	}
	return (hash & HASH_MASK);
}

// for your debugging pleasure
void HashMap::display()
{

	for (int i=0; i< table_size; i++)
	{
		cout << i << ": ";
		if (table[i] == nullptr)
		{
			cout << endl;
		}
		else 
		{
			LinkedHashEntry *entry = table[i];
			while (entry != nullptr)
			{
				cout << entry->getKey() << " -> ";
				entry = entry->getNext();
			}
			cout << " nullptr" << endl;
		}
	}
}

// creates a new Entry and then invokes the other insertItem method
bool HashMap::insertItem(string key, string part, string def)
{
	Entry *e = new Entry(key, part, def);
	return this->insertItem(e);
}

// inserts the entry into the HashMap
bool HashMap::insertItem(Entry *ent)
{
	// get the key from the entry
	string key = ent->getKey();

	// generate a hash code, recalling that it is two_step process
	// first turn the key into an integer
	// then place it in the range 0 ... table_size -1 (use mod operator)
	int val = myHashCode(key);
	val = val % table_size;
	if (findItem(key) != nullptr)
	{
		return false;
	}
	// if that bucket is empty, just make it the first entry in the list
	if (table[val] == nullptr)
	{ 
		LinkedHashEntry *tmp = new LinkedHashEntry(ent);
		table[val] = tmp;
	}

	// otherwise, iterate through that bucket's list
	// checking to see if the key already exists in the list
	else
	{
		LinkedHashEntry *cur = table[val];
		while (cur->getNext() != nullptr)
		{
			cur = cur->getNext();
		}
		LinkedHashEntry *tmp = new LinkedHashEntry(ent);
		cur->setNext(tmp);
	}
	counter++;
	return true;


	// if so, return false	
	// otherwise, add a new LinkedHashEntry containing that Entry
	// at the end of the list
	// don't forget to increment counter and return true
}


// returns a pointer to the Entry if it is in the HashMap
// otherwise return nullptr
Entry* HashMap::findItem(string key)
{
	// generate the hash 
	int val = myHashCode(key);
	val = val % table_size;

	// if that bucket is empty, return nullptr
	if (table[val] == nullptr)
	{
		return nullptr;
	}

	// otherwise, iterate through the list for that bucket
	// and return the entry if you find it, or nullptr 
   // if you don't
   else
   {
	   LinkedHashEntry *cur = table[val];
	   while (cur != nullptr)
	   {
		   if (cur->getKey() == key)
		   {
			   return cur->getEntry();
		   }
		   cur = cur->getNext();
	   }
	   return nullptr;
   }
}


//deletes the LinkedHashEntry containing the provided key
//if key not found, no action taken
void HashMap::deleteItem(string key)
{
	// generate the hash
	int val = myHashCode(key);
	val = val % table_size;

	if (findItem(key) == nullptr)
	{
		return;
	}
	// if the bucket for that hash is not empty
	// traverse the list until you find the entry with the desired key
    // and then splice it out and delete it
	// Consider the same cases as when you implemented the linked list
	// Suggest using leading and trailing cursors ...
	Entry *d = new Entry("a", "a", "a");
	LinkedHashEntry *dummy = new LinkedHashEntry(d);

	LinkedHashEntry *pre = dummy;
	LinkedHashEntry *cur = table[val];


	dummy->setNext(cur);

	while (cur != nullptr)
	{
		if (cur->getKey() == key)
		{
			pre->setNext(cur->getNext());
		}
		else
		{
			pre = cur;
		}
		cur = cur->getNext();		
	}
	table[val] = dummy->getNext();
	return;
}


