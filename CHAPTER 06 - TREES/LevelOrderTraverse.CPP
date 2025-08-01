#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->leftChild = node->rightChild = nullptr;
    return node;
}

void levelOrderTraversing(Node *root)
{

    if (root == nullptr)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node *> checkQueue;
    checkQueue.push(root);

    while (!checkQueue.empty())
    {
        Node *current = checkQueue.front();
        checkQueue.pop();

        cout << current->data << " ";

        if (current->leftChild)
        {
            checkQueue.push(current->leftChild);
        }

        if (current->rightChild)
        {
            checkQueue.push(current->rightChild);
        }
    }
}

int main()
{
    Node *root = newNode(1);
    root->leftChild = newNode(2);
    root->rightChild = newNode(3);
    root->leftChild->leftChild = newNode(4);
    root->leftChild->rightChild = newNode(5);
    root->rightChild->leftChild = newNode(6);
    root->rightChild->rightChild = newNode(7);

    cout << "\n ==> Level Order Traversing <==" << endl;
    cout << "\t";
    levelOrderTraversing(root);
    cout << endl;

    return 0;
}