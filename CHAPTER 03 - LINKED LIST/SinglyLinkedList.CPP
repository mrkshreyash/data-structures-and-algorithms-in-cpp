#include <iostream>

struct Node
{
    int data;
    Node *next;
};

/*

[10 | *] -> [20 | *] -> [10 | *] -> [20 | nullptr]
  Head                                 Tail

*/

void printList(Node *head)
{

    std::cout << std::endl
              << "The Single Linked List: " << std::endl;
    while (head != nullptr)
    {

        std::cout << head->data << " -> ";
        head = head->next;
    }

    std::cout << "nullptr" << std::endl
              << std::endl;
}

void insertAtBeginning(Node *&head, int value)
{
    // First create a node
    Node *newNode = new Node;

    // Assign value
    newNode->data = value;

    // Link the node
    newNode->next = head;

    // Assign te node
    head = newNode;
}

void insertAtEnd(Node *&head, int value)
{
    if (head == nullptr)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node *newNode = new Node;

    newNode->data = value;

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // set newNode next to nullptr
    newNode->next = nullptr;
    temp->next = newNode;
}

void insertAtPosition(Node *&head, int value, int position)
{
    if (position == 1)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node *newNode = new Node;
    newNode->data = value;

    Node *temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        std::cout << "Index " << position << " is out of bounds." << std::endl;
        delete newNode; // if the position does not exists then delete the previously created note and assigned values to free up memeory
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteHead(Node *&head)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty." << std::endl;

        return;
    }

    Node *temp = head;
    head = head->next;

    std::cout << "Deleted " << temp->data << " from the list." << std::endl;
    delete temp;
    return;
}

void deleteTail(Node *&head)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    if (head->next == nullptr)
    {
        std::cout << "Deleted " << head->data << " from the list." << std::endl;
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    std::cout << "Deleted " << temp->next->data << " from the list." << std::endl;
    delete temp->next;
    temp->next = nullptr;
    return;
}

void deleteAtPosition(Node *&head, int position)
{
    if (position == 1)
    {
        deleteHead(head);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < position - 1 & temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        std::cout << "The list is emtpy." << std::endl;
        return;
    }

    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    std::cout << "Deleted " << deleteNode->data << " from position " << position << " in the list." << std::endl;
    delete deleteNode;
    return;
}

int main()
{
    Node *head = nullptr;

    insertAtBeginning(head, 5);
    insertAtBeginning(head, 6);
    insertAtBeginning(head, 7);
    insertAtEnd(head, 8);
    printList(head);
    // insertAtPosition(head, 9, 10);
    // deleteHead(head);
    // deleteTail(head);
    deleteAtPosition(head, 2);
    printList(head);

    return 0;
}
