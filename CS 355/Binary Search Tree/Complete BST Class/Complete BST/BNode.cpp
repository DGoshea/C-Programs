#include "BNode.h"
#include <iostream>
using namespace std;

/*Bnode constructors
    The first takes no parameters and sets the left and right children to null
    The second takes a data parameter and sets the left and right children to null
    The last take a data parameters and two BNode pointers and sets them accordingly
*/
BNode::BNode():left(nullptr), right(nullptr){}
BNode::BNode(T e):data(e), left(nullptr), right(nullptr){}
BNode::BNode(T e, BNode* l, BNode* r):data(e), left(l), right(r){}



