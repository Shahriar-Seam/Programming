#include <stdio.h>

int main()
{
    int a, b, c, d, temp;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (c > d) {
        temp = c;
        c = d;
        d = temp;
    }
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    printf("2nd largest = %d\n", c);

    return 0;
}