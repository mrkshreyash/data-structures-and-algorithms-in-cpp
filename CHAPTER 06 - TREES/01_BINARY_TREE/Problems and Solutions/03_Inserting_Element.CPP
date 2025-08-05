#include <iostream>
#include <queue>
#include <string>
#include "build_binary_tree.h"

using namespace std;

TreeNode *newNode(int data)
{
    TreeNode *node = new TreeNode();
    node->data = data;
    node->leftChild = node->rightChild = nullptr;
    return node;
}

TreeNode *insertElement(TreeNode *root, int element)
{

    if (!root)
    {
        root = newNode(element);
        return root;
    }

    queue<TreeNode *> callQueue;
    callQueue.push(root);

    while (!callQueue.empty())
    {
        TreeNode *current = callQueue.front();
        callQueue.pop();

        if (current->leftChild)
        {
            callQueue.push(current->leftChild);
        }
        else
        {
            current->leftChild = newNode(element);
            cout << "\nElement " << element << " inserted at left node." << endl;
            return root;
        }

        if (current->rightChild)
        {
            callQueue.push(current->rightChild);
        }
        else
        {
            current->rightChild = newNode(element);
            cout << "\nElement " << element << " inserted at right node." << endl;
            return root;
        }
    }

    return root;
}

int main()
{

    TreeNode *root = newNode(1);
    root = insertElement(root, 2);

    root = insertElement(root, 3);
    root = insertElement(root, 4);

    printBinaryTree(root);

    return 0;
}