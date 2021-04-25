#include <iostream>
#include "BSTNode.h"
#include "BinarySearchTree.h"
using namespace std;

#define cnt 10

// the search tree maintains the number of nodes in the tree (count)
// and a pointer to the root of the tree
// the initial tree points to nullptr and has count=0 
BinarySearchTree::BinarySearchTree():root(nullptr), count(0){};

//==============================================
// GENERAL BINARY SEARCH TREE METHODS
//==============================================
// method search starts at the root looking for the specified item (integer)
// it returns either the node where the item was found, or failing that, 
// the position where a node with that value should be attached
// the method asssumes root!=null
BSTNode *BinarySearchTree::search( int it) const {	
	BSTNode *v=root;
	bool found=false;

	// while we haven't found it ..
	while( !found && it!=v->getElement()) {
		// if less than current node, go left if possible
		if( it<v->getElement() && v->getLeft()!=nullptr )
			v = v->getLeft();
		// else if greater than currend node, go right if possible
		else if( it>v->getElement() && v->getRight() !=nullptr )
			v = v->getRight() ;
		else 
			// we found the matching node
			found = true;
	}
	return v;
}

// creates a new node containing the element and 
// calls the private insertItem(int val, BSTNode *newNode) method;
void BinarySearchTree::insertItem(int it) {
	insertItem( new BSTNode(it,nullptr) );
}

// is invoked by the public insertItem method
// inserts the new node into the tree at the appropriate place
// --> You need to implement this method
bool BinarySearchTree::insertItem(BSTNode *newNode) {
	// get the value from node provided as a parameter
	int val = newNode->getElement();;
	// check if the tree is empty 
   // if so, update count and make this the root
	if (root == nullptr){			
		root = newNode;	
		return true;
	}
	else{
		bool Found = true;
		BSTNode *cur = root;
		while (Found){
			if (val > cur->getElement()){
				if(cur->getRight() != nullptr){
					cur = cur->getRight();
				}
				else{
					cur->setRight(newNode);
					newNode->setParent(cur);
					Found = false;
				}
				count++;
			}
			else if (val < cur->getElement()){
				if(cur->getLeft() != nullptr){
					cur = cur->getLeft();
					count++;
				}
				else{
					cur->setLeft(newNode);
					newNode->setParent(cur);
					Found = false;
				}
				count++;
			}
			else{
				cout << "duplicate" << endl;
				Found = false;
			}
		}
		return true;

	}
	// if the tree is not empty, then search for the location
   // of a node with the desired integer value 
	// create a temp pointer to work through the tree
		// if the value is less than the temp  pointer, 
		// go left, update the parent and increment count
		// else if it is larger than the searched for element	
		// go right, update the parent and increment count
		// else display "duplicate" and return false if it is already in the tree
		// return true if you make to here 
}  


// public, non-recursive method for findItem
// checks/returns false for an emptyTree
//
bool BinarySearchTree::findItem(int it) const {
	// if the tree is empty, return false
	if(count==0)
		return false;
	// search for the value in the tree
	int item = search(it)->getElement();
	// if the value in the returned node is what we're looking for
   // return true -- we found it!
	if( item == it )
		return true;
	// otherwise, return false -- we did not find it
	else 
   // return true -- we found it!
		return false;
} 

//----------------------------------------------
// delete item

bool BinarySearchTree::deleteItem(int it) {      

	// Is the tree empty?  
	// If so, return false
	if( root==nullptr){
		//cout << "root is null, returning false" << endl;
		return false;
	}

	// if the item to be deleted is the root and 
   // it has at most one child
	if( it == root->getElement() && 
		( root->getLeft()==nullptr || root->getRight() == nullptr ) ) {
		// deleting root
		//cout << "deleting the root " << endl;
		BSTNode *toBeDeleted = root;
		// if the left child exists, make the left child the root	
		// else make the right child the root
		if( root->getLeft()!=nullptr )
			root = root->getLeft();
		else
			root = root->getRight() ;
		// update the parent pointer
		root->setParent(nullptr);
		// decrement count
		count--;
		// delete the associated node
   	delete toBeDeleted;
		// return true to indicate success
		return true;
	} 

	// Now we consider cases in which the node to delete is not the root
	BSTNode *curr = root;
	// Here, we use a pointer to traverse the tree iteratively
   // rather than using recursion (which is another option)
	while ( curr!=nullptr && curr->getElement()!=it) {
		// if the element we're looking for is less than curr, go left
		if( it < curr->getElement() ){ 
			curr = curr->getLeft();
		}
		// else, go right
		else {
			curr = curr->getRight() ;
		}
	}
	// if we reach this point and have a null pointer, we did not find it
   // so return false 
	if( curr==nullptr ){
		return false;
	}

	// curr points to the location in the tree i
	// that holds the node to be deleted 
	// case: this node has two children
	if( curr->getLeft()!=nullptr && curr->getRight() !=nullptr ) {
		//get a temp pointer to the current node
		BSTNode *hold = curr;
		//direct curr to the right child
		curr = curr->getRight();
		//find the leftmost child node of the right subtree
		while ( curr->getLeft()!=nullptr ) 
			curr = curr->getLeft();
		//update the deleted node with the content of the next highest node
		hold->setElement(curr->getElement());
	}
	
	// case: the current node did not have two children
	BSTNode *parentOfCurr = curr->getParent();
	// get a temp variable to point to the node to the deleted
	BSTNode *toBeDeleted = curr;
	// if the node has left child, go left, else go right 
	if( curr->getLeft()!=nullptr ) 
		curr = curr->getLeft();
	else
		curr = curr->getRight() ;
	//update the grandparent node to refer to this node as the 
   //the left or right child, as appropriate 
	if( toBeDeleted == parentOfCurr->getLeft() )          
		parentOfCurr->setLeft(curr);
	else
		parentOfCurr->setRight(curr);
	// update curr (if non-null) to point to its parent
	if (curr != nullptr)
		curr->setParent(parentOfCurr);
	// decrement count and delete the node
  	count--;
	delete toBeDeleted;
	return true;   
}                

//=======================================
//  OUTPUT METHODS
//=======================================

// public method to display items in their value order
void BinarySearchTree::dumpItemsInOrder( ) const {
	if( count==0 )
		cout << "Empty" << endl;
	else {
		inOrder(root);   	
		cout << endl; 
	}
}

// recursive private method for inOrder traversal
void BinarySearchTree::inOrder(BSTNode *v) const {
	if( v==nullptr )
		return;
	inOrder(v->getLeft());
	cout << v->getElement() << " ";
	inOrder(v->getRight());
}

//=======================================
// DESTRUCTOR
//=======================================

// public method to delete the nodes that make up the tree
BinarySearchTree::~BinarySearchTree( ) {
        deleteTree(root);
}

// private, recursive  method to delete the tree 
// rooted at the provide node
void BinarySearchTree::deleteTree(BSTNode *curr) {
	if( curr==nullptr ) 
		return;
	deleteTree( curr->getLeft() );
	deleteTree( curr->getRight()  );
	delete curr;
}

// public method for level order (breadth first) display
void BinarySearchTree::printLevelOrder(){
	printLevelOrder(root);
}

// private method to perform a level order
// display of the subtree rooted at the provided node
void BinarySearchTree::printLevelOrder(BSTNode *r){
	int h = height(r);
	int i;
	for (i=1; i<=h; i++)
		printGivenLevel(r, i);
};
	   	
// private method that prints the value of the node at the root
// keeping track of level
// displays value of current node
// and then recursively calls on left and right subtrees, with updated levels
void BinarySearchTree::printGivenLevel(BSTNode *root, int level){
	if (root == nullptr)
		return;
	if (level == 1)
		cout << root->getElement() << " ";
	else if (level >1){
		printGivenLevel(root->getLeft(), level-1);
		printGivenLevel(root->getRight(), level-1);
	}
	//cout << endl;
};

// recursively calculates the height of the BST
// rooted at the current node 
int BinarySearchTree::height(BSTNode* node){
	if (node == nullptr)
		return 0;
	else{
		int lheight = height(node->getLeft());
		int rheight = height(node->getRight());

		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
};

// public method to invoke structural diagram of BST
void BinarySearchTree::display(){
	display(root,1);
};

// private  method to invoke structural diagram of BST
// displays right most portion of tree first
// then root value
// the left substree
// uses level parameter to indent accordingly
// --> you need to implement this method
void BinarySearchTree::display(BSTNode *ptr, int level){
	// for you to implement ....
	if (ptr == nullptr){
		return;
	}
	level += cnt;
	display(ptr->getRight(), level);
	cout << endl;
	for (int i = cnt; i < level; i++){
		cout << " ";
	}
	cout << ptr->getElement()<<"\n";
	display(ptr->getLeft(), level);


};
