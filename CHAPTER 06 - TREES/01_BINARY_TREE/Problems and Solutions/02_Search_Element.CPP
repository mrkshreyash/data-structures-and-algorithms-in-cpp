#include <iostream>
#include "build_binary_tree.h"
#include <queue>

using namespace std;

void searchElementIterative(TreeNode *root, int element)
{
    if (root == nullptr)
    {
        cout << "\nTree is empty." << endl;
        return;
    }

    queue<TreeNode *> checkQueue;
    checkQueue.push(root);

    while (!checkQueue.empty())
    {
        TreeNode *current = checkQueue.front();
        checkQueue.pop();

        if (element == current->data)
        {
            cout << "\nElement " << current->data << " found in the tree." << endl;
            return;
        }

        if (current->leftChild)
        {
            checkQueue.push(current->leftChild);
        }

        if (current->rightChild)
        {
            checkQueue.push(current->rightChild);
        }
    }

    cout << "\nElement " << element << " does not exist in the tree." << endl;
}

int searchElementRecursiveMethodOne(TreeNode *root, int element)
{
    int temp;

    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        if (element == root->data)
        {
            return 1;
        }
        else
        {
            temp = searchElementRecursiveMethodOne(root->leftChild, element);
            if (temp != 0)
            {
                return temp;
            }
            else
            {
                return searchElementRecursiveMethodOne(root->rightChild, element);
            }
        }
    }
    return 0;
}

bool searchElementRecursiveMethodTwo(TreeNode *root, int element)
{
    if (root == nullptr)
        return false;

    if (root->data == element)
        return true;

    return searchElementRecursiveMethodTwo(root->leftChild, element) || searchElementRecursiveMethodTwo(root->rightChild, element);
}

int main()
{
    TreeNode *root = buildSampleBinaryTree();
    int element = 5;

    cout << "\n ==> Searching element in tree (Iterative) <== " << endl;
    searchElementIterative(root, element);

    cout << "\n\n ==> Searching element in tree (Recursive Method 1) <== " << endl;

    if (searchElementRecursiveMethodOne(root, element) == 0)
    {
        cout << "\nElement " << element << " does not exist in the tree" << endl;
    }
    else
    {
        cout << "\nElement " << element << " found in the tree." << endl;
    }

    cout << "\n\n ==> Searching element in tree (Recursive Method 2) <== " << endl;

    if (searchElementRecursiveMethodTwo(root, element))
    {
        cout << "\nElement " << element << " found in the tree." << endl;
    }
    else
    {
        cout << "\nElement " << element << " does not exist in the tree" << endl;
    }

    return 0;
}