/*
Write a recursive solution to print the 
polynomial series for any input 
n: 1 + x + x2 + ................. + xn-1
*/

#include <stdio.h>

void recurse(int i, int n)
{
    if (i == n) {
        return;
    }

    if (i == 0) {
        printf("1");
    }
    else if (i == 1) {
        printf(" + x");
    }
    else {
        printf(" + x^%d", i);
    }

    recurse(i + 1, n);
}

int main()
{
    int n;

    scanf("%d", &n);

    recurse(0, n);

    return 0;
}