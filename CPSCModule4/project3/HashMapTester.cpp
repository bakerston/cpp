#include <iostream>
#include "HashMap.h"

int main(){

	HashMap hm(5);
	cout << "Created " << endl;
	
	hm.insertItem("apple", "noun", "red fruit");
	hm.insertItem("banana", "noun", "yellow fruit");
	hm.insertItem("car", "noun", "automobile");
	
	cout << "After first 3 insertions the hash table contains: " << endl;
	hm.display();
	cout << endl;
	
	hm.insertItem("aardvark", "noun", "anteating animal");
	hm.insertItem("avocado", "noun","green vegetable");
	hm.insertItem("bubble", "noun","clear and round");
	cout << "After next 3 insertions the hash table contains: " << endl;
	hm.display();
	cout << endl;

	hm.insertItem("aaahhhh", "noun","a screaming noise");
	hm.insertItem("danger", "noun","as in stranger danger");
	hm.insertItem("run", "verb","faster than walking ");
	hm.insertItem("scream", "verb","a loud and shrill verbalization ");
	cout << "After next 4 more insertions the hash table contains: " << endl;
	hm.display();
	cout << endl;

	Entry *tempEntry = hm.findItem("danger");
	if (tempEntry == nullptr)
			cout << "danger not found" <<endl;
	else
			cout << *tempEntry <<endl;

	tempEntry = hm.findItem("stranger");
	if (tempEntry == nullptr)
			cout << "stranger not found" <<endl;
	else
			cout << *tempEntry <<endl;
	
	hm.deleteItem("banana");
	cout << "done" << endl;
	hm.display();
	
	hm.deleteItem("aaahhhh");
	cout << "After deleting banana and aaahhhh" << endl;
	hm.display();
	cout << endl;

	
	hm.deleteItem("bubble");
	hm.deleteItem("avocado");
	cout << "After deleting bubble and avocado" << endl;
	hm.display();
	cout << endl;
	
	
	
}
