#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BSTNode.h"

class BinarySearchTree { 

public:
	// create an empty BST
	BinarySearchTree( );  

	// delete all the nodes in the BST
	~BinarySearchTree( );  

	// insert a new item into the tree
	// make use of the private insertItem method below
	void insertItem(int it); 

	
	bool deleteItem(int it);

	bool findItem(int it) const;

	void dumpItemsInOrder( ) const; 

	void printLevelOrder();

	void display();
	   	
  private:         
    BSTNode *root;
    int count;

    /* the methods below are "helpers" that are called by the public methods*/
    bool insertItem(BSTNode *newNode);
    BSTNode *search( int it ) const; 
    void inOrder(BSTNode *v) const;
    void deleteTree(BSTNode *curr);
    int height(BSTNode* node);
	 BSTNode *newNode(int data);
	 void printLevelOrder(BSTNode *root);
	 void printGivenLevel(BSTNode *root, int level);
	 void display(BSTNode *ptr, int level);
}; 
#endif
