#include "customer.h"
#include "heap.h"
#include <iostream>
using namespace std;
int comparisonWay = 0; // 0 for arrival time, 1 for processing time


bool Customer::operator>(const Customer& c) {
	return comparisonWay ? processing_time < c.processing_time : arrival_time < c.arrival_time; // a customer is "greater" if his time is shorter
};



void customerQueueTest(int n_cust) {
	int current_time = 0;
	int totalWaitingTime = 0;
	int i;
	int WT = 0; // waiting time for each customer

	Heap<Customer> queue;

	Customer* custList = new Customer[n_cust];
	cout << endl << endl << "Setup" << endl;
	cout << "List of customers and their arrival and processing times" << endl;
	for (i = 0; i < n_cust; i++)
	{
		custList[i].setAT(i);
		custList[i].setPT((n_cust - i) % (n_cust / 2) + 1 + (i % 2) * (n_cust / 2));
		cout << "Customer " << i << " will arrive at time " << custList[i].AT() << " with PT=" << custList[i].PT() << endl;
	}
	cout << endl;


	for (int round = 0; round < 2; round++) {
		// you may need a big modification within this for-loop
		cout << endl << endl;
		cout << "Test Round " << round + 1 << endl;
		cout << (round == 0 ? "First come first serve" : "Customer with the least PT served first") << endl;
		comparisonWay = round; //should be round 
		current_time = 0;
		totalWaitingTime = 0;

		
		if (comparisonWay == 0) {
			for (int i = 0; i < n_cust; i++) {
				queue.insert(custList[i]);
				//cout << "the current heap is: " << queue.peek(i).PT()<< " ";
			}
			/*cout << "the current heap is: ";
			for (int i = 0; i < n_cust; i++) {
				cout << queue.peek(i).AT() << " ";
			}cout << '\n';*/
		}
		else if (comparisonWay == 1) {
			
			queue.insert(custList[0]);
		}


		//cout << "Customer arrives at time " << custList[0].AT() << " with PT=" << custList[0].PT() << endl;
		
		int serverBusy=0; 
		int waitingline=0;
		
		while (!queue.empty()) {
			
			// you should change all of the code here inside
			//Customer c = queue.extractMax();
			if (waitingline == 0&&serverBusy==0&&(current_time<n_cust)){
				cout << "Customer arrives at time " <<custList[current_time].AT() << " with PT=" << custList[current_time].PT() << endl;
				cout << "Customer arrives when no one is waiting" << endl;
			}
			else if (serverBusy!=0 && (current_time < n_cust)) {
				cout << "Customer arrives at time " << custList[current_time].AT() << " with PT=" << custList[current_time].PT() << endl;
			}

			int lowestPT = 0;
			int lowestPTindex = 0;
			int currentPT = 0;

			if (serverBusy == 0) {
				if (comparisonWay==0) {
					/*cout << "the current heap is: ";
					for (int i = 0; i < n_cust; i++) {
						cout << queue.peek(i).AT() << " ";
					}cout << '\n';*/
					Customer c = queue.extractMax();
					WT = current_time - c.AT();
					cout << "Customer is served at time " << current_time << " with AT=" << c.AT() << " and PT=" << c.PT() << " after waiting for "
					<< WT << " min." << endl;
					totalWaitingTime += WT;
					serverBusy = c.PT();
				}
				else if (comparisonWay==1) {
					if (waitingline == 0) {
						//Customer c = custList[current_time];
						Customer c = queue.extractMax();
						WT = current_time - c.AT();
						cout << "Customer is served at time " << current_time << " with AT=" << c.AT() << " and PT=" << c.PT() << " after waiting for "
							<< WT << " min." << endl;
						totalWaitingTime += WT;
						serverBusy = c.PT();
					}
					else if(waitingline!=0){//theres a queue, so u extract min from minheap
						
						Customer c = queue.extractMax();

						WT = current_time - c.AT();
						cout << "Customer is served at time " << current_time << " with AT=" << c.AT() << " and PT=" << c.PT() << " after waiting for "
							<< WT << " min." << endl;
						totalWaitingTime += WT;
						serverBusy = c.PT();
					}
				}	
				serverBusy = serverBusy - 1;
				if (waitingline != 0)waitingline--;
			}
			else {
				serverBusy--; //serverbusy for 4 cycle 
				waitingline++;
				
			}
			current_time++;	
			if (current_time != 0 && comparisonWay == 1 && current_time < n_cust) {
				queue.insert(custList[current_time]);
			}
		}


		cout << "Total Waiting Time: " << totalWaitingTime << endl;
		cout << "Average Waiting Time: " << totalWaitingTime / (float)n_cust << endl;
		
	}



	delete[] custList;
}
