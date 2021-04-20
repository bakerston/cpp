/*
 * PosPoly.cpp
 * etk
 * jan 2021
 */

#include "Pair.h"
#include "PosPoly.h"
#include <iostream>

/*
 * The constructor creates a polynomial with a zero value (no terms).
 */
PosPoly::PosPoly():num_entries{0}{};

/*
 * incrementBy receives a coefficient and power for
 * a term to add to the polynomial.
 * If a term with a matching power is already in the 
 * polynomial, then the coefficient is added to the 
 * existing pair.  Otherwise,a new pair is created.
 * Notice that you must use the "new" operator to 
 * dynamically allocate a Pair object.  Merely
 * creating a local object on the stack and pushing
 * it into the vector is not correct as the variable
 * goes out of scope when incrementBy returns and the
 * associated memory may be re-used upon subsequent
 * method invocations.
 */
void PosPoly::incrementBy(int c, int p){ 
	bool exists = false;

	// if a pair with the matching power exists
   // update the coefficient and note that it exists
	for (int i=0; i<num_entries; i++){
		if (entries[i].getY() == p){
			entries[i].setX(entries[i].getX() + c);
			exists = true;
	   }
	}

	// if no pair with a matching power is found, create a new one
	if (!exists){
		Pair *pp = new Pair(c,p);
		entries.push_back(*pp);
		num_entries++;
	}
};

/*
 * display the polynomial
 */
std::ostream& operator<<(std::ostream& output, const PosPoly& poly){ 
	Pair pp;

	// if the polynomial contains no entries then the value is zero
	if (poly.num_entries == 0)
		output << " 0 ";
	else{
		// display each term 
		for (int i=0; i<poly.num_entries; i++){
			pp = poly.entries[i];
			output << pp.getX() << "x^" << pp.getY();
			// display a + after each term but the last
			if (i < (poly.num_entries - 1)){
				output << " + ";
	   	} 
    	}
	}

	return output;
};

bool PosPoly::operator==(PosPoly &right){ 
	bool match;
	int i, j;

	// check the size
	if (num_entries != right.num_entries){
		return false;
	}
	else{
		// for each pair in this polynomial
		for (i=0; i<num_entries; i++){
			// does it have a matching pair in right?
			match = false;
			for (j=0; j<num_entries; j++){
				if (entries[i].isEqualTo(right.entries[j]) )
					match = true;
			} // end for j
			// if any missing terms, return false
			if (match == false) 
				return false;
		} // end for i
	}

	// if we make it to here, then everything matched and return true
	return true;
};
  
