#ifndef BUILD_GT
#define BUILD_GT

#include <iostream>
#include <queue>

struct GT_NODE
{
    int data;
    GT_NODE *firstChild;
    GT_NODE *nextSibling;
};

GT_NODE *createGTNode(int value)
{
    GT_NODE *newNode = new GT_NODE();
    newNode->data = value;
    newNode->firstChild = newNode->nextSibling = nullptr;
    return newNode;
}

void addChild(GT_NODE *parent, GT_NODE *child)
{
    if (parent->firstChild == nullptr)
    {
        parent->firstChild = child;
    }
    else
    {
        GT_NODE *temp = parent->firstChild;
        while (temp->nextSibling != nullptr)
        {
            temp = temp->nextSibling;
        }

        temp->nextSibling = child;
    }
}

void printGenTree(GT_NODE *parent)
{
    if (parent == nullptr)
    {
        std::cout << "Tree is empty.\n";
        return;
    }

    std::queue<GT_NODE *> callQueue;
    callQueue.push(parent);

    while (!callQueue.empty())
    {

        int size = callQueue.size();

        while (size--)
        {
            GT_NODE *current = callQueue.front();
            callQueue.pop();

            std::cout << current->data << " ";
            GT_NODE *child = current->firstChild;

            while (child)
            {
                callQueue.push(child);
                child = child->nextSibling;
            }
        }
        std::cout << "\n";
    }
}

#endif