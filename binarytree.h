#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <math.h>
#include <algorithm>
template<class T>
class Node {
public:
    Node(T);

    T data;
    Node *rChild;
    Node *lChild;
};

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    lChild = nullptr;
    rChild = nullptr;
}

template<class T>
class BinaryTree {
public:
    BinaryTree();

    //Helper functions for the recursive
    virtual void insert(T) = 0;

    virtual void remove(T) = 0;

    virtual bool contains(T) const = 0;

    bool isBalanced() const;

    virtual  ~BinaryTree();

protected:
    int getHeight(Node<T> *) const;

    bool isBalanced(Node<T> *) const;

    Node<T> *leftRotate(Node<T> *);

    Node<T> *rightRotate(Node<T> *);

    virtual Node<T> * insert(Node<T> *, T) = 0;

    virtual Node<T> * remove(Node<T> *, T) = 0;

    virtual bool contains(Node<T> *, T) const = 0;

    Node<T> *root;
};

template<class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    ;
}

template<class T>
int BinaryTree<T>::getHeight(Node<T> *root) const{
    if(root == nullptr)
        return 0;

    return (1 + std::max(getHeight(root->lChild), getHeight(root->rChild)));
}

template<class T>
bool BinaryTree<T>::isBalanced() const {
    return isBalanced(root);
}

template<class T>
bool BinaryTree<T>::isBalanced(Node<T> * root) const {
    if(root == nullptr)
        return true;

    int lHeight = getHeight(root->lChild);
    int rHeight = getHeight(root->rChild);

    if(abs(lHeight - rHeight) <= 1)
        return isBalanced(root->lChild) && isBalanced(root->rChild);
    else
        return false;
}

template<class T>
Node<T> *BinaryTree<T>::rightRotate(Node<T> *root) {
    Node<T> *pivot = root->lChild;
    root->lChild = pivot->rChild;
    pivot->rChild = root;
    root = pivot;
    return root;
}

template<class T>
Node<T> *BinaryTree<T>::leftRotate(Node<T> *root) {
    Node<T> *pivot = root->rChild;
    root->rChild = pivot->lChild;
    pivot->lChild = root;
    root = pivot;
    return root;
}

#endif