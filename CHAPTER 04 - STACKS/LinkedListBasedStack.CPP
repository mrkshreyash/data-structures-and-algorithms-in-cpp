#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class LinkedListBasedStack
{
private:
    Node *topNode;

public:
    LinkedListBasedStack()
    {
        topNode = nullptr;
    }

    bool isEmpty()
    {
        if (topNode == nullptr)
        {
            std::cout << "CHK: STACK is emtpy." << std::endl;
            return true;
        }

        return false;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
        std::cout << "INS: Element " << value << " pushed inside the STACK." << std::endl;
    }

    void pop()
    {
        if (LinkedListBasedStack::isEmpty())
        {
            std::cout << "WARN: Cannot POP element in empty stack. STACK UNDERFLOW." << std::endl;
            return;
        }
        Node *temp = topNode;

        std::cout << "DEL: Popped " << topNode->data << " from the STACK." << std::endl;

        topNode = topNode->next;

        delete temp;
    }

    void peek()
    {
        if (LinkedListBasedStack::isEmpty())
        {
            return;
        }

        std::cout << "INFO: Top element in the STACK is: " << topNode->data << std::endl;
        return;
    }

    void print()
    {
        if (LinkedListBasedStack::isEmpty())
        {
            return;
        }

        std::cout << "STACK (top --> bottom): ";
        Node *current = topNode;
        while (current)
        {
            std::cout << current->data << " --> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;

        std::cout << std::endl;
    }
};

int main()
{
    LinkedListBasedStack stack;
    int choice, value;

    std::cout << "\n---> LINKED LIST BASED STACK <----\n"
              << std::endl;

    while (true)
    {
        std::cout << std::endl;
        std::cout << "==> Operations: <==" << std::endl
                  << "1. PUSH" << std::endl
                  << "2. POP" << std::endl
                  << "3. PEEK" << std::endl
                  << "4. PRINT" << std::endl
                  << "5. EXIT" << std::endl
                  << "====================" << std::endl;

        std::cout << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:

            std::cout << "Enter the value: ";
            std::cin >> value;
            stack.push(value);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            stack.peek();
            break;

        case 4:
            stack.print();
            break;

        case 5:
            std::cout << "EXITING THE PROGRAM.";
            return 0;

        default:
            std::cout << "Invalid choice, kindly select again." << std::endl;
            break;
        }
    }
}
