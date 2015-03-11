#include <iostream>
#include "avl.h"
#include <random>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));

    AVL<int> b;

    for (int i = 0; i < 1090090; ++i)
        b.insert(rand() % 300985);

    //cout << b.contains(20) << endl;

    cout << b.isBalanced() << endl;

    return 0;
}