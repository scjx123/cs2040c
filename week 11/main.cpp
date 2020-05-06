#include "heap.h"
#include "customer.h"


void heapTest();
//void hiddenHeapTest();
//void customerQueueTest();

int main() {
    heapTest();
    //customerQueueTest(10);


}


void heapTest(){
    
    Heap<int> ih;
	cout << "Integer Heap Test" << endl;
    ih.insert(9);
    ih.insert(10);
    ih.insert(22);
    ih.insert(7);
    ih.insert(2);
    ih.insert(12);
    ih.insert(8);
 
    ih.printTree();
    cout << endl << endl;

    /*for (int i=1; i < 16; i++)
    {
        ih.insert(i);
		cout << "Insert " << i << " into the heap." << endl;
		cout << "Heap Array:";
		ih.printHeapArray();
		cout << endl;
        ih.printTree();
        cout << endl << endl;
    }
    

    cout << "Increasing 13 to 99" << endl;
    ih.increaseKey(13,99);
	cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;
    
    cout << "Deleting the item 2" << endl;
    ih.deleteItem(2);
    cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;
    
    cout << "Deleting the item 10" << endl;
    ih.deleteItem(10);
	cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;
    
    cout << "Decreasing the key 15 to 13)"  << endl;
    ih.decreaseKey(15,13);
	cout << "Heap Array:";
	ih.printHeapArray();
	cout << endl;
	ih.printTree();
	cout << endl << endl;



    for (int i = 1; i < 12; i++)
    {
        cout << "Extract Max: Max = ";
        cout << ih.extractMax() << endl;
        ih.printTree();
        cout << endl << endl;
    }*/
    
}
