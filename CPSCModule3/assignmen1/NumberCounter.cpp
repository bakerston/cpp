#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "NumberCounter.h"
using namespace std;

NumberCounter::NumberCounter(int a, int b){
	N_min = a;
	N_max = b;
	arr = new int[b - a + 1]{};
}

void NumberCounter::addElement(unsigned int a){
	if(a > N_max || a < N_min){
		cout<< a <<" OUT OF RANGE; ";
	}
	else{
		arr[a - N_min]++;
		}
}

bool NumberCounter::removeElement(unsigned int a){
	return true;
}

void NumberCounter::display(){
	for( int i=0; i<100; i++){
		cout <<'\n'<< N_min + i<< ":";
		for(int j = 0; j<arr[i]; j++){
			cout<<"*";
		}
	}
}

unsigned int NumberCounter::getLuckyNumber(){
	int cnt = 0;
	int I = 0;
	for(int i = 0; i<= 100; i++){
		if (cnt < arr[i]) {
			cnt =  arr[i];
			I = i + 1;
		}	
	}
	cout <<'\n'<<"LUCKY NUMBER IS: "<< I <<endl;
	return I;
}

NumberCounter::~NumberCounter(){
	delete []arr;
}