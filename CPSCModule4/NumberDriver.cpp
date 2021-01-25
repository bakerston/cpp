#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstdlib>
#include "NumberCounter.h"
using namespace std;

int main(){

	cout << "Testing the functionality of NumberCounter" << endl;
	
	ifstream	inFile("numbers.txt", ios::in);

	if (!inFile){
		cerr << "File could not be opened " << endl;
		exit(EXIT_FAILURE);
	}

	while (inFile >> number){
		// increment the counter for that number 
	}

	// display the histogram 	

	// display the lucky number histogram 	
}

