#include <stdio.h>

int main()
{
    char ch = 'c';

    switch (ch)
    {
    case 'a':
        puts("A");
    case 'b':
        puts("B");
    case 'c':
        puts("B");
    case 'd':
        puts("B");
    
    default:
        puts("C");
    }

    return 0;
}