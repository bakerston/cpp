# include<iostream>
# include<iomanip>
#include <cstdlib>
#include <fstream>

#ifndef NUMBERCOUNTER_H
#define NUMBERCOUNTER_H

class NumberCounter {
public:
	NumberCounter(int, int);//Constructor
	~NumberCounter(); //Destructor
	void addElement(unsigned int);
	bool removeElement(unsigned int);
	void display();
	unsigned int getLuckyNumber();
private:
	int *numberArray;
	unsigned int N_max;
	unsigned int N_min;
};

#endif