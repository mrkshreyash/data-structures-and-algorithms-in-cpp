#include <iostream>

int Factorial(int num)
{
    if (num < 2)
    {
        return 1;
    }
    return num * Factorial(num - 1);
}

int main()
{
    int result = Factorial(5);

    std::cout << result;

    return 0;
}
