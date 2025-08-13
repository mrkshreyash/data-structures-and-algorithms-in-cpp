#include <iostream>
#include "../build_generic_tree.h"

using namespace std;

int countSiblings(GT_NODE *treeRoot)
{
    int count = 0;

    while (treeRoot)
    {
        count++;
        // cout << "\n\n"
        //      << treeRoot->data << "\n\n";
        treeRoot = treeRoot->nextSibling;
    }

    return count;
}

int main()
{

    GT_NODE *root = createGTNode(1);
    GT_NODE *n1 = createGTNode(2);
    GT_NODE *n2 = createGTNode(3);
    GT_NODE *n3 = createGTNode(4);

    addChild(root, n1);
    addChild(n1, n2);
    addChild(n1, n3);

    cout << "The total siblings in tree are : " << countSiblings(root);
    cout << "\nThe total siblings in tree are : " << countSiblings(n1->firstChild);

    return 0;
}
