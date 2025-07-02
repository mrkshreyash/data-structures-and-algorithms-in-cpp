#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    // Create constructor
    Node(int val) : data(val), next(nullptr) {}
};

// Create a circular linked list class
class circularLinkedList
{
private:
    Node *tail;

public:
    circularLinkedList() : tail(nullptr) {};

    // insert node at the head of the list
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (!tail)
        {
            tail = newNode;
            newNode->next = newNode;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
    }

    // insert node at the tail of the list
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (!tail)
        {
            tail = newNode;
            tail->next = newNode;
            return;
        }

        newNode->next = tail->next; // points to the head
        tail->next = newNode;       // old tail points to the new node
        tail = newNode;             // convert old tail to new tail
    }

    // delete a node by value
    void deleteNode(int key)
    {
        if (!tail)
            return;

        Node *current = tail->next;
        Node *previous = tail;

        do
        {
            if (current->data == key)
            {
                if (current == previous)
                { // i.e. only one node exists
                    delete current;
                    tail = nullptr;
                }
                else
                {
                    previous->next = current->next;
                    if (current == tail)
                        tail = previous;
                    delete current;
                }
                return;
            }
            previous = current;
            current = current->next;

        } while (current != tail->next);
        std::cout << "Value " << key << " not found.\n";
    }

    // Print list
    void print()
    {
        if (!tail)
        {
            std::cout << "List is empty.\n";
            return;
        }

        Node *current = tail->next;
        do
        {
            std::cout << current->data << " -> ";
            current = current->next;

        } while (current != tail->next);
        std::cout << "(back to head)\n";
    }

    // Destructor to clean the memory
    ~circularLinkedList()
    {
        if (!tail)
            return;

        Node *current = tail->next;
        tail->next = nullptr; // break circle

        while (current)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    circularLinkedList cll;

    cll.insertAtHead(10);
    cll.insertAtTail(20);
    cll.insertAtTail(30);

    cll.print();
    // 10 -> 20 -> 30 -> back to head(10)

    cll.insertAtHead(5);
    cll.print();
    // 5 -> 10 -> 20 -> 30 -> back to head(5)

    cll.deleteNode(20);
    cll.print();
    // 5 -> 10 -> 30 -> back to head(5)

    cll.deleteNode(2100);
    // Not found case
}