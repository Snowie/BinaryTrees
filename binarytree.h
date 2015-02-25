template <class T>
class Node {
public:
    Node(T);

    T data;
    Node *rChild;
    Node *lChild;
};

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    lChild = nullptr;
    rChild = nullptr;
}

template <class T>
class BinaryTree{
    public:
        BinaryTree();
        virtual  ~BinaryTree();
    protected:
        Node<T> * leftRotate(Node<T> *);
        Node<T> * rightRotate(Node<T> *);
        Node<T> * root;
};

template <class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template  <class T>
BinaryTree<T>::~BinaryTree() {
    ;
}

template <class T>
Node<T> * BinaryTree<T>::rightRotate(Node<T> *root) {
    Node<T> *pivot = root->lChild;
    root->lChild = pivot->rChild;
    pivot->rChild = root;
    root = pivot;
    return root;
}

template <class T>
Node<T> * BinaryTree<T>::leftRotate(Node<T> *root) {
    Node<T> *pivot = root->rChild;
    root->rChild = pivot->lChild;
    pivot->lChild = root;
    root = pivot;
    return root;
}