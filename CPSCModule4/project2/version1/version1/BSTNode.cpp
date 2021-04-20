/*
 * April 2021
 * ETK
 * BinarySearchTree.cpp
 * This version assumes integer data element
 */

#include "BSTNode.h"

// initialize element value, parent, and left and right children
BSTNode::BSTNode (int e, BSTNode *p): element(e), left(nullptr), 
	right(nullptr), parent(p) {};

int BSTNode::getElement() const{
	return element;
};

BSTNode * BSTNode::getLeft() const{
	return left;
};

BSTNode * BSTNode::getRight() const{
	return right;
};

BSTNode * BSTNode::getParent() const{
	return parent;
};

void BSTNode::setElement(int val){
	element = val;
};

void BSTNode::setLeft(BSTNode *l){
	left = l;
};

void BSTNode::setRight(BSTNode *r){
	right = r;
};

void BSTNode::setParent(BSTNode *p){
	parent = p;
};

