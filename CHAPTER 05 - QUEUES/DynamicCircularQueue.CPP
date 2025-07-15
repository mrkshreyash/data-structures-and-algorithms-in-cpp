#include <iostream>
#include <vector>

using namespace std;

class DynamicCircularQueue
{
private:
    vector<int> dynamicQueue;
    int front, rear, count, capacity;

public:
    DynamicCircularQueue(int size)
    {
        dynamicQueue.resize(size);
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return (count == capacity);
    }

    void enQueue(int value)
    {
        if (isFull())
        {

            // Resize the list
            // double the capacity
            int newCapacity = capacity * 2;

            cout << "\nThe list is full. Doubling the list capacity.\n===> New Capacity is: " << newCapacity << " <===" << endl;

            vector<int> newArr(newCapacity);

            // Copy old queue to new
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = dynamicQueue[i];
            }

            dynamicQueue = newArr;
            capacity = newCapacity;
            front = 0;
            rear = count - 1;
        }

        rear = (rear + 1) % capacity;
        dynamicQueue[rear] = value;
        cout << "\nThe element: " << value << " inserted into the Queue." << endl;
        count++;
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "WARN: Cannot remove element from empty list. (Queue Underflow.)";
            return;
        }

        cout << "\nINFO: Element " << dynamicQueue[front] << " removed from the Queue." << endl;
        front = (front + 1) % capacity;
        count--;
    }

    void print()
    {

        int i = front;

        cout << "\nPrinting the list: ";
        while (true)
        {
            cout << " | " << dynamicQueue[i];

            if (rear == i)
                break;

            i = (i + 1) % capacity;
        }

        cout << " | " << endl;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "INFO: The list is empty." << endl;
            return;
        }

        cout << "Element on front is : " << dynamicQueue[front] << endl;
    }
};

int main()
{
    DynamicCircularQueue dcq(5);
    int choice, value;

    while (true)
    {
        std::cout << std::endl;

        std::cout << " --------> Dynamic Circular Queue <-------- " << std::endl
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
            std::cout << "Enter element value: ";
            std::cin >> value;
            dcq.enQueue(value);
            break;

        case 2:

            dcq.deQueue();
            break;

        case 3:

            dcq.peek();

            break;

        case 4:
            dcq.print();
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
