#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;
};

Node *newNode(int value)
{
    Node *node = new Node();
    node->data = value;
    node->leftChild = node->rightChild = nullptr;
    return node;
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> callStack;
    callStack.push(root);

    while (!callStack.empty())
    {
        Node *current = callStack.top();
        callStack.pop();

        cout << current->data << " ";

        if (current->rightChild)
        {
            callStack.push(current->rightChild);
        }

        if (current->leftChild)
        {
            callStack.push(current->leftChild);
        }
    }
}

void inOrder(Node *root)
{
    stack<Node *> callStack;
    Node *current = root;

    while (current != nullptr || !callStack.empty())
    {
        while (current != nullptr)
        {
            callStack.push(current);
            current = current->leftChild;
        }

        current = callStack.top();
        cout << current->data << " ";
        callStack.pop();
        current = current->rightChild;
    }
}

void postOrder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> callStack1, callStack2;
    callStack1.push(root);

    while (!callStack1.empty())
    {
        Node *current = callStack1.top();
        callStack1.pop();
        callStack2.push(current);

        if (current->leftChild)
        {
            callStack1.push(current->leftChild);
        }

        if (current->rightChild)
        {
            callStack1.push(current->rightChild);
        }
    }

    while (!callStack2.empty())
    {
        cout << callStack2.top()->data << " ";
        callStack2.pop();
    }
}

int main()
{

    Node *root = newNode(1);

    // Left subtree
    root->leftChild = newNode(2);
    root->leftChild->leftChild = newNode(4);
    root->leftChild->rightChild = newNode(5);

    // Right subtree
    root->rightChild = newNode(3);
    root->rightChild->leftChild = newNode(6);
    root->rightChild->rightChild = newNode(7);

    cout << "\n\n----> PREORDER <----" << endl;
    preOrder(root);
    cout << endl;
    cout << "--------------------" << endl;

    cout << "\n\n----> INORDER <----" << endl;
    inOrder(root);
    cout << endl;
    cout << "--------------------" << endl;

    cout << "\n\n----> POSTORDER <----" << endl;
    postOrder(root);
    cout << endl;
    cout << "--------------------" << endl;

    return 0;
}