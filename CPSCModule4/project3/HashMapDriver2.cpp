#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "HashMap.h"
using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";
 
string ltrim(const std::string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
string rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
string trim(const std::string& s)
{
    return rtrim(ltrim(s));
}

int main(int argc, char *argv[]){
	HashMap dictionary(128);
	string line;
	string word;
	string term;
	string partOfSpeech;
	string definition;
	int leftParen;
	int rightParen;
	int next;
	int attemptCounter = 0;
	int foundCounter = 0;
	struct timespec begin_wall, end_wall;
	struct timespec begin_cpu, end_cpu;
	
	// check for correct number of command line parameters
	if (argc != 3){
		cerr << "usage: HashMapDriver2 infile_name searchfile_name " << endl;
	}
	
	// open the named infile
	ifstream	infile(argv[1], ios::in);
	ifstream	searchfile(argv[2], ios::in);

	// report errors if file can't be opened
	if (!infile){
		cerr << "input file " << argv[1] << " could not be opened " << endl;
		exit(EXIT_FAILURE);
	}

	// report errors if file can't be opened
	if (!searchfile){
		cerr << "search file " << argv[2] << "could not be opened " << endl;
		exit(EXIT_FAILURE);
	}

	// loop through the input file, reading one line at a time
   while (getline(infile, line)){
		if ((trim(line)).size() > 0){
			// find the delimiters:  term (pos) definition
			leftParen = line.find('(');
			rightParen = line.find(')');

			// parse out the elements of the entry 
			term = line.substr(0,leftParen);
			partOfSpeech = line.substr(leftParen + 1, rightParen - leftParen - 1);
			definition = line.substr(rightParen + 1);

			// create a new entry for the dictionary 
			Entry *e = new Entry(term, partOfSpeech, definition);
			//cout << *e << endl;

			attemptCounter++;
			// add it to the dictionary
			dictionary.insertItem(e);
		}
	}
	// get start time
	clock_gettime(CLOCK_REALTIME, &begin_wall);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin_cpu);

	// read in and find all the search terms 
	Entry e;
   while (getline(searchfile, word)){
		if (dictionary.findItem(word)){
			foundCounter++;
		};
	}

	// get end time
	clock_gettime(CLOCK_REALTIME, &end_wall);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_cpu);

	long wall_seconds = end_wall.tv_sec - begin_wall.tv_sec;
	long wall_nanoseconds = end_wall.tv_nsec - begin_wall.tv_nsec;
	double wall_elapsed = wall_seconds + wall_nanoseconds * 1e-9;
	long cpu_seconds = end_cpu.tv_sec - begin_cpu.tv_sec;
	long cpu_nanoseconds = end_cpu.tv_nsec - begin_cpu.tv_nsec;
	double cpu_elapsed = cpu_seconds + cpu_nanoseconds * 1e-9;
	
	infile.close();
	searchfile.close();
	cout << "Found " << foundCounter << " words in a dictionary of size " << dictionary.size() << endl;
	cout << "Timing: " << endl;
	cout << "\t wall clock elapsed seconds:" << fixed << setprecision(3) << wall_elapsed << endl;
	cout << "\t cpu time elapsed seconds:" << fixed << setprecision(3) << cpu_elapsed << endl;

}



