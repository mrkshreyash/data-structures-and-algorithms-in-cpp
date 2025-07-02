#include <iostream>

struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

void checkListIsEmtpy(Node *&head)
{
    if (head == nullptr)
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }
}

void forwardPrint(Node *head)
{

    std::cout << "\nThe Linked List: \n\n";
    std::cout << "NULL (head) <-> ";
    while (head != nullptr)
    {
        std::cout << head->value << " <-> ";
        head = head->next;
    }
    std::cout << "(tail) NULL" << std::endl
              << std::endl;
}

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);

    newNode->next = head;

    if (head != nullptr)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        insertAtHead(head, value);
        return;
    }

    Node *temp = head;

    // Traverse to the end
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Connect the nodes internally
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node *&head, int value, int position)
{
    // If position is 1 then the list is emtpy and we had to place it on head so call insertAtHead() function
    if (position == 1)
    {
        insertAtHead(head, value);
        return;
    }

    // Otherwise create a temp node
    Node *temp = head;

    // Traverse the list and find out predessor location of the position node.
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    // Check for out of bound position error
    if (temp == nullptr)
    {
        std::cout << "The position " << position << " is out of bounds (does not exists).\n";
        return;
    }

    // Create a new node
    Node *newNode = new Node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteHead(Node *&head)
{
    checkListIsEmtpy(head);

    Node *temp = head;

    head = head->next;
    head->prev = nullptr;

    std::cout << "Deleted " << temp->value << " from the list." << std::endl;

    delete temp;

    return;
}

void deleteTail(Node *&head)
{
    checkListIsEmtpy(head);

    if (head->next == nullptr)
    {
        std::cout << "Deleted " << head->value << " from the list." << std::endl;
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    std::cout << "Deleted " << temp->value << " from the list." << std::endl;
    delete temp;
    return;
}

void deleteAtPosition(Node *&head, int position)
{
    checkListIsEmtpy(head);

    if (position == 1)
    {
        deleteHead(head);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    // for (int i = 1; i < position - 1 && temp->next != nullptr; i++)
    // {
    //     temp = temp->next;
    // }

    if (temp == nullptr)
    {
        std::cout << "The " << position << " is out of bounds or does not exists." << std::endl;
        return;
    }

    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }

    std::cout << "Deleted " << temp->value << " from the list." << std::endl;
    delete temp;
    return;
}

int main()
{
    Node *head = nullptr;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtTail(head, 6);
    insertAtPosition(head, 10, 3);
    insertAtTail(head, 26);
    forwardPrint(head);

    // deleteHead(head);
    // deleteTail(head);

    deleteAtPosition(head, 3);

    forwardPrint(head);
    return 0;
}
