#ifndef BUILD_BT
#define BUILD_BT

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

#endif