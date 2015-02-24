#include "bst.h"

Node::Node(int data)
{
    this->data = data;
    lChild = nullptr;
    rChild = nullptr;
}

BST::BST()
{
    root = nullptr;
}

void BST::insert(int data)
{
    root = insert(root, data);
}

void BST::remove(int data)
{
    root = remove(root, data);
}

bool BST::contains(int data) const
{
    contains(root, data);
}

Node * BST::insert(Node * node, int data)
{
    //We've found an empty node, put it here!
    if(node == nullptr)
        return new Node(data);

    //We don't allow duplicate values
    if(node->data == data)
        return nullptr;

    //Does the data go left or right?
    if(node->data > data)
        node->lChild = insert(node->lChild, data);
    else
        node->rChild = insert(node->rChild, data);

    return node;
}

Node * BST::remove(Node * node, int data)
{
    //TODO: Implement, include rotations
    return nullptr;
}

bool BST::contains(Node * node, int data) const
{
    //It isn't here!
    if(node == nullptr)
        return false;

    //Got it!
    if(node->data == data)
        return true;

    //Could it possibly be to the left or to the right?
    if(node->data > data)
        return contains(node->lChild, data);
    else
        return contains(node->rChild, data);
}

//Warning: Not functional!
BST::~BST()
{
    /*while(root != nullptr)
        remove(root->data);*/
}