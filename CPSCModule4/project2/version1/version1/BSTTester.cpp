#include "BSTNode.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main(){

	// make a binary search tree
	BinarySearchTree bst;

	// insert a few items
	cout << "Inserting 5: " << endl;
	bst.insertItem(5);
	cout << "-----------------------" << endl;
	bst.display();
	cout << endl << endl;
	cout << "-----------------------" << endl;
	cout << endl << endl;

	cout << "Inserting 2 and then 13: "<< endl;
	bst.insertItem(2);
	bst.insertItem(13);
	cout << "-----------------------" << endl;
	bst.display();
	cout << endl << endl;
	cout << "-----------------------" << endl;
	cout << endl << endl;

	cout << "Inserting 3, then 1, then 9: " << endl;
	bst.insertItem(3);
	bst.insertItem(1);
	bst.insertItem(9);
	cout << "-----------------------" << endl;
	bst.display();
	cout << endl << endl;
	cout << "-----------------------" << endl;
	cout << endl << endl;

	cout << "Inserting 17, then 7, then 8: " << endl;
	bst.insertItem(17);
	bst.insertItem(7);
	bst.insertItem(8);
	cout << "-----------------------" << endl;
	bst.display();
	cout << endl << endl;
	cout << "-----------------------" << endl;
	cout << endl << endl;

	//test for presence of particular values
	cout << "Checking for 14 .... " << endl;
	if (bst.findItem(14))
		cout << "14 was found" << endl;
	else
		cout << "14 was NOT found" << endl;
	cout << endl;
	cout << endl;

	cout << "Checking for 17  ..." << endl;
	if (bst.findItem(17))
		cout << "17 was found" << endl;
	else
		cout << "17 was NOT found" << endl;
	cout << endl;
	cout << endl;


	//  display
	cout << "displaying items in order:" << endl;
	bst.dumpItemsInOrder();
	cout << endl;
	cout << endl;

	//  delete and display again
	cout << "deleting 7:" << endl;
	bst.deleteItem(7);
	cout << "-----------------------" << endl;
	bst.display();
	cout << endl << endl;
	cout << "-----------------------" << endl;
	cout << endl << endl;

	//  delete and display again
	cout << "deleting 8:" << endl;
	bst.deleteItem(8);
	cout << "Items in order are: " << endl;
	bst.dumpItemsInOrder();
	cout << endl;

	//  delete and display again
	cout << "deleting 5:" << endl;
	bst.deleteItem(5);
	cout << "-----------------------" << endl;
	bst.display();
	cout << endl << endl;
	cout << "-----------------------" << endl;
	cout << endl << endl;

	//  delete and display again
	cout << "deleting 2:" << endl;
	bst.deleteItem(2);
	
	cout << "Items in order are: " << endl;
	bst.dumpItemsInOrder();
	cout << endl;

	cout << "Level order is:" << endl;
	bst.printLevelOrder();
	cout << endl;
	cout << endl;
	
	cout << "Final tree is:" << endl;
	cout << "-----------------------" << endl;
	bst.display();
	cout << endl << endl;
	cout << "-----------------------" << endl;
	cout << endl << endl;
	cout << endl;
	
	
}
