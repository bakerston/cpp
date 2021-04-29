#ifndef ENTRY_H
#define ENTRY_H
#include <string>
#include <iostream>

/*
 * EK - April 2021
 * class to encapsulate term, part of speech, definition entries 
 * for a dictionary
 */

using namespace std;

class Entry{

// overloaded operators for display using either entry or pointer to entry
friend ostream & operator<<(ostream& out, Entry* e);
friend ostream & operator<<(ostream& out, const Entry& e);

public:

	// constructors
	Entry();
	Entry(const string &term, const string & partOfSpeech, const string & definition);

	// destructor
	// -- no dynamic memory allocation; not needed 

	// accessors 
	string getKey() const;		// assumes term is the key
	string getTerm() const;
	string getPart() const;
	string getDefinition() const;

	// mutators 
	void setTerm(const string &term);
	void setPart(const string &part);
	void setDefinition(const string &definition);

private:
	string term;
	string partOfSpeech;
	string definition;
};


#endif
