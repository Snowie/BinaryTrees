#ifndef BST_H
#define BST_H

#include "binarytree.h"
#include <iostream>

using namespace std;

template<class T>
class BST : public BinaryTree<T> {
public:
    BST();

    //Helper functions for the recursive
    void insert(T);

    void remove(T);

    bool contains(T) const;

    ~BST();

protected:

    Node<T> * insert(Node<T> *, T);

    Node<T> * remove(Node<T> *, T);

    bool contains(Node<T> *, T) const;

};

template<class T>
BST<T>::BST() : BinaryTree<T>() {
    ;
}

template<class T>
void BST<T>::insert(T data) {
    this->root = insert(this->root, data);
}

template<class T>
void BST<T>::remove(T data) {
    this->root = remove(this->root, data);
}

template<class T>
bool BST<T>::contains(T data) const {
    contains(this->root, data);
}

template<class T>
Node<T> *BST<T>::insert(Node<T> *root, T data) {
    //We've found an empty node, put it here!
    if (root == nullptr)
        return new Node<T>(data);

    //We don't allow duplicate values, pass root back up the chain
    if (root->data == data)
        return root;

    //Does the data go left or right?
    if (root->data > data)
        root->lChild = insert(root->lChild, data);
    else
        root->rChild = insert(root->rChild, data);

    //Pass back up the recursive chain
    return root;
}

template<class T>
Node<T> *BST<T>::remove(Node<T> *root, T data) {
    //Not found! Pass nullptr back up the chain
    if (root == nullptr)
        return nullptr;

    if (root->data == data) {
        //Leaf node! Kill it!
        if (root->lChild == nullptr && root->rChild == nullptr) {
            //Free the memory and pass nullptr back up the chain
            delete root;
            return nullptr;
        }
            //Only a left child
        else if (root->rChild == nullptr) {
            root = this->rightRotate(root);
            root->rChild = remove(root->rChild, data);

        }
            //Only a right child
        else if (root->lChild == nullptr) {
            root = this->leftRotate(root);
            root->lChild = remove(root->lChild, data);
        }
            //Two children, arbitrary design choice to right rotate
        else {
            root = this->rightRotate(root);
            root->rChild = remove(root->rChild, data);
        }
    }

    //Could it be to the left or right?
    if (root->data > data)
        root->lChild = remove(root->lChild, data);
    else
        root->rChild = remove(root->rChild, data);

    //Pass this back up the recursion chain
    return root;
}

template<class T>
bool BST<T>::contains(Node<T> *root, T data) const {
    //It isn't here!
    if (root == nullptr)
        return false;

    //Got it!
    if (root->data == data)
        return true;

    //Could it possibly be to the left or to the right?
    if (root->data > data)
        return contains(root->lChild, data);
    else
        return contains(root->rChild, data);
}

template<class T>
BST<T>::~BST() {
    //Continually remove root until there is no more root.
    while (this->root != nullptr)
        remove(this->root->data);
}

#endif