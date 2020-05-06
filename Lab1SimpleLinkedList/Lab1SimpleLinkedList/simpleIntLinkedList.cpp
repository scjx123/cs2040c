#include <iostream>
#include "simpleIntLinkedList.h"
using namespace std;

ListNode::ListNode(int n)
{
	_item = n;
	_next = NULL;
}

void List::insertHead(int n)
{
	ListNode *aNewNode = new ListNode(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};
void List::insertMid(int n)
{
	//search for n 
	ListNode* curr = _head;
	while (curr->_item != n) {
		curr = curr->_next;
		break;
	}
	//add in the node 
	ListNode* aNewNode = new ListNode(n);
	aNewNode->_next = curr->_next;
	curr->_next=aNewNode;
	_size++;
	return;
};

void List::removeHead()
{
	if (_size > 0) {
		ListNode *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

void List::print() {
	ListNode* ptr = _head;
	while(ptr) {
		cout << ptr->_item;//printing the item 
		cout << " ";
		ptr = ptr->_next;//move to the next node 
	}
	cout << endl; // modify this
}

bool List::exist(int n) {
	ListNode* ptr = _head;
	while (ptr) {
		if ((ptr->_item) == n)return 1;
		ptr = ptr->_next;
	}
	
	return 0;// modify this
}

/*int List::headItem()
{
	return 0; // modify this
}*/

List::~List()
{
	while (_size != 0)
		removeHead();
};


void List::reverseOp() {
	ListNode* current = _head;
	ListNode* next = NULL;
	ListNode* prev = NULL;

	while (current != NULL) {
		next = current->_next;//pointing to node 2 
		current->_next = prev;//pointing to before node 1

		prev = current; 
		current = next;
	}
	_head = prev;
	
};


void List::broadcast(int n) {
	ListNode* curr = _head; 
	int key;
	while (curr) {
		key = curr->_next->_item;
		for (int i = 0; i < n; i++) {
			ListNode* newnode = new ListNode(curr->_item);
			newnode->_next = curr->_next;
			curr->_next = newnode;
			_size++;
		}
		while (curr->_item != key) {
			curr = curr->_next;
		}
	}
}

//reversing an array
/*mid_index = sizeof(array) / 2;
start = mid_index;
if (size of array % 2 = 0)//even
while(end!=n-1){
	start = mid_index--;
	end = mid_index++;
	swap(start, end);
}
else {//odd
	end = mid_index++;
	swap(start, end);
	--start;
}*/

