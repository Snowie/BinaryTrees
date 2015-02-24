#include "bst.h"

Node::Node(int data) {
    this->data = data;
    lChild = nullptr;
    rChild = nullptr;
}

BST::BST() {
    root = nullptr;
}

void BST::insert(int data) {
    root = insert(root, data);
}

void BST::remove(int data) {
    root = remove(root, data);
}

bool BST::contains(int data) const {
    contains(root, data);
}

Node *BST::rightRotate(Node *root) {
    Node *pivot = root->lChild;
    root->lChild = pivot->rChild;
    pivot->rChild = root;
    root = pivot;
    return root;
}

Node *BST::leftRotate(Node *root) {
    Node *pivot = root->rChild;
    root->rChild = pivot->lChild;
    pivot->lChild = root;
    root = pivot;
    return root;
}

Node *BST::insert(Node *root, int data) {
    //We've found an empty node, put it here!
    if (root == nullptr)
        return new Node(data);

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

Node *BST::remove(Node *root, int data) {
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
            root = rightRotate(root);
            root->rChild = remove(root->rChild, data);

        }
            //Only a right child
        else if (root->lChild == nullptr) {
            root = leftRotate(root);
            root->lChild = remove(root->lChild, data);
        }
            //Two children, arbitrary design choice to right rotate
        else {
            root = rightRotate(root);
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

bool BST::contains(Node *root, int data) const {
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

//Warning: Not functional!
BST::~BST() {
    //Continually remove root until there is no more root.
    while (root != nullptr)
        remove(root->data);
}