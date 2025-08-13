#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *firstChild;
    Node *nextSibling;
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->firstChild = newNode->nextSibling = nullptr;
    return newNode;
}

void addChild(Node *parent, Node *child)
{
    if (parent->firstChild == nullptr)
    {
        parent->firstChild = child;
    }

    else
    {
        Node *temp = parent->firstChild;
        while (temp->nextSibling != nullptr)
        {
            temp = temp->nextSibling;
        }

        temp->nextSibling = child;
    }
}

int main()
{
    Node *root = createNode(1);
    Node *n1 = createNode(2);
    Node *n2 = createNode(3);
    Node *n3 = createNode(4);
    Node *n4 = createNode(5);
    Node *n5 = createNode(6);
    Node *n6 = createNode(7);

    addChild(root, n1);
    addChild(root, n2);

    addChild(n1, n3);
    addChild(n2, n4);

    addChild(n3, n5);
    addChild(n4, n6);

    return 0;
}