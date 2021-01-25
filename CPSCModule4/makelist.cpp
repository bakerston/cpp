#include <iostream>
#include <iomanip>
#include <random>

int main(){
using namespace std;

default_random_engine	engine{static_cast<unsigned int>(time(0))};
uniform_int_distribution<unsigned int> randomInt{1,100};


for (int i=0; i<1000; i++){
	cout << setw(10) << randomInt(engine);
}



}

