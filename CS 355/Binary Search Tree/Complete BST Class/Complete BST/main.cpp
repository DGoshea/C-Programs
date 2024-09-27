/* Divine Goshea, Dr. Jenkins,
   Binary Search Tree(Complete BNode class and BST class to implement the BST data structure
   1/23/2024
*/
#include <iostream>
#include <string>
#include <sstream>
#include "BST.h"
using namespace std;

void menu();

int main(){
    char operation;
    int value;
    BST<int> bt1;
    menu();
    cout << "Please select a choice: ";
    cin >> operation;

    while(operation != 'q')
    {
        if(operation == '+')
        {
            if(cin >> value)
            {
                bt1.Insert(value);
            }
        }
        else if(operation == '-')
        {
            if(cin >> value)
            {
                bt1.Remove(value);
            }
        }
        else if(operation == '?')
        {
            if(cin >> value)
            {
                bt1.Search(value);
            }
        }
        else if(operation == 'p')
        {
            bt1.printInOrder();
        }
        else if(operation == '@')
        {
            bt1.atCursor();
        }
        else if(operation == 'b')
        {
            bt1.goToBeginning();
        }
        else if(operation == 'e')
        {
            bt1.goToEnd();
        }
        else if(operation == '>')
        {
            bt1.goToNext();
        }
        else if(operation == '<')
        {
            bt1.goToPrev();
        }
        else if(operation == '1')
        {
            BST<int> t1;
        }
        else if(operation == '2')
        {
            //could not figure out
        }
        else if(operation == '3')
        {
            BST<string> toDelete;
        }
        else if(operation == '4')
        {
            BST<int> ogTree;
            ogTree.Insert(10); //NOT WORKING PROPERLY
            ogTree.Insert(20);
            ogTree.Insert(30);
            ogTree.Insert(40);
            ogTree.printInOrder();
            cout << "Copying your tree..." << endl;
            BST<int> copyTree;
            copyTree = ogTree;
            copyTree.printInOrder();
        }
        else if(operation == '5')
        {
            bt1.clearList();
        }
        else if(operation == '6')
        {
            bt1.emptyList();
        }
        else if(operation == '7')
        {
            bt1.printInOrder(); cout << endl;
            bt1.printPreorder(); cout << endl;
            bt1.printPostorder(); cout << endl;
        }
        else if(operation == 'm')
        {
            menu();
        }
        else
        {
            cout << "INVALID INPUT " << endl;
        }
        cin >> operation;
    }

    return 0;
}


void menu()
{
    cout << "Choose an option below: " << endl;
    cout << "+ and a value to insert an item into the BST." << endl;
    cout << "- and a value to remove an item from the BST." << endl;
    cout << "? and a value to search for an item in the BST." << endl;
    cout << "p to print out the BST using an Inorder traversal." << endl;
    cout << "@ to return the address of the cursor." << endl;
    cout << "b sets the cursor to the min val of the list" << endl;
    cout << "e sets the cursor to the max val of the list" << endl;
    cout << "> sets the cursor to the next item in the list" << endl;
    cout << "< sets the cursor to the prev val in the list" << endl;
    cout << "1 to test the BST constructor." << endl;
    cout << "2 to test the BST copy constructor." << endl;
    cout << "3 to test the BST destructor." << endl;
    cout << "4 to test the assignment operator." << endl;
    cout << "5 to clear the BST." << endl;
    cout << "6 to check if the BST is empty." << endl;
    cout << "7 to print all traversals of the BST." << endl;
    cout << "q to quit." << endl;
}
