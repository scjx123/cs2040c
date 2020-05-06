#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

template <class T>
void Heap<T>::_bubbleUp(int index) {
	T temp;
	int parent = floor((index - 1) / 2);
	//while (index!=parent) [2,3,5,1,,3,4]
	while (_heap[index] > _heap[parent])
	{
		temp = _heap[index];
		_heap[index] = _heap[parent];
		_heap[parent] = temp;
		index = parent;
		parent = floor((index - 1) / 2);
	}
	return;
}

template <class T>
void Heap<T>::_bubbleDown(int index) {
	int leftindex, rightindex, biggerChild;
	T leftP, rightP, temp;
	
	while (index<_n)
	{
		//compute for biggerChild
		leftindex = (2 * index)+1 ; //2x+1
		rightindex = (2 * index) + 2;//2x+2 
		if (leftindex > _n || rightindex > _n)return;
		leftP = _heap[leftindex];
		rightP = _heap[rightindex];

		biggerChild = leftP > rightP ? leftindex : rightindex;
		if (_heap[biggerChild] > _heap[index]) {
			//swap priority
			temp = _heap[index];
			_heap[index] = _heap[biggerChild];
			_heap[biggerChild] = temp;
			index = biggerChild;
		}
		else return;
		
	}
}

template <class T>
void Heap<T>::insert(T item) {
	_heap[_n] = item;
	_bubbleUp(_n);
	_n++;
}

template <class T>
T Heap<T>::extractMax() {
	T max;
	if (empty()) {
		
	}
	else {
		//replace the root with the last element 
		max = _heap[0];
		_heap[0] = _heap[_n - 1];
		_n--;
		//bubble down from the root 
		_bubbleDown((int)0);
		return T(max);
	}
}
template <class T>
void Heap<T>::swap(int i,int j) {
	T temp;
	temp = _heap[i];
	_heap[i] = _heap[j];
	_heap[j] = temp;
}

template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x) { // not a very good implementation, but just use this for now.
	int i;
	for (i = 0; i < _n; i++)
		if (_heap[i] == x)
			return i;

	return -1;
}

template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
	if (empty()) {} //do nothing if heap is empty 
	else if (to > from) {
		//do nothing if increasing key
	}
	else {
		int size = _lookFor(from); //get index of 'from' 
		if (size == -1) {} //index does not exist in the heap
		else {
			_heap[size] = to; //decrease it to 'to'
			_bubbleDown(size);
		}
	}
}


template <class T>
void Heap<T>::increaseKey(T from, T to)
{
	if (empty()) {}//do nothing if heap is empty 
	else if (to < from) {
		//do nothing if decreasing key
	}
	else {
		int size = _lookFor(from); //get index of 'from'
		if (size == -1) {}//index does not exist in the heap
		else {
			_heap[size] = to;//increase it to 'to'
			_bubbleUp(size);
		}
	}
}

template <class T>
void Heap<T>::deleteItem(T x)
{
	int index, size = _n;
	if (empty()) {
		//do nothing is the heap is empty 
	}
	else {
		//find index of x 
		index = _lookFor(x);
		if (index == -1) {} //item does not exist 
		else {
			//swap x with the last element 
			T temp = x;
			_heap[index] = _heap[_n - 1];
			_n--;

			//bubble down from the root 
			int parent = floor((index - 1) / 2);//parent of x
			if (_heap[index] > _heap[parent])
				_bubbleUp(index);
			else _bubbleDown(index);
		}
	}
}

template <class T>
void Heap<T>::printTree() {
	int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2, 1 + (int)log2f(_n)), i;
	int nLevel = (int)log2f(_n) + 1;
	int index = 0, endIndex;
	int tempIndex;

	for (int l = 0; l < nLevel; l++)
	{
		index = 1;
		parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
		endIndex = index * 2 - 1;
		index--;
		tempIndex = index;
		while (index < _n && index < endIndex) {
			for (i = 0; i < space - 1; i++)
				cout << " ";
			if (index == 0)
				cout << "|";
			else if (parity)
				cout << "\\";
			else
				cout << "/";
			parity = !parity;
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}
		cout << endl;
		index = tempIndex;
		while (index < _n && index < endIndex) {
			for (i = 0; i < (space - 1 - ((int)log10(_heap[index]))); i++)
				cout << " ";
			cout << _heap[index];
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}

		cout << endl;
		space /= 2;
	}

}






#endif
