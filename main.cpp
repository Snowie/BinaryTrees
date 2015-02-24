#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BST b;
    b.insert(7);

    cout << b.contains(7) << endl;
    //cout << "Hello, World!" << endl;
    return 0;
}