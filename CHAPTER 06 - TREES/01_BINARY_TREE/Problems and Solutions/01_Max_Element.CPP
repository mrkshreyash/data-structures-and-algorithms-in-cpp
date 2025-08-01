#include <iostream>
#include <queue>
#include <climits>

#include "build_binary_tree.h"

using namespace std;

// Find maximum element iteratively
int findMaxElementIteratively(TreeNode *root)
{
    if (root == nullptr)
        return INT_MIN;

    queue<TreeNode *> checkQueue;
    checkQueue.push(root);

    int maxValue = INT_MIN;

    while (!checkQueue.empty())
    {
        TreeNode *current = checkQueue.front();
        checkQueue.pop();

        maxValue = max(maxValue, current->data);

        if (current->leftChild)
        {
            checkQueue.push(current->leftChild);
        }

        if (current->rightChild)
            checkQueue.push(current->rightChild);
    }

    return maxValue;
}

// Find maximum element recursively
int findMaxElementRecursively(TreeNode *root)
{
    if (root == nullptr)
        return INT_MIN;

    int leftMax = findMaxElementRecursively(root->leftChild);
    int rightMax = findMaxElementRecursively(root->rightChild);

    return max(root->data, max(leftMax, rightMax));
}

int main()
{

    // You can change tree elements in build_binary_tree.h header file
    TreeNode *root = buildSampleBinaryTree();

    cout << "\nMax Element Present in the Binary Tree (ITERATIVELY): " << findMaxElementIteratively(root) << endl;
    cout << "\nMax Element Present in the Binary Tree (RECURSIVELY): " << findMaxElementRecursively(root) << endl;

    return 0;
}