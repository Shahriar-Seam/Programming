#include <stdio.h>
#include <stdlib.h>

int main()
{
    int durjay = 230234;
    char turjo[10];

    itoa(durjay, turjo, 10);

    puts(turjo);

    return 0;
}