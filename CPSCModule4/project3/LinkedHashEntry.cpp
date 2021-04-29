#include "LinkedHashEntry.h"

/*
 * ETK - April 2021
 * LinkedHashEntry class
 * provides a node suitable for the linked list
 * in a hash table with chaining
 * Nodes contain a pointer to an Entry and pointer
 * to the next entry in the list.
 */


// constructors 
LinkedHashEntry::LinkedHashEntry(Entry *en): entry(en), next(nullptr){};

LinkedHashEntry::LinkedHashEntry(string t, string p, string d):
	entry(new Entry(t, p, d)), next(nullptr){};

// destructor 
LinkedHashEntry::~LinkedHashEntry(){
	delete entry;
};

// mutators
void LinkedHashEntry::setEntry(Entry *e){
	this->entry = e;
};

void LinkedHashEntry::setNext(LinkedHashEntry *n){
	this->next = n;
};

// accessors
string LinkedHashEntry::getKey(){
	if (entry != nullptr)
		return entry->getTerm();
	else
		return nullptr;
};

Entry * LinkedHashEntry::getEntry(){
	return entry;
};	

LinkedHashEntry * LinkedHashEntry::getNext(){
	return next;
};

