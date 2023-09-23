#include <stdio.h>

int main()
{
    int i = 5;

    for (i = 20; i < 50; i++) {
        printf("%p\n", &i);
        break;
    }

    printf("\n%p", &i);

    return 0;
}