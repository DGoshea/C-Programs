/* Divine Goshea
   Binary Search Tree(Complete BNode class and BST class to implement the BST data structure
   1/23/2024
*/
#include <iostream>
using namespace std;

//BNode class that is a friend class of BST to allow us to access BNode private attributess
class BNode{
    int data;
    BNode* left;
    BNode* right;
    BNode();
    BNode(int e);
    BNode(int e, BNode* l, BNode* r);
    friend class BST; //STUDYYYYYYY
};
/*Bnode constructors
    The first takes no parameters and sets the left and right children to null
    The second takes a data parameter and sets the left and right children to null
    The last take a data parameters and two BNode pointers and sets them accordingly
*/
BNode::BNode():left(nullptr), right(nullptr){}
BNode::BNode(int e):data(e), left(nullptr), right(nullptr){}
BNode::BNode(int e, BNode* l, BNode* r):data(e), left(l), right(r){}

//--------------------------------------------------------------------------------------------

//Create our binary search tree class
class BST
{
    BNode* root;

    //Keep these helpers private to keep abstraction
    bool insertHelper(int e, BNode*& subroot);
    void printInOrderHelper(BNode* subroot)const;
    void printPreorderHelper(BNode* subroot)const;
    void printPostorderHelper(BNode* subroot)const;
    BNode* searcherHelper(int e, BNode* subroot)const;

public:
    BST();
    BST(BST& b);
    bool Insert(int e);
    void printInOrder()const;

    //Methods to be implemented
    BNode* searcher(int e)const;
    void printPreorder()const;
    void printPostorder()const;

};

/* BST constructor
    Takes in no parameters and sets the BNode pointer to null
    Return type none
*/
BST::BST():root(nullptr){}

/* Insert method to insert nodes into our BSt
    Takes in one data parameter
    Return type true if the data was created and false if it was a copy
*/
bool BST::Insert(int e)
{
    return insertHelper(e, root);
}

/* Insert Helper Method to define the implementation for insert method
    Takes in data parameter and a BNode pointer
    Return type true if we did insert and item and false if we did not
*/
bool BST::insertHelper(int e, BNode*& subroot)
{
    bool success = true;
    if(subroot == nullptr)
    {
        subroot = new BNode(e);
    }
    else if(e == subroot->data)
    {
        cout << "NO DUPLICATES ALLOWED" << endl;
        success = false;
    }
    else if(e < subroot->data)
    {
        success = insertHelper(e, subroot->left);
    }
    else //(e > subroot->data)
    {
        success = insertHelper(e, subroot->right);
    }
    return success;
}

/* Print In order method to print out the data of our nodes in order
    Takes in no parameters
    Return type void
*/
void BST::printInOrder()const
{
    cout << "< ";
    printInOrderHelper(root);
    cout << "> ";
}

/* Print in order helper method to define the implementation to the print in order method
    Takes in the root of the BST
    Return type void just prints the entire BST
*/
void BST::printInOrderHelper(BNode* subroot)const
{
    if(subroot != nullptr)
    {
        printInOrderHelper(subroot->left);
        cout << subroot->data << " ";
        printInOrderHelper(subroot->right);
    }
}

/* Searcher method is used to find if the value the user inputs is in the BST
    Takes in the value to search and a pointer to the root of the bst
    Returns the pointer to the node if found if not it returns null
*/
BNode* BST::searcher(int e) const
{
    return searcherHelper(e, root);
}

/* Searcher method is used to find if the value the user inputs is in the BST
    Takes in the value to search and a pointer to the root of the bst
    Returns the pointer to the node if found if not it returns null
*/
BNode* BST::searcherHelper(int e, BNode* subroot) const
{
    if(subroot == nullptr || subroot->data == e)
    {
        return subroot;
    }
    else if(e < subroot->data)
    {
        return searcherHelper(e, subroot->left);
    }
    else
    {
        return searcherHelper(e, subroot->right);
    }
}

/* Print preorder method is used to print the tree in preorder traversal (root, left, right)
    Takes in the root of the BST
    Return type void just prints the entire BST in preorder traversal
*/
void BST::printPreorder()const
{
    printPreorderHelper(root);
}

/* Print preorder helper method is used to print the tree in preorder traversal (root, left, right)
    Takes in the root of the BST
    Return type void just prints the entire BST in preorder traversal
*/
void BST::printPreorderHelper(BNode* subroot)const
{
    if(subroot != nullptr)
    {
        cout << subroot->data << " "; //print the current node
        printPreorderHelper(subroot->left); // traverse the left subtree recursively
        printPreorderHelper(subroot->right); // traverse the right tree recursively
    }
}

/* Print Postorder method is used to print the BST in Postorder traversal (left, right, root)
    Takes in the root of the BST
    Return type void just prints the entire BST in postorder traversal
*/
void BST::printPostorder()const
{
    printPostorderHelper(root);
}

/* Print Postorder helper method is used to print the BST in Postorder traversal (left, right, root)
    Takes in the root of the BST
    Return type void just prints the entire BST in postorder traversal
*/
void BST::printPostorderHelper(BNode* subroot)const
{
    if(subroot != nullptr)
    {
        printPostorderHelper(subroot->left);
        printPostorderHelper(subroot->right);
        cout << subroot->data << " ";
    }
}


int main(){
    BST b;
    b.Insert(50);
    b.printInOrder();
    cout << endl;
    b.Insert(75);
    b.printInOrder();
    cout << endl;
    b.Insert(25);
    b.printInOrder();
    cout << endl;
    b.Insert(110);
    b.printInOrder();
    cout << endl;
    b.Insert(60);
    b.printInOrder();
    cout << endl;
    b.Insert(10);
    b.printInOrder();
    cout << endl;
    b.Insert(30);
    b.printInOrder();
    cout << endl;
    b.printPostorder();
    cout << endl;
    b.printPreorder();
    cout << endl;
    cout << "Looking for 110..." << endl;
    if(b.searcher(110) != nullptr)
    {
        cout << "Item found" << endl;
    }
    else
    {
        cout << "Item not found" << endl;
    }

    cout << "Looking for 10..." << endl;
    if(b.searcher(10) != nullptr)
    {
        cout << "Item found" << endl;
    }
    else
    {
        cout << "Item not found" << endl;
    }
    return 0;
}
