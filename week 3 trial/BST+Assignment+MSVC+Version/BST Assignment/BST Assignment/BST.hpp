#pragma once
#ifndef BSTHPP
#define BSTHPP
#include "BST.h"

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {

	if (current == NULL) {
		current = new TreeNode<T>(x);
		current->_left = current->_right = NULL;
		current->_height = 0;
	}
	else if (current->_item > x)
	{
		if (current->_left)
			current->_left = _insert(current->_left, x);
		else
		{
			current->_left = new TreeNode<T>(x);
			current->_height = getHeight(current);
		}

	}
	else if (x > current->_item) {
		if (current->_right)
			current->_right = _insert(current->_right, x);
		else
		{
			current->_right = new TreeNode<T>(x);
			current->_height = getHeight(current);

		}
	}
	else
		return current;

	current->_height = getHeight(current);

	int balance = balanceFactor(current);
	/*	if (balance > 1)//current is left heavy
		{
			if (balanceFactor(current->_left) < -1)_leftRotation(current->_left);
			_rightRotation(current);
		}
		else if (balance < -1)//current is right heavy
		{
			if (balanceFactor(current->_right) > 1)_rightRotation(current->_right);
			_leftRotation(current);
		}*/
		
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
	return current;

}
template <class T>
int BinarySearchTree<T>::balanceFactor(TreeNode<T>* x) {
	if (x == NULL)
		return 0;
	return getHeight(x->_left) - getHeight(x->_right);
}
template <class T>
void BinarySearchTree<T>::insert(T x) {

	if (_root == NULL)
		_root = new TreeNode<T>(x);
	else
		_root = _insert(_root, x);
	_size++;

}
int max(int left, int right) {
	if (left > right) {
		return left;
	}
	else return right;
}
template <class T>
int BinarySearchTree<T>::getHeight(TreeNode<T>* current) {
	if (current == NULL) return -1;
	else return max(getHeight(current->_left), getHeight(current->_right)) + 1;
}

template <class T>
bool BinarySearchTree<T>::exist(T x) {
	TreeNode<T>* current = _root;

	while (current) {
		if (x == current->_item)
			return true;
		else if (x > current->_item)
			current = current->_right;
		else current = current->_left;
	}
	return false;
}

template <class T>
T BinarySearchTree<T>::searchMax() {
	TreeNode<T>* current = _root;
	while (current->_right)
		current = current->_right;
	return current->_item;
}

template <class T>
T BinarySearchTree<T>::searchMin() {
	TreeNode<T>* current = _root;
	while (current->_left)
		current = current->_left;
	return current->_item;
}

template <class T>
T BinarySearchTree<T>::searchMin(TreeNode<T>* current) {
	while (current->_left)
		current = current->_left;
	return current->_item;
}

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


	//return T();
}


template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
	TreeNode<T>* w = node->_right; //label the right of node to be w
	w->_parent = node->_parent;
	node->_parent = w;
	node->_right = w->_left;
	if (w->_left != NULL)w->_left->_parent = node;
	w->_left = node;
	node->_height = getHeight(node);
	w->_height = getHeight(w);
	return w;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
	TreeNode<T>* w = node->_left; //label the right of node to be w
	w->_parent = node->_parent;
	node->_parent = w;
	node->_left = w->_right;
	if (w->_right != NULL)w->_right->_parent = node;
	w->_right = node;
	node->_height = getHeight(node);
	w->_height = getHeight(w);
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
	inOrderPrint(_root);
	cout << endl;
}
template <class T>
void BinarySearchTree<T>::inOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	inOrderPrint(node->_left);
	cout << node->_item << " ";
	inOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::postOrderPrint() {
	postOrderPrint(_root);
	cout << endl;
}
template <class T>
void BinarySearchTree<T>::postOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	postOrderPrint(node->_left);
	postOrderPrint(node->_right);
	cout << node->_item << " ";
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
void BinarySearchTree<T>::deletenode(int key) {
	TreeNode<T>* curr = _root;
	//recurse until found the node to be deleted 
	if (curr == NULL) return curr;

	if (key < curr->key)
		curr->_left = deleteNode(curr->_left, key);

	else if (key > curr->key)
		curr->_right = deleteNode(curr->_right, key);

	else
	{
		// node with only one child or no child 
		if (curr->_left == NULL)
		{
			TreeNode<T>* temp = curr->_right;
			delete curr;
			return temp;
		}
		else if (curr->_right == NULL)
		{
			TreeNode<T>* temp = root->left;
			delete curr;
			return temp;
		}
		// node with two children: Get the inorder successor (smallest 
				// in the right subtree) 
		TreeNode<T>* temp = searchMin(root->right);

		// Copy the inorder successor's content to this node 
		root->key = temp->key;

		// Delete the inorder successor 
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}


#endif
