#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *leftChild;
    Node *rightChild;
};

Node *buildTree()
{
    int value;

    cout << "\nEnter value (-1 for Null) : ";
    cin >> value;

    if (value == -1)
    {
        return nullptr;
    }

    // Create node
    Node *newNode = new Node();
    newNode->data = value;

    cout << "\nEnter left child node of --> " << value << " (-1 for Null): ";
    newNode->leftChild = buildTree();

    cout << "\nEnter right child node of --> " << value << "(-1 for Null): ";
    newNode->rightChild = buildTree();

    return newNode;
}

void preOrder(Node *root)
{
    // Follow the rule : DLR

    if (root == nullptr)
        return;

    cout << "\t" << root->data << " ";
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}

void inOrder(Node *root)
{
    // Follow the rule : LDR

    if (root == nullptr)
        return;

    inOrder(root->leftChild);
    cout << "\t" << root->data << " ";
    inOrder(root->rightChild);
}

void postOrder(Node *root)
{

    // Follow the rule: LRD
    if (root == nullptr)
        return;

    postOrder(root->leftChild);
    postOrder(root->rightChild);
    cout << "\t" << root->data << " ";
}

int main()
{

    cout << " ==> Build tree by entering just values <== \n"
         << endl;

    Node *root = buildTree();

    while (true)
    {

        cout << "\n\n\n\t| ==> MENU <== |" << endl
             << "\t   1. Preorder" << endl
             << "\t   2. Inorder" << endl
             << "\t   3. Postorder" << endl
             << "\t   4. Exit" << endl
             << "\t| ============ |" << endl;

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\n\t==> PREORDER <==" << endl;
            preOrder(root);
            break;

        case 2:
            cout << "\n\n\t==> INORDER <==" << endl;
            inOrder(root);
            break;

        case 3:
            cout << "\n\n\t==> POSTORDER <==" << endl;
            postOrder(root);
            break;

        case 4:
            cout << "\nExiting the system." << endl;
            return 0;

        default:
            cout << "Select correct option." << endl;
            break;
        }
    }

    return 0;
}