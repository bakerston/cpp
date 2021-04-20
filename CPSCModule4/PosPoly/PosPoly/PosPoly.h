/*
 * PosPoly.h
 * ETK
 * 1/21/21
 * The PosPoly class represents a polynomial as a vector
 * of terms, in which each term is represented as a Pair.
 * The << operator is a friend function using operator overloading.
 * The == operator is a member function using operator overloading. 
 * An integer num_entries keeps track of the number of terms.
 * A vector of pairs contains the values of each term.
 * The order of terms is arbitrary, depending on the order in 
 * which they are encountered.  Coefficients are combined for 
 * terms with the same power of x, as seen in the sample output.
 * A polynomial with no terms should display as "0".
 */
#ifndef POSPOLY_H
#define POSPOLY_H
#include <iostream>
#include <vector>
#include "Pair.h"

class PosPoly{

friend std::ostream& operator<<(std::ostream& output, const PosPoly& poly);

public:
    PosPoly();
	 void incrementBy(int c, int p); 
	 bool operator==(PosPoly &right);
	 
  
private:
	int num_entries;
	std::vector < Pair > entries{0};

};

#endif
