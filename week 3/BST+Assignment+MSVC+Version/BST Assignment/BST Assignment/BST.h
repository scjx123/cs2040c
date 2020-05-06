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
	int _weight;
public:
	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; };

	friend BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree {
private:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);
	int height(TreeNode<T>*);
	void _preOrderPrint(TreeNode<T>*);
	void _postOrderPrint(TreeNode<T>*);
	void _inOrderPrint(TreeNode<T>*);
	void _levelOrderPrint(TreeNode<T>*);
	void printgivenlevel(TreeNode<T>*,int );

	TreeNode<T>* _insert(TreeNode<T>*, T );
	int _weight(TreeNode<T>* );
	TreeNode<T>* _select(TreeNode<T>* ,int);
	int _rank(TreeNode<T>*, T); 

	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
    void _destroySubTree(TreeNode<T>*);
    
public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax() ;
	T searchMin();
	T searchMin(TreeNode<T>*);
	int weight(TreeNode<T>*);
	int select(int );
	int rank(T x);
	bool exist(T x);
	T successor(T);
	void levelOrderPrint();
	int balanceFactor(TreeNode<T>*);
	

};

#include "BST.hpp"
