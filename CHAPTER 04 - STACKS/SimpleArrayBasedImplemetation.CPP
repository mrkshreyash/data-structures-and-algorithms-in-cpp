#include <iostream>

class ArrayStack
{
private:
    int *array;
    int capacity;
    int topIndex;

public:
    // Constructor
    ArrayStack(int size)
    {
        capacity = size;
        array = new int[capacity];
        topIndex = -1; // Initially the stack is empty
    }

    // Destructor
    ~ArrayStack()
    {
        delete[] array;
        std::cout << "\n\n==== DELETE: Stack object destoryed. ====" << std::endl;
    }

    bool isEmpty()
    {
        if (topIndex == -1)
        {
            std::cout << "CHECK: The stack is empty." << std::endl;
            return true;
        }
        // std::cout << "CHECK: The stack is not empty." << std::endl;
        return false;
    }

    bool isFull()
    {
        if (topIndex == capacity - 1)
        {
            std::cout << "CHECK: The stack is full." << std::endl;
            return true;
        }
        // std::cout << "CHECK: The stack is not full." << std::endl;
        return false;
    }

    int top()
    {
        if (ArrayStack::isEmpty() == true)
        {
            // std::cout << "INFO: The stack is empty, cannot return any value." << std::endl;
            return -1;
        }

        std::cout << "VALUE: The top element on the stack is: " << array[topIndex] << std::endl;
        return topIndex;
    }

    void push(int val)
    {

        if (ArrayStack::isFull() == true)
        {
            std::cout << "\n==== ALERT: Stack Overflow. ====\n"
                      << std::endl;
            return;
        }
        else
        {
            topIndex += 1;
            array[topIndex] = val;
            std::cout << "INFO: Element " << val << " is pushed into stack." << std::endl;
            return;
        }
    }

    void pop()
    {
        if (ArrayStack::isEmpty() == true)
        {
            std::cout << "\n==== ALERT: Stack Underflow. ====\n"
                      << std::endl;
            return;
        }

        std::cout << "\nINFO: Element " << array[topIndex] << " is popped." << std::endl;
        topIndex -= 1;
    }
};

int main()
{
    ArrayStack stack(5);
    stack.pop();
    stack.top();
    stack.push(5);
    stack.top();
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);
    stack.push(11);
    stack.top();
    stack.pop();
    stack.top();
    return 0;
}