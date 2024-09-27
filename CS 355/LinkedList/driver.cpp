#include <iostream>
using namespace std;
#include "LinkedList.h"


int main() {
	LinkedList list1; //creates and instance of the linked list class
	int x;
	while (x!=-1){ //loop to insert and item into the list and print the list
		cout << "Enter Insertion item: ";
		cin >> x;
		list1.Insert(x);
		cout << list1 << endl;
	}
	Node* found = list1.Search(1);
	if(found)
    {
        cout << "Node with value 1 found" << endl;
    }
    else
    {
        cout << "Node with value 1 not found" << endl;
    }
	LinkedList list2;
	cout << list2 << endl;
	LinkedList list3;
	list3 = list1;
	cout << list3 << endl;
	list2.Insert(99);
	list3 = list2;
	cout << list3 << endl;
	LinkedList list4 = list4;
	cout << list4 << endl;
	LinkedList list5;
	LinkedList list6 = list5;
	cout << list6 << endl;
	LinkedList list7 = list7;
	return 0;
}