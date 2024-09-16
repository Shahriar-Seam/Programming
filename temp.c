#include <stdio.h>

long long int g_fibonacci_array[100] = {};

long long int fibonacci(int i)
{
    if (i < 2)
    {
        return i;
    }

    if (g_fibonacci_array[i] > 0)
    {
        return g_fibonacci_array[i];
    }

    g_fibonacci_array[i] = fibonacci(i - 1) + fibonacci(i - 2);

    return g_fibonacci_array[i];
}

int main()
{
    for (int i = 0; i < 50; i++)
    {
        printf("%lld\n", fibonacci(i));
    }

    return 0;
}