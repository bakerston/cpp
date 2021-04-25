#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){

	char c;

	cout << "Quote Remover" << endl;
	if (argc != 3){
		cerr << "usage: Quote_Remover infile outfile" << endl;
		exit(1);
	}	
	
	// open the named infile
	ifstream	infile(argv[1], ios::in);
	ofstream	outfile(argv[2], ios::out);

	// report errors if file can't be opened
	if (!infile){
		cerr << "File could not be opened " << endl;
		exit(EXIT_FAILURE);
	}

	// loop through the input file, reading one line at a time
	while (infile.get(c)){
		if (c != '"') 
			outfile << c;
	}

	infile.close();
	outfile.close();


}
