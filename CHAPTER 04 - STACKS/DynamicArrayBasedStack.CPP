#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> dynamicArray;

public:
    void push(int value)
    {
        dynamicArray.push_back(value);
        cout << "INFO: " << value << " pushed." << endl;
    }

    void pop()
    {
        if (dynamicArray.empty())
        {
            cout << "WARN: STACK is empty." << endl;
            return;
        }

        cout << "INFO: Popped " << dynamicArray.back() << " from the STACK." << endl;
        dynamicArray.pop_back();
    }

    void peek()
    {
        if (dynamicArray.empty())
        {
            cout << "WARN: STACK is empty." << endl;
            return;
        }

        cout << "INFO: Element on top is : " << dynamicArray.back() << endl;
    }

    void print()
    {
        if (dynamicArray.empty())
        {
            cout << "WARN: STACK is empty." << endl;
            return;
        }

        cout << "INFO: STACK (bottom --> top) : ";
        for (int val : dynamicArray)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    Stack stack;

    int choice, value;

    while (true)
    {
        cout << "\n----> Stack Menu <----" << endl;
        cout << "1. PUSH" << endl
             << "2. POP" << endl
             << "3. PEEK" << endl
             << "4. PRINT" << endl
             << "5. EXIT" << endl
             << "Choose: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
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
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid Choice !" << endl;
        }
    }
}