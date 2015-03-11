#include <iostream>
#include "bst.h"
#include <random>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));

    BST<int> b;
    //b.insert(7);
    //b.insert(8);
    //b.insert(9);
    //b.insert(6);
    for (int i = 0; i < 1000000; ++i)
        b.insert(rand() % 10);

    //cout << b.contains(20) << endl;

    cout << b.isBalanced() << endl;

    return 0;
}