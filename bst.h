#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;
class Node
{
    public:
        Node(int);
        int data;
        Node * rChild;
        Node * lChild;
};
typedef struct Node Node;

class BST
{
    public:
        BST();
        //Helper functions for the recursive
        void insert(int);
        void remove(int);
        bool contains(int) const;
        ~BST();
    private:
        Node * leftRotate(Node *);
        Node * rightRotate(Node *);
        Node * insert(Node *, int);
        Node * remove(Node *, int);
        bool contains(Node *, int) const;
        Node * root;


};
#endif