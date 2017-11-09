#ifndef TST_H
#define TST_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
struct Node;

template <typename T> class TST {

	private:
		struct Node {
			T leftValue;
			T rightValue;
			bool leftBool;
			bool rightBool;
			Node* left;
			Node* center;
			Node* right;

			Node() {
				leftBool = false;
				rightBool = false;
				left = NULL;
				center = NULL;
				right = NULL;
			};
			Node(const T& newValue1, const T& newValue2) {
				if(newValue1 >= newValue2) {
					rightValue = newValue1;
					leftValue = newValue2;
				}
				else {
					leftValue = newValue1;
					rightValue = newValue2;
				}
				leftBool = true;
				rightBool = true;
				left = NULL;
				center = NULL;
				right = NULL;
			}

			Node(const T& newValue) {
				leftValue = newValue;
				leftBool = true;
				rightBool = false;
				left = NULL;
				center = NULL;
				right = NULL;
			}
			~Node(){};
		};

		Node* root;



	public:
		TST();

		~TST();

		bool insert(const T&);
		bool insertAux(Node*&, const T&);

		bool remove(const T&);
		T findSuccessorMax(Node*);
		T findSuccessorMin(Node*);

		bool find(const T&) const;
		bool findAux(Node*&, const T&) const;

		void display() const; //inorder display
		void displayAux(Node*) const;
};

template <typename T>
TST<T>::TST() {
   root = NULL;  
}

template <typename T>
TST<T>::~TST() {

}

template <typename T>
bool TST<T>::insert(const T& value) {
	if(root == NULL) {
		root = new Node(value);
		return true;
	}
	return insertAux(root, value);
}

template <typename T>
bool TST<T>::insertAux(Node*& current, const T& value) {
	if(current == NULL) { // if node null, put value in new node's left value
		current = new Node(value);
		return true;
	}

	if((current->leftBool && (current->leftValue == value)) || ((current->rightBool) && (current->rightValue == value))) { // if duplicate
		return false;
	}

	if((current->leftBool) && (current->rightBool == false)) { // if only left value
		if(value > current->leftValue) {
			current->rightValue = value;
			current->rightBool = true;
		}
		else {
			current->rightValue = current->leftValue;
			current->leftValue = value;
			current->rightBool = true;
		}
		return true;
	}

	if((current->leftBool) && (current->rightBool)) { //if both values full
		if(value < current->leftValue) // if value < left, send to left subtree
			return insertAux(current->left, value);

		if((value > current->leftValue) && (value < current->rightValue))  // if in middle, send to center s.t.
			return insertAux(current->center, value);

		if((value > current->rightValue)) // if > right, send to right subtree
			return insertAux(current->right, value);
	}
}

template <typename T>
bool TST<T>::remove(const T& value) {
	//cout << "removing " << value << "\n";
	Node *parent, *node, *temp;
	T successorValue;
	T parentValue;
	parent = node = root;
	// Iterate until we find the correct node
	while((node != NULL) && ((node->leftValue != value) && ((node->rightBool) && (node->rightValue != value)))) {
		parent = node;

		if(node->rightBool == false) { //only left value, this is a leaf
				if(value != node->leftValue)
					return false;
		}

		else { // both values exist
			if(value < node->leftValue)
				node = node->left;
			else if((value > node->leftValue) && (value < node->rightValue))
				node = node->center;
			else if(value > node->rightValue)
				node= node->right;
		}
	}

	if(node == NULL)
		return false;


// Replacement logic

//===========================CASE 1: LEAF==================
	if((node->left == NULL) && (node->center == NULL) && (node->right == NULL)) { 
		if(node == root) { // if deleting tree with just root sepcial case
			if(value == root->leftValue) {
				if(node->rightBool)	{
					root->leftValue = root->rightValue;
					root->rightBool = false;
				}
				else {
					delete root;
					root = NULL;
				}
			
				return true;
			}

			if((root->rightBool) && (value == root->rightValue)) {
				root->rightBool = false;
				return true;
			}
		}

		// case 1a: leaf has only left value
		if(node->rightBool == false) {
			if(node->leftValue < parent->leftValue) // if leaf is from parent's left
				parent->left = NULL;
			else if((node->leftValue > parent->leftValue) && (node->leftValue < parent->rightValue)) // if leaf is from parent's center
				parent->center = NULL;
			else if(node->leftValue > parent->rightValue) // if leaf is from parent's right
				parent->right = NULL;

			delete node;
			return true;
		}
	
		// case 1b: leaf has both values
		if(node->rightBool == true) {
			if(value == node->leftValue) {
				node->leftValue = node->rightValue;
				node->rightBool = false;
				return true;
			}

			if(value == node->rightValue) {
				/*root->rightValue = NULL;*/
				node->rightBool = false;
				return true;
			}
		}
	}

// ========= CASE 2: NOT LEAF -- LEFT VALUE REMOVED ===========

	if(value == node->leftValue) { // LEFT VALUE REMOVED
		if(node->left) { // if LEFT TREE exists, find largest (rightmost) value of it
			successorValue = findSuccessorMax(node->left);
			remove(successorValue);
			node->leftValue = successorValue; // REPLACES value to be removed here with successor
			return true;
		}

		else if(node->center) { // if left tree DNE, find smallest (leftmost) value of CENTER TREE
			successorValue = findSuccessorMin(node->center);
			remove(successorValue);
			node->leftValue = successorValue; // REPLACES value to be removed here with successor
			return true;
		}
		else { // left and center tree DNE... move right value to leftValue, find smallest of right tree
			node->leftValue = node->rightValue;
			successorValue = findSuccessorMin(node->right);
			remove(successorValue);
			node->rightValue = successorValue;
			return true;
		}
	}

// ======== CASE 3: NOT LEAF -- RIGHT VALUE REMOVED ==========

	if(value == node->rightValue) { // RIGHT VALUE REMOVED
		if(node->right) { // if RIGHT TREE exists, find smallest (leftmost) value of it
			successorValue = findSuccessorMin(node->right);
			remove(successorValue);
			node->rightValue = successorValue;
			return true;
		}
		else if(node->center) { // if right tree DNE, find max (rightmost) value of CENTER TREE
			successorValue = findSuccessorMax(node->center);
			remove(successorValue);
			node->rightValue = successorValue;
			return true;
		}
		else { // right and center tree DNE, move leftV to rightV, find max of left subtree, put in leftV
			node->rightValue = node->leftValue;
			successorValue = findSuccessorMax(node->left);
			remove(successorValue);
			node->leftValue = successorValue;
			return true;
		}
	}		
}



template <typename T>
T TST<T>::findSuccessorMax(Node* node) { // will take in a left subtree head (FIND MAX)
	if(node->rightBool) { // if right value exists
		if(node->right) // if there is a right subtree
			return findSuccessorMax(node->right);
		else
			return node->rightValue;
	}
	else { // right value does not exist, must return left
		return node->leftValue;
	}
}

template <typename T>
T TST<T>::findSuccessorMin(Node* node) { // will take in a center subtree head (FIND MIN)
	if(node->rightBool == false)
		return node->leftValue;
	else {
		if(node->left) // if there is a left subtree
			return findSuccessorMin(node->left);
		else
			return node->leftValue;
	}

}


template <typename T>
bool TST<T>::find(const T& value) const {
	if(root == NULL)
		return false;

	if(root->rightBool == false) {
		if(value == root->leftValue)
			return true;
		else
			return false;
	}

// here we know both values exist

	if((value == root->leftValue) || (value == root->rightValue))
		return true;

	if(value < root->leftValue)
		return findAux(root->left, value);

	if((value > root->leftValue) && (value < root->rightValue))
		return findAux(root->center, value);

	if(value > root->rightValue)
		return findAux(root->right, value);

	//compiler satisfier
	return false;

}

template <typename T>
bool TST<T>::findAux(Node*& current, const T& value) const {
	if(current == NULL)
		return false;

	if(current->rightBool == false) {
		if(value == current->leftValue)
			return true;
		else
			return false;
	}

// here we know both values exist

	if((value == current->leftValue) || (value == current->rightValue))
		return true;

	if(value < current->leftValue)
		return findAux(current->left, value);

	if((value > current->leftValue) && (value < current->rightValue))
		return findAux(current->center, value);

	if(value > current->rightValue)
		return findAux(current->right, value);

	//compiler satisfier
	return false;
}

template <typename T>
void TST<T>::display() const {
	if(root == NULL)
		cout << "No root.\n";

	else {
		if(root->left != NULL)
			displayAux(root->left);

		cout << root->leftValue << " ";

		if(root->center != NULL)
			displayAux(root->center);
		
		if(root->rightBool)
			cout << root->rightValue << " ";
		
		if(root->right != NULL)
			displayAux(root->right);

		cout << "\n";
	}		
}

template <typename T>
void TST<T>::displayAux(Node* node) const {
	if(node == NULL)
		return;
	else {
		if(node->leftBool)
			displayAux(node->left);

		cout << node->leftValue << " ";

		if(node->center != NULL)
			displayAux(node->center);
		
		if(node->rightBool)
			cout << node->rightValue << " ";
		
		if(node->right != NULL)
			displayAux(node->right);
	}
	
}


//#include "TST.cpp"

#endif
