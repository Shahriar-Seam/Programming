#include <stdio.h>

int rifat()
{
    int sadik = 5;
    static int turjo = 3;

    turjo++;
    sadik++;

    printf("turjo = %d\tsadik = %d\n", turjo, sadik);
}

int main()
{
    int durjay = 2;

    rifat();
    rifat();
    rifat();

    return 0;
}