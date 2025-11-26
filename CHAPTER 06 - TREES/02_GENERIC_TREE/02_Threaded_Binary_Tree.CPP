/*
IDEA BEHIND TBT

Each node has 2 pointers
    1. Left
    2. Right

We introduce 2 extra boolean flags:
    1. lThread --> true if left pointer is a thread (not a real child)
    2. rThread --> true if right pointer is a thread


    ------------> What is a Thread ??? <-------------
    A 'Thread' is a pointer that points to
        1. Inorder predecessor (via left thread)
        2. Inorder successor   (via right thread)

    This makes the Inorder traversal possible without recursion or stack.
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    bool lThread;
    bool rThread;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
        lThread = rThread = true;
    }
};

class ThreadedBinaryTree
{
private:
    Node *root;

public:
    ThreadedBinaryTree()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        // Find location for insertion
        while (current != nullptr)
        {
            parent = current;

            if (val < current->data)
            {
                if (current->lThread == false)
                {
                    current = current->left;
                }
                else
                    break;
            }
            else
            {
                if (current->rThread == false)
                {
                    current = current->right;
                }
                else
                    break;
            }
        }

        // Insert as left child
        if (val < parent->data)
        {
            newNode->left = parent->left; // inorder predescessor
            newNode->right = parent;      // inorder successor
            parent->lThread = false;
            parent->left = newNode;
        }

        // Insert as right child
        else
        {
            newNode->right = parent->right; // inorder predescessor
            newNode->left = parent;         // inorder successor
            parent->lThread = false;
            parent->right = newNode;
        }
    }

    // Find the leftmost node
    Node *leftMost(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        while (node->lThread == false)
            node = node->left;

        return node;
    }

    // Inorder traversal
    void inorder()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty.\n";
            return;
        }

        Node *current = leftMost(root);

        while (current != nullptr)
        {
            cout << current->data << " ";

            if (current->rThread)
                current = current->right; // follow thread
            else
                current = leftMost(current->right); // go to next subtree
        }
    }
};

int main()
{
    ThreadedBinaryTree tbt;

    tbt.insert(50);
    tbt.insert(30);
    tbt.insert(70);
    tbt.insert(20);
    tbt.insert(40);
    tbt.insert(60);
    tbt.insert(80);

    cout << "Inorder Traversal of Threaded Binary Tree: ";
    tbt.inorder();

    return 0;
}