#ifndef AVL_H
#define AVL_H


#include "bst.h"

template<class T>
class AVL : public BST<T> {
public:
    AVL();

    //Helper functions for the recursive
    void insert(T);

    void remove(T);

private:
    void balance(Node<T> *);

    Node<T> *insert(Node<T> *, T);
};

template<class T>
AVL<T>::AVL() : BST<T>() {

}


template<class T>
void AVL<T>::insert(T data) {
    this->root = insert(this->root, data);
}

template<class T>
void AVL<T>::remove(T data) {
    this->root = BST<T>::remove(this->root, data);
}

template<class T>
Node<T> *AVL<T>::insert(Node<T> *root, T data) {
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
    balance(root);
    return root;
}

template<class T>
void AVL<T>::balance(Node<T> *root) {
    int balanceFactor = this->getHeight(root->lChild) - this->getHeight(root->rChild);

    if (abs(balanceFactor) > 2)
        cout << "Bad balance factor: " << balanceFactor << endl;

    //Left taller
    if (balanceFactor == 2) {
        Node<T> *subtree = root->lChild;

        //Subtree leaning
        int subtreeBalanceFactor = this->getHeight(subtree->lChild) - this->getHeight(subtree->rChild);

        //Left right case? Make left left
        if (subtreeBalanceFactor == -1)
            this->leftRotate(subtree);

        this->rightRotate(root);
    }
        //Right taller
    else if (balanceFactor == -2) {
        Node<T> *subtree = root->rChild;

        int subtreeBalanceFactor = this->getHeight(subtree->lChild) - this->getHeight(subtree->rChild);

        //Right left case? Make right right
        if (subtreeBalanceFactor == 1)
            this->rightRotate(subtree);

        this->leftRotate(root);
    }
}

#endif