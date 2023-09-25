#include <stdio.h>

void Test(void)
{
    static int a = 10;
    a++;
    printf(" %d", a);
}

int main()
{
    Test();
    Test();
    Test();

    return 0;
}