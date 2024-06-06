#include <stdio.h>

double pi = 3.14; // Global variable

void my_fnc()
{
    double pi = 3.1416; // Local variable
    // pi = 3.1416; // it would change value of pi as global variable
    return;
}

int main()
{
    printf("%lf\n", pi);
    my_fnc();
    printf("%lf\n", pi);

    return 0;
}