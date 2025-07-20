#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedListQueue
{

private:
    int count;
    Node *front;
    Node *rear;

public:
    LinkedListQueue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enQueue(int value)
    {
        Node *newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
        cout << "\nENQUEUE: Element " << value << " inserted into the Queue." << endl;
    }

    void deQueue()
    {
        if (isEmpty())
        {

            cout << "\n ==> DEQUEUE: Queue Underflow. <===" << endl;
            return;
        }

        Node *temp = front;

        cout << "\nElement " << front->data << " deleted from the Queue" << endl;
        front = front->next;

        if (front = nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        count--;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "\n ==> PEEK: List is empty. <==" << endl;
            return;
        }

        cout << "\nPEEK: Element on front is : " << front->data << endl;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "\n ==> PRINT: Queue is Empty. <== " << endl;
            return;
        }

        Node *temp = front;

        cout << "\n\nPRINT: <Start> --> ";

        while (temp != nullptr)
        {
            cout << "| " << temp->data << " |" << " --> ";
            temp = temp->next;
        }
        cout << "<Null / End>" << endl;
    }
};

int main()
{

    LinkedListQueue llq;

    int choice, value;

    while (true)
    {
        std::cout << std::endl;

        std::cout << " --------> Dynamic Circular Queue <-------- " << std::endl
                  << " 1. Enqueue" << std::endl
                  << " 2. Dequeu" << std::endl
                  << " 3. Peek" << std::endl
                  << " 4. Print" << std::endl
                  << " 5. Exit" << std::endl
                  << " ----------------------------------------- " << std::endl;

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        std::cout << std::endl;

        switch (choice)
        {
        case 1:
            std::cout << "Enter element value: ";
            std::cin >> value;
            llq.enQueue(value);
            break;

        case 2:
            llq.deQueue();
            break;

        case 3:
            llq.peek();
            break;

        case 4:
            llq.print();
            break;

        case 5:
            std::cout << "INFO: Exiting the system." << std::endl;
            return 0;

        default:
            std::cout << "INFO: Please, choose valid option." << std::endl;
            break;
        }
    }
}