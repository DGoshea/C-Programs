#include "LinkedList.h"
/*Node constructors
    The first takes no parameter and assigns the next pointer to null
    THe second takes in an integer value and sets the data value to that integer and assigns node value to next
    The third takes in a node pointer and and int value and sets the int value and the pointer to the next node
*/
Node::Node():next(nullptr){}
Node::Node(int e):data(e), next(nullptr){}
Node::Node(int e, Node* n):data(e), next(n){}

/* Linked list constructor
    Takes no parameters
    Sets the head value to null
*/
LinkedList::LinkedList():head(nullptr){}

/* Linked list insert method
    Takes in a int value
    If the list is empty it creates the first node with the int value
    If the list is not empty and the int value is already in the list send a message to user
    If the list is not empty and the int value is not in the list it inserts it in order
    Returns true or false
*/
bool LinkedList::Insert(int e){
	bool success = true;
	if (head == nullptr || e < head->data)
		head = new Node(e, head);
	else{
		Node* current = head;
		Node* prev = head;
		while (current != nullptr && e > current->data){
			prev = current;
			current = current->next;
		}
		if (prev == nullptr || e == prev->data){
			cout << "NO DUPLICATES" << endl;
			success = false;
		}
		else
			prev->next = new Node(e, current);
	}

	return success;
}

/* Linked list search method
    Takes in a int value
    Returns a node pointer
    Maybe not fully defined??
*/
Node* LinkedList::Search(int e)
{
    Node* current = head;
    bool found = false;
    while(current != nullptr)
    {
        if(current->data == e)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

/* Overloaded insertion operator
    Takes in the ostream operator by reference and a linked list by reference
    Uses a pointer to cout all the contents in a linked list
    Returns the ostream operator's new function
*/
ostream& operator<<(ostream& os, const LinkedList& l){
	Node* temp = l.head;
	while (temp != nullptr){
		os << temp->data << endl;
		temp = temp->next;
	}
	return os;
}
/* Copy Constructor
    Takes in a linked list by reference
    Copies the original linked list into another linked list
*/
LinkedList::LinkedList(const LinkedList& ll)
{
    head = nullptr;
    if(ll.head)
    {
        Node* current = ll.head;
        head = new Node(current->data);
        Node* currentCopy = head;
        while(current->next)
        {
            current = current->next;
            currentCopy->next = new Node(current->data);
            currentCopy = currentCopy->next;
        }
    }

}

/* Overloaded assignment operator
    Takes in a linked list by reference
    Creates a deep copy of the original linked list
*/
LinkedList& LinkedList::operator=(const LinkedList& ll)
{
    if(this != &ll)
    {
        Node* current = head;
        Node* next;
        while(current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        if(ll.head)
        {
            Node* currentLL = ll.head;
            head = new Node(currentLL->data);
            Node* currentCopyList = head;
            while(currentLL->next != nullptr)
            {
                currentLL = currentLL->next;
                currentCopyList->next = new Node(currentLL->data);
                currentCopyList = currentCopyList->next;
            }
        }
        else
        {
            head = nullptr;
        }
    }
    return *this;

}

/* Destructor for linked list
    No parameters
    Frees all the memory allocated by the linked list
*/
LinkedList::~LinkedList()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << "Deleting Node..." << endl;
        head = head->next;
        delete temp;
        temp = head;
    }
}


