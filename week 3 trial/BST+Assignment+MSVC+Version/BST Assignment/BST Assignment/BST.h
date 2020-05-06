#pragma once
#include <iostream>
using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	TreeNode<T>* _parent; 
	int _height;
public:
	TreeNode(T x) { _parent =_left = _right = NULL; _item = x; _height = 0; };
	friend BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree {
private:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);

	void _preOrderPrint(TreeNode<T>*);
	void inOrderPrint(TreeNode<T>*);
	void postOrderPrint(TreeNode<T>*);
	//int getHeight(TreeNode<T>*);
	//T successor(TreeNode<T>*);
	
	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
	void _destroySubTree(TreeNode<T>*);
public:
	//constructor & destructor 
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();

	//Normal Operation 
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax();
	T searchMin();
	T searchMin(TreeNode<T>*);
	T successor(T);
	TreeNode<T>* search(TreeNode<T>*, int );
	bool exist(T x);
	int getHeight(TreeNode<T>*);
	int balanceFactor(TreeNode<T>*);
	TreeNode<T>* _insert(TreeNode<T>* current, T x);
	void deletenode(int);
	

};

#include "BST.hpp"
