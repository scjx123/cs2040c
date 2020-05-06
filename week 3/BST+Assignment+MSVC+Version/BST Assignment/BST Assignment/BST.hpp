#pragma once
#ifndef BSTHPP
#define BSTHPP
#include "BST.h"

int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
template <class T>
int BinarySearchTree<T>::height(TreeNode<T>* current) {
	if (current == NULL)return -1;
	else return max(height(current->_right), height(current->_left)) + 1;
}
template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {


	if (x < current->_item) {
		if (current->_left)
			current->_left = _insert(current->_left, x);
		else {
			current->_left = new TreeNode<T>(x);
			current->_left->_parent = current;
			current->_height = height(current);
			current->_weight = weight(current);
			_size++;
		}
	}
	else if (x > current->_item) {
		if (current->_right) 
			current->_right = _insert(current->_right, x);
		else {
			current->_right = new TreeNode<T>(x);
			current->_right->_parent = current;
			current->_height = height(current);
			current->_weight = weight(current);
			_size++;
		}
	}
	else {
		return current;
	}

	current->_height = height(current);
	int balance=balanceFactor(current);

	// Left Left Case
	if (balance > 1 && x < current->_left->_item)
		return _rightRotation(current);

	// Right Right Case  
	if (balance < -1 && x > current->_right->_item)
		return _leftRotation(current);

	// Left Right Case  
	if (balance > 1 && x > current->_left->_item)
	{
		current->_left = _leftRotation(current->_left);
		return _rightRotation(current);
	}

	// Right Left Case  
	if (balance < -1 && x < current->_right->_item)
	{
		current->_right = _rightRotation(current->_right);
		return _leftRotation(current);
	}
	return current;;

}
template <class T>
int BinarySearchTree<T>::weight(TreeNode<T>* node) {
	return _weight(node);
}
template <class T>
int BinarySearchTree<T>::select(int x) {
	TreeNode<T>* node = _select(_root,x);
	return node->_item;

}
template <class T>
int BinarySearchTree<T>::rank(T x) {
	TreeNode<T>* root = _root;
	return _rank(root,x);
}
template <class T>
int BinarySearchTree<T>::_rank(TreeNode<T>* node, T x) {

	while (node->_item != x) {
		if (x > node->_item)node = node->_right;
		else node = node->_left;
	}

	int rank = weight(node->_left) + 1;
	while (node->_parent != NULL) {
		if (node->_parent->_left == node) {} //if node is left child 
		else if (node->_parent->_right==node) {//if node is right child 
			rank += weight(node->_parent->_left) + 1;
			node = node->_parent;
		}
	}
	return rank; 
}
template <class T>
int BinarySearchTree<T>::_weight(TreeNode<T>* node) {
	if (node == NULL)return 0;
	else if (node->_right == NULL && node->_left == NULL)return 1;
	else return (_weight(node->_left) + _weight(node->_right))+ 1;
}
template <class T>
TreeNode<T>* BinarySearchTree<T>::_select(TreeNode<T>* root,int x) {
	int rank = _weight(root->_left) + 1;
	if (x == rank)return root;
	else if (x < rank) {
		if (root->_left != NULL)
		return _select(root->_left, x);
	}
	else if (x > rank) {
		if (root->_right != NULL)
		return _select(root->_right, x - rank);
	}
}
template <class T>
TreeNode<T>* rank(T x) {
	
}


template <class T>
int BinarySearchTree<T>::balanceFactor(TreeNode<T>* current) {
	if (current == NULL)return 0;
	return height(current->_left) - height(current->_right);
}
template <class T>
void BinarySearchTree<T>::insert(T x) {

	if (_root == NULL)
		_root = new TreeNode<T>(x);
	else
		_root = _insert(_root, x);

}

template <class T>
bool BinarySearchTree<T>::exist(T x) {
	TreeNode<T>* node = _root;
	while (node) {
		if (x == node->_item)return true;
		if (x > node->_item) node = node->_right;
		else if (x < node->_item) node = node->_left;
	}
	return false;
}

template <class T>
T BinarySearchTree<T>::searchMax() {
	TreeNode<T>* node = _root;
	while (node->_right) {
		node = node->_right;
	}
	return node->_item;
}

template <class T>
T BinarySearchTree<T>::searchMin() {
	TreeNode<T>* node = _root;
	while (node->_left) {
		node = node->_left;
	}
	return node->_item;
}
template <class T>
T BinarySearchTree<T>::searchMin(TreeNode<T>* node) {
	while (node->_left) {
		node = node->_left;
	}
	return node->_item;

template <class T>
T BinarySearchTree<T>::successor(T x)
{
	
	TreeNode<T>* current = _root;
	TreeNode<T>* successor = NULL;

	if (current->_item == x)
	{
		if (current->_right != NULL)                        // we have right subtree
			return searchMin(current->_right);	// this is the successor
	}
	while (current != NULL) {
		if (x < current->_item)
		{
			successor = current;
			current = current->_left;
		}
		else if (x > current->_item)
			current = current->_right;
		else break;
	}
	return successor->_item;
	
	return 0;
}
	

template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
	TreeNode<T>* parent = node->_parent;
	TreeNode<T>* w = node->_right;
	//hand over the parent 
	w->_parent = node->_parent;
	node->_parent = w;
	//handover the child 
	node->_right = w->_left;
	//update right of w 
	w->_left = node;
	
	return w;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
	TreeNode<T>* parent = node->_parent;
	TreeNode<T>* w = node->_left;
	//hand over the parent 
	w->_parent = node->_parent;
	node->_parent = w;
	//handover the child 
	node->_left = w->_right;
	//update right of w. 
	w->_right = node;
	
	return w; 
	
}

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}

template <class T>
void BinarySearchTree<T>::preOrderPrint() {
	_preOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::inOrderPrint() {
	_inOrderPrint(_root);
	cout << endl;
}
template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
	if (!node)return;
	_inOrderPrint(node->_left);
	cout << node->_item << " ";
	_inOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::postOrderPrint() {
	_postOrderPrint(_root);
	cout << endl;
}template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
	if (!node)return;
	_postOrderPrint(node->_left);
	_postOrderPrint(node->_right);
	cout << node->_item << " ";
}

	template <class T>
	void BinarySearchTree<T>::levelOrderPrint() {
		_levelOrderPrint(_root);
		cout << endl;
	}
	template <class T>
	void BinarySearchTree<T>::_levelOrderPrint(TreeNode<T>* node) {
		int h = height(node);
		int i;
		for (i = 0; i <= h+1; i++) {
			printgivenlevel(node, i);
		}
	}
	template <class T>
	void BinarySearchTree<T>::printgivenlevel(TreeNode<T>* node,int i) {
		if (node==NULL)return;
		if (i == 1)cout << node->_item << " ";
		else if (i > 1) {
			printgivenlevel(node->_left,i-1);
			printgivenlevel(node->_right, i-1); 
		}
	}



template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}


#endif
