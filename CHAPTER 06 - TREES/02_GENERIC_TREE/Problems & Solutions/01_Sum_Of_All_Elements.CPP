#include <iostream>
#include "../build_generic_tree.h"
#include <stack>

using namespace std;

int findSumRecursive(GT_NODE *root)
{
    if (!root)
        return 0;
    return root->data + findSumRecursive(root->firstChild) + findSumRecursive(root->nextSibling);
}

int findSumIterative(GT_NODE *root)
{
    if (!root)
        return 0;

    stack<GT_NODE *> callStack;
    callStack.push(root);
    int total = 0;

    while (!callStack.empty())
    {
        GT_NODE *current = callStack.top();

        total += current->data;

        callStack.pop();

        if (current->firstChild)
        {
            callStack.push(current->firstChild);
        }

        if (current->nextSibling)
        {
            callStack.push(current->nextSibling);
        }
    }

    return total;
}
int main()
{
    GT_NODE *root = createGTNode(1);
    GT_NODE *n1 = createGTNode(2);
    GT_NODE *n2 = createGTNode(3);
    GT_NODE *n3 = createGTNode(4);

    addChild(root, n1);
    addChild(n1, n2);
    addChild(n2, n3);

    printGenTree(root);

    cout << "The sum of all elements in the tree by recursive approach is: " << findSumRecursive(root);
    cout << "\n\nThe sum of all elements in the tree by iterative approach is: " << findSumIterative(root);

    return 0;
}
