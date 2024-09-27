#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>
using namespace std;

class LinkedList;
class Node{
	int data; //node contains int and pointer to next node
	Node* next;
	Node(); //parameterless node constructor
	Node(int e); //parametric constructor that takes a number
	Node(int e, Node* n); // parametric constructor that takes a number and node pointer
	friend class LinkedList; //not sure what a friend class means
	friend ostream& operator<<(ostream& os, const LinkedList& l); //overload insertion operator so we can easily print a linked list
};

class LinkedList{
	Node* head; //private attribute pointer to the first node in the list
public:
	LinkedList(); //linked list contructor
	bool Insert(int e); //boolean method
	Node* Search(int e); //method to look for a number in the list
	friend ostream& operator<<(ostream& os, const LinkedList& l); //overload the insertion operator so we can print a list
	//Added Methods
	LinkedList(const LinkedList& ll); //Copy constructor method
    LinkedList& operator =(const LinkedList&); //Overloaded assignment operator
	~LinkedList(); //Destructor
};



#endif