/* Binary Search tree classs and BNode class implementations
*/
#include <iostream>
#include "BST.h"
using namespace std;

/*Bnode constructors
    The first takes no parameters and sets the left and right children to null
    The second takes a data parameter and sets the left and right children to null
    The last take a data parameters and two BNode pointers and sets them accordingly
*/
template <typename T>
BNode<T>::BNode():left(nullptr), right(nullptr){}
template <typename T>
BNode<T>::BNode(T e):data(e), left(nullptr), right(nullptr){}
template <typename T>
BNode<T>::BNode(T e, BNode<T>* l, BNode<T>* r):data(e), left(l), right(r){}

/* BST constructor
    Takes in no parameters and sets the BNode pointer to null
    Return type none
*/
template <typename T>
BST<T>::BST():root(nullptr), cursor(nullptr){}

template <typename T>
BST<T>::BST(const BST<T>& B):root(nullptr), cursor(nullptr)
{
    root = copyTree(B.root);
    cursor = new BNode<T>(B.cursor);
}

/* Insert method to insert nodes into our BSt
    Takes in one data parameter
    Return type true if the data was created and false if it was a copy
*/
template <typename T>
bool BST<T>::Insert(T e)
{
    return insertHelper(e, root);
}

/* Insert Helper Method to define the implementation for insert method
    Takes in data parameter and a BNode pointer
    Return type true if we did insert and item and false if we did not
*/
template <typename T>
bool BST<T>::insertHelper(T e, BNode<T>*& subroot)
{
    bool success = true;
    if(subroot == nullptr)
    {
        subroot = new BNode<T>(e);
        cursor = subroot;
    }
    else if(e == subroot->data)
    {
        cout << "NO DUPLICATES ALLOWED" << endl;
        success = false;
    }
    else if(e < subroot->data)
    {
        success = insertHelper(e, subroot->left);
        cursor = subroot;
    }
    else //(e > subroot->data)
    {
        success = insertHelper(e, subroot->right);
        cursor = subroot;
    }
    return success;
}

/* Print In order method to print out the data of our nodes in order
    Takes in no parameters
    Return type void
*/
template <typename T>
void BST<T>::printInOrder()const
{
    cout << "< ";
    printInOrderHelper(root);
    cout << "> ";
}

/* Print in order helper method to define the implementation to the print in order method
    Takes in the root of the BST
    Return type void just prints the entire BST
*/
template <typename T>
void BST<T>::printInOrderHelper(BNode<T>* subroot)const
{
    if(subroot != nullptr)
    {
        printInOrderHelper(subroot->left);
        if(cursor->data == subroot->data)
        {
            cout << "[" << subroot->data << "]" << " ";
        }
        else
        {
            cout << subroot->data << " ";
        }
        printInOrderHelper(subroot->right);
    }
}

/* Print preorder method is used to print the tree in preorder traversal (root, left, right)
    Takes in the root of the BST
    Return type void just prints the entire BST in preorder traversal
*/
template <typename T>
void BST<T>::printPreorder()const
{
    printPreorderHelper(root);
}

/* Print preorder helper method is used to print the tree in preorder traversal (root, left, right)
    Takes in the root of the BST
    Return type void just prints the entire BST in preorder traversal
*/
template <typename T>
void BST<T>::printPreorderHelper(BNode<T>* subroot)const
{
    if(subroot != nullptr)
    {
        if(cursor->data == subroot->data)
        {
            cout << "[" << subroot->data << "]" << " ";
        }
        else
        {
            cout << subroot->data << " "; //print the current node
        }
        printPreorderHelper(subroot->left); // traverse the left subtree recursively
        printPreorderHelper(subroot->right); // traverse the right tree recursively
    }
}

/* Print Postorder method is used to print the BST in Postorder traversal (left, right, root)
    Takes in the root of the BST
    Return type void just prints the entire BST in postorder traversal
*/
template <typename T>
void BST<T>::printPostorder()const
{
    printPostorderHelper(root);
}

/* Print Postorder helper method is used to print the BST in Postorder traversal (left, right, root)
    Takes in the root of the BST
    Return type void just prints the entire BST in postorder traversal
*/
template <typename T>
void BST<T>::printPostorderHelper(BNode<T>* subroot)const
{
    if(subroot != nullptr)
    {
        printPostorderHelper(subroot->left);
        printPostorderHelper(subroot->right);
        if(cursor->data == subroot->data)
        {
            cout << "[" << subroot->data << "]" << " ";
        }
        else
        {
            cout << subroot->data << " "; //print the current node
        }
    }
}

/* Search method uses the data value passed by the user to search from the cursor to the end of the list
    if the data member is found it is set as the new cursor if no the cursor is set to the max val
    Incoming Data: data val from user
    Outgoing data: BNode*;
*/
template <typename T>
BNode<T>* BST<T>::Search(T e)const {
	return Search(e, cursor);
}

template <typename T>
BNode<T>* BST<T>::Search(T e, BNode<T>* subroot)const{
    if (subroot == nullptr)
    {// know it's not there..
        goToEnd(root);
       return subroot;
    }
    else if(e == subroot->data)
    {
       return subroot;
    }
    else if(e > subroot->data)
    {
        return Search(e, subroot->right);
        cursor = subroot;
    }
    else if(e < subroot->data)
    {
        return nullptr;
        goToEnd(root);
    }

}

/* Remove method takes in a data value and looks for the node to delete it also sets
    the cursor to
    Incoming Data: data value and the tree's root
    Outgoing data: returns true or false if the node was removed
*/
template <typename T>
bool BST<T>::Remove(T e)
{
    return Remove(e, root);
}

template <typename T>
bool BST<T>::Remove(T e, BNode<T>*& subroot)
{
//First case: Empty Tree or Item Not In BST
    if(subroot == nullptr)
    {
        return false;
    }
//Found the item to remove
    else if(e == subroot->data)
    {
        //NO CHILDREN
        if(subroot->left == nullptr && subroot->right == nullptr)
        {
            delete subroot;
            subroot = nullptr;
            return true;
        }
        //ONE CHILD
            //RIGHT CHILD
        else if(subroot->left == nullptr && subroot->right != nullptr)
        {
            BNode<T>* temp = subroot;
            subroot = subroot->right;
            delete temp;
            return true;
        }
            //LEFT CHILD
        else if(subroot->right == nullptr && subroot->left != nullptr)
        {
            BNode<T>* temp = subroot;
            subroot = subroot->left;
            delete temp;
            return true;
        }
        //TWO CHILDREN
        else
        {
            //FIND SUCCESSOR OR PREDOCESSOR (WE WILL CHOOSE SUCCESSOR)
            BNode<T>* temp = subroot->right;
            while(temp->left != nullptr)
            {
                temp = temp->left;
            //REPLACE SUNROOT->DATA WITH THE SUCCESSOR VALUE
                subroot->data = temp->data;
                cursor = subroot;
            //REMPVE THE SUCCESSOR FROM THE RIGHT SUBTREE OF SUBROOT
                return Remove(temp->data, subroot->right);
            }
        }
    }

//Fourth Case: Recurse left to remove left
    else if(e < subroot->data)
    {
        return Remove(e, subroot->left);
    }
//Fifth Case: Recuse Right to Remove Right
    else
        return Remove(e, subroot->right);
}

/* Test Print prints out the binary search tree in order using the print in order helper method
    Incoming Data: None
    Outgoing Data: None

*/
template <typename T>
void BST<T>::testPrint()
{
    cout << "< ";
    printInOrderHelper(root);
    cout << "> ";
}


/* At cursor method returns the data value that is pointed to by the cursor
    Incoming data: none
    Outgoing Data: returns the data value that the cursor points to

*/
template <typename T>
T BST<T>::atCursor()
{
    if(cursor == nullptr)
    {
        cout << "Your cursor is empty." << endl;
    }
    else
    {
        return cursor->data;
    }

}

/* GoToBeginning Method sets the cursor equal to the min val in the tree or null if the tree is empty
    Incoming Data: BNode* which is the root of the BST
    Outgoing Data: None

*/
template <typename T>
void BST<T>::goToBeginning(BNode<T>* subroot)
{
    if(subroot == nullptr)
    {
        cout << "Empty tree. Cursor set to null." << endl;
        cursor = nullptr;
    }
    while(subroot->left != nullptr)
    {
        subroot = subroot->left;
    }
    cursor = subroot;
}
template <typename T>
void BST<T>::goToBeginning()
{
    goToBeginning(root);
}

/* GoToEnd method sets the cursor to the max val in the tree or null if it is iempty
    Incoming Data: BNode* (root of BST)
    Outgoing Data: None
*/
template <typename T>
void BST<T>::goToEnd(BNode<T>* subroot)
{
    if(subroot == nullptr)
    {
        cout << "Empty tree. Cursor set to null." << endl;
        cursor = nullptr;
    }
    while(subroot->right != nullptr)
    {
        subroot = subroot->right;
    }
    cursor = subroot;

}

template <typename T>
void BST<T>::goToEnd()
{
    goToEnd(root);
}

/* Helper method to find the predecessor(prev) of the value passed by user
    in the BST
    Incoming Data: BNode*
    Outgoing Data: BNode*
*/
template <typename T>
BNode<T>* BST<T>::findPredecessor(BNode<T>* subroot)
{
    while(subroot!= nullptr && subroot->right != nullptr)
    {
        subroot = subroot->right;
    }
    return subroot;
}

/* Helper method to find the successor(next) of the value passed by user
    in the BST
    Incoming Data: BNode*
    Outgoing Data: BNode*
*/
template <typename T>
BNode<T>* BST<T>::findSuccessor(BNode<T>* subroot)
{
    while(subroot != nullptr && subroot->left != nullptr)
    {
        subroot = subroot->left;
    }
    return subroot;
}

/* GoToNext method starts at the cursor and sets it to the successor
    if there is no successor then the cursor is set to the min val
    Incoming Data: none
    Outgoing Data: none
*/
template <typename T>
void BST<T>::goToNext()
{
    if(cursor != nullptr && cursor->right != nullptr)
    {
        cursor = findSuccessor(cursor);
    }
    else
    {
        goToBeginning(root);

    }

}

/* GoToPrev method starts at the cursor and sets it to the predecessor
    if there is no successor then the cursor is set to the min val
    Incoming Data: none
    Outgoing Data: none
*/
template <typename T>
void BST<T>::goToPrev()
{
    if(cursor != nullptr && cursor->left != nullptr)
    {
        cursor = findPredecessor(cursor);
    }
    else
    {
        goToEnd(root);
    }

}

/* ClearList uses recursion to clear the BST
    Incoming Data: BNode* (root of the BST)
    Outgoing Data: none
*/
template <typename T>
void BST<T>::clearList(BNode<T>* subroot)const
{
    while(subroot != nullptr)
    {
        clearList(subroot->left);
        clearList(subroot->right);
        delete subroot;
    }
    cursor = nullptr;
    root = nullptr;

}

template <typename T>
void BST<T>::clearList()
{
    clearList(root);
}

/* EmptyList method is used to determine whether the list is empty or not
    Incoming Data: BNode* root of BST
    Outgoing Data: Returns true if the BST is empty and false if it isn't empty
*/
template <typename T>
bool BST<T>::emptyList()
{
    return emptyList(root);
}
template <typename T>
bool BST<T>::emptyList(BNode<T>* subroot)const
{
    if(subroot == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* The BST destructor deallocates the BST using the clearList method
    Also sends the user a message
*/
template <typename T>
BST<T>::~BST<T>()
{
    cout << "Clearing your list..." << endl;
    clearList(root);
}

/* The overloaded assignment operator is used to create a deep copy of the tree
    by simply using the assignment operator through the use of the copyTree method
    Incoming Data: BST by reference
    Outgoing Data: BST
*/
template <typename T>
BST<T>& BST<T>::operator=(const BST<T>& B)
{
    if(this != &B)
    {
        clearList(root);
        root = copyTree(root);
        cursor = new BNode<T>(B.cursor);
    }
    return *this;
}

/* CopyTree method is a method that uses recursion to create a deep copy of the tree
    Incoming Data: BNode* (root of the BST)
    Outgoing Data: returns the (root) of the new BST
*/
template <typename T>
BNode<T>* BST<T>::copyTree(const BNode<T>* subroot)
{
    if (subroot == nullptr)
    {
        return nullptr;
    }
    BNode<T>* newBNode = new BNode<T>(subroot->data);
    newBNode->left = copyTree(subroot->left);
    newBNode->right = copyTree(subroot->right);
    return newBNode;
}
