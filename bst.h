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
        //Helper functions for the recursive
        BST();
        void insert(int);
        void remove(int);
        bool contains(int) const;
        ~BST();
    private:
        Node * insert(Node *, int);
        Node * remove(Node *, int);
        bool contains(Node *, int) const;
        Node * root;


};
#endif