#include <iostream>

// 1, 2, 3, 5, 8

int FibonacciSeries(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return FibonacciSeries(num - 1) + FibonacciSeries(num - 2);
}

int main()
{
    int result = FibonacciSeries(5);

    std::cout << result;

    return 0;
}