#include <iostream>
#include "simpleIntLinkedList.h"
using namespace std;

int main()
{
	List l;

	l.insertHead(3);
	l.insertHead(3);
	l.insertHead(2);
	l.insertHead(1);



		cout << "The current list is: ";
		l.print();
		//l.reverseOp();
		//cout << "The reversed list is: ";
		//l.insertMid(1);
		l.broadcast(3);
		l.print();
	

	return 0;

}