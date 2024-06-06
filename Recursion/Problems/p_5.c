/*
Write a recursive solution to evaluate the 
previous polynomial for any given x and n. 
Like, when x=2 and n=5, we have
1 + x + x2 + ................. + xn-1 = 31
*/

#include <stdio.h>
#include <math.h>

int recurse(int x, int n, int i)
{
    if (n == 0) {
        return 1;
    }
    if (i < n) {
        return (int) pow(x, i) + recurse(x, n, i + 1);
    }

    return 0;
}

int main()
{
    int x, n;

    scanf("%d %d", &x, &n);

    printf("%d", recurse(x, n, 0));

    return 0;
}