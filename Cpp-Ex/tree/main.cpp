#include <iostream>
#include "logitree.h"

using namespace std;

int main() {
    // struct ExprTreeNode *root = new struct ExprTreeNode;
    // build(root);
    // cout << "Answer: " << evaluate(root) << endl;
    struct ExprTreeNode *root = new struct ExprTreeNode;
    build(root);
    cout << "Answer: " << evaluatelogitree(root) << endl;

    showStructure(root);
    commute(root);
    showStructure(root);
    return 0;
}