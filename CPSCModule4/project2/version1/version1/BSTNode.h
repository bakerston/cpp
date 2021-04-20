#ifndef BSTNODE_H
#define BSTNODE_H

/*
 * BinarySearchTree.h
 * ETK - April 2021
 * This version of the BinarySearch Tree has an integer element (stored data)
 * The node keeps track not only of the element, but also the left child
 * right child, and parent.  Keeping a pointer to the parent simplifies
 * the code for insertion/deletion. 
 */

class BSTNode {
public:
	BSTNode (int e, BSTNode *p);
   // no destructor required 

	int getElement() const;
	BSTNode * getLeft() const;
	BSTNode * getRight() const;
	BSTNode * getParent() const;

	void setElement(int val);
	void setLeft(BSTNode * val);
	void setRight(BSTNode * val);
	void setParent(BSTNode * val);

private:
	int element;
	BSTNode *left, *right, *parent;
};
#endif
