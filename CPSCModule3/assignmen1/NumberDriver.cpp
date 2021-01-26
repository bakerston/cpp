#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "NumberCounter.h"
using namespace std;

int main(){
	cout << "Testing the functionality of NumberCounter"<<endl;
	int number;
	NumberCounter CountingNumber(1, 100);
	
	ifstream	inFile("numbers.txt", ios::in);

	if (!inFile){
		cerr << "File could not be opened " << endl;
		exit(EXIT_FAILURE);
	}

	while (inFile >> number){
		// increment the counter for that number 
		CountingNumber.addElement(number);
	}

	// display the histogram 	
	CountingNumber.display();

	// display the lucky number histogram 	
	CountingNumber.getLuckyNumber();
}

