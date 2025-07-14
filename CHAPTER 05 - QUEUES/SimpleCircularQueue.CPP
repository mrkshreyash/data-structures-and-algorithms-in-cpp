#include <iostream>
#include <string>

#define MAX_SIZE 5

class SimpleCircularQueue
{
private:
    int rear, front;
    int array[MAX_SIZE];

public:
    SimpleCircularQueue()
    {
        rear = -1;
        front = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return (front == (rear + 1) % MAX_SIZE);
    }

    bool enQueue(int value)
    {

        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            front = 0;
        }

        rear = (rear + 1) % MAX_SIZE;
        array[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        if (front == rear)
        {
            front = rear = -1; // emtpy queue because front == rear meaning it only include 1 element.
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }

        return true;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }

        return array[front];
    }

    void print()
    {

        if (isEmpty())
        {
            std::cout << "List is emtpy.";
            return;
        }

        std::cout << std::endl;

        int i = front;

        while (true)
        {

            std::cout << " | " << array[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX_SIZE;
        }

        std::cout << " | " << std::endl;
    }
};

int main()
{
    SimpleCircularQueue s;
    int choice, value;

    while (true)
    {
        std::cout << std::endl;

        std::cout << " --------> Simple Circular Queue <-------- " << std::endl
                  << " 1. Enqueue" << std::endl
                  << " 2. Dequeu" << std::endl
                  << " 3. Front" << std::endl
                  << " 4. Print" << std::endl
                  << " 5. Exit" << std::endl
                  << " ----------------------------------------- " << std::endl;

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        std::cout << std::endl;

        switch (choice)
        {
        case 1:
            if (s.isFull())
            {
                std::cout << "\nWARN: Queue Overflow. (Queue is full.)" << std::endl;
            }
            else
            {
                std::cout << "Enter element value: ";
                std::cin >> value;

                if (s.enQueue(value))
                {
                    std::cout << "\nINS: Value " << value << " is inserted successfuly.\n"
                              << std::endl;
                }
            }
            break;

        case 2:

            if (s.isEmpty())
            {
                std::cout << "INFO: Queue is emtpy." << std::endl;
            }
            else

            {

                int deletingElement = s.peek();
                s.deQueue();

                std::cout << "DEL: Element " << deletingElement << " deleted successfuly." << std::endl;
            }

            break;

        case 3:

            if (s.peek() == -1)
            {
                std::cout << "INFO: The list is empty." << std::endl;
            }
            else
            {
                std::cout << "INFO: The element on front is: " << s.peek() << std::endl;
            }

            break;

        case 4:
            if (s.isEmpty())
            {
                std::cout << "INFO: Queue is empty." << std::endl;
            }
            else
            {
                s.print();
            }
            break;

        case 5:
            std::cout << "INFO: Exiting the system." << std::endl;
            return 0;

        default:
            std::cout << "INFO: Please, choose valid option." << std::endl;
            break;
        }
    }

    return 0;
}
