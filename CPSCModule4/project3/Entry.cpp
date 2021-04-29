#include <string>
#include "Entry.h"
/*
 * EK - April 2021
 * class to encapsulate term, part of speech, definition entries 
 * for a dictionary
 */

// constructors 
Entry::Entry(){};

Entry::Entry(const string &term, const string & partOfSpeech, const string & definition):
term(term), partOfSpeech(partOfSpeech), definition(definition) { };


// accessors
string Entry::getKey() const{
	return term;
};

string Entry::getTerm() const{
	return term;
};

string Entry::getPart() const{
	return partOfSpeech;
};

string Entry::getDefinition() const{
	return definition;
};

//mutators
void Entry::setTerm(const string & term){
	this->term = term;
};

void Entry::setPart(const string & part){
	this->partOfSpeech = part;
};

void Entry::setDefinition(const string & definition){
	this->definition = definition;
};

// overloaded display operators

ostream & operator<<(ostream& out, Entry* e){
	out << e->getTerm() << " (" << e->getPart() << ") " << e->getDefinition();
	return out;
};

ostream & operator<<(ostream& out, const Entry& e){
	out << e.getTerm() << " (" << e.getPart() << ") " << e.getDefinition();
	return out;
};

