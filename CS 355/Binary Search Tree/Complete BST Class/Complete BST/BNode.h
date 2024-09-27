#include <iostream>
#ifndef BNODE_H
#define BNODE_H
#endif // BNODE_H
using namespace std;

template <typename T>
class BNode
{
    BNode* left, right;
    T data;
    BNode<T>();
    BNode<T>(T e);
    BNode<T>(T e, BNode* l, BNode* r);
    friend class BST<T>;
};
