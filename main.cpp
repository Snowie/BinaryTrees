#include <iostream>
#include "bst.h"
#include <random>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));

    BST b;
    b.insert(7);
    for (int i = 0; i < 10000; ++i)
        b.insert(rand() % 10);

    return 0;
}