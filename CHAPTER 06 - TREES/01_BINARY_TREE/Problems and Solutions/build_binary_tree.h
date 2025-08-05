#ifndef BUILD_BT
#define BUILD_BT

#include <iostream>
#include <queue>

struct TreeNode
{
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};

TreeNode *newTreeNode(int data)
{
    TreeNode *node = new TreeNode();
    node->data = data;
    node->leftChild = node->rightChild = nullptr;
    return node;
}

TreeNode *buildSampleBinaryTree()
{
    // Parent node
    TreeNode *root = newTreeNode(1);

    // Left Subtree
    root->leftChild = newTreeNode(2);
    root->leftChild->leftChild = newTreeNode(4);
    root->leftChild->rightChild = newTreeNode(5);

    // Right Subtree
    root->rightChild = newTreeNode(3);
    root->rightChild->leftChild = newTreeNode(6);
    root->rightChild->rightChild = newTreeNode(7);

    return root;
}

void printBinaryTree(TreeNode *root)
{

    if (!root)
    {
        std::cout << "\nTree is empty." << std::endl;
        return;
    }

    std::queue<TreeNode *> printQueue;

    printQueue.push(root);

    std::cout << "\n ==> Printing Constructed Binary Tree <== " << std::endl;

    while (!printQueue.empty())
    {

        int levelSize = printQueue.size();

        for (int i = 0; i < levelSize; ++i)
        {

            TreeNode *current = printQueue.front();
            printQueue.pop();

            std::cout << current->data << "  ";

            if (current->leftChild)
            {
                printQueue.push(current->leftChild);
            }

            if (current->rightChild)
            {
                printQueue.push(current->rightChild);
            }
        }

        std::cout << std::endl;
    }
}

#endif